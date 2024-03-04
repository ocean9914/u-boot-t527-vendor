/*
 * Copyright (C) 2013 Allwinnertech, wangjx <wangjx@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Adjustable factor-based clock implementation
 *
 * freq table from hardware, need follow rules
 * 1)   each table  named as
 *      factor_pll1_tbl
 *      factor_pll2_tbl
 *      ...
 * 2) for each table line
 *      a) follow the format PLLx(n, k, m, p, d1, d2, freq), and keep the
 *         factors order
 *      b) if any factor not used, skip it
 *      c) the factor is the value to write registers, not means factor + 1
 *
 *      example
 *      PLL1(9, 0, 0, 2, 60000000) means PLL1(n, k, m, p, freq)
 *      PLLVIDEO0(3, 0, 96000000) means PLLVIDEO0(n, m, freq)
 *
 */

#include "clk-sun8iw5.h"


 /* F_N8X8_P16x1 */


struct sunxi_clk_factor_freq factor_pllcpu_tbl[] = {
PLLCPU(9 , 0 , 3 , 0 , 60000000U),
PLLCPU(10 , 0 , 3  , 0 ,	66000000U),
PLLCPU(11 , 0 , 3 , 0 ,	72000000U),
PLLCPU(12 , 0 , 3 , 0 ,	78000000U),
PLLCPU(4 , 1 , 2 , 0 ,	80000000U),
PLLCPU(13 , 0 , 3 , 0 ,	84000000U),
PLLCPU(10 , 0 , 2 , 0 ,	88000000U),
PLLCPU(14 , 0 , 3 , 0 ,	90000000U),
PLLCPU(15 , 0 , 3 , 0 ,	96000000U),
PLLCPU(16 , 0 , 3 , 0 ,	102000000U),
PLLCPU(12 , 0 , 2 , 0 ,	104000000U),
PLLCPU(17 , 0 , 3 , 0 ,	108000000U),
PLLCPU(6 , 1 , 2  , 0 ,	112000000U),
PLLCPU(18 , 0 , 3 , 0 ,	114000000U),
PLLCPU(19 , 0 , 3 , 0 ,	120000000U),
PLLCPU(20 , 0 , 3 , 0 ,	126000000U),
PLLCPU(7 , 1 , 2 , 0 ,	128000000U),
PLLCPU(21 , 0 , 3 , 0,	132000000U),
PLLCPU(16 , 0 , 2 , 0,	136000000U),
PLLCPU(22 , 0 , 3 , 0,	138000000U),
PLLCPU(23 , 0 , 3 , 0,	144000000U),
PLLCPU(24 , 0 , 3 , 0,	150000000U),
PLLCPU(18 , 0 , 2 , 0,	152000000U),
PLLCPU(12 , 1 , 3 , 0,	156000000U),
PLLCPU(19 , 0 , 2 , 0,	160000000U),
PLLCPU(8 , 2 , 3 , 0,	162000000U),
PLLCPU(27 , 0 , 3 , 0,	168000000U),
PLLCPU(28 , 0 , 3 , 0 ,	174000000U),
PLLCPU(10 , 1 , 2 , 0,	176000000U),
PLLCPU(14 , 1 , 3 , 0,	180000000U),
PLLCPU(22 , 0 , 2 , 0,	184000000U),
PLLCPU(30 , 0 , 3 , 0,	186000000U),
PLLCPU(15 , 1 , 3 , 0,	192000000U),
PLLCPU(10 , 2 , 3 , 0,	198000000U),
PLLCPU(24 , 0 , 2 , 0,	200000000U),
PLLCPU(16 , 1 , 3 , 0,	204000000U),
PLLCPU(25 , 0 , 2 , 0,	208000000U),
PLLCPU(17 , 1 , 3 , 0,	216000000U),
PLLCPU(27 , 0 ,  2 , 0,	224000000U),
PLLCPU(18 , 1 , 3 , 0,	228000000U),
PLLCPU(28 , 0 , 2 , 0,	232000000U),
PLLCPU(12 , 2 , 3 , 0,	234000000U),
PLLCPU(19 , 1 , 3 , 0,	240000000U),
PLLCPU(30 , 0 , 2 , 0,	248000000U),
PLLCPU(20 , 1 , 3 , 0,	252000000U),
PLLCPU(15 , 1 , 2 , 0,	256000000U),
PLLCPU(21 , 1 , 3 , 0,	264000000U),
PLLCPU(14 , 2 , 3 , 0,	270000000U),
PLLCPU(16 , 1 , 2 , 0,	272000000U),
PLLCPU(22 , 1 , 3 , 0,	276000000U),
PLLCPU(23 , 1 , 3 , 0,	288000000U),
PLLCPU(24 , 1 , 3 , 0,	300000000U),
PLLCPU(18 , 1 , 2 , 0,	304000000U),
PLLCPU(16 , 2 , 3 , 0,	306000000U),
PLLCPU(25 , 1 , 3 , 0,	312000000U),
PLLCPU(9 , 3  , 2  , 0,	320000000U),
PLLCPU(26 , 1 , 3 , 0,	324000000U),
PLLCPU(27 , 1 , 3 , 0,	336000000U),
PLLCPU(18 , 2 , 3 , 0,	342000000U),
PLLCPU(28 , 1 , 3 , 0,	348000000U),
PLLCPU(21 , 1 , 2 , 0,	352000000U),
PLLCPU(29 , 1 , 3 , 0,	360000000U),
PLLCPU(22 , 1 , 2 , 0,	368000000U),
PLLCPU(30 , 1 , 3 , 0,	372000000U),
PLLCPU(20 ,  2 , 3 , 0,	378000000U),
PLLCPU(11 , 3 , 2 , 0,	384000000U),
PLLCPU(21 , 2 , 3 , 0,	396000000U),
PLLCPU(24 , 1 , 2 , 0,	400000000U),
PLLCPU(16 , 3 , 3 , 0,	408000000U),
PLLCPU(22 , 2 , 3 , 0,	414000000U),
PLLCPU(25 , 1 , 2 , 0,	416000000U),
PLLCPU(23 , 2 , 3 , 0,	432000000U),
PLLCPU(13 , 3 , 2 , 0,	448000000U),
PLLCPU(24 , 2 , 3 , 0,	450000000U),
PLLCPU(18 , 3 , 3 , 0,	456000000U),
PLLCPU(28 , 1 , 2 , 0,	464000000U),
PLLCPU(25 , 2 , 3 , 0,	468000000U),
PLLCPU(19 , 3 , 3 , 0,	480000000U),
PLLCPU(26 , 2 , 3 , 0,	486000000U),
PLLCPU(30 , 1 , 2 , 0,	496000000U),
PLLCPU(20 , 3 , 3 , 0,	504000000U),
PLLCPU(15 , 3 , 2 , 0,	512000000U),
PLLCPU(28 , 2 , 3 , 0,	522000000U),
PLLCPU(21 , 3 , 3 , 0,	528000000U),
PLLCPU(14 , 2 , 1 , 0,	540000000U),
PLLCPU(16 , 3 , 2 , 0,	544000000U),
PLLCPU(22 , 3 , 3 , 0,	552000000U),
PLLCPU(30 , 2 , 3 , 0,	558000000U),
PLLCPU(17 , 3 , 2 , 0,	576000000U),
PLLCPU(24 , 2 , 2 , 0,	600000000U),
PLLCPU(18 , 3 , 2 , 0,	608000000U),
PLLCPU(16 , 2 , 1 , 0,	612000000U),
PLLCPU(25 , 2 , 2 , 0,	624000000U),
PLLCPU(19 , 3 , 2 , 0,	640000000U),
PLLCPU(26 , 2 , 2 , 0,	648000000U),
PLLCPU(20 , 3 , 2 , 0,	672000000U),
PLLCPU(18 , 2 , 1 , 0,	684000000U),
PLLCPU(28 , 2 , 2 , 0,	696000000U),
PLLCPU(21 , 3 , 2 , 0,	704000000U),
PLLCPU(19 , 2 , 1 , 0,	720000000U),
PLLCPU(22 , 3 , 2 , 0,	736000000U),
PLLCPU(30 , 2  , 2 , 0,	744000000U),
PLLCPU(20 , 2 , 1 , 0,	756000000U),
PLLCPU(15 , 3 , 1 , 0,	768000000U),
PLLCPU(21 , 2 , 1 , 0,	792000000U),
PLLCPU(16 ,  3 , 1 , 0,	816000000U),
PLLCPU(22 , 2 , 1 , 0,	828000000U),
PLLCPU(17 , 3 , 1 , 0,	864000000U),
PLLCPU(24 , 2 , 1 , 0,	900000000U),
PLLCPU(18 , 3 , 1 , 0,	912000000U),
PLLCPU(25 , 2 , 1 , 0,	936000000U),
PLLCPU(19 , 3 , 1 , 0,	960000000U),
PLLCPU(26 , 2 , 1 , 0,	972000000U),
PLLCPU(20 , 3 , 1 , 0,	1008000000U),
PLLCPU(28 , 2 , 1 , 0,	1044000000U),
PLLCPU(21 , 3 , 1 , 0,	1056000000U),
PLLCPU(14 , 2 , 0 , 0,	1080000000U),
PLLCPU(22 , 1 , 0 , 0,	1104000000U),
PLLCPU(30 , 2 , 1 , 0,	1116000000U),
PLLCPU(23 , 1 , 0 , 0,	1152000000U),
PLLCPU(24 , 1 , 0 , 0,	1200000000U),
PLLCPU(16 , 2  , 0 , 0,	1224000000U),
PLLCPU(25 , 1 , 0 , 0,	1248000000U),
PLLCPU(26 , 1 , 0 , 0,	1296000000U),
PLLCPU(27 , 1 , 0 , 0,	1344000000U),
PLLCPU(18 , 2 , 0 , 0,	1368000000U),
PLLCPU(28 , 1 , 0 , 0,	1392000000U),
PLLCPU(19 , 2 , 0 , 0,	1440000000U),
PLLCPU(30 , 1 , 0 , 0,	1488000000U),
PLLCPU(20 , 2 , 0 , 0,	1512000000U),
PLLCPU(15 , 3 , 0 , 0,	1536000000U),
PLLCPU(21 , 2 , 0 , 0,	1584000000U),
PLLCPU(16 , 3 , 0 , 0,	1632000000U),
PLLCPU(22 , 2 , 0 , 0,	1656000000U),
PLLCPU(23 , 2 , 0 , 0,	1728000000U),
PLLCPU(24 , 2  , 0 , 0,	1800000000U),
PLLCPU(18 , 3 , 0 , 0,	1824000000U),
PLLCPU(25 , 2 , 0 , 0,	1872000000U),
PLLCPU(19 , 3 , 0 , 0,	1920000000U),
PLLCPU(26 , 2 , 0 , 0,	1944000000U),
PLLCPU(20 , 3 , 0 , 0,	2016000000U),
PLLCPU(28 , 2 , 0 , 0,	2088000000U),
PLLCPU(21 , 3 , 0 , 0,	2112000000U),
PLLCPU(29 , 2 , 0 , 0,	2160000000U),
PLLCPU(22 , 3 , 0 , 0,	2208000000U),
PLLCPU(30 , 2 , 0 , 0,	2232000000U),
PLLCPU(23 , 3 , 0 , 0,	2304000000U),
};
/*n, m, freq */
struct sunxi_clk_factor_freq factor_pllvideo_tbl[] = {
PLLVIDEO(4 , 0, 120000000U),
PLLVIDEO(10 , 1, 132000000U),
PLLVIDEO(5 , 0, 144000000U),
PLLVIDEO(24 , 3, 150000000U),
PLLVIDEO(18 , 2, 152000000U),
PLLVIDEO(12 , 1, 156000000U),
PLLVIDEO(19 , 2, 160000000U),
PLLVIDEO(26 , 3, 162000000U),
PLLVIDEO(6 , 0, 168000000U),
PLLVIDEO(28 , 3, 174000000U),
PLLVIDEO(21 , 2, 176000000U),
PLLVIDEO(14 , 1, 180000000U),
PLLVIDEO(60 , 7, 183000000U),
PLLVIDEO(22 , 2, 184000000U),
PLLVIDEO(30 , 3, 186000000U),
PLLVIDEO(62 , 7, 189000000U),
PLLVIDEO(31 , 3, 192000000U),
PLLVIDEO(64 , 7, 195000000U),
PLLVIDEO(32 , 3, 198000000U),
PLLVIDEO(24 , 2, 200000000U),
PLLVIDEO(66 , 7, 201000000U),
PLLVIDEO(16 , 1, 204000000U),
PLLVIDEO(68 , 7, 207000000U),
PLLVIDEO(25 , 2, 208000000U),
PLLVIDEO(34 , 3, 210000000U),
PLLVIDEO(70 , 7, 213000000U),
PLLVIDEO(35 , 3, 216000000U),
PLLVIDEO(72 , 7, 219000000U),
PLLVIDEO(36 , 3, 222000000U),
PLLVIDEO(27 , 2, 224000000U),
PLLVIDEO(74 , 7, 225000000U),
PLLVIDEO(18 , 1, 228000000U),
PLLVIDEO(76 , 7, 231000000U),
PLLVIDEO(28 , 2, 232000000U),
PLLVIDEO(38 , 3, 234000000U),
PLLVIDEO(78 , 7, 237000000U),
PLLVIDEO(9 , 0, 240000000U),
PLLVIDEO(80 , 7, 243000000U),
PLLVIDEO(40 , 3, 246000000U),
PLLVIDEO(30 , 2, 248000000U),
PLLVIDEO(82 , 7, 249000000U),
PLLVIDEO(20 , 1, 252000000U),
PLLVIDEO(84 , 7, 255000000U),
PLLVIDEO(31 , 2, 256000000U),
PLLVIDEO(42 , 3, 258000000U),
PLLVIDEO(86 , 7, 261000000U),
PLLVIDEO(10 , 0, 264000000U),
PLLVIDEO(88 , 7, 267000000U),
PLLVIDEO(44 , 3, 270000000U),
PLLVIDEO(33 , 2, 272000000U),
PLLVIDEO(90 , 7, 273000000U),
PLLVIDEO(22 , 1, 276000000U),
PLLVIDEO(92 , 7, 279000000U),
PLLVIDEO(34 , 2, 280000000U),
PLLVIDEO(46 , 3, 282000000U),
PLLVIDEO(94 , 7, 285000000U),
PLLVIDEO(11 , 0, 288000000U),
PLLVIDEO(96 , 7, 291000000U),
PLLVIDEO(48 , 3, 294000000U),
PLLVIDEO(36 , 2, 296000000U),
PLLVIDEO(98 , 7, 297000000U),
PLLVIDEO(24 , 1, 300000000U),
PLLVIDEO(100 , 7, 303000000U),
PLLVIDEO(37 , 2, 304000000U),
PLLVIDEO(50 , 3, 306000000U),
PLLVIDEO(102 , 7, 309000000U),
PLLVIDEO(12 , 0, 312000000U),
PLLVIDEO(104 , 7, 315000000U),
PLLVIDEO(52 , 3, 318000000U),
PLLVIDEO(39 , 2, 320000000U),
PLLVIDEO(106 , 7, 321000000U),
PLLVIDEO(26 , 1, 324000000U),
PLLVIDEO(108 , 7, 327000000U),
PLLVIDEO(40 , 2, 328000000U),
PLLVIDEO(54 , 3 , 330000000U),
PLLVIDEO(110 , 7, 333000000U),
PLLVIDEO(13 , 0, 336000000U),
PLLVIDEO(112 , 7, 339000000U),
PLLVIDEO(56 , 3, 342000000U),
PLLVIDEO(114 , 7, 345000000U),
PLLVIDEO(28 , 1, 348000000U),
PLLVIDEO(116 , 7, 351000000U),
PLLVIDEO(58 , 3, 354000000U),
PLLVIDEO(118  , 7, 357000000U),
PLLVIDEO(14 , 0, 360000000U),
PLLVIDEO(120 , 7, 363000000U),
PLLVIDEO(60 , 3, 366000000U),
PLLVIDEO(122 , 7, 369000000U),
PLLVIDEO(30 , 1, 372000000U),
PLLVIDEO(124 , 7, 375000000U),
PLLVIDEO(62 , 3, 378000000U),
PLLVIDEO(126 , 7, 381000000U),
PLLVIDEO(15 , 0, 384000000U),
PLLVIDEO(64 , 3, 390000000U),
PLLVIDEO(32 , 1, 396000000U),
PLLVIDEO(66 , 3, 402000000U),
PLLVIDEO(16 , 0, 408000000U),
PLLVIDEO(68 , 3, 414000000U),
PLLVIDEO(34 , 1, 420000000U),
PLLVIDEO(70 , 3, 426000000U),
PLLVIDEO(17 , 0, 432000000U),
PLLVIDEO(72 , 3, 438000000U),
PLLVIDEO(36 , 1, 444000000U),
PLLVIDEO(74 , 3, 450000000U),
PLLVIDEO(18 , 0, 456000000U),
PLLVIDEO(76 , 3, 462000000U),
PLLVIDEO(38 , 1, 468000000U),
PLLVIDEO(78 , 3, 474000000U),
PLLVIDEO(19 , 0, 480000000U),
PLLVIDEO(80 , 3, 486000000U),
PLLVIDEO(40 , 1, 492000000U),
PLLVIDEO(82 , 3, 498000000U),
PLLVIDEO(20 , 0, 504000000U),
PLLVIDEO(84 , 3, 510000000U),
PLLVIDEO(85 , 3, 516000000U),
PLLVIDEO(86 , 3, 522000000U),
PLLVIDEO(21 , 0, 528000000U),
PLLVIDEO(88 , 3, 534000000U),
PLLVIDEO(89 , 3, 540000000U),
PLLVIDEO(90 , 3, 546000000U),
PLLVIDEO(22 , 0, 552000000U),
PLLVIDEO(92 , 3, 558000000U),
PLLVIDEO(93 , 3, 564000000U),
PLLVIDEO(94 , 3, 570000000U),
PLLVIDEO(23 , 0, 576000000U),
PLLVIDEO(96 , 3, 582000000U),
PLLVIDEO(97 , 3, 588000000U),
PLLVIDEO(98 , 3, 594000000U),
PLLVIDEO(24 , 0, 600000000U),
PLLVIDEO(100 , 3, 606000000U),
PLLVIDEO(101 , 3, 612000000U),
PLLVIDEO(102 , 3, 618000000U),
PLLVIDEO(25 , 0, 624000000U),
PLLVIDEO(104 , 3, 630000000U),
PLLVIDEO(105 , 3, 636000000U),
PLLVIDEO(106 , 3, 642000000U),
PLLVIDEO(26 , 0, 648000000U),
PLLVIDEO(108 , 3, 654000000U),
PLLVIDEO(109 , 3, 660000000U),
PLLVIDEO(110 , 3, 666000000U),
PLLVIDEO(27 , 0, 672000000U),
PLLVIDEO(112 , 3, 678000000U),
PLLVIDEO(113 , 3, 684000000U),
PLLVIDEO(114 , 3, 690000000U),
PLLVIDEO(28 , 0, 696000000U),
PLLVIDEO(116 , 3, 702000000U),
PLLVIDEO(117 , 3, 708000000U),
PLLVIDEO(118 , 3, 714000000U),
PLLVIDEO(29 , 0, 720000000U),
PLLVIDEO(120 , 3, 726000000U),
PLLVIDEO(121 , 3, 732000000U),
PLLVIDEO(122 , 3, 738000000U),
PLLVIDEO(30 , 0, 744000000U),
PLLVIDEO(124 , 3, 750000000U),
PLLVIDEO(125 , 3, 756000000U),
PLLVIDEO(126  , 3, 762000000U),
PLLVIDEO(31 , 0, 768000000U),
PLLVIDEO(32 , 0, 792000000U),
PLLVIDEO(33 , 0, 816000000U),
PLLVIDEO(34 , 0, 840000000U),
PLLVIDEO(35 , 0, 864000000U),
PLLVIDEO(36 , 0, 888000000U),
};
/*n,m,freq */
struct sunxi_clk_factor_freq factor_pllve_tbl[] = {
PLLVE(4, 0, 120000000U),
PLLVE(10, 1, 132000000U),
PLLVE(22, 3, 138000000U),
PLLVE(11, 1, 144000000U),
PLLVE(24, 3, 150000000U),
PLLVE(18, 2, 152000000U),
PLLVE(12, 1, 156000000U),
PLLVE(19, 2, 160000000U),
PLLVE(26, 3, 162000000U),
PLLVE(13, 1, 168000000U),
PLLVE(56, 7, 171000000U),
PLLVE(57, 7, 174000000U),
PLLVE(21, 2, 176000000U),
PLLVE(58, 7, 177000000U),
PLLVE(14, 1, 180000000U),
PLLVE(60, 7, 183000000U),
PLLVE(22, 2, 184000000U),
PLLVE(30, 3, 186000000U),
PLLVE(62, 7, 189000000U),
PLLVE(15, 1, 192000000U),
PLLVE(64, 7, 195000000U),
PLLVE(32, 3, 198000000U),
PLLVE(24, 2, 200000000U),
PLLVE(66, 7, 201000000U),
PLLVE(16, 1, 204000000U),
PLLVE(68, 7, 207000000U),
PLLVE(25, 2, 208000000U),
PLLVE(34, 3, 210000000U),
PLLVE(70, 7, 213000000U),
PLLVE(17, 1, 216000000U),
PLLVE(72, 7, 219000000U),
PLLVE(36, 3, 222000000U),
PLLVE(27, 2, 224000000U),
PLLVE(74, 7, 225000000U),
PLLVE(37, 3, 228000000U),
PLLVE(76, 7, 231000000U),
PLLVE(28, 2, 232000000U),
PLLVE(38, 3, 234000000U),
PLLVE(78, 7, 237000000U),
PLLVE(39, 3, 240000000U),
PLLVE(80, 7, 243000000U),
PLLVE(81, 7, 246000000U),
PLLVE(30, 2, 248000000U),
PLLVE(82, 7, 249000000U),
PLLVE(20, 1, 252000000U),
PLLVE(84, 7, 255000000U),
PLLVE(31, 2, 256000000U),
PLLVE(85, 7, 258000000U),
PLLVE(86, 7, 261000000U),
PLLVE(43, 3, 264000000U),
PLLVE(88, 7, 267000000U),
PLLVE(44, 3, 270000000U),
PLLVE(33, 2, 272000000U),
PLLVE(90, 7, 273000000U),
PLLVE(45, 3, 276000000U),
PLLVE(92, 7, 279000000U),
PLLVE(34, 2, 280000000U),
PLLVE(46, 3, 282000000U),
PLLVE(94, 7, 285000000U),
PLLVE(95, 7, 288000000U),
PLLVE(96, 7, 291000000U),
PLLVE(97, 7, 294000000U),
PLLVE(36, 2, 296000000U),
PLLVE(98, 7, 297000000U),
PLLVE(99, 7, 300000000U),
PLLVE(100, 7, 303000000U),
PLLVE(37, 2, 304000000U),
PLLVE(50, 3, 306000000U),
PLLVE(102, 7, 309000000U),
PLLVE(25, 1, 312000000U),
PLLVE(104, 7, 315000000U),
PLLVE(52, 3, 318000000U),
PLLVE(39, 2, 320000000U),
PLLVE(106, 7, 321000000U),
PLLVE(26, 1, 324000000U),
PLLVE(108, 7, 327000000U),
PLLVE(40, 2, 328000000U),
PLLVE(54, 3, 330000000U),
PLLVE(110, 7, 333000000U),
PLLVE(55, 3, 336000000U),
PLLVE(112, 7, 339000000U),
PLLVE(56, 3, 342000000U),
PLLVE(114, 7, 345000000U),
PLLVE(57, 3, 348000000U),
PLLVE(116, 7, 351000000U),
PLLVE(58, 3, 354000000U),
PLLVE(118, 7, 357000000U),
PLLVE(59, 3, 360000000U),
PLLVE(120, 7, 363000000U),
PLLVE(121, 7, 366000000U),
PLLVE(122, 7, 369000000U),
PLLVE(61, 3, 372000000U),
PLLVE(124, 7, 375000000U),
PLLVE(62, 3, 378000000U),
PLLVE(126, 7, 381000000U),
PLLVE(63, 3, 384000000U),
PLLVE(64, 3, 390000000U),
PLLVE(65, 3, 396000000U),
PLLVE(66, 3, 402000000U),
PLLVE(67, 3, 408000000U),
PLLVE(68, 3, 414000000U),
PLLVE(69, 3, 420000000U),
PLLVE(70, 3, 426000000U),
PLLVE(71, 3, 432000000U),
PLLVE(72, 3, 438000000U),
PLLVE(73, 3, 444000000U),
PLLVE(74, 3, 450000000U),
PLLVE(75, 3, 456000000U),
PLLVE(76, 3, 462000000U),
PLLVE(77, 3, 468000000U),
PLLVE(78, 3, 474000000U),
PLLVE(79, 3, 480000000U),
PLLVE(80, 3, 486000000U),
PLLVE(81, 3, 492000000U),
PLLVE(82, 3, 498000000U),
PLLVE(83, 3, 504000000U),
PLLVE(84, 3, 510000000U),
PLLVE(85, 3, 516000000U),
PLLVE(86, 3, 522000000U),
PLLVE(87, 3, 528000000U),
PLLVE(88, 3, 534000000U),
PLLVE(89, 3, 540000000U),
PLLVE(90, 3, 546000000U),
PLLVE(91, 3, 552000000U),
PLLVE(92, 3, 558000000U),
PLLVE(93, 3, 564000000U),
PLLVE(94, 3, 570000000U),
PLLVE(95, 3, 576000000U),
PLLVE(96, 3, 582000000U),
PLLVE(97, 3, 588000000U),
PLLVE(98, 3, 594000000U),
PLLVE(99, 3, 600000000U),
PLLVE(100, 3, 606000000U),
PLLVE(101, 3, 612000000U),
PLLVE(102, 3, 618000000U),
PLLVE(103, 3, 624000000U),
PLLVE(104, 3, 630000000U),
PLLVE(105, 3, 636000000U),
PLLVE(106, 3, 642000000U),
PLLVE(107, 3, 648000000U),
PLLVE(108, 3, 654000000U),
PLLVE(109, 3, 660000000U),
PLLVE(110, 3, 666000000U),
PLLVE(111, 3, 672000000U),
PLLVE(112, 3, 678000000U),
PLLVE(113, 3, 684000000U),
PLLVE(114, 3, 690000000U),
PLLVE(115, 3, 696000000U),
PLLVE(116, 3, 702000000U),
PLLVE(117, 3, 708000000U),
PLLVE(118, 3, 714000000U),
PLLVE(119, 3, 720000000U),
PLLVE(120, 3, 726000000U),
PLLVE(121, 3, 732000000U),
PLLVE(122, 3, 738000000U),
PLLVE(123, 3, 744000000U),
PLLVE(124, 3, 750000000U),
PLLVE(125, 3, 756000000U),
PLLVE(126, 3, 762000000U),
PLLVE(127, 3, 768000000U),
PLLVE(32, 0, 792000000U),
PLLVE(33, 0 , 816000000U),
PLLVE(34, 0, 840000000U),
PLLVE(35, 0, 864000000U),
PLLVE(36, 0, 888000000U),
};
/* n,k,m,freq */
struct sunxi_clk_factor_freq factor_pllddr0_tbl[] = {
PLLDDR0(7	, 0 ,	3 ,	48000000U),
PLLDDR0(8	, 0 ,	3 ,	54000000U),
PLLDDR0(6	, 0 ,	2 ,	56000000U),
PLLDDR0(9	, 0 ,	3 ,	60000000U),
PLLDDR0(7	, 0 ,	2 ,	64000000U),
PLLDDR0(10	, 0 ,	3 ,	66000000U),
PLLDDR0(11	, 0 ,	3 ,	72000000U),
PLLDDR0(12	, 0 ,	3 ,	78000000U),
PLLDDR0(9	, 0 ,	2 ,	80000000U),
PLLDDR0(13	, 0 ,	3 ,	84000000U),
PLLDDR0(10	, 0 ,	2 ,	88000000U),
PLLDDR0(14	, 0 ,	3 ,	90000000U),
PLLDDR0(15	, 0 ,	3 ,	96000000U),
PLLDDR0(16	, 0 ,	3 ,	102000000U),
PLLDDR0(12	, 0 ,	2 ,	104000000U),
PLLDDR0(17	, 0 ,	3 ,	108000000U),
PLLDDR0(6	, 1 ,	2 ,	112000000U),
PLLDDR0(18	, 0 ,	3 ,	114000000U),
PLLDDR0(4	, 3 ,	3 ,	120000000U),
PLLDDR0(6	, 2 ,	3 ,	126000000U),
PLLDDR0(15	, 0 ,	2 ,	128000000U),
PLLDDR0(21	, 0 ,	3 ,	132000000U),
PLLDDR0(16	, 0 ,	2 ,	136000000U),
PLLDDR0(22	, 0 ,	3 ,	138000000U),
PLLDDR0(5	, 3 ,	3 ,	144000000U),
PLLDDR0(24	, 0 ,	3 ,	150000000U),
PLLDDR0(18	, 0 ,	2 ,	152000000U),
PLLDDR0(25	, 0 ,	3 ,	156000000U),
PLLDDR0(19	, 0 ,	2 ,	160000000U),
PLLDDR0(26	, 0 ,	3 ,	162000000U),
PLLDDR0(27	, 0 ,	3 ,	168000000U),
PLLDDR0(28	, 0 ,	3 ,	174000000U),
PLLDDR0(10	, 1 ,	2 ,	176000000U),
PLLDDR0(9	, 2 ,	3 ,	180000000U),
PLLDDR0(22	, 0 ,	2 ,	184000000U),
PLLDDR0(30	, 0 ,	3 ,	186000000U),
PLLDDR0(7	, 3 ,	3 ,	192000000U),
PLLDDR0(10	, 2 ,	3 ,	198000000U),
PLLDDR0(24	, 0  ,	2 ,	200000000U),
PLLDDR0(16	, 1 ,	3 ,	204000000U),
PLLDDR0(12	, 1 ,	2 ,	208000000U),
PLLDDR0(11	, 2 ,	3 ,	216000000U),
PLLDDR0(13	, 1 ,	2 ,	224000000U),
PLLDDR0(18	, 1 ,	3 ,	228000000U),
PLLDDR0(28	, 0 ,	2 ,	232000000U),
PLLDDR0(12	, 2 ,	3 ,	234000000U),
PLLDDR0(19	, 1 ,	3 ,	240000000U),
PLLDDR0(30	, 0 ,	2 ,	248000000U),
PLLDDR0(20	, 1 ,	3,	252000000U),
PLLDDR0(15	, 1 ,	2,	256000000U),
PLLDDR0(21	, 1 ,	3,	264000000U),
PLLDDR0(14	, 2 ,	3,	270000000U),
PLLDDR0(16	, 1 ,	2,	272000000U),
PLLDDR0(22	, 1 ,	3,	276000000U),
PLLDDR0(23	, 1 ,	3,	288000000U),
PLLDDR0(24	, 1 ,	3,	300000000U),
PLLDDR0(18	, 1 ,	2,	304000000U),
PLLDDR0(16	, 2 ,	3,	306000000U),
PLLDDR0(25	, 1 ,	3,	312000000U),
PLLDDR0(19	, 1 ,	2,	320000000U),
PLLDDR0(26	, 1 ,	3,	324000000U),
PLLDDR0(27	, 1 ,	3,	336000000U),
PLLDDR0(18	, 2 ,	3,	342000000U),
PLLDDR0(28	, 1 ,	3,	348000000U),
PLLDDR0(21	, 1 ,	2,	352000000U),
PLLDDR0(29	, 1 ,	3,	360000000U),
PLLDDR0(22	, 1 ,	2,	368000000U),
PLLDDR0(30	, 1 ,	3,	372000000U),
PLLDDR0(20	, 2 ,	3,	378000000U),
PLLDDR0(15	, 2,	2,	384000000U),
PLLDDR0(21	, 2,	3,	396000000U),
PLLDDR0(24	, 1 ,	2,	400000000U),
PLLDDR0(16	, 3 ,	3,	408000000U),
PLLDDR0(22	,  2,	3,	414000000U),
PLLDDR0(25	, 1 ,	2,	416000000U),
PLLDDR0(26	, 1 ,	2,	432000000U),
PLLDDR0(27	, 1 ,	2,	448000000U),
PLLDDR0(24	, 2 ,	3,	450000000U),
PLLDDR0(18	, 2 ,	2,	456000000U),
PLLDDR0(28	, 1 ,	2,	464000000U),
PLLDDR0(25	, 2 ,	3,	468000000U),
PLLDDR0(19	, 2 ,	2,	480000000U),
PLLDDR0(26	, 2 ,	3,	486000000U),
PLLDDR0(30	, 1 ,	2 ,	496000000U),
PLLDDR0(20	, 2 ,	2 ,	504000000U),
PLLDDR0(15	, 3 ,	2 ,	512000000U),
PLLDDR0(21	, 2 ,	2 ,	528000000U),
PLLDDR0(14	, 2 ,	1 ,	540000000U),
PLLDDR0(16	, 3 ,	2 ,	544000000U),
PLLDDR0(22	, 2 ,	2 ,	552000000U),
PLLDDR0(23	, 0 ,	0 ,	576000000U),
PLLDDR0(24	, 2 ,	2 ,	600000000U),
PLLDDR0(18	, 3 ,	2 ,	608000000U),
PLLDDR0(16	, 2  ,	1 ,	612000000U),
PLLDDR0(25	, 2 ,	2 ,	624000000U),
PLLDDR0(19	, 3 ,	2 ,	640000000U),
PLLDDR0(26	, 2 ,	2 ,	648000000U),
PLLDDR0(27	, 2 ,	2 ,	672000000U),
PLLDDR0(18	, 2 ,	1 ,	684000000U),
PLLDDR0(28	, 1 ,	1 ,	696000000U),
PLLDDR0(19	, 2 ,	1 ,	720000000U),
PLLDDR0(30	, 1 ,	1 ,	744000000U),
PLLDDR0(20	, 2 ,	1 ,	756000000U),
PLLDDR0(15	, 3 ,	1 ,	768000000U),
PLLDDR0(21	, 2 ,	1 ,	792000000U),
PLLDDR0(16	, 3 ,	1 ,	816000000U),
PLLDDR0(22	, 2 ,	1 ,	828000000U),
PLLDDR0(23	, 2 ,	1 ,	864000000U),
PLLDDR0(24	, 2 ,	1 ,	900000000U),
PLLDDR0(18	, 3 ,	1 ,	912000000U),
PLLDDR0(25	, 2 ,	1 ,	936000000U),
PLLDDR0(19	, 3 ,	1 ,	960000000U),
PLLDDR0(26	, 2 ,	1 ,	972000000U),
PLLDDR0(27	, 2 ,	1 ,	1008000000U),
PLLDDR0(10	, 3 ,	0 ,	1056000000U),
PLLDDR0(14	, 2 ,	0 ,	1080000000U),
PLLDDR0(22	, 1 ,	0 ,	1104000000U),
PLLDDR0(11	, 3 ,	0 ,	1152000000U),
PLLDDR0(24	, 1  ,	0 ,	1200000000U),
PLLDDR0(16	, 2 ,	0 ,	1224000000U),
PLLDDR0(12	, 3 ,	0 ,	1248000000U),
PLLDDR0(17	, 2 ,	0 ,	1296000000U),
PLLDDR0(13	, 3 ,	0 ,	1344000000U),
PLLDDR0(18	, 2 ,	0 ,	1368000000U),
PLLDDR0(28	, 1 ,	0 ,	1392000000U),
PLLDDR0(14	, 3 ,	0 ,	1440000000U),
PLLDDR0(30	, 1 ,	0 ,	1488000000U),
PLLDDR0(20	, 2 ,	0 ,	1512000000U),
PLLDDR0(15	, 3 ,	0 ,	1536000000U),
PLLDDR0(21	, 2 ,	0 ,	1584000000U),
PLLDDR0(16	, 3 ,	0 ,	1632000000U),
PLLDDR0(22	, 2 ,	0 ,	1656000000U),
PLLDDR0(17	, 3 ,	0 ,	1728000000U),
PLLDDR0(24	, 2 ,	0 ,	1800000000U),
PLLDDR0(18	, 3 ,	0 ,	1824000000U),
PLLDDR0(25	, 2 ,	0 ,	1872000000U),
PLLDDR0(19	, 3 ,	0 ,	1920000000U),
PLLDDR0(26	, 2 ,	0 ,	1944000000U),
PLLDDR0(20	, 3 ,	0 ,	2016000000U),
};
/* n,k,freq */
struct sunxi_clk_factor_freq factor_pllperiph_tbl[] = {
PLLPERIPH(7,  0 ,	96000000U),
PLLPERIPH(9,  0 ,	120000000U),
PLLPERIPH(10, 0 ,	132000000U),
PLLPERIPH(11, 0 ,	144000000U),
PLLPERIPH(12, 0 ,	156000000U),
PLLPERIPH(13, 0 ,	168000000U),
PLLPERIPH(14, 0 ,	180000000U),
PLLPERIPH(15, 0 ,	192000000U),
PLLPERIPH(16, 0 ,	204000000U),
PLLPERIPH(17, 0 ,	216000000U),
PLLPERIPH(18, 0 ,	228000000U),
PLLPERIPH(9, 1 ,	240000000U),
PLLPERIPH(20, 0 ,	252000000U),
PLLPERIPH(21, 0 ,	264000000U),
PLLPERIPH(22, 0 ,	276000000U),
PLLPERIPH(23, 0 ,	288000000U),
PLLPERIPH(24, 0 ,	300000000U),
PLLPERIPH(25, 0 ,	312000000U),
PLLPERIPH(26, 0 ,	324000000U),
PLLPERIPH(27, 0 ,	336000000U),
PLLPERIPH(28, 0 ,	348000000U),
PLLPERIPH(14, 1 ,	360000000U),
PLLPERIPH(30, 0 ,	372000000U),
PLLPERIPH(15, 1 ,	384000000U),
PLLPERIPH(10, 2 ,	396000000U),
PLLPERIPH(16, 1 ,	408000000U),
PLLPERIPH(17, 1 ,	432000000U),
PLLPERIPH(18, 1 ,	456000000U),
PLLPERIPH(12, 2 ,	468000000U),
PLLPERIPH(19,  1 ,	480000000U),
PLLPERIPH(20, 1 ,	504000000U),
PLLPERIPH(21, 1 ,	528000000U),
PLLPERIPH(14, 2 ,	540000000U),
PLLPERIPH(22, 1 ,	552000000U),
PLLPERIPH(23, 1 ,	576000000U),
PLLPERIPH(24,  1 ,	600000000U),
PLLPERIPH(16, 2 ,	612000000U),
PLLPERIPH(25, 1 ,	624000000U),
PLLPERIPH(26, 1 ,	648000000U),
PLLPERIPH(27, 1  ,	672000000U),
PLLPERIPH(18, 2 ,	684000000U),
PLLPERIPH(28, 1 ,	696000000U),
PLLPERIPH(29, 1 ,	720000000U),
PLLPERIPH(30, 1 ,	744000000U),
};
/* n,m,freq */
struct sunxi_clk_factor_freq factor_pllgpu_tbl[] = {
PLLGPU(4  , 0 ,	120000000U),
PLLGPU(15 , 2 ,	128000000U),
PLLGPU(10 , 1 ,	132000000U),
PLLGPU(16 , 2 ,	136000000U),
PLLGPU(11 , 1 ,	144000000U),
PLLGPU(18 , 2 ,	152000000U),
PLLGPU(12 , 1 ,	156000000U),
PLLGPU(19 , 2 ,	160000000U),
PLLGPU(26 , 3 ,	162000000U),
PLLGPU(54 , 7 ,	165000000U),
PLLGPU(6 , 0 ,	168000000U),
PLLGPU(56 , 7 ,	171000000U),
PLLGPU(28 , 3 ,	174000000U),
PLLGPU(21 , 2 ,	176000000U),
PLLGPU(58 , 7 ,	177000000U),
PLLGPU(29 , 3 ,	180000000U),
PLLGPU(60 , 7 ,	183000000U),
PLLGPU(22 , 2 ,	184000000U),
PLLGPU(30 , 3 ,	186000000U),
PLLGPU(62 , 7 ,	189000000U),
PLLGPU(31 , 3 ,	192000000U),
PLLGPU(64 , 7 ,	195000000U),
PLLGPU(32 , 3 ,	198000000U),
PLLGPU(24 , 2 ,	200000000U),
PLLGPU(66 , 7 ,	201000000U),
PLLGPU(33 , 3 ,	204000000U),
PLLGPU(68 , 7 ,	207000000U),
PLLGPU(25 , 2 ,	208000000U),
PLLGPU(34 , 3 ,	210000000U),
PLLGPU(70 , 7 ,	213000000U),
PLLGPU(35 , 3 ,	216000000U),
PLLGPU(72 , 7 ,	219000000U),
PLLGPU(36 , 3 ,	222000000U),
PLLGPU(27 , 2 ,	224000000U),
PLLGPU(74 , 7,	225000000U),
PLLGPU(37 , 3 ,	228000000U),
PLLGPU(76 , 7 ,	231000000U),
PLLGPU(28 , 2 ,	232000000U),
PLLGPU(38 , 3 ,	234000000U),
PLLGPU(78 , 7 ,	237000000U),
PLLGPU(39 , 3 ,	240000000U),
PLLGPU(80 , 7 ,	243000000U),
PLLGPU(40 , 3 ,	246000000U),
PLLGPU(30 , 2 ,	248000000U),
PLLGPU(82 , 7 ,	249000000U),
PLLGPU(20 , 1 ,	252000000U),
PLLGPU(84 , 7 ,	255000000U),
PLLGPU(31 , 2 ,	256000000U),
PLLGPU(42 , 3 ,	258000000U),
PLLGPU(86 , 7 ,	261000000U),
PLLGPU(43 , 3 ,	264000000U),
PLLGPU(88 , 7 ,	267000000U),
PLLGPU(44 , 3 ,	270000000U),
PLLGPU(33 , 2 ,	272000000U),
PLLGPU(90 , 7 ,	273000000U),
PLLGPU(45 , 3 ,	276000000U),
PLLGPU(92 , 7 ,	279000000U),
PLLGPU(34 , 2 ,	280000000U),
PLLGPU(46 , 3 ,	282000000U),
PLLGPU(94 , 7 ,	285000000U),
PLLGPU(47 , 3 ,	288000000U),
PLLGPU(96 , 7 ,	291000000U),
PLLGPU(48 , 3 ,	294000000U),
PLLGPU(36 , 2 ,	296000000U),
PLLGPU(98 , 7 ,	297000000U),
PLLGPU(49 , 3 ,	300000000U),
PLLGPU(100 , 7 ,	303000000U),
PLLGPU(37 , 2 ,		304000000U),
PLLGPU(50 , 3 ,		306000000U),
PLLGPU(102 , 7 ,	309000000U),
PLLGPU(51 , 3 ,		312000000U),
PLLGPU(104 , 7 ,	315000000U),
PLLGPU(52 , 3 ,		318000000U),
PLLGPU(39 , 2 ,		320000000U),
PLLGPU(106 , 7 ,	321000000U),
PLLGPU(53 , 3 ,		324000000U),
PLLGPU(108 , 7 ,	327000000U),
PLLGPU(40 , 2 ,		328000000U),
PLLGPU(54 , 3 ,		330000000U),
PLLGPU(110 , 7 ,	333000000U),
PLLGPU(55 , 3 ,		336000000U),
PLLGPU(112   , 7 ,	339000000U),
PLLGPU(56 , 3 ,		342000000U),
PLLGPU(114 , 7 ,	345000000U),
PLLGPU(57 , 3 ,		348000000U),
PLLGPU(116 , 7 ,	351000000U),
PLLGPU(58 , 3 ,		354000000U),
PLLGPU(118 , 7 ,	357000000U),
PLLGPU(59 , 3  ,	360000000U),
PLLGPU(120 , 7 ,	363000000U),
PLLGPU(60 , 3  ,	366000000U),
PLLGPU(122 , 7 ,	369000000U),
PLLGPU(61 , 3 ,	372000000U),
PLLGPU(124, 7 ,	375000000U),
PLLGPU(62 , 3,	378000000U),
PLLGPU(126, 7,	381000000U),
PLLGPU(63 , 3 ,	384000000U),
PLLGPU(64 , 3 ,	390000000U),
PLLGPU(65 , 3 ,	396000000U),
PLLGPU(66 , 3 ,	402000000U),
PLLGPU(33 , 1 ,	408000000U),
PLLGPU(68 , 3 , 414000000U),
PLLGPU(69 , 3 ,	420000000U),
PLLGPU(70 , 3 ,	426000000U),
PLLGPU(71 , 3 ,	432000000U),
PLLGPU(72 , 3 ,	438000000U),
PLLGPU(73 , 3 ,	444000000U),
PLLGPU(74 , 3 ,	450000000U),
PLLGPU(75 , 3 ,	456000000U),
PLLGPU(76 , 3 ,	462000000U),
PLLGPU(77 , 3 ,	468000000U),
PLLGPU(78 , 3 ,	474000000U),
PLLGPU(79 , 3 ,	480000000U),
PLLGPU(80 , 3 ,	486000000U),
PLLGPU(81 , 3 ,	492000000U),
PLLGPU(82 , 3 ,	498000000U),
PLLGPU(83 , 3 ,	504000000U),
PLLGPU(84 , 3 ,	510000000U),
PLLGPU(85 , 3 ,	516000000U),
PLLGPU(86 , 3 ,	522000000U),
PLLGPU(87 , 3 ,	528000000U),
PLLGPU(88 , 3 ,	534000000U),
PLLGPU(89 , 3 ,	540000000U),
PLLGPU(90 , 3 ,	546000000U),
PLLGPU(91 , 3 ,	552000000U),
PLLGPU(92 , 3 ,	558000000U),
PLLGPU(93 , 3 ,	564000000U),
PLLGPU(94 , 3 ,	570000000U),
PLLGPU(95 , 3 ,	576000000U),
PLLGPU(96 , 3 ,	582000000U),
PLLGPU(97 , 3 ,	588000000U),
PLLGPU(98 , 3 , 594000000U),
PLLGPU(99 , 3 , 600000000U),
PLLGPU(100 , 3 , 606000000U),
PLLGPU(101 , 3 , 612000000U),
PLLGPU(102 , 3 ,	618000000U),
PLLGPU(103 , 3 ,	624000000U),
PLLGPU(104 , 3 ,	630000000U),
PLLGPU(105 , 3 ,	636000000U),
PLLGPU(106 , 3 ,	642000000U),
PLLGPU(107 , 3 ,	648000000U),
PLLGPU(108 , 3 ,	654000000U),
PLLGPU(109 , 3 ,	660000000U),
PLLGPU(110 , 3 ,	666000000U),
PLLGPU(111 , 3 ,	672000000U),
PLLGPU(112 , 3 ,	678000000U),
PLLGPU(113 , 3 ,	684000000U),
PLLGPU(114 , 3 ,	690000000U),
PLLGPU(115 , 3 ,	696000000U),
PLLGPU(116 , 3 ,	702000000U),
PLLGPU(117 , 3 ,	708000000U),
PLLGPU(118 , 3 ,	714000000U),
PLLGPU(119 , 3 ,	720000000U),
PLLGPU(120 , 3 ,	726000000U),
PLLGPU(121 , 3 ,	732000000U),
PLLGPU(122 , 3 ,	738000000U),
PLLGPU(123 , 3 ,	744000000U),
PLLGPU(124 , 3 ,	750000000U),
PLLGPU(125 , 3 ,	756000000U),
PLLGPU(126 , 3 ,	 762000000U),
PLLGPU(127 , 3 ,	768000000U),
PLLGPU(32 , 0 ,		792000000U),
PLLGPU(33 , 0 ,		816000000U),
PLLGPU(34 , 0 ,		840000000U),
PLLGPU(35 , 0 ,		864000000U),
PLLGPU(36 , 0 ,		888000000U),
};
/* n,m,freq */
struct sunxi_clk_factor_freq factor_pllhsic_tbl[] = {
PLLHSIC(19	, 3 ,	120000000U),
PLLHSIC(20	, 3 ,	126000000U),
PLLHSIC(15	, 2 ,	128000000U),
PLLHSIC(10	, 1 ,	132000000U),
PLLHSIC(16	, 2 ,	136000000U),
PLLHSIC(22	, 3 ,	138000000U),
PLLHSIC(11	, 1 ,	144000000U),
PLLHSIC(24	, 3 ,	150000000U),
PLLHSIC(18	, 2 ,	152000000U),
PLLHSIC(12	, 1 ,	156000000U),
PLLHSIC(52	, 7 ,	159000000U),
PLLHSIC(19	, 2 ,	160000000U),
PLLHSIC(26	, 3 ,	162000000U),
PLLHSIC(54	, 7 ,	165000000U),
PLLHSIC(13	, 1 ,	168000000U),
PLLHSIC(56	, 7 ,	171000000U),
PLLHSIC(28	, 3 ,	174000000U),
PLLHSIC(21	, 2 ,	176000000U),
PLLHSIC(58	, 7 ,	177000000U),
PLLHSIC(29	, 3 ,	180000000U),
PLLHSIC(60	, 7 ,	183000000U),
PLLHSIC(22	, 2 ,	184000000U),
PLLHSIC(30	, 3  ,	186000000U),
PLLHSIC(62	, 7 ,	189000000U),
PLLHSIC(31	, 3 ,	192000000U),
PLLHSIC(64	, 7 ,	195000000U),
PLLHSIC(32	, 3 ,	198000000U),
PLLHSIC(24	, 2 ,	200000000U),
PLLHSIC(66	, 7 ,	201000000U),
PLLHSIC(33	, 3 ,	204000000U),
PLLHSIC(68	, 7 ,	207000000U),
PLLHSIC(25	, 2 ,	208000000U),
PLLHSIC(34	, 3 ,	210000000U),
PLLHSIC(70	, 7 ,	213000000U),
PLLHSIC(35	, 3  ,	216000000U),
PLLHSIC(72	, 7 ,	219000000U),
PLLHSIC(36	,  3,	222000000U),
PLLHSIC(27	, 2 ,	224000000U),
PLLHSIC(74	, 7 ,	225000000U),
PLLHSIC(37	, 3 ,	228000000U),
PLLHSIC(76	, 7 ,	231000000U),
PLLHSIC(28	, 2 ,	232000000U),
PLLHSIC(38	, 3 ,	234000000U),
PLLHSIC(78	, 7 ,	237000000U),
PLLHSIC(39	, 3 ,	240000000U),
PLLHSIC(80	, 7 ,	243000000U),
PLLHSIC(40	, 3 ,	246000000U),
PLLHSIC(30	, 2 ,	248000000U),
PLLHSIC(82	, 7 ,	249000000U),
PLLHSIC(41	, 3 ,	252000000U),
PLLHSIC(84	, 7 ,	255000000U),
PLLHSIC(31	, 2 ,	256000000U),
PLLHSIC(42	, 3 ,	258000000U),
PLLHSIC(86	, 7 ,	261000000U),
PLLHSIC(43	,  3 ,	264000000U),
PLLHSIC(88	, 7 ,	267000000U),
PLLHSIC(44	, 3 ,	270000000U),
PLLHSIC(33	, 2 ,	272000000U),
PLLHSIC(90	, 7 ,	273000000U),
PLLHSIC(45	, 3 ,	276000000U),
PLLHSIC(92	, 7 ,	279000000U),
PLLHSIC(34	, 2 ,	280000000U),
PLLHSIC(46	, 3 ,	282000000U),
PLLHSIC(94	, 7 ,	285000000U),
PLLHSIC(47	, 3 ,	288000000U),
PLLHSIC(96	, 7 ,	291000000U),
PLLHSIC(48	, 3 ,	294000000U),
PLLHSIC(36	, 2 ,	296000000U),
PLLHSIC(98	, 7 ,	297000000U),
PLLHSIC(49	, 3 ,	300000000U),
PLLHSIC(100	, 7 ,	303000000U),
PLLHSIC(37	, 2 ,	304000000U),
PLLHSIC(50	, 3 ,	306000000U),
PLLHSIC(102	, 7 ,	309000000U),
PLLHSIC(51	, 3 ,	312000000U),
PLLHSIC(104	, 7 ,	315000000U),
PLLHSIC(52	, 3 ,	318000000U),
PLLHSIC(39	, 2,	320000000U),
PLLHSIC(106	, 7 ,	321000000U),
PLLHSIC(53	, 3 ,	324000000U),
PLLHSIC(108	, 7 ,	327000000U),
PLLHSIC(40	, 2 ,	328000000U),
PLLHSIC(54	, 3 ,	330000000U),
PLLHSIC(110	, 7 ,	333000000U),
PLLHSIC(55	, 3 ,	336000000U),
PLLHSIC(112	, 7 ,	339000000U),
PLLHSIC(56	, 3 ,	342000000U),
PLLHSIC(114	, 7 ,	345000000U),
PLLHSIC(57	, 3 ,	348000000U),
PLLHSIC(116	, 7 ,	351000000U),
PLLHSIC(58	, 3 ,	354000000U),
PLLHSIC(118	, 7 ,	357000000U),
PLLHSIC(59	, 3 ,	360000000U),
PLLHSIC(120	, 7 ,	363000000U),
PLLHSIC(60	, 3 ,	366000000U),
PLLHSIC(122	, 7 ,	369000000U),
PLLHSIC(61	, 3 ,	372000000U),
PLLHSIC(124	, 7 ,	375000000U),
PLLHSIC(62	, 3 ,	378000000U),
PLLHSIC(126	, 7 ,	381000000U),
PLLHSIC(63	, 3 ,	384000000U),
PLLHSIC(64	, 3 ,	390000000U),
PLLHSIC(65	, 3 ,	396000000U),
PLLHSIC(66	, 3 ,	402000000U),
PLLHSIC(67	, 3 ,	408000000U),
PLLHSIC(68	, 3 ,	414000000U),
PLLHSIC(69	, 3 ,	420000000U),
PLLHSIC(70	, 3 ,	426000000U),
PLLHSIC(71	, 3 ,	432000000U),
PLLHSIC(72	, 3 ,	438000000U),
PLLHSIC(73	, 3 ,	444000000U),
PLLHSIC(74	, 3 ,	450000000U),
PLLHSIC(75	, 3 ,	456000000U),
PLLHSIC(76	, 3 ,	462000000U),
PLLHSIC(77	, 3 ,	468000000U),
PLLHSIC(78	, 3 ,	474000000U),
PLLHSIC(79	, 3 ,	480000000U),
PLLHSIC(80	, 3 ,	486000000U),
PLLHSIC(81	, 3 ,	492000000U),
PLLHSIC(82	, 3 ,	498000000U),
PLLHSIC(83	, 3 ,	504000000U),
PLLHSIC(84	, 3 ,	510000000U),
PLLHSIC(85	, 3 ,	516000000U),
PLLHSIC(86	, 3 ,	522000000U),
PLLHSIC(87	, 3 ,	528000000U),
PLLHSIC(88	, 3 ,	534000000U),
PLLHSIC(89	, 3 ,	540000000U),
PLLHSIC(90	, 3 ,	546000000U),
PLLHSIC(91	, 3 ,	552000000U),
PLLHSIC(92	, 3 ,	558000000U),
PLLHSIC(93	, 3 ,	564000000U),
PLLHSIC(94	, 3 ,	570000000U),
PLLHSIC(95	, 3 ,	576000000U),
PLLHSIC(96	, 3 ,	582000000U),
PLLHSIC(97	, 3 ,	588000000U),
PLLHSIC(98	, 3 ,	594000000U),
PLLHSIC(99	, 3 ,	600000000U),
PLLHSIC(100	, 3 ,	606000000U),
PLLHSIC(101	, 3 ,	612000000U),
PLLHSIC(102	, 3 ,	618000000U),
PLLHSIC(103	, 3 ,	624000000U),
PLLHSIC(104	, 3 ,	630000000U),
PLLHSIC(105	, 3 ,	636000000U),
PLLHSIC(106	, 3 ,	642000000U),
PLLHSIC(107	, 3 ,	648000000U),
PLLHSIC(108	, 3 ,	654000000U),
PLLHSIC(109	, 3 ,	660000000U),
PLLHSIC(110	, 3 ,	666000000U),
PLLHSIC(111	, 3 ,	672000000U),
PLLHSIC(112	, 3 ,	678000000U),
PLLHSIC(113	, 3 ,	684000000U),
PLLHSIC(114	, 3 ,	690000000U),
PLLHSIC(115	, 3 ,	696000000U),
PLLHSIC(116	, 3,	702000000U),
PLLHSIC(117	, 3,	708000000U),
PLLHSIC(118	, 3,	714000000U),
PLLHSIC(119	, 3,	720000000U),
PLLHSIC(120	,  3,	726000000U),
PLLHSIC(121	, 3,	732000000U),
PLLHSIC(122	, 3,	738000000U),
PLLHSIC(123	, 3,	744000000U),
PLLHSIC(124	, 3,	750000000U),
PLLHSIC(125	, 3,	756000000U),
PLLHSIC(126	, 3,	762000000U),
PLLHSIC(127	, 3,	768000000U),
PLLHSIC(32	, 0,	792000000U),
PLLHSIC(33	, 0,	816000000U),
PLLHSIC(34	, 0,	840000000U),
PLLHSIC(35	, 0,	864000000U),
PLLHSIC(36	, 0 ,	888000000U),
};
/* n,m,freq */
struct sunxi_clk_factor_freq factor_pllde_tbl[] = {
PLLDE(4 , 0 , 120000000U),
PLLDE(15 , 2 , 128000000U),
PLLDE(10 , 1 , 132000000U),
PLLDE(16 , 2 , 136000000U),
PLLDE(11 , 1 , 144000000U),
PLLDE(24 ,  3 , 150000000U),
PLLDE(18 , 2 , 152000000U),
PLLDE(12 , 1 , 156000000U),
PLLDE(19 , 2 , 160000000U),
PLLDE(26 , 3 , 162000000U),
PLLDE(13 , 1 , 168000000U),
PLLDE(28 , 3 , 174000000U),
PLLDE(21 , 2 , 176000000U),
PLLDE(14 , 1 , 180000000U),
PLLDE(22 , 2 , 184000000U),
PLLDE(30 , 3 , 186000000U),
PLLDE(15 , 1 , 192000000U),
PLLDE(64 , 7 , 195000000U),
PLLDE(32 , 3 , 198000000U),
PLLDE(24 , 2 , 200000000U),
PLLDE(66 , 7 , 201000000U),
PLLDE(16 , 1 , 204000000U),
PLLDE(68 , 7 , 207000000U),
PLLDE(25 , 2 , 208000000U),
PLLDE(34 , 3 , 210000000U),
PLLDE(70 , 7 , 213000000U),
PLLDE(17 , 1 , 216000000U),
PLLDE(72 , 7 , 219000000U),
PLLDE(36 , 3 , 222000000U),
PLLDE(27 , 2 , 224000000U),
PLLDE(74 , 7 , 225000000U),
PLLDE(18 , 1 , 228000000U),
PLLDE(76 , 7 , 231000000U),
PLLDE(28 , 2 , 232000000U),
PLLDE(38 , 3 , 234000000U),
PLLDE(78 , 7 , 237000000U),
PLLDE(19 , 1 , 240000000U),
PLLDE(80 , 7 , 243000000U),
PLLDE(40 , 3 , 246000000U),
PLLDE(30 , 2 , 248000000U),
PLLDE(82 , 7 , 249000000U),
PLLDE(20 , 1 , 252000000U),
PLLDE(84 , 7 , 255000000U),
PLLDE(31 , 2 , 256000000U),
PLLDE(42 , 3 , 258000000U),
PLLDE(86 , 7 , 261000000U),
PLLDE(21 , 1 , 264000000U),
PLLDE(88 , 7 , 267000000U),
PLLDE(44 , 3 , 270000000U),
PLLDE(33 , 2 , 272000000U),
PLLDE(90 , 7 , 273000000U),
PLLDE(22 , 1 , 276000000U),
PLLDE(92 , 7 , 279000000U),
PLLDE(34 , 2 , 280000000U),
PLLDE(46 , 3 , 282000000U),
PLLDE(94 , 7 , 285000000U),
PLLDE(23 , 1 , 288000000U),
PLLDE(96 , 7 , 291000000U),
PLLDE(48 , 3 , 294000000U),
PLLDE(36 , 2 , 296000000U),
PLLDE(98 , 7 , 297000000U),
PLLDE(24 , 1 , 300000000U),
PLLDE(100 , 7 , 303000000U),
PLLDE(37 , 2 , 304000000U),
PLLDE(50 , 3 , 306000000U),
PLLDE(102 , 7 , 309000000U),
PLLDE(25 , 1 , 312000000U),
PLLDE(104 , 7 , 315000000U),
PLLDE(52 , 3 , 318000000U),
PLLDE(39 , 2 , 320000000U),
PLLDE(106 , 7 , 321000000U),
PLLDE(26 , 1 , 324000000U),
PLLDE(108 , 7 , 327000000U),
PLLDE(40 , 2 , 328000000U),
PLLDE(54 , 3 , 330000000U),
PLLDE(110 , 7 , 333000000U),
PLLDE(27 , 1 , 336000000U),
PLLDE(112 , 7 , 339000000U),
PLLDE(56 , 3 , 342000000U),
PLLDE(114 , 7 , 345000000U),
PLLDE(28 , 1 , 348000000U),
PLLDE(116 , 7 , 351000000U),
PLLDE(58 , 3 , 354000000U),
PLLDE(118 , 7 , 357000000U),
PLLDE(29 , 1 , 360000000U),
PLLDE(120 , 7 , 363000000U),
PLLDE(60 , 3 , 366000000U),
PLLDE(122 , 7 , 369000000U),
PLLDE(30 , 1 , 372000000U),
PLLDE(124 , 7 , 375000000U),
PLLDE(62 , 3 , 378000000U),
PLLDE(126 , 7 , 381000000U),
PLLDE(31 , 1 , 384000000U),
PLLDE(64 , 3 , 390000000U),
PLLDE(32 , 1 , 396000000U),
PLLDE(66 , 3 , 402000000U),
PLLDE(33 , 1 , 408000000U),
PLLDE(68 , 3 , 414000000U),
PLLDE(34 , 1 , 420000000U),
PLLDE(70 ,  3 , 426000000U),
PLLDE(35 , 1 , 432000000U),
PLLDE(72 , 3 , 438000000U),
PLLDE(36 , 1 , 444000000U),
PLLDE(74 , 3 , 450000000U),
PLLDE(37 , 1 , 456000000U),
PLLDE(76 , 3 , 462000000U),
PLLDE(77 , 3 , 468000000U),
PLLDE(78 , 3 , 474000000U),
PLLDE(39 , 1 , 480000000U),
PLLDE(80 , 3 , 486000000U),
PLLDE(40  , 1 , 492000000U),
PLLDE(82 , 3 , 498000000U),
PLLDE(41 , 1 , 504000000U),
PLLDE(84 , 3 , 510000000U),
PLLDE(85 , 3 , 516000000U),
PLLDE(86 , 3 , 522000000U),
PLLDE(87 , 3 , 528000000U),
PLLDE(88 , 3 , 534000000U),
PLLDE(89 , 3 , 540000000U),
PLLDE(90 , 3 , 546000000U),
PLLDE(91 , 3 , 552000000U),
PLLDE(92 , 3 , 558000000U),
PLLDE(93 , 3 , 564000000U),
PLLDE(94 , 3 , 570000000U),
PLLDE(23 , 0 , 576000000U),
PLLDE(96 , 3 , 582000000U),
PLLDE(97 , 3 , 588000000U),
PLLDE(98 , 3 , 594000000U),
PLLDE(24 , 0 , 600000000U),
PLLDE(100 , 3 , 606000000U),
PLLDE(101 , 3 , 612000000U),
PLLDE(102 , 3 , 618000000U),
PLLDE(25 , 0 , 624000000U),
PLLDE(104 , 3 , 630000000U),
PLLDE(105 , 3 , 636000000U),
PLLDE(106 , 3 , 642000000U),
PLLDE(26 , 0 , 648000000U),
PLLDE(108 , 3 , 654000000U),
PLLDE(109 , 3 , 660000000U),
PLLDE(110 , 3 , 666000000U),
PLLDE(27 , 0 , 672000000U),
PLLDE(112 , 3 , 678000000U),
PLLDE(113 , 3 , 684000000U),
PLLDE(114 , 3 , 690000000U),
PLLDE(28 , 0 , 696000000U),
PLLDE(116 , 3 , 702000000U),
PLLDE(117 , 3 , 708000000U),
PLLDE(118 , 3 , 714000000U),
PLLDE(29 , 0 , 720000000U),
PLLDE(120 , 3 , 726000000U),
PLLDE(121 , 3 , 732000000U),
PLLDE(122 , 3 , 738000000U),
PLLDE(30 , 0 , 744000000U),
PLLDE(124 , 3 , 750000000U),
PLLDE(125 , 3 , 756000000U),
PLLDE(126 , 3 , 762000000U),
PLLDE(31 , 0 , 768000000U),
PLLDE(32 , 0 , 792000000U),
PLLDE(33 , 0 , 816000000U),
PLLDE(34 , 0 , 840000000U),
PLLDE(35 , 0 , 864000000U),
PLLDE(36 , 0 , 888000000U),
};
/* n,freq */
struct sunxi_clk_factor_freq factor_pllddr1_tbl[] = {
PLLDDR1(11	, 288000000U),
PLLDDR1(12	, 312000000U),
PLLDDR1(13	, 336000000U),
PLLDDR1(14	, 360000000U),
PLLDDR1(15	, 384000000U),
PLLDDR1(16	, 408000000U),
PLLDDR1(17	, 432000000U),
PLLDDR1(18	, 456000000U),
PLLDDR1(19	, 480000000U),
PLLDDR1(20	, 504000000U),
PLLDDR1(21	, 528000000U),
PLLDDR1(22	, 552000000U),
PLLDDR1(23	, 576000000U),
PLLDDR1(24	, 600000000U),
PLLDDR1(25	, 624000000U),
PLLDDR1(26	, 648000000U),
PLLDDR1(27	, 672000000U),
PLLDDR1(28	, 696000000U),
PLLDDR1(29	, 720000000U),
PLLDDR1(30	, 744000000U),
PLLDDR1(31	, 768000000U),
PLLDDR1(32	, 792000000U),
PLLDDR1(33	, 816000000U),
PLLDDR1(34	, 840000000U),
PLLDDR1(35	, 864000000U),
PLLDDR1(36	, 888000000U),
PLLDDR1(37	, 912000000U),
PLLDDR1(38	, 936000000U),
PLLDDR1(39	, 960000000U),
PLLDDR1(40	, 984000000U),
PLLDDR1(41	, 1008000000U),
PLLDDR1(42	, 1032000000U),
PLLDDR1(43	, 1056000000U),
PLLDDR1(44	, 1080000000U),
PLLDDR1(45	, 1104000000U),
PLLDDR1(46	, 1128000000U),
PLLDDR1(47	, 1152000000U),
PLLDDR1(48	, 1176000000U),
PLLDDR1(49	, 1200000000U),
PLLDDR1(50	, 1224000000U),
};
static unsigned int pllcpu_max , pllvideo_max;
static unsigned int pllve_max , pllddr0_max;
static unsigned int pllperiph_max , pllgpu_max;
static unsigned int pllhsic_max , pllde_max , pllddr1_max;
void sunxi_clk_factor_initlimits(void)
{
	pllcpu_max = factor_pllcpu_tbl[ARRAY_SIZE(factor_pllcpu_tbl)-1].freq;
	pllvideo_max = factor_pllvideo_tbl[ARRAY_SIZE(factor_pllvideo_tbl)-1].freq;
	pllve_max = factor_pllve_tbl[ARRAY_SIZE(factor_pllve_tbl)-1].freq;
	pllddr0_max = factor_pllddr0_tbl[ARRAY_SIZE(factor_pllddr0_tbl)-1].freq;
	pllperiph_max = factor_pllperiph_tbl[ARRAY_SIZE(factor_pllperiph_tbl)-1].freq;
	pllgpu_max = factor_pllgpu_tbl[ARRAY_SIZE(factor_pllgpu_tbl)-1].freq;
	pllhsic_max = factor_pllhsic_tbl[ARRAY_SIZE(factor_pllhsic_tbl)-1].freq;
	pllde_max = factor_pllde_tbl[ARRAY_SIZE(factor_pllde_tbl)-1].freq;
	pllddr1_max = factor_pllddr1_tbl[ARRAY_SIZE(factor_pllddr1_tbl)-1].freq;
}

