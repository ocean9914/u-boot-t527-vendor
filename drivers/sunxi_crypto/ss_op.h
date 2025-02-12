/*
 * (C) Copyright 2013-2016
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef SS_HARDWARE_OP_H_
#define SS_HARDWARE_OP_H_

#include <asm/types.h>

int ss_get_ver(void);
void ss_set_drq(u32 addr);
#if defined(CONFIG_SUNXI_CE_30)
void ss_ctrl_start(u8 channel_id, u8 alg_type);
int ss_wait_finish(u32 task_id);
#else
void ss_ctrl_start(u8 alg_type);
void ss_wait_finish(u32 task_id);
#endif
void ss_ctrl_stop(void);

u32 ss_pending_clear(u32 task_id);
void ss_irq_enable(u32 task_id);
void ss_irq_disable(u32 task_id);
#if defined(CONFIG_SUNXI_CE_21) || defined(CONFIG_SUNXI_CE_23) || defined(CONFIG_SUNXI_CE_30)
u32 ss_check_err(u32 task_id);
#else
u32 ss_check_err(void);
#endif
void ss_open(void);
void ss_close(void);
u32 ss_get_addr_align(void);

#endif

