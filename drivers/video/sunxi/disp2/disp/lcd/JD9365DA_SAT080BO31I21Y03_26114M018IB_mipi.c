/*
 * drivers/video/sunxi/disp2/disp/lcd/JD9365DA_SAT080BO31I21Y03_26114M018IB.c
 *
 * Copyright (c) 2007-2018 Allwinnertech Co., Ltd.
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

//#include "JD9365DA_SAT080BO31I21Y03_26114M018IB.h"
//#include <mach/sys_config.h>
#include "panels.h"

/*
&lcd0 {
	lcd_used            = <1>;
	status              = "okay";
	lcd_driver_name     = "JD9365DA_SAT080BO31I21Y03_26114M018IB";
	lcd_backlight       = <50>;
	lcd_if              = <4>;

	lcd_x               = <800>;
	lcd_y               = <1280>;
	lcd_width           = <135>;
	lcd_height          = <216>;
	lcd_dclk_freq       = <75>;

	lcd_pwm_used        = <1>;
	lcd_pwm_ch          = <0>;
	lcd_pwm_freq        = <50000>;
	lcd_pwm_pol         = <1>;
	lcd_pwm_max_limit   = <255>;

	lcd_hbp             = <88>;
	lcd_ht              = <960>;
	lcd_hspw            = <4>;
	lcd_vbp             = <12>;
	lcd_vt              = <1300>;
	lcd_vspw            = <4>;

	lcd_frm             = <0>;
	lcd_gamma_en        = <0>;
	lcd_bright_curve_en = <0>;
	lcd_cmap_en         = <0>;

	deu_mode            = <0>;
	lcdgamma4iep        = <22>;
	smart_color         = <90>;

	lcd_dsi_if          = <0>;
	lcd_dsi_lane        = <4>;
	lcd_dsi_format      = <0>;
	lcd_dsi_te          = <0>;
	lcd_dsi_eotp        = <0>;

	lcd_pin_power = "dcdc1";
	lcd_pin_power1 = "eldo3";

	lcd_power = "eldo3";

	lcd_power1 = "dcdc1";
	lcd_power2 = "dc1sw";

	lcd_gpio_1 = <&pio PD 22 1 0 3 1>;

	pinctrl-0 = <&dsi4lane_pins_a>;
	pinctrl-1 = <&dsi4lane_pins_b>;

	lcd_bl_en = <&pio PB 8 1 0 3 1>;
	lcd_bl_0_percent	= <15>;
	lcd_bl_100_percent  = <100>;
};

*/

extern s32 bsp_disp_get_panel_info(u32 screen_id, disp_panel_para *info);
static void LCD_power_on(u32 sel);
static void LCD_power_off(u32 sel);
static void LCD_bl_open(u32 sel);
static void LCD_bl_close(u32 sel);

static void LCD_panel_try_switch(u32 sel);
static void LCD_panel_init(u32 sel);
static void LCD_panel_exit(u32 sel);

//static u8 const mipi_dcs_pixel_format[4] = {0x77,0x66,0x66,0x55};
#define panel_reset(val) sunxi_lcd_gpio_set_value(sel, 2, val)
#define power_gpio_en(val) sunxi_lcd_gpio_set_value(sel, 1, val)
#define power_en(val) sunxi_lcd_gpio_set_value(sel, 0, val)
#define panel_getid0() sunxi_lcd_gpio_get_value(sel, 3)
#define panel_getid1() sunxi_lcd_gpio_get_value(sel, 4)

static void LCD_cfg_panel_info(panel_extend_para *info)
{
	u32 i = 0, j = 0;
	u32 items;
	u8 lcd_gamma_tbl[][2] = {
		//{input value, corrected value}
		{ 0, 0 },     { 15, 15 },   { 30, 30 },   { 45, 45 },
		{ 60, 60 },   { 75, 75 },   { 90, 90 },   { 105, 105 },
		{ 120, 120 }, { 135, 135 }, { 150, 150 }, { 165, 165 },
		{ 180, 180 }, { 195, 195 }, { 210, 210 }, { 225, 225 },
		{ 240, 240 }, { 255, 255 },
	};

	u32 lcd_cmap_tbl[2][3][4] = {
		{
			{ LCD_CMAP_G0, LCD_CMAP_B1, LCD_CMAP_G2, LCD_CMAP_B3 },
			{ LCD_CMAP_B0, LCD_CMAP_R1, LCD_CMAP_B2, LCD_CMAP_R3 },
			{ LCD_CMAP_R0, LCD_CMAP_G1, LCD_CMAP_R2, LCD_CMAP_G3 },
		},
		{
			{ LCD_CMAP_B3, LCD_CMAP_G2, LCD_CMAP_B1, LCD_CMAP_G0 },
			{ LCD_CMAP_R3, LCD_CMAP_B2, LCD_CMAP_R1, LCD_CMAP_B0 },
			{ LCD_CMAP_G3, LCD_CMAP_R2, LCD_CMAP_G1, LCD_CMAP_R0 },
		},
	};

	items = sizeof(lcd_gamma_tbl) / 2;
	for (i = 0; i < items - 1; i++) {
		u32 num = lcd_gamma_tbl[i + 1][0] - lcd_gamma_tbl[i][0];

		for (j = 0; j < num; j++) {
			u32 value = 0;

			value = lcd_gamma_tbl[i][1] +
				((lcd_gamma_tbl[i + 1][1] -
				  lcd_gamma_tbl[i][1]) *
				 j) / num;
			info->lcd_gamma_tbl[lcd_gamma_tbl[i][0] + j] =
				(value << 16) + (value << 8) + value;
		}
	}
	info->lcd_gamma_tbl[255] = (lcd_gamma_tbl[items - 1][1] << 16) +
				   (lcd_gamma_tbl[items - 1][1] << 8) +
				   lcd_gamma_tbl[items - 1][1];

	memcpy(info->lcd_cmap_tbl, lcd_cmap_tbl, sizeof(lcd_cmap_tbl));
}

static s32 LCD_open_flow(u32 sel)
{
	LCD_OPEN_FUNC(sel, LCD_power_on, 0); //must delay 0
	LCD_OPEN_FUNC(sel, LCD_panel_try_switch, 0); //must delay 0
	LCD_OPEN_FUNC(sel, LCD_panel_init,
		      200); //open lcd power, than delay 200ms
	LCD_OPEN_FUNC(sel, sunxi_lcd_tcon_enable,
		      50); //open lcd controller, and delay 100ms
	LCD_OPEN_FUNC(sel, LCD_bl_open, 0); //open lcd backlight, and delay 0ms

	return 0;
}

static s32 LCD_close_flow(u32 sel)
{
	LCD_CLOSE_FUNC(sel, LCD_bl_close,
		       200); //close lcd backlight, and delay 0ms
	LCD_CLOSE_FUNC(sel, sunxi_lcd_tcon_disable,
		       20); //close lcd controller, and delay 0ms
	LCD_CLOSE_FUNC(sel, LCD_panel_exit,
		       10); //open lcd power, than delay 200ms
	LCD_CLOSE_FUNC(sel, LCD_power_off,
		       500); //close lcd power, and delay 500ms

	return 0;
}

static void LCD_power_on(u32 sel)
{
	panel_reset(0);
	sunxi_lcd_power_enable(sel, 0); //config lcd_power pin to open lcd power
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_enable(sel,
			       1); //config lcd_power pin to open lcd power1
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_enable(sel,
			       2); //config lcd_power pin to open lcd power2
	sunxi_lcd_delay_ms(5);
	power_en(1);
	sunxi_lcd_delay_ms(20);
	power_gpio_en(1);

	//panel_reset(1);
	sunxi_lcd_delay_ms(40);
	panel_reset(1);
	sunxi_lcd_delay_ms(10);
	panel_reset(0);
	sunxi_lcd_delay_ms(5);
	panel_reset(1);
	sunxi_lcd_delay_ms(120);
	//sunxi_lcd_delay_ms(5);

	sunxi_lcd_pin_cfg(sel, 1);
}

static void LCD_power_off(u32 sel)
{
	sunxi_lcd_pin_cfg(sel, 0);
	power_gpio_en(0);
	power_en(0);
	sunxi_lcd_delay_ms(20);
	panel_reset(0);
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_disable(sel,
				2); //config lcd_power pin to close lcd power2
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_disable(sel,
				1); //config lcd_power pin to close lcd power1
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_disable(sel,
				0); //config lcd_power pin to close lcd power
}

static void LCD_bl_open(u32 sel)
{
	sunxi_lcd_pwm_enable(sel);
	sunxi_lcd_delay_ms(50);
	sunxi_lcd_backlight_enable(
		sel); //config lcd_bl_en pin to open lcd backlight
}

static void LCD_bl_close(u32 sel)
{
	sunxi_lcd_backlight_disable(
		sel); //config lcd_bl_en pin to close lcd backlight
	sunxi_lcd_delay_ms(20);
	sunxi_lcd_pwm_disable(sel);
}

#define REGFLAG_DELAY 0XFE
#define REGFLAG_END_OF_TABLE 0xFD // END OF REGISTERS MARKER

struct LCM_setting_table {
	u8 cmd;
	u32 count;
	u8 para_list[64];
};

/*add panel initialization below*/

static struct LCM_setting_table lcm_initialization_setting[] = {

	//======initial code==========//
	//Page0
	{ 0xE0, 1, { 0x00 } },
	{ 0xE1, 1, { 0x93 } },
	{ 0xE2, 1, { 0x65 } },
	{ 0xE3, 1, { 0xF8 } },
	{ 0x80, 1, { 0x03 } },

	{ 0xE0, 1, { 0x01 } },
	{ 0x00, 1, { 0x00 } },
	{ 0x01, 1, { 0x4E } },
	{ 0x03, 1, { 0x00 } },
	{ 0x04, 1, { 0x65 } },

	{ 0x0C, 1, { 0x74 } },

	{ 0x17, 1, { 0x00 } },
	{ 0x18, 1, { 0xB7 } },
	{ 0x19, 1, { 0x00 } },
	{ 0x1A, 1, { 0x00 } },
	{ 0x1B, 1, { 0xB7 } },
	{ 0x1C, 1, { 0x00 } },

	{ 0x24, 1, { 0xFE } },

	{ 0x37, 1, { 0x19 } },

	{ 0x38, 1, { 0x05 } },
	{ 0x39, 1, { 0x00 } },
	{ 0x3A, 1, { 0x01 } },
	{ 0x3B, 1, { 0x01 } },
	{ 0x3C, 1, { 0x70 } },
	{ 0x3D, 1, { 0xFF } },
	{ 0x3E, 1, { 0xFF } },
	{ 0x3F, 1, { 0xFF } },

	{ 0x40, 1, { 0x06 } },
	{ 0x41, 1, { 0xA0 } },
	{ 0x43, 1, { 0x1E } },
	{ 0x44, 1, { 0x0F } },
	{ 0x45, 1, { 0x28 } },
	{ 0x4B, 1, { 0x04 } },

	{ 0x55, 1, { 0x02 } },
	{ 0x56, 1, { 0x01 } },
	{ 0x57, 1, { 0xA9 } },
	{ 0x58, 1, { 0x0A } },
	{ 0x59, 1, { 0x0A } },
	{ 0x5A, 1, { 0x37 } },
	{ 0x5B, 1, { 0x19 } },

	{ 0x5D, 1, { 0x78 } },
	{ 0x5E, 1, { 0x63 } },
	{ 0x5F, 1, { 0x54 } },
	{ 0x60, 1, { 0x49 } },
	{ 0x61, 1, { 0x45 } },
	{ 0x62, 1, { 0x38 } },
	{ 0x63, 1, { 0x3D } },
	{ 0x64, 1, { 0x28 } },
	{ 0x65, 1, { 0x43 } },
	{ 0x66, 1, { 0x41 } },
	{ 0x67, 1, { 0x43 } },
	{ 0x68, 1, { 0x62 } },
	{ 0x69, 1, { 0x50 } },
	{ 0x6A, 1, { 0x57 } },
	{ 0x6B, 1, { 0x49 } },
	{ 0x6C, 1, { 0x44 } },
	{ 0x6D, 1, { 0x37 } },
	{ 0x6E, 1, { 0x23 } },
	{ 0x6F, 1, { 0x10 } },
	{ 0x70, 1, { 0x78 } },
	{ 0x71, 1, { 0x63 } },
	{ 0x72, 1, { 0x54 } },
	{ 0x73, 1, { 0x49 } },
	{ 0x74, 1, { 0x45 } },
	{ 0x75, 1, { 0x38 } },
	{ 0x76, 1, { 0x3D } },
	{ 0x77, 1, { 0x28 } },
	{ 0x78, 1, { 0x43 } },
	{ 0x79, 1, { 0x41 } },
	{ 0x7A, 1, { 0x43 } },
	{ 0x7B, 1, { 0x62 } },
	{ 0x7C, 1, { 0x50 } },
	{ 0x7D, 1, { 0x57 } },
	{ 0x7E, 1, { 0x49 } },
	{ 0x7F, 1, { 0x44 } },
	{ 0x80, 1, { 0x37 } },
	{ 0x81, 1, { 0x23 } },
	{ 0x82, 1, { 0x10 } },

	{ 0xE0, 1, { 0x02 } },
	{ 0x00, 1, { 0x47 } },
	{ 0x01, 1, { 0x47 } },
	{ 0x02, 1, { 0x45 } },
	{ 0x03, 1, { 0x45 } },
	{ 0x04, 1, { 0x4B } },
	{ 0x05, 1, { 0x4B } },
	{ 0x06, 1, { 0x49 } },
	{ 0x07, 1, { 0x49 } },
	{ 0x08, 1, { 0x41 } },
	{ 0x09, 1, { 0x1F } },
	{ 0x0A, 1, { 0x1F } },
	{ 0x0B, 1, { 0x1F } },
	{ 0x0C, 1, { 0x1F } },
	{ 0x0D, 1, { 0x1F } },
	{ 0x0E, 1, { 0x1F } },
	{ 0x0F, 1, { 0x5F } },
	{ 0x10, 1, { 0x5F } },
	{ 0x11, 1, { 0x57 } },
	{ 0x12, 1, { 0x77 } },
	{ 0x13, 1, { 0x35 } },
	{ 0x14, 1, { 0x1F } },
	{ 0x15, 1, { 0x1F } },

	{ 0x16, 1, { 0x46 } },
	{ 0x17, 1, { 0x46 } },
	{ 0x18, 1, { 0x44 } },
	{ 0x19, 1, { 0x44 } },
	{ 0x1A, 1, { 0x4A } },
	{ 0x1B, 1, { 0x4A } },
	{ 0x1C, 1, { 0x48 } },
	{ 0x1D, 1, { 0x48 } },
	{ 0x1E, 1, { 0x40 } },
	{ 0x1F, 1, { 0x1F } },
	{ 0x20, 1, { 0x1F } },
	{ 0x21, 1, { 0x1F } },
	{ 0x22, 1, { 0x1F } },
	{ 0x23, 1, { 0x1F } },
	{ 0x24, 1, { 0x1F } },
	{ 0x25, 1, { 0x5F } },
	{ 0x26, 1, { 0x5F } },
	{ 0x27, 1, { 0x57 } },
	{ 0x28, 1, { 0x77 } },
	{ 0x29, 1, { 0x35 } },
	{ 0x2A, 1, { 0x1F } },
	{ 0x2B, 1, { 0x1F } },

	{ 0x58, 1, { 0x40 } },
	{ 0x59, 1, { 0x00 } },
	{ 0x5A, 1, { 0x00 } },
	{ 0x5B, 1, { 0x10 } },
	{ 0x5C, 1, { 0x06 } },
	{ 0x5D, 1, { 0x40 } },
	{ 0x5E, 1, { 0x01 } },
	{ 0x5F, 1, { 0x02 } },
	{ 0x60, 1, { 0x30 } },
	{ 0x61, 1, { 0x01 } },
	{ 0x62, 1, { 0x02 } },
	{ 0x63, 1, { 0x03 } },
	{ 0x64, 1, { 0x6B } },
	{ 0x65, 1, { 0x05 } },
	{ 0x66, 1, { 0x0C } },
	{ 0x67, 1, { 0x73 } },
	{ 0x68, 1, { 0x09 } },
	{ 0x69, 1, { 0x03 } },
	{ 0x6A, 1, { 0x56 } },
	{ 0x6B, 1, { 0x08 } },
	{ 0x6C, 1, { 0x00 } },
	{ 0x6D, 1, { 0x04 } },
	{ 0x6E, 1, { 0x04 } },
	{ 0x6F, 1, { 0x88 } },
	{ 0x70, 1, { 0x00 } },
	{ 0x71, 1, { 0x00 } },
	{ 0x72, 1, { 0x06 } },
	{ 0x73, 1, { 0x7B } },
	{ 0x74, 1, { 0x00 } },
	{ 0x75, 1, { 0xF8 } },
	{ 0x76, 1, { 0x00 } },
	{ 0x77, 1, { 0xD5 } },
	{ 0x78, 1, { 0x2E } },
	{ 0x79, 1, { 0x12 } },
	{ 0x7A, 1, { 0x03 } },
	{ 0x7B, 1, { 0x00 } },
	{ 0x7C, 1, { 0x00 } },
	{ 0x7D, 1, { 0x03 } },
	{ 0x7E, 1, { 0x7B } },

	{ 0xE0, 1, { 0x04 } },
	{ 0x00, 1, { 0x0E } },
	{ 0x02, 1, { 0xB3 } },
	{ 0x09, 1, { 0x60 } },
	{ 0x0E, 1, { 0x2A } },
	{ 0x36, 1, { 0x59 } },
	{ 0x37, 1, { 0x58 } }, //2022-1-22
	{ 0xE0, 1, { 0x00 } },
	//SLP OUT
	{ 0x11, 0, { 0x00 } }, // SLPOUT
	{ REGFLAG_DELAY, REGFLAG_DELAY, { 120 } },

	//DISP ON
	{ 0x29, 0, { 0x00 } }, // DSPON
	{ REGFLAG_DELAY, REGFLAG_DELAY, { 20 } },
	{ 0x35, 0, { 0x00 } },
	{ REGFLAG_END_OF_TABLE, REGFLAG_END_OF_TABLE, {} }
};

static void LCD_panel_try_switch(u32 sel)
{
#if 0
	//u8 result[16] = {0};
	//struct LCM_setting_table readId = {0xB0, 1, {0x00}};
	int val_id, val_id1;
	//u32 num = 0;
	sunxi_lcd_delay_ms(100);

	sunxi_lcd_dsi_dcs_read(sel, 0x04, result, &num);

	printf("get lcd id 0x%x,0x%x,0x%x\n", result[0], result[1], result[2]);

	if (result[0] == 0x93) {
		LCD_power_off(sel);
		sunxi_lcd_switch_compat_panel(sel, 1); /*switch to lcd0_1*/
		return;
	}
//#else
#if 1
	val_id = panel_getid0();
	sunxi_lcd_delay_ms(10);
	val_id1 = panel_getid1();
	val_id = (val_id | (val_id1 << 1));
	printf("get lcd id 0x%x\n", val_id);
	if (val_id == 1)
		sunxi_lcd_switch_compat_panel(sel, 1); /*switch to lcd0_1*/
	else if (val_id == 2)
		sunxi_lcd_switch_compat_panel(sel, 2); /*switch to lcd0_2*/
	else if (val_id == 0)
		sunxi_lcd_switch_compat_panel(sel, 3); /*switch to lcd0_3*/
	else {
		//sunxi_lcd_switch_compat_panel(sel, 1);/*switch to lcd0_3*/
		printf("<===default lcd0 ===>\n"); /*because float or pull up is 3 so switch to lcd0*/
	}
#endif
#endif
}

static void LCD_panel_init(u32 sel)
{
	__u32 i;

	sunxi_lcd_dsi_clk_enable(sel);
	sunxi_lcd_delay_ms(20);
	sunxi_lcd_dsi_dcs_write_0para(sel, DSI_DCS_SOFT_RESET);
	sunxi_lcd_delay_ms(10);
	for (i = 0;; i++) {
		if (lcm_initialization_setting[i].count == REGFLAG_END_OF_TABLE)
			break;
		else if (lcm_initialization_setting[i].count == REGFLAG_DELAY)
			sunxi_lcd_delay_ms(
				lcm_initialization_setting[i].para_list[0]);
#ifdef SUPPORT_DSI
		else
			dsi_dcs_wr(sel, lcm_initialization_setting[i].cmd,
				   lcm_initialization_setting[i].para_list,
				   lcm_initialization_setting[i].count);
#endif
		//break;
	}

	return;
}

static void LCD_panel_exit(u32 sel)
{
	sunxi_lcd_dsi_dcs_write_0para(sel, DSI_DCS_SET_DISPLAY_OFF);
	sunxi_lcd_delay_ms(20);
	sunxi_lcd_dsi_dcs_write_0para(sel, DSI_DCS_ENTER_SLEEP_MODE);
	sunxi_lcd_delay_ms(80);

	return;
}

//sel: 0:lcd0; 1:lcd1
static s32 LCD_user_defined_func(u32 sel, u32 para1, u32 para2, u32 para3)
{
	return 0;
}

//sel: 0:lcd0; 1:lcd1
/*static s32 LCD_set_bright(u32 sel, u32 bright)
{
	sunxi_lcd_dsi_dcs_write_1para(sel,0x51,bright);
	return 0;
}*/

__lcd_panel_t JD9365DA_SAT080BO31I21Y03_26114M018IB_mipi_panel = {
	/* panel driver name, must mach the name of lcd_drv_name in sys_config.fex */
	.name = "SAT080BO31I21Y03_26114M018IB",
	.func = {
		.cfg_panel_info = LCD_cfg_panel_info,
		.cfg_open_flow = LCD_open_flow,
		.cfg_close_flow = LCD_close_flow,
		.lcd_user_defined_func = LCD_user_defined_func,
		//.set_bright = LCD_set_bright,
	},
};
