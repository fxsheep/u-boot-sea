// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2018 Xilinx, Inc. (Michal Simek)
 */

#include <cpu_func.h>
#include <init.h>
#include <asm/armv7_mpu.h>
#include <asm/global_data.h>
#include <asm/io.h>

DECLARE_GLOBAL_DATA_PTR;


#define SYSCON_BASE				0x800d4000
#define SYSCON_CLKDIV_TIMER0	0xe4
#define SYSCON_CLKDIV_TIMER1	0xe8
#define SYSCON_CLKDIV_TIMER2	0xec

struct mpu_region_config region_config[] = {
	{ 0x00000000, REGION_0, XN_DIS, PRIV_RW_USR_RW,
      O_I_WB_RD_WR_ALLOC, REGION_4GB },
	{ 0x80000000, REGION_1, XN_EN, PRIV_RW_USR_RW,
	  SHARED_WRITE_BUFFERED, REGION_256MB },
};

int arch_cpu_init(void)
{
	//gd->cpu_clk = CONFIG_CPU_FREQ_HZ;

	setup_mpu_regions(region_config, ARRAY_SIZE(region_config));

	// disable prescaler of timers
	writel(0x0, SYSCON_BASE + SYSCON_CLKDIV_TIMER0);
	writel(0x0, SYSCON_BASE + SYSCON_CLKDIV_TIMER1);
	writel(0x0, SYSCON_BASE + SYSCON_CLKDIV_TIMER2);

	return 0;
}

#if defined(CONFIG_DISPLAY_CPUINFO)
int print_cpuinfo(void)
{
	printf("CPU: Seagate SEA4\n");

	return 0;
}
#endif

/*
 * Perform the low-level reset.
 */
void reset_cpu(void)
{
	while (1)
		;
}
