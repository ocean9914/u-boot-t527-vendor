/*
 * sprite/cartoon/sprite_char/sfte/FontEngine.c
 *
 * Copyright (c) 2007-2019 Allwinnertech Co., Ltd.
 * Author: zhengxiaobin <zhengxiaobin@allwinnertech.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <common.h>
#include "FontEngine.h"
#include "sfte.h"
#include <malloc.h>
SFTE_Face face;
FE_FONT   font;

__s32 open_font(const char *font_file, int pixel_size, unsigned int width,
		unsigned char *addr)
{
	if (font != NULL)
		return 0;

	font = (FE_FONT)malloc(sizeof(FE_FONT_t));
	if (font == NULL) {
		return 0;
	}

	face = SFTE_New_Face((char *)font_file);
	if (face == NULL)
		goto error;

	if (SFTE_Set_Pixel_Sizes(face, pixel_size))
		goto error;

	font->face = face;
	font->bbox_ymin = face->descender * (__s32)pixel_size /
			  (face->ascender - face->descender);
	font->line_distance = face->height * pixel_size / face->units_per_EM;
	font->base_width = width;
	font->base_addr = addr;
	font->base_psize = pixel_size;

	return 0;

error:
	if (face != NULL)
		SFTE_Done_Face(face);
	if (font != NULL)
		free(font);

	return -1;
}

__s32 close_font(void)
{
	if (font == NULL)
		return -1;

	if (SFTE_Done_Face(font->face)) {
		return -1;
	}
	font->face = NULL;

	free(font);

	return 0;
}

__s32 check_change_line(unsigned int x, unsigned char ch)
{
	if (SFTE_Get_Glyph(face, ch))
		return -1;

	/* place pen to the next line */
	if (x + face->glyph->bitmap_left + face->glyph->bitmap.width >=
	    font->base_width) {
		return 1;
	}

	return 0;
}

#define TC_WHITE       { 255, 255, 255, 255 }
#define TC_BLACK       {   0,   0,   0, 255 }
#define TC_RED         {   0,   0, 255, 255 }
#define TC_GREEN       {   0, 255,   0, 255 }
#define TC_BLUE        { 255,   0,   0, 255 }

static __s32 draw_pixel(__u32 x, __u32 y, __u32 width, __u8 *alpha, __u32 color)
{
	__u8 *tmp_addr;
	__u32 *base;
	__u32 i;

	tmp_addr = font->base_addr + font->base_width * (y << 2) + (x << 2);
	base = (__u32 *)tmp_addr;
	for (i = 0; i < width; i++) {
		base[i] = (alpha[i] << 8);
	}

	return 0;
}

/* origin is the upper left corner */
/* origin is the upper left corner */
__s32 draw_bmp_ulc(__u32 ori_x, __u32 ori_y, __u32 color)
{
	__u32 i, j;
	__u8 *p;
	__u8 alpha[64]; // alpha
	SFTE_Bitmap *bitmap;

	bitmap = &(face->glyph->bitmap);
	p = (__u8 *)bitmap->buffer;

	ori_x += face->glyph->bitmap_left;
	ori_y += font->base_psize + font->bbox_ymin - face->glyph->bitmap_top;

	for (i = 0; i < bitmap->rows; i++) {
		for (j = 0; j < bitmap->width; j++) {
			if (bitmap->pitch > 0)
				alpha[j] = p[i * bitmap->pitch + j];
			else
				alpha[j] = p[(bitmap->rows - 1 - i) *
						 -(bitmap->pitch) +
					     j];
		}
		draw_pixel(ori_x, ori_y + i, bitmap->width, alpha, color);
	}
	flush_cache(
		    (unsigned long)font->base_addr, 1024*1024);

	return face->glyph->advance.x >> 6; //???ص?ǰ?ֵĿ???
}

__s32 draw_cursor(__u32 ori_x, __u32 ori_y, __u32 color)
{
	__u32 i, j;
	__u8 *p;
	__u8 alpha[64]; // alpha
	SFTE_Bitmap *bitmap;

	bitmap = &(face->glyph->bitmap);
	p = (__u8 *)bitmap->buffer;

	ori_x += face->glyph->bitmap_left;
	ori_y += font->base_psize + font->bbox_ymin - face->glyph->bitmap_top;

	for (i = 0; i < bitmap->rows; i++) {
		for (j = 0; j < bitmap->width; j++) {
			if (bitmap->pitch > 0)
				alpha[j] = p[i * bitmap->pitch + j];
			else
				alpha[j] = p[(bitmap->rows - 1 - i) *
						 -(bitmap->pitch) +
					     j];
		}
		draw_pixel(ori_x, ori_y + i, bitmap->width, alpha, color);
	}
	flush_cache(
		    (unsigned long)font->base_addr, 1024*1024);

	return face->glyph->advance.x >> 6;
}
