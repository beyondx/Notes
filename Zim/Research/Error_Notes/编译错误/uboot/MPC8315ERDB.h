/*
 * Copyright (C) 2007, 2009 Freescale Semiconductor, Inc.
 *
 * Dave Liu <daveliu@freescale.com>
 * Jerry Huang <Chang-Ming.Huang@freescale.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */
#define CONFIG_E300		1 /* E300 family */
#define CONFIG_MPC83XX		1 /* MPC83xx family */
#define CONFIG_MPC831X		1 /* MPC831x CPU family */
#define CONFIG_MPC8315		1 /* MPC8315 CPU specific */
#define CONFIG_MPC8315ERDB	1 /* MPC8315ERDB board specific */

/*
 * System Clock Setup
 */
#define CONFIG_83XX_CLKIN	66666667 /* in Hz */
#define CONFIG_SYS_CLK_FREQ	CONFIG_83XX_CLKIN

#ifdef CONFIG_PCISLAVE
#define CONFIG_PCI
#define CONFIG_83XX_PCICLK	66666667 /* in Hz */
#endif /* CONFIG_PCISLAVE */
/*
 * The 8315 silicon has three speed grade, they are
 * A: CORE/CSB = 400MHz/133MHz
 * B: CORE/CSB = 333MHz/133MHz
 * C: CORE/CSB = 266MHz/133MHz
 * Hardware Reset Configuration Word
 * if CLKIN is 66.66MHz, then
 * CSB = 133MHz, DDRC = 266MHz, LBC = 133MHz
 * We choose the A type silicon as default, so the core is 400Mhz.
 */

#define CONFIG_SYS_FREQ_400MHz		1
#define CONFIG_SYS_FREQ_333MHz		2
#define CONFIG_SYS_FREQ_266MHz		3

#ifndef CONFIG_CORE_FREQ
	#define CONFIG_CORE_FREQ	CONFIG_SYS_FREQ_400MHz
#endif

#if (CONFIG_CORE_FREQ == CONFIG_SYS_FREQ_266MHz)
#define CONFIG_SYS_HRCW_LOW (\
	HRCWL_LCL_BUS_TO_SCB_CLK_1X1 |\
	HRCWL_DDR_TO_SCB_CLK_2X1 |\
	HRCWL_SVCOD_DIV_2 |\
	HRCWL_CSB_TO_CLKIN_2X1 |\
	HRCWL_CORE_TO_CSB_2X1)
#elif (CONFIG_CORE_FREQ == CONFIG_SYS_FREQ_333MHz)
#define CONFIG_SYS_HRCW_LOW (\
	HRCWL_LCL_BUS_TO_SCB_CLK_1X1 |\
	HRCWL_DDR_TO_SCB_CLK_2X1 |\
	HRCWL_SVCOD_DIV_2 |\
	HRCWL_CSB_TO_CLKIN_2X1 |\
	HRCWL_CORE_TO_CSB_2_5X1)
#else
#define CONFIG_SYS_HRCW_LOW (\
	HRCWL_LCL_BUS_TO_SCB_CLK_1X1 |\
	HRCWL_DDR_TO_SCB_CLK_2X1 |\
	HRCWL_SVCOD_DIV_2 |\
	HRCWL_CSB_TO_CLKIN_2X1 |\
	HRCWL_CORE_TO_CSB_3X1)
#endif

#ifdef CONFIG_NAND_SPL
#ifdef CONFIG_PCISLAVE
#define CONFIG_SYS_HRCW_HIGH (\
	HRCWH_PCI_AGENT |\
	HRCWH_PCI_ARBITER_DISABLE |\
	HRCWH_CORE_ENABLE |\
	HRCWH_FROM_0XFFF00100 |\
	HRCWH_BOOTSEQ_DISABLE |\
	HRCWH_SW_WATCHDOG_DISABLE |\
	HRCWH_ROM_LOC_NAND_SP_8BIT |\
	HRCWH_RL_EXT_NAND |\
	HRCWH_TSEC1M_IN_RGMII |\
	HRCWH_TSEC2M_IN_RGMII |\
	HRCWH_BIG_ENDIAN |\
	HRCWH_LALE_NORMAL)
#else
#define CONFIG_SYS_HRCW_HIGH (\
	HRCWH_PCI_HOST |\
	HRCWH_PCI_ARBITER_ENABLE |\
	HRCWH_CORE_ENABLE |\
	HRCWH_FROM_0XFFF00100 |\
	HRCWH_BOOTSEQ_DISABLE |\
	HRCWH_SW_WATCHDOG_DISABLE |\
	HRCWH_ROM_LOC_NAND_SP_8BIT |\
	HRCWH_RL_EXT_NAND |\
	HRCWH_TSEC1M_IN_RGMII |\
	HRCWH_TSEC2M_IN_RGMII |\
	HRCWH_BIG_ENDIAN |\
	HRCWH_LALE_NORMAL)
#endif
#else
#ifdef CONFIG_PCISLAVE
#define CONFIG_SYS_HRCW_HIGH (\
	HRCWH_PCI_AGENT |\
	HRCWH_PCI1_ARBITER_DISABLE |\
	HRCWH_CORE_ENABLE |\
	HRCWH_FROM_0X00000100 |\
	HRCWH_BOOTSEQ_DISABLE |\
	HRCWH_SW_WATCHDOG_DISABLE |\
	HRCWH_ROM_LOC_LOCAL_16BIT |\
	HRCWH_RL_EXT_LEGACY |\
	HRCWH_TSEC1M_IN_RGMII |\
	HRCWH_TSEC2M_IN_RGMII |\
	HRCWH_BIG_ENDIAN |\
	HRCWH_LALE_NORMAL)
#else
#define CONFIG_SYS_HRCW_HIGH (\
	HRCWH_PCI_HOST |\
	HRCWH_PCI1_ARBITER_ENABLE |\
	HRCWH_CORE_ENABLE |\
	HRCWH_FROM_0X00000100 |\
	HRCWH_BOOTSEQ_DISABLE |\
	HRCWH_SW_WATCHDOG_DISABLE |\
	HRCWH_ROM_LOC_LOCAL_16BIT |\
	HRCWH_RL_EXT_LEGACY |\
	HRCWH_TSEC1M_IN_RGMII |\
	HRCWH_TSEC2M_IN_RGMII |\
	HRCWH_BIG_ENDIAN |\
	HRCWH_LALE_NORMAL)
#endif
#endif

/*
 * System IO Config
 */
#define CONFIG_SYS_SICRH		0x00000000
#define CONFIG_SYS_SICRL		0x00000000 /* 3.3V, no delay */

#define CONFIG_BOARD_EARLY_INIT_F /* call board_pre_init */

/*
 * IMMR new address
 */
#define CONFIG_SYS_IMMR		0xE0000000

/*
 * Arbiter Setup
 */
#define CONFIG_SYS_ACR_PIPE_DEP	3 /* Arbiter pipeline depth is 4 */
#define CONFIG_SYS_ACR_RPTCNT		3 /* Arbiter repeat count is 4 */
#define CONFIG_SYS_SPCR_TSECEP		3 /* eTSEC emergency priority is highest */

/*
 * DDR Setup
 */
#define CONFIG_SYS_DDR_BASE		0x00000000 /* DDR is system memory */
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_BASE
#define CONFIG_SYS_DDR_SDRAM_BASE	CONFIG_SYS_DDR_BASE
#define CONFIG_SYS_DDR_SDRAM_CLK_CNTL	DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05
#define CONFIG_SYS_DDRCDR_VALUE	( DDRCDR_EN \
				| DDRCDR_PZ_LOZ \
				| DDRCDR_NZ_LOZ \
				| DDRCDR_ODT \
				| DDRCDR_Q_DRN )
				/* 0x7b880001 */
/*
 * Manually set up DDR parameters
 * consist of two chips HY5PS12621BFP-C4 from HYNIX
 */
#define CONFIG_SYS_DDR_SIZE		512 /* MB */
#define CONFIG_SYS_DDR_CS0_BNDS	0x0000001f
#define CONFIG_SYS_DDR_CS0_CONFIG	( CSCONFIG_EN \
				| 0x00010000  /* ODT_WR to CSn */ \
				| CSCONFIG_ROW_BIT_13 | CSCONFIG_COL_BIT_10 )
				/* 0x80010102 */
#define CONFIG_SYS_DDR_TIMING_3	0x00000000
#define CONFIG_SYS_DDR_TIMING_0	( ( 0 << TIMING_CFG0_RWT_SHIFT ) \
				| ( 0 << TIMING_CFG0_WRT_SHIFT ) \
				| ( 0 << TIMING_CFG0_RRT_SHIFT ) \
				| ( 0 << TIMING_CFG0_WWT_SHIFT ) \
				| ( 2 << TIMING_CFG0_ACT_PD_EXIT_SHIFT ) \
				| ( 2 << TIMING_CFG0_PRE_PD_EXIT_SHIFT ) \
				| ( 8 << TIMING_CFG0_ODT_PD_EXIT_SHIFT ) \
				| ( 2 << TIMING_CFG0_MRS_CYC_SHIFT ) )
				/* 0x00220802 */
#define CONFIG_SYS_DDR_TIMING_1	( ( 2 << TIMING_CFG1_PRETOACT_SHIFT ) \
				| ( 7 << TIMING_CFG1_ACTTOPRE_SHIFT ) \
				| ( 2 << TIMING_CFG1_ACTTORW_SHIFT ) \
				| ( 5 << TIMING_CFG1_CASLAT_SHIFT ) \
				| ( 6 << TIMING_CFG1_REFREC_SHIFT ) \
				| ( 2 << TIMING_CFG1_WRREC_SHIFT ) \
				| ( 2 << TIMING_CFG1_ACTTOACT_SHIFT ) \
				| ( 2 << TIMING_CFG1_WRTORD_SHIFT ) )
				/* 0x27256222 */
#define CONFIG_SYS_DDR_TIMING_2	( ( 1 << TIMING_CFG2_ADD_LAT_SHIFT ) \
				| ( 4 << TIMING_CFG2_CPO_SHIFT ) \
				| ( 2 << TIMING_CFG2_WR_LAT_DELAY_SHIFT ) \
				| ( 2 << TIMING_CFG2_RD_TO_PRE_SHIFT ) \
				| ( 2 << TIMING_CFG2_WR_DATA_DELAY_SHIFT ) \
				| ( 3 << TIMING_CFG2_CKE_PLS_SHIFT ) \
				| ( 5 << TIMING_CFG2_FOUR_ACT_SHIFT) )
				/* 0x121048c5 */
#define CONFIG_SYS_DDR_INTERVAL	( ( 0x0360 << SDRAM_INTERVAL_REFINT_SHIFT ) \
				| ( 0x0100 << SDRAM_INTERVAL_BSTOPRE_SHIFT ) )
				/* 0x03600100 */
#define CONFIG_SYS_DDR_SDRAM_CFG	( SDRAM_CFG_SREN \
				| SDRAM_CFG_SDRAM_TYPE_DDR2 \
				| SDRAM_CFG_32_BE )
				/* 0x43080000 */
#define CONFIG_SYS_DDR_SDRAM_CFG2	0x00401000 /* 1 posted refresh */
#define CONFIG_SYS_DDR_MODE		( ( 0x0448 << SDRAM_MODE_ESD_SHIFT ) \
				| ( 0x0232 << SDRAM_MODE_SD_SHIFT ) )
				/* ODT 150ohm CL=3, AL=1 on SDRAM */
#define CONFIG_SYS_DDR_MODE2		0x00000000

/*
 * Memory test
 */
#undef CONFIG_SYS_DRAM_TEST		/* memory test, takes time */
#define CONFIG_SYS_MEMTEST_START	0x00040000 /* memtest region */
#define CONFIG_SYS_MEMTEST_END		0x00140000

/*
 * The reserved memory
 */
#define CONFIG_SYS_MONITOR_BASE	TEXT_BASE /* start of monitor */

#if (CONFIG_SYS_MONITOR_BASE < CONFIG_SYS_FLASH_BASE) && !defined(CONFIG_NAND_U_BOOT)
#define CONFIG_SYS_RAMBOOT
#else
#undef CONFIG_SYS_RAMBOOT
#endif

#define CONFIG_SYS_MONITOR_LEN		(384 * 1024) /* Reserve 384 kB for Mon */
#define CONFIG_SYS_MALLOC_LEN		(512 * 1024) /* Reserved for malloc */

/*
 * Initial RAM Base Address Setup
 */
#define CONFIG_SYS_INIT_RAM_LOCK	1
#define CONFIG_SYS_INIT_RAM_ADDR	0xE6000000 /* Initial RAM address */
#define CONFIG_SYS_INIT_RAM_END	0x1000 /* End of used area in RAM */
#define CONFIG_SYS_GBL_DATA_SIZE	0x100 /* num bytes initial data */
#define CONFIG_SYS_GBL_DATA_OFFSET	(CONFIG_SYS_INIT_RAM_END - CONFIG_SYS_GBL_DATA_SIZE)

/*
 * Local Bus Configuration & Clock Setup
 */
#define CONFIG_SYS_LCRR		(LCRR_DBYP | LCRR_CLKDIV_2)
#define CONFIG_SYS_LBC_LBCR		0x00040000

/*
 * FLASH on the Local Bus
 */
#define CONFIG_SYS_FLASH_CFI		/* use the Common Flash Interface */
#define CONFIG_FLASH_CFI_DRIVER	/* use the CFI driver */
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT

#define CONFIG_SYS_FLASH_BASE		0xFE000000 /* FLASH base address */
#define CONFIG_SYS_FLASH_SIZE		8 /* FLASH size is 8M */
#define CONFIG_SYS_FLASH_PROTECTION	1		/* Use h/w Flash protection. */

#define CONFIG_SYS_LBLAWBAR0_PRELIM	CONFIG_SYS_FLASH_BASE /* Window base at flash base */
#define CONFIG_SYS_LBLAWAR0_PRELIM	0x80000016 /* 8MB window size */

#define CONFIG_SYS_FLASH_BR_PRELIM	( CONFIG_SYS_FLASH_BASE	/* Flash Base address */ \
				| (2 << BR_PS_SHIFT)	/* 16 bit port size */ \
				| BR_V )		/* valid */
#define CONFIG_SYS_FLASH_OR_PRELIM	( (~(CONFIG_SYS_FLASH_SIZE - 1) << 20) \
				| OR_UPM_XAM \
				| OR_GPCM_CSNT \
				| OR_GPCM_ACS_DIV2 \
				| OR_GPCM_XACS \
				| OR_GPCM_SCY_15 \
				| OR_GPCM_TRLX \
				| OR_GPCM_EHTR \
				| OR_GPCM_EAD )

#define CONFIG_SYS_MAX_FLASH_BANKS	1 /* number of banks */
#define CONFIG_SYS_MAX_FLASH_SECT	135 /* 127 64KB sectors and 8 8KB top sectors per device */

#undef CONFIG_SYS_FLASH_CHECKSUM
#define CONFIG_SYS_FLASH_ERASE_TOUT	60000 /* Flash Erase Timeout (ms) */
#define CONFIG_SYS_FLASH_WRITE_TOUT	500 /* Flash Write Timeout (ms) */

/*
 * NAND Flash on the Local Bus
 */
#ifdef CONFIG_NAND_SPL
#define CONFIG_SYS_NAND_BASE		0xFFF00000
#else
#define CONFIG_SYS_NAND_BASE		0xE0600000	/* 0xE0600000 */
#endif
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_MTD_NAND_VERIFY_WRITE	1
#define CONFIG_CMD_NAND			1
#define CONFIG_NAND_FSL_ELBC		1

#ifndef CONFIG_NAND_ECC_OFF
#define CONFIG_SYS_NAND_BR_PRELIM	( CONFIG_SYS_NAND_BASE \
				| (2<<BR_DECC_SHIFT)	/* Use HW ECC */ \
				| BR_PS_8		/* Port Size = 8 bit */ \
				| BR_MS_FCM		/* MSEL = FCM */ \
				| BR_V )		/* valid */
#else
#define CONFIG_SYS_NAND_BR_PRELIM	( CONFIG_SYS_NAND_BASE \
				| BR_PS_8		/* Port Size = 8 bit */ \
				| BR_MS_FCM		/* MSEL = FCM */ \
				| BR_V )
#endif

#define CONFIG_SYS_NAND_OR_PRELIM	( 0xFFFF8000		/* length 32K */ \
				| OR_FCM_CSCT \
				| OR_FCM_CST \
				| OR_FCM_CHT \
				| OR_FCM_SCY_1 \
				| OR_FCM_TRLX \
				| OR_FCM_EHTR )
				/* 0xFFFF8396 */

#define CONFIG_SYS_LBLAWBAR1_PRELIM	CONFIG_SYS_NAND_BASE
#define CONFIG_SYS_LBLAWAR1_PRELIM	0x8000000E	/* 32KB  */

#define CONFIG_SYS_NAND_LBLAWBAR_PRELIM CONFIG_SYS_LBLAWBAR1_PRELIM
#define CONFIG_SYS_NAND_LBLAWAR_PRELIM CONFIG_SYS_LBLAWAR1_PRELIM

/*
 * Swap CS0 / CS1 based upon NAND or NOR Flash Boot mode
 */
#if defined(CONFIG_NAND_U_BOOT)
#define CONFIG_SYS_BR0_PRELIM		CONFIG_SYS_NAND_BR_PRELIM  /* NAND Base Address */
#define CONFIG_SYS_OR0_PRELIM		CONFIG_SYS_NAND_OR_PRELIM  /* NAND Options */
#define CONFIG_SYS_BR1_PRELIM		CONFIG_SYS_FLASH_BR_PRELIM /* NOR Base address */
#define CONFIG_SYS_OR1_PRELIM		CONFIG_SYS_FLASH_OR_PRELIM /* NOR Options */
#else
#define CONFIG_SYS_BR0_PRELIM		CONFIG_SYS_FLASH_BR_PRELIM /* NOR Base address */
#define CONFIG_SYS_OR0_PRELIM		CONFIG_SYS_FLASH_OR_PRELIM /* NOR Options */
#define CONFIG_SYS_BR1_PRELIM		CONFIG_SYS_NAND_BR_PRELIM  /* NAND Base Address */
#define CONFIG_SYS_OR1_PRELIM		CONFIG_SYS_NAND_OR_PRELIM  /* NAND Options */
#endif /* CONFIG_NAND_U_BOOT */

/*
 * NAND Boot Configuration, for board/../nand_boot.c
 */
#define CONFIG_SYS_NAND_BR0_PRELIM	CONFIG_SYS_NAND_BR_PRELIM
#define CONFIG_SYS_NAND_OR0_PRELIM	CONFIG_SYS_NAND_OR_PRELIM
#define CONFIG_SYS_NAND_LBLAWBAR0_PRELIM	CONFIG_SYS_NAND_BASE
#define CONFIG_SYS_NAND_LBLAWAR0_PRELIM	0x8000000E	/* 32KB  */

#undef  CONFIG_SYS_NAND_BOOT_QUIET			/* Enable NAND boot status messages */
#define CONFIG_SYS_NAND_BOOT_SHOW_ECC_NUM		/* Show corrected ECC errors */
#define CONFIG_SYS_NAND_PAGE_SIZE	(512)		/* NAND chip page size */
#define CONFIG_SYS_NAND_BLOCK_SIZE	(16 << 10)	/* NAND chip block size */
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	(5)		/* Bad block marker location */
#define CONFIG_SYS_NAND_FMR		((15 << FMR_CWTO_SHIFT) | (0 << FMR_AL_SHIFT))

#define CONFIG_SYS_NAND_U_BOOT_SIZE	(384 << 10)	/* Size of RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_DST	(0x01000000)	/* Load NUB to this addr */
#define CONFIG_SYS_NAND_U_BOOT_START	(CONFIG_SYS_NAND_U_BOOT_DST + 0x120) /* NUB start */
#define CONFIG_SYS_NAND_U_BOOT_OFFS	(16 << 10)
#define CONFIG_SYS_NAND_U_BOOT_RELOC	0x00010000

/*
 * JFFS2 configuration
 */
#define CONFIG_JFFS2_NAND

/* mtdparts command line support */
#define CONFIG_JFFS2_CMDLINE
#define MTDIDS_DEFAULT		"nor0=nor,nand0=nand"
#define MTDPARTS_DEFAULT	"mtdparts=nand:-@4m(jffs2)"
#define NAND_CACHE_PAGES	32

/*
 * Serial Port
 */
#define CONFIG_CONS_INDEX	1
#undef CONFIG_SERIAL_SOFTWARE_FIFO
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	1
#define CONFIG_SYS_NS16550_CLK		gd->csb_clk

#define CONFIG_SYS_BAUDRATE_TABLE  \
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200}

#define CONFIG_SYS_NS16550_COM1	(CONFIG_SYS_IMMR+0x4500)
#define CONFIG_SYS_NS16550_COM2	(CONFIG_SYS_IMMR+0x4600)

/* Use the HUSH parser */
#define CONFIG_SYS_HUSH_PARSER
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2 "> "
#endif

/* Pass open firmware flat tree */
#define CONFIG_OF_LIBFDT	1
#define CONFIG_OF_BOARD_SETUP	1
#define CONFIG_OF_STDOUT_VIA_ALIAS	1

/* I2C */
#define CONFIG_HARD_I2C		/* I2C with hardware support */
#define CONFIG_FSL_I2C
#define CONFIG_SYS_I2C_SPEED		400000 /* I2C speed and slave address */
#define CONFIG_SYS_I2C_SLAVE		0x7F
#define CONFIG_SYS_I2C_NOPROBES	{0x51} /* Don't probe these addrs */
#define CONFIG_SYS_I2C_OFFSET		0x3000
#define CONFIG_SYS_I2C2_OFFSET		0x3100

/*
 * Board info - revision and where boot from
 */
#define CONFIG_SYS_I2C_PCF8574A_ADDR	0x39

/*
 * Config on-board RTC
 */
#define CONFIG_RTC_DS1337	/* ds1339 on board, use ds1337 rtc via i2c */
#define CONFIG_SYS_I2C_RTC_ADDR	0x68 /* at address 0x68 */

/*
 * General PCI
 * Addresses are mapped 1-1.
 */
#define CONFIG_SYS_PCI_MEM_BASE	0x80000000
#define CONFIG_SYS_PCI_MEM_PHYS	CONFIG_SYS_PCI_MEM_BASE
#define CONFIG_SYS_PCI_MEM_SIZE	0x10000000 /* 256M */
#define CONFIG_SYS_PCI_MMIO_BASE	0x90000000
#define CONFIG_SYS_PCI_MMIO_PHYS	CONFIG_SYS_PCI_MMIO_BASE
#define CONFIG_SYS_PCI_MMIO_SIZE	0x10000000 /* 256M */
#define CONFIG_SYS_PCI_IO_BASE		0x00000000
#define CONFIG_SYS_PCI_IO_PHYS		0xE0300000
#define CONFIG_SYS_PCI_IO_SIZE		0x100000 /* 1M */

#define CONFIG_SYS_PCI_SLV_MEM_LOCAL	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_PCI_SLV_MEM_BUS	0x00000000
#define CONFIG_SYS_PCI_SLV_MEM_SIZE	0x80000000

#define CONFIG_SYS_PCIE1_BASE		0xA0000000
#define CONFIG_SYS_PCIE1_MEM_BASE	0xA0000000
#define CONFIG_SYS_PCIE1_MEM_PHYS	0xA0000000
#define CONFIG_SYS_PCIE1_MEM_SIZE	0x10000000
#define CONFIG_SYS_PCIE1_CFG_BASE	0xB0000000
#define CONFIG_SYS_PCIE1_CFG_SIZE	0x01000000
#define CONFIG_SYS_PCIE1_IO_BASE	0x00000000
#define CONFIG_SYS_PCIE1_IO_PHYS	0xB1000000
#define CONFIG_SYS_PCIE1_IO_SIZE	0x00800000

#define CONFIG_SYS_PCIE2_BASE		0xC0000000
#define CONFIG_SYS_PCIE2_MEM_BASE	0xC0000000
#define CONFIG_SYS_PCIE2_MEM_PHYS	0xC0000000
#define CONFIG_SYS_PCIE2_MEM_SIZE	0x10000000
#define CONFIG_SYS_PCIE2_CFG_BASE	0xD0000000
#define CONFIG_SYS_PCIE2_CFG_SIZE	0x01000000
#define CONFIG_SYS_PCIE2_IO_BASE	0x00000000
#define CONFIG_SYS_PCIE2_IO_PHYS	0xD1000000
#define CONFIG_SYS_PCIE2_IO_SIZE	0x00800000

#define CONFIG_PCI
#define CONFIG_83XX_GENERIC_PCI	1 /* Use generic PCI setup */
#define CONFIG_83XX_GENERIC_PCIE	1
#define CONFIG_83XX_GENERIC_PCIE_REGISTER_HOSES

#define PCI_VENDOR_ID_FREESCALE 0x1957
#define PCI_DEVICE_ID_MPC8315E 0x00b4

#define CONFIG_NET_MULTI
#define CONFIG_PCI_PNP		/* do pci plug-and-play */

#define CONFIG_EEPRO100
#undef CONFIG_PCI_SCAN_SHOW	/* show pci devices on startup */
#define CONFIG_SYS_PCI_SUBSYS_VENDORID 0x1957	/* Freescale */
#define CONFIG_SKIP_PCI_SCAN

#ifndef CONFIG_NET_MULTI
#define CONFIG_NET_MULTI	1
#endif

#define CONFIG_HAS_FSL_DR_USB

/*
 * TSEC
 */
#define CONFIG_TSEC_ENET	/* TSEC ethernet support */
#define CONFIG_SYS_TSEC1_OFFSET	0x24000
#define CONFIG_SYS_TSEC1		(CONFIG_SYS_IMMR+CONFIG_SYS_TSEC1_OFFSET)
#define CONFIG_SYS_TSEC2_OFFSET	0x25000
#define CONFIG_SYS_TSEC2		(CONFIG_SYS_IMMR+CONFIG_SYS_TSEC2_OFFSET)

/*
 * TSEC ethernet configuration
 */
#define CONFIG_MII		1 /* MII PHY management */
//#define CONFIG_TSEC1		1
//#define CONFIG_TSEC1_NAME	"eTSEC0"
#define CONFIG_TSEC2		1
#define CONFIG_TSEC2_NAME	"eTSEC0"
//#define TSEC1_PHY_ADDR		0
#define TSEC2_PHY_ADDR		1
//#define TSEC1_PHYIDX		0
#define TSEC2_PHYIDX		0
//#define TSEC1_FLAGS		TSEC_GIGABIT
#define TSEC2_FLAGS		TSEC_GIGABIT

/* Options are: eTSEC[0-1] */
#define CONFIG_ETHPRIME		"eTSEC0"

/*
 * SATA
 */
#define CONFIG_LIBATA
#define CONFIG_FSL_SATA

#define CONFIG_SYS_SATA_MAX_DEVICE	2
#define CONFIG_SATA1
#define CONFIG_SYS_SATA1_OFFSET	0x18000
#define CONFIG_SYS_SATA1		(CONFIG_SYS_IMMR + CONFIG_SYS_SATA1_OFFSET)
#define CONFIG_SYS_SATA1_FLAGS		FLAGS_DMA
#define CONFIG_SATA2
#define CONFIG_SYS_SATA2_OFFSET	0x19000
#define CONFIG_SYS_SATA2		(CONFIG_SYS_IMMR + CONFIG_SYS_SATA2_OFFSET)
#define CONFIG_SYS_SATA2_FLAGS		FLAGS_DMA

#ifdef CONFIG_FSL_SATA
#define CONFIG_LBA48
#define CONFIG_CMD_SATA
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_EXT2
#endif

/*
 * Environment
 */
#if defined(CONFIG_NAND_U_BOOT)
	#define CONFIG_ENV_IS_IN_NAND	1
	#define CONFIG_ENV_SIZE		CONFIG_SYS_NAND_BLOCK_SIZE
	#define CONFIG_ENV_OFFSET	((1024<<10) - (CONFIG_SYS_NAND_BLOCK_SIZE<<1))
#elif !defined(CFG_RAMBOOT)
	#define CONFIG_ENV_IS_IN_FLASH	1
	#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE + CONFIG_SYS_MONITOR_LEN)
	#define CONFIG_ENV_SECT_SIZE	0x10000 /* 64K(one sector) for env */
	#define CONFIG_ENV_SIZE		0x2000
#else
	#define CONFIG_SYS_NO_FLASH		1	/* Flash is not usable now */
	#define CONFIG_ENV_IS_NOWHERE	1	/* Store ENV in memory only */
	#define CONFIG_ENV_ADDR		(CONFIG_SYS_MONITOR_BASE - 0x1000)
	#define CONFIG_ENV_SIZE		0x2000
#endif

#define CONFIG_LOADS_ECHO	1	/* echo on for serial download */
#define CONFIG_SYS_LOADS_BAUD_CHANGE	1	/* allow baudrate change */

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_I2C
#define CONFIG_CMD_MII
#define CONFIG_CMD_DATE
#define CONFIG_CMD_PCI
#define CONFIG_CMD_JFFS2
#define CONFIG_CMD_FDT

#if defined(CONFIG_SYS_RAMBOOT)
    #undef CONFIG_CMD_SAVEENV
    #undef CONFIG_CMD_LOADS
#endif

#define CONFIG_CMDLINE_EDITING	1	/* add command line history */

#undef CONFIG_WATCHDOG		/* watchdog disabled */

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_LOAD_ADDR		0x2000000 /* default load address */
#define CONFIG_SYS_PROMPT		"=> "	/* Monitor Command Prompt */

#if defined(CONFIG_CMD_KGDB)
	#define CONFIG_SYS_CBSIZE	1024 /* Console I/O Buffer Size */
#else
	#define CONFIG_SYS_CBSIZE	256 /* Console I/O Buffer Size */
#endif

#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16		/* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size */
#define CONFIG_SYS_HZ		1000		/* decrementer freq: 1ms ticks */

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ		(8 << 20) /* Initial Memory map for Linux */

/*
 * Core HID Setup
 */
#define CONFIG_SYS_HID0_INIT		0x000000000
#define CONFIG_SYS_HID0_FINAL		(HID0_ENABLE_MACHINE_CHECK | \
				 HID0_ENABLE_DYNAMIC_POWER_MANAGMENT)
#define CONFIG_SYS_HID2		HID2_HBE

/*
 * MMU Setup
 */
#define CONFIG_HIGH_BATS	1	/* High BATs supported */

/* DDR: cache cacheable, low 256MB */
#define CONFIG_SYS_IBAT0L	(CONFIG_SYS_SDRAM_BASE | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT0U	(CONFIG_SYS_SDRAM_BASE | BATU_BL_256M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT0L	CONFIG_SYS_IBAT0L
#define CONFIG_SYS_DBAT0U	CONFIG_SYS_IBAT0U


/* IMMRBAR, PCI IO and NAND: cache-inhibit and guarded */
#define CONFIG_SYS_IBAT1L	(CONFIG_SYS_IMMR | BATL_PP_10 | \
			BATL_CACHEINHIBIT | BATL_GUARDEDSTORAGE)
#define CONFIG_SYS_IBAT1U	(CONFIG_SYS_IMMR | BATU_BL_8M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT1L	CONFIG_SYS_IBAT1L
#define CONFIG_SYS_DBAT1U	CONFIG_SYS_IBAT1U

/* FLASH: icache cacheable, but dcache-inhibit and guarded */
#define CONFIG_SYS_IBAT2L	(CONFIG_SYS_FLASH_BASE | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT2U	(CONFIG_SYS_FLASH_BASE | BATU_BL_32M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT2L	(CONFIG_SYS_FLASH_BASE | BATL_PP_10 | \
			BATL_CACHEINHIBIT | BATL_GUARDEDSTORAGE)
#define CONFIG_SYS_DBAT2U	CONFIG_SYS_IBAT2U

/* Stack in dcache: cacheable, no memory coherence */
#define CONFIG_SYS_IBAT3L	(CONFIG_SYS_INIT_RAM_ADDR | BATL_PP_10)
#define CONFIG_SYS_IBAT3U	(CONFIG_SYS_INIT_RAM_ADDR | BATU_BL_128K | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT3L	CONFIG_SYS_IBAT3L
#define CONFIG_SYS_DBAT3U	CONFIG_SYS_IBAT3U

/* PCI MEM space: cacheable */
#define CONFIG_SYS_IBAT4L	(CONFIG_SYS_PCI_MEM_PHYS | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT4U	(CONFIG_SYS_PCI_MEM_PHYS | BATU_BL_256M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT4L	CONFIG_SYS_IBAT4L
#define CONFIG_SYS_DBAT4U	CONFIG_SYS_IBAT4U

/* PCI MMIO space: cache-inhibit and guarded */
#define CONFIG_SYS_IBAT5L	(CONFIG_SYS_PCI_MMIO_PHYS | BATL_PP_10 | \
			BATL_CACHEINHIBIT | BATL_GUARDEDSTORAGE)
#define CONFIG_SYS_IBAT5U	(CONFIG_SYS_PCI_MMIO_PHYS | BATU_BL_256M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT5L	CONFIG_SYS_IBAT5L
#define CONFIG_SYS_DBAT5U	CONFIG_SYS_IBAT5U

/* DDR: cache cacheable, high 256MB */
#define CONFIG_SYS_IBAT6L	(0x10000000 | BATL_PP_10 | BATL_MEMCOHERENCE)
#define CONFIG_SYS_IBAT6U	(0x10000000 | BATU_BL_256M | BATU_VS | BATU_VP)
#define CONFIG_SYS_DBAT6L	CONFIG_SYS_IBAT6L
#define CONFIG_SYS_DBAT6U	CONFIG_SYS_IBAT6U

#define CONFIG_SYS_IBAT7L	0
#define CONFIG_SYS_IBAT7U	0
#define CONFIG_SYS_DBAT7L	CONFIG_SYS_IBAT7L
#define CONFIG_SYS_DBAT7U	CONFIG_SYS_IBAT7U

/*
 * Internal Definitions
 *
 * Boot Flags
 */
#define BOOTFLAG_COLD	0x01 /* Normal Power-On: Boot from FLASH */
#define BOOTFLAG_WARM	0x02 /* Software reboot */

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	230400	/* speed of kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	2	/* which serial port to use */
#endif

/*
 * Environment Configuration
 */

#define CONFIG_ENV_OVERWRITE

#if defined(CONFIG_TSEC_ENET)
#define CONFIG_HAS_ETH0
#define CONFIG_ETHADDR		04:00:00:00:00:0A
#define CONFIG_HAS_ETH1
#define CONFIG_ETH1ADDR		04:00:00:00:00:0B
#endif

#define CONFIG_BAUDRATE 115200

#define CONFIG_LOADADDR 500000	/* default location for tftp and bootm */

#define CONFIG_BOOTDELAY 6	/* -1 disables auto-boot */
#undef CONFIG_BOOTARGS		/* the boot command will set bootargs */

#define CONFIG_PCI_CONFIG_HOST_BRIDGE 1

#define CONFIG_EXTRA_ENV_SETTINGS					\
   "netdev=eth0\0"							\
   "consoledev=ttyS0\0"							\
   "ramdiskaddr=1000000\0"						\
   "ramdiskfile=ramfs.83xx\0"						\
   "fdtaddr=400000\0"							\
   "fdtfile=mpc8315erdb.dtb\0"						\
   "pciconfighost=yes\0"				                \
   ""

#define CONFIG_NFSBOOTCOMMAND						\
   "setenv bootargs root=/dev/nfs rw "					\
      "nfsroot=$serverip:$rootpath "					\
      "ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname:$netdev:off " \
      "console=$consoledev,$baudrate $othbootargs;"			\
   "tftp $loadaddr $bootfile;"						\
   "tftp $fdtaddr $fdtfile;"						\
   "bootm $loadaddr - $fdtaddr"

#define CONFIG_RAMBOOTCOMMAND						\
   "setenv bootargs root=/dev/ram rw "					\
      "console=$consoledev,$baudrate $othbootargs;"			\
   "tftp $ramdiskaddr $ramdiskfile;"					\
   "tftp $loadaddr $bootfile;"						\
   "tftp $fdtaddr $fdtfile;"						\
   "bootm $loadaddr $ramdiskaddr $fdtaddr"


#define CONFIG_BOOTCOMMAND CONFIG_NFSBOOTCOMMAND

#endif	/* __CONFIG_H */
