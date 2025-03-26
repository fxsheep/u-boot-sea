#include <init.h>
#include <asm/global_data.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <linux/bitops.h>

DECLARE_GLOBAL_DATA_PTR;

int board_early_init_f(void)
{
	return 0;
}

int board_init(void)
{
	return 0;
}

int dram_init(void)
{
	gd->ram_base = CFG_SYS_SDRAM_BASE;
	gd->ram_size = 0x4000000;
	//gd->relocaddr = CONFIG_TEXT_BASE;

	return 0;
}
