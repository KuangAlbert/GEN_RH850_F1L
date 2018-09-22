/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: 生成F1L 100pin的pinmux
 * Instance		:
 * Description	:
 *-----------------------------------------------------------------------
 * Version		: v1.0
 * Date			: 2018/08/27
 * Author		: uidp5021
 ***********************************************************************/
 /*-History--------------------------------------------------------------
 * Version       Date               Name            Changes and comments
 * 1.0           2018/08/27			Lishi           add Init version
*=========================================================================*/
#include <stdio.h>
#include <stdarg.h>
#include "GenPinmux_pin.h"
#include "ProcessExcel.h"
#include "config.h"


FILE* File;

/* ACTIVE */
const U8 PmcStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_ACTIVE_VAL ",
	"#define GPIO_PMC8_ACTIVE_VAL ",
	"#define GPIO_PMC9_ACTIVE_VAL ",
	"#define GPIO_PMC10_ACTIVE_VAL",
	"#define GPIO_PMC11_ACTIVE_VAL",
	"#define GPIO_JPMC0_ACTIVE_VAL",
};

const U8 PmStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_ACTIVE_VAL ",
	"#define GPIO_PM8_ACTIVE_VAL ",
	"#define GPIO_PM9_ACTIVE_VAL ",
	"#define GPIO_PM10_ACTIVE_VAL",
	"#define GPIO_PM11_ACTIVE_VAL",
	"#define GPIO_APM0_ACTIVE_VAL",
	"#define GPIO_JPM0_ACTIVE_VAL",
};

const U8 PibcStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_ACTIVE_VAL ",
	"#define GPIO_PIBC8_ACTIVE_VAL ",
	"#define GPIO_PIBC9_ACTIVE_VAL ",
	"#define GPIO_PIBC10_ACTIVE_VAL",
	"#define GPIO_PIBC11_ACTIVE_VAL ",
	"#define GPIO_APIBC0_ACTIVE_VAL",
	"#define GPIO_JPIBC0_ACTIVE_VAL",
};

const U8 PbdcStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_ACTIVE_VAL ",
	"#define GPIO_PBDC8_ACTIVE_VAL ",
	"#define GPIO_PBDC9_ACTIVE_VAL ",
	"#define GPIO_PBDC10_ACTIVE_VAL",
	"#define GPIO_PBDC11_ACTIVE_VAL",
	"#define GPIO_APBDC0_ACTIVE_VAL",
	"#define GPIO_JPBDC0_ACTIVE_VAL",
};

const U8 PuStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_ACTIVE_VAL ",
	"#define GPIO_PU8_ACTIVE_VAL ",
	"#define GPIO_PU9_ACTIVE_VAL ",
	"#define GPIO_PU10_ACTIVE_VAL",
	"#define GPIO_PU11_ACTIVE_VAL",
	"#define GPIO_APU0_ACTIVE_VAL",
	"#define GPIO_JPU0_ACTIVE_VAL",
};

const U8 PdStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_ACTIVE_VAL ",
	"#define GPIO_PD8_ACTIVE_VAL ",
	"#define GPIO_PD9_ACTIVE_VAL ",
	"#define GPIO_PD10_ACTIVE_VAL",
	"#define GPIO_PD11_ACTIVE_VAL",
	"#define GPIO_APD0_ACTIVE_VAL",
	"#define GPIO_JPD0_ACTIVE_VAL",
};

const U8 PdscStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_ACTIVE_VAL ",
	"#define GPIO_PDSC8_ACTIVE_VAL ",
	"#define GPIO_PDSC9_ACTIVE_VAL ",
	"#define GPIO_PDSC10_ACTIVE_VAL",
	"#define GPIO_PDSC11_ACTIVE_VAL",
};

const U8 PodcStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_ACTIVE_VAL ",
	"#define GPIO_PODC8_ACTIVE_VAL ",
	"#define GPIO_PODC9_ACTIVE_VAL ",
	"#define GPIO_PODC10_ACTIVE_VAL",
	"#define GPIO_PODC11_ACTIVE_VAL",
	"#define GPIO_APODC0_ACTIVE_VAL",
	"#define GPIO_JPODC0_ACTIVE_VAL",
};

const U8 PStringActive_100[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_ACTIVE_VAL ",
	"#define GPIO_P8_ACTIVE_VAL ",
	"#define GPIO_P9_ACTIVE_VAL ",
	"#define GPIO_P10_ACTIVE_VAL",
	"#define GPIO_P11_ACTIVE_VAL",
	"#define GPIO_JP0_ACTIVE_VAL",
	"#define GPIO_AP0_ACTIVE_VAL",
};

const U8 AlternativeActive_100[6][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_ACTIVE_VAL  ",
		"#define GPIO_PFCE0_ACTIVE_VAL ",
		"#define GPIO_PFCAE0_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC8_ACTIVE_VAL  ",
		"#define GPIO_PFCE8_ACTIVE_VAL ",
		"#define GPIO_PFCAE8_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC9_ACTIVE_VAL  ",
		"#define GPIO_PFCE9_ACTIVE_VAL ",
		"#define GPIO_PFCAE9_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC10_ACTIVE_VAL  ",
		"#define GPIO_PFCE10_ACTIVE_VAL ",
		"#define GPIO_PFCAE10_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC11_ACTIVE_VAL  ",
		"#define GPIO_PFCE11_ACTIVE_VAL ",
		"#define GPIO_PFCAE11_ACTIVE_VAL",
	},
	{
		"#define GPIO_JPFC0_ACTIVE_VAL  ",
		"#define GPIO_JPFCE0_ACTIVE_VAL ",
		"#define GPIO_JPFCAE0_ACTIVE_VAL",
	}
};

const U8 PipcStringActive_100[][ROW_BUF_MAX] =
{
"#define GPIO_REG_NONE_VAL						0x0000u  /* none register */\n"
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_ACTIVE_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_ACTIVE_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_ACTIVE_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_ACTIVE_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_ACTIVE_VAL                  0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

/* RESET */
const U8 PmcStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_RESET_VAL ",
	"#define GPIO_PMC8_RESET_VAL ",
	"#define GPIO_PMC9_RESET_VAL ",
	"#define GPIO_PMC10_RESET_VAL",
	"#define GPIO_PMC11_RESET_VAL",
	"#define GPIO_JPMC0_RESET_VAL",
};

const U8 PmStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_RESET_VAL ",
	"#define GPIO_PM8_RESET_VAL ",
	"#define GPIO_PM9_RESET_VAL ",
	"#define GPIO_PM10_RESET_VAL",
	"#define GPIO_PM11_RESET_VAL",
	"#define GPIO_APM0_RESET_VAL",
	"#define GPIO_JPM0_RESET_VAL",
};

const U8 PibcStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_RESET_VAL ",
	"#define GPIO_PIBC8_RESET_VAL ",
	"#define GPIO_PIBC9_RESET_VAL ",
	"#define GPIO_PIBC10_RESET_VAL",
	"#define GPIO_PIBC11_RESET_VAL",
	"#define GPIO_APIBC0_RESET_VAL",
	"#define GPIO_JPIBC0_RESET_VAL",
};

const U8 PbdcStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_RESET_VAL ",
	"#define GPIO_PBDC8_RESET_VAL ",
	"#define GPIO_PBDC9_RESET_VAL ",
	"#define GPIO_PBDC10_RESET_VAL",
	"#define GPIO_PBDC11_RESET_VAL",
	"#define GPIO_APBDC0_RESET_VAL",
	"#define GPIO_JPBDC0_RESET_VAL",
};

const U8 PuStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_RESET_VAL ",
	"#define GPIO_PU8_RESET_VAL ",
	"#define GPIO_PU9_RESET_VAL ",
	"#define GPIO_PU10_RESET_VAL",
	"#define GPIO_PU11_RESET_VAL",
	"#define GPIO_APU0_RESET_VAL",
	"#define GPIO_JPU0_RESET_VAL",
};

const U8 PdStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_RESET_VAL ",
	"#define GPIO_PD8_RESET_VAL ",
	"#define GPIO_PD9_RESET_VAL ",
	"#define GPIO_PD10_RESET_VAL",
	"#define GPIO_PD11_RESET_VAL",
	"#define GPIO_APD0_RESET_VAL",
	"#define GPIO_JPD0_RESET_VAL",
};

const U8 PdscStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_RESET_VAL ",
	"#define GPIO_PDSC8_RESET_VAL ",
	"#define GPIO_PDSC9_RESET_VAL ",
	"#define GPIO_PDSC10_RESET_VAL",
	"#define GPIO_PDSC11_RESET_VAL",
};

const U8 PodcStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_RESET_VAL ",
	"#define GPIO_PODC8_RESET_VAL ",
	"#define GPIO_PODC9_RESET_VAL ",
	"#define GPIO_PODC10_RESET_VAL",
	"#define GPIO_PODC11_RESET_VAL",
	"#define GPIO_APODC0_RESET_VAL",
	"#define GPIO_JPODC0_RESET_VAL",
};

const U8 PStringReset_100[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_RESET_VAL ",
	"#define GPIO_P8_RESET_VAL ",
	"#define GPIO_P9_RESET_VAL ",
	"#define GPIO_P10_RESET_VAL",
	"#define GPIO_P11_RESET_VAL",
	"#define GPIO_JP0_RESET_VAL",
	"#define GPIO_AP0_RESET_VAL",
};

const U8 AlternativeReset_100[6][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_RESET_VAL  ",
		"#define GPIO_PFCE0_RESET_VAL ",
		"#define GPIO_PFCAE0_RESET_VAL",
	},
	{
		"#define GPIO_PFC8_RESET_VAL  ",
		"#define GPIO_PFCE8_RESET_VAL ",
		"#define GPIO_PFCAE8_RESET_VAL",
	},
	{
		"#define GPIO_PFC9_RESET_VAL  ",
		"#define GPIO_PFCE9_RESET_VAL ",
		"#define GPIO_PFCAE9_RESET_VAL",
	},
	{
		"#define GPIO_PFC10_RESET_VAL  ",
		"#define GPIO_PFCE10_RESET_VAL ",
		"#define GPIO_PFCAE10_RESET_VAL",
	},
	{
		"#define GPIO_PFC11_RESET_VAL  ",
		"#define GPIO_PFCE11_RESET_VAL ",
		"#define GPIO_PFCAE11_RESET_VAL",
	},
	{
		"#define GPIO_JPFC0_RESET_VAL  ",
		"#define GPIO_JPFCE0_RESET_VAL ",
		"#define GPIO_JPFCAE0_RESET_VAL",
	}
};

const U8 PipcStringReset_100[][ROW_BUF_MAX] =
{
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_RESET_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_RESET_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_RESET_VAL                  0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

/* STANDBY */
const U8 PmcStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_STANDBY_VAL ",
	"#define GPIO_PMC8_STANDBY_VAL ",
	"#define GPIO_PMC9_STANDBY_VAL ",
	"#define GPIO_PMC10_STANDBY_VAL",
	"#define GPIO_PMC11_STANDBY_VAL",
	"#define GPIO_JPMC0_STANDBY_VAL",
};

const U8 PmStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_STANDBY_VAL ",
	"#define GPIO_PM8_STANDBY_VAL ",
	"#define GPIO_PM9_STANDBY_VAL ",
	"#define GPIO_PM10_STANDBY_VAL",
	"#define GPIO_PM11_STANDBY_VAL",
	"#define GPIO_APM0_STANDBY_VAL",
	"#define GPIO_JPM0_STANDBY_VAL",
};

const U8 PibcStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_STANDBY_VAL ",
	"#define GPIO_PIBC8_STANDBY_VAL ",
	"#define GPIO_PIBC9_STANDBY_VAL ",
	"#define GPIO_PIBC10_STANDBY_VAL",
	"#define GPIO_PIBC11_STANDBY_VAL",
	"#define GPIO_APIBC0_STANDBY_VAL",
	"#define GPIO_JPIBC0_STANDBY_VAL",
};

const U8 PbdcStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_STANDBY_VAL ",
	"#define GPIO_PBDC8_STANDBY_VAL ",
	"#define GPIO_PBDC9_STANDBY_VAL ",
	"#define GPIO_PBDC10_STANDBY_VAL",
	"#define GPIO_PBDC11_STANDBY_VAL",
	"#define GPIO_APBDC0_STANDBY_VAL",
	"#define GPIO_JPBDC0_STANDBY_VAL",
};

const U8 PuStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_STANDBY_VAL ",
	"#define GPIO_PU8_STANDBY_VAL ",
	"#define GPIO_PU9_STANDBY_VAL ",
	"#define GPIO_PU10_STANDBY_VAL",
	"#define GPIO_PU11_STANDBY_VAL",
	"#define GPIO_APU0_STANDBY_VAL",
	"#define GPIO_JPU0_STANDBY_VAL",
};

const U8 PdStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_STANDBY_VAL ",
	"#define GPIO_PD8_STANDBY_VAL ",
	"#define GPIO_PD9_STANDBY_VAL ",
	"#define GPIO_PD10_STANDBY_VAL",
	"#define GPIO_PD11_STANDBY_VAL",
	"#define GPIO_APD0_STANDBY_VAL",
	"#define GPIO_JPD0_STANDBY_VAL",
};

const U8 PdscStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_STANDBY_VAL ",
	"#define GPIO_PDSC8_STANDBY_VAL ",
	"#define GPIO_PDSC9_STANDBY_VAL ",
	"#define GPIO_PDSC10_STANDBY_VAL",
	"#define GPIO_PDSC11_STANDBY_VAL",
};

const U8 PodcStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_STANDBY_VAL ",
	"#define GPIO_PODC8_STANDBY_VAL ",
	"#define GPIO_PODC9_STANDBY_VAL ",
	"#define GPIO_PODC10_STANDBY_VAL",
	"#define GPIO_PODC11_STANDBY_VAL",
	"#define GPIO_APODC0_STANDBY_VAL",
	"#define GPIO_JPODC0_STANDBY_VAL",
};

const U8 PStringStandby_100[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_STANDBY_VAL ",
	"#define GPIO_P8_STANDBY_VAL ",
	"#define GPIO_P9_STANDBY_VAL ",
	"#define GPIO_P10_STANDBY_VAL",
	"#define GPIO_P11_STANDBY_VAL",
	"#define GPIO_JP0_STANDBY_VAL",
	"#define GPIO_AP0_STANDBY_VAL",
};

const U8 AlternativeStandby_100[6][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_STANDBY_VAL  ",
		"#define GPIO_PFCE0_STANDBY_VAL ",
		"#define GPIO_PFCAE0_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC8_STANDBY_VAL  ",
		"#define GPIO_PFCE8_STANDBY_VAL ",
		"#define GPIO_PFCAE8_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC9_STANDBY_VAL  ",
		"#define GPIO_PFCE9_STANDBY_VAL ",
		"#define GPIO_PFCAE9_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC10_STANDBY_VAL  ",
		"#define GPIO_PFCE10_STANDBY_VAL ",
		"#define GPIO_PFCAE10_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC11_STANDBY_VAL  ",
		"#define GPIO_PFCE11_STANDBY_VAL ",
		"#define GPIO_PFCAE11_STANDBY_VAL",
	},
	{
		"#define GPIO_JPFC0_STANDBY_VAL  ",
		"#define GPIO_JPFCE0_STANDBY_VAL ",
		"#define GPIO_JPFCAE0_STANDBY_VAL",
	}
};

const U8 PipcStringStandby_100[][ROW_BUF_MAX] =
{
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_STANDBY_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_STANDBY_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_STANDBY_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_STANDBY_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_STANDBY_VAL                  0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

_MacroStr MacroStrActive_100[] = 
{
    PmcStringActive_100,
    PmStringActive_100,
    PibcStringActive_100,
    PbdcStringActive_100,
    PuStringActive_100,
    PdStringActive_100,
    PdscStringActive_100,
    PodcStringActive_100,
    PStringActive_100,
    AlternativeActive_100,
    PipcStringActive_100,
};

_MacroStr MacroStrStandby_100[] =
{
    PmcStringStandby_100,
    PmStringStandby_100,
    PibcStringStandby_100,
    PbdcStringStandby_100,
    PuStringStandby_100,
    PdStringStandby_100,
    PdscStringStandby_100,
    PodcStringStandby_100,
    PStringStandby_100,
    AlternativeStandby_100,
    PipcStringStandby_100,
};

_MacroStr MacroStrReset_100[] =
{
    PmcStringReset_100,
    PmStringReset_100,
    PibcStringReset_100,
    PbdcStringReset_100,
    PuStringReset_100,
    PdStringReset_100,
    PdscStringReset_100,
    PodcStringReset_100,
    PStringReset_100,
    AlternativeReset_100,
    PipcStringReset_100,
};



/* ACTIVE */
const U8 PmcStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_ACTIVE_VAL ",
    "#define GPIO_PMC1_ACTIVE_VAL ",
	"#define GPIO_PMC8_ACTIVE_VAL ",
	"#define GPIO_PMC9_ACTIVE_VAL ",
	"#define GPIO_PMC10_ACTIVE_VAL",
	"#define GPIO_PMC11_ACTIVE_VAL",
	"#define GPIO_PMC12_ACTIVE_VAL",
	"#define GPIO_PMC18_ACTIVE_VAL",
	"#define GPIO_PMC20_ACTIVE_VAL",
	"#define GPIO_JPMC0_ACTIVE_VAL",
};

const U8 PmStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_ACTIVE_VAL ",
    "#define GPIO_PM1_ACTIVE_VAL ",
	"#define GPIO_PM8_ACTIVE_VAL ",
	"#define GPIO_PM9_ACTIVE_VAL ",
	"#define GPIO_PM10_ACTIVE_VAL",
	"#define GPIO_PM11_ACTIVE_VAL",
	"#define GPIO_PM12_ACTIVE_VAL",
	"#define GPIO_PM18_ACTIVE_VAL",
	"#define GPIO_PM20_ACTIVE_VAL",
	"#define GPIO_JPM0_ACTIVE_VAL",
    "#define GPIO_APM0_ACTIVE_VAL",
	"#define GPIO_APM1_ACTIVE_VAL",
};

const U8 PibcStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_ACTIVE_VAL ",
    "#define GPIO_PIBC1_ACTIVE_VAL ",
	"#define GPIO_PIBC8_ACTIVE_VAL ",
	"#define GPIO_PIBC9_ACTIVE_VAL ",
	"#define GPIO_PIBC10_ACTIVE_VAL",
	"#define GPIO_PIBC11_ACTIVE_VAL ",
	"#define GPIO_PIBC12_ACTIVE_VAL ",
	"#define GPIO_PIBC18_ACTIVE_VAL ",
	"#define GPIO_PIBC20_ACTIVE_VAL ",
	"#define GPIO_JPIBC0_ACTIVE_VAL",
	"#define GPIO_APIBC0_ACTIVE_VAL",
	"#define GPIO_APIBC1_ACTIVE_VAL",
};

const U8 PbdcStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_ACTIVE_VAL ",
    "#define GPIO_PBDC1_ACTIVE_VAL ",
	"#define GPIO_PBDC8_ACTIVE_VAL ",
	"#define GPIO_PBDC9_ACTIVE_VAL ",
	"#define GPIO_PBDC10_ACTIVE_VAL",
	"#define GPIO_PBDC11_ACTIVE_VAL",
	"#define GPIO_PBDC12_ACTIVE_VAL ",
	"#define GPIO_PBDC18_ACTIVE_VAL ",
	"#define GPIO_PBDC20_ACTIVE_VAL ",
	"#define GPIO_JPBDC0_ACTIVE_VAL",
    "#define GPIO_APBDC0_ACTIVE_VAL",
	"#define GPIO_APBDC1_ACTIVE_VAL",
};

const U8 PuStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_ACTIVE_VAL ",
    "#define GPIO_PU1_ACTIVE_VAL ",
	"#define GPIO_PU8_ACTIVE_VAL ",
	"#define GPIO_PU9_ACTIVE_VAL ",
	"#define GPIO_PU10_ACTIVE_VAL",
	"#define GPIO_PU11_ACTIVE_VAL",
	"#define GPIO_PU12_ACTIVE_VAL",
	"#define GPIO_PU18_ACTIVE_VAL",
	"#define GPIO_PU20_ACTIVE_VAL",
	"#define GPIO_APU0_ACTIVE_VAL",
	"#define GPIO_APU1_ACTIVE_VAL",
	"#define GPIO_JPU0_ACTIVE_VAL",
};

const U8 PdStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_ACTIVE_VAL ",
    "#define GPIO_PD1_ACTIVE_VAL ",
	"#define GPIO_PD8_ACTIVE_VAL ",
	"#define GPIO_PD9_ACTIVE_VAL ",
	"#define GPIO_PD10_ACTIVE_VAL",
	"#define GPIO_PD11_ACTIVE_VAL",
	"#define GPIO_PD12_ACTIVE_VAL",
	"#define GPIO_PD18_ACTIVE_VAL",
	"#define GPIO_PD20_ACTIVE_VAL",
	"#define GPIO_APD0_ACTIVE_VAL",
	"#define GPIO_APD1_ACTIVE_VAL",
	"#define GPIO_JPD0_ACTIVE_VAL",
};

const U8 PdscStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_ACTIVE_VAL ",
    "#define GPIO_PDSC1_ACTIVE_VAL ",
	"#define GPIO_PDSC8_ACTIVE_VAL ",
	"#define GPIO_PDSC9_ACTIVE_VAL ",
	"#define GPIO_PDSC10_ACTIVE_VAL",
	"#define GPIO_PDSC11_ACTIVE_VAL",
	"#define GPIO_PDSC12_ACTIVE_VAL",
	"#define GPIO_PDSC18_ACTIVE_VAL",
	"#define GPIO_PDSC20_ACTIVE_VAL",
};

const U8 PodcStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_ACTIVE_VAL ",
    "#define GPIO_PODC1_ACTIVE_VAL ",
	"#define GPIO_PODC8_ACTIVE_VAL ",
	"#define GPIO_PODC9_ACTIVE_VAL ",
	"#define GPIO_PODC10_ACTIVE_VAL",
	"#define GPIO_PODC11_ACTIVE_VAL",
	"#define GPIO_PODC12_ACTIVE_VAL",
	"#define GPIO_PODC18_ACTIVE_VAL",
	"#define GPIO_PODC20_ACTIVE_VAL",
	"#define GPIO_APODC0_ACTIVE_VAL",
	"#define GPIO_APODC1_ACTIVE_VAL",
	"#define GPIO_JPODC0_ACTIVE_VAL",
};

const U8 PStringActive_144[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_ACTIVE_VAL ",
    "#define GPIO_P1_ACTIVE_VAL ",
	"#define GPIO_P8_ACTIVE_VAL ",
	"#define GPIO_P9_ACTIVE_VAL ",
	"#define GPIO_P10_ACTIVE_VAL",
	"#define GPIO_P11_ACTIVE_VAL",
	"#define GPIO_P12_ACTIVE_VAL",
	"#define GPIO_P18_ACTIVE_VAL",
	"#define GPIO_P20_ACTIVE_VAL",
	"#define GPIO_JP0_ACTIVE_VAL",
	"#define GPIO_AP0_ACTIVE_VAL",
	"#define GPIO_AP1_ACTIVE_VAL",
};

const U8 AlternativeActive_144[10][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_ACTIVE_VAL  ",
		"#define GPIO_PFCE0_ACTIVE_VAL ",
		"#define GPIO_PFCAE0_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC1_ACTIVE_VAL  ",
		"#define GPIO_PFCE1_ACTIVE_VAL ",
		"#define GPIO_PFCAE1_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC8_ACTIVE_VAL  ",
		"#define GPIO_PFCE8_ACTIVE_VAL ",
		"#define GPIO_PFCAE8_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC9_ACTIVE_VAL  ",
		"#define GPIO_PFCE9_ACTIVE_VAL ",
		"#define GPIO_PFCAE9_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC10_ACTIVE_VAL  ",
		"#define GPIO_PFCE10_ACTIVE_VAL ",
		"#define GPIO_PFCAE10_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC11_ACTIVE_VAL  ",
		"#define GPIO_PFCE11_ACTIVE_VAL ",
		"#define GPIO_PFCAE11_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC12_ACTIVE_VAL  ",
		"#define GPIO_PFCE12_ACTIVE_VAL ",
		"#define GPIO_PFCAE12_ACTIVE_VAL",
	},
	{
		"#define GPIO_PFC18_ACTIVE_VAL  ",
		"#define GPIO_PFCE18_ACTIVE_VAL ",
		"#define GPIO_PFCAE18_ACTIVE_VAL",
	},
    {
		"#define GPIO_PFC20_ACTIVE_VAL  ",
		"#define GPIO_PFCE20_ACTIVE_VAL ",
		"#define GPIO_PFCAE20_ACTIVE_VAL",
	},
	{
		"#define GPIO_JPFC0_ACTIVE_VAL  ",
		"#define GPIO_JPFCE0_ACTIVE_VAL ",
		"#define GPIO_JPFCAE0_ACTIVE_VAL",
	}
};

const U8 PipcStringActive_144[][ROW_BUF_MAX] =
{
"#define GPIO_REG_NONE_VAL						0x0000u  /* none register */\n"
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_ACTIVE_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC1_ACTIVE_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_ACTIVE_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_ACTIVE_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_ACTIVE_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_ACTIVE_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC12_ACTIVE_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC18_ACTIVE_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC20_ACTIVE_VAL                  0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

/* RESET */
const U8 PmcStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_RESET_VAL ",
    "#define GPIO_PMC1_RESET_VAL ",
	"#define GPIO_PMC8_RESET_VAL ",
	"#define GPIO_PMC9_RESET_VAL ",
	"#define GPIO_PMC10_RESET_VAL",
	"#define GPIO_PMC11_RESET_VAL",
	"#define GPIO_PMC12_RESET_VAL",
	"#define GPIO_PMC18_RESET_VAL",
	"#define GPIO_PMC20_RESET_VAL",
	"#define GPIO_JPMC0_RESET_VAL",
};

const U8 PmStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_RESET_VAL ",
    "#define GPIO_PM1_RESET_VAL ",
	"#define GPIO_PM8_RESET_VAL ",
	"#define GPIO_PM9_RESET_VAL ",
	"#define GPIO_PM10_RESET_VAL",
	"#define GPIO_PM11_RESET_VAL",
	"#define GPIO_PM12_RESET_VAL",
	"#define GPIO_PM18_RESET_VAL",
	"#define GPIO_PM20_RESET_VAL",
	"#define GPIO_APM0_RESET_VAL",
	"#define GPIO_APM1_RESET_VAL",
	"#define GPIO_JPM0_RESET_VAL",
};

const U8 PibcStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_RESET_VAL ",
    "#define GPIO_PIBC1_RESET_VAL ",
	"#define GPIO_PIBC8_RESET_VAL ",
	"#define GPIO_PIBC9_RESET_VAL ",
	"#define GPIO_PIBC10_RESET_VAL",
	"#define GPIO_PIBC11_RESET_VAL",
	"#define GPIO_PIBC12_RESET_VAL",
	"#define GPIO_PIBC18_RESET_VAL",
	"#define GPIO_PIBC20_RESET_VAL",
	"#define GPIO_APIBC0_RESET_VAL",
	"#define GPIO_APIBC1_RESET_VAL",
	"#define GPIO_JPIBC0_RESET_VAL",
};

const U8 PbdcStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_RESET_VAL ",
    "#define GPIO_PBDC1_RESET_VAL ",
	"#define GPIO_PBDC8_RESET_VAL ",
	"#define GPIO_PBDC9_RESET_VAL ",
	"#define GPIO_PBDC10_RESET_VAL",
	"#define GPIO_PBDC11_RESET_VAL",
	"#define GPIO_PBDC12_RESET_VAL",
	"#define GPIO_PBDC18_RESET_VAL",
	"#define GPIO_PBDC20_RESET_VAL",
	"#define GPIO_APBDC0_RESET_VAL",
	"#define GPIO_APBDC1_RESET_VAL",
	"#define GPIO_JPBDC0_RESET_VAL",
};

const U8 PuStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_RESET_VAL ",
    "#define GPIO_PU1_RESET_VAL ",
	"#define GPIO_PU8_RESET_VAL ",
	"#define GPIO_PU9_RESET_VAL ",
	"#define GPIO_PU10_RESET_VAL",
	"#define GPIO_PU11_RESET_VAL",
	"#define GPIO_PU12_RESET_VAL",
	"#define GPIO_PU18_RESET_VAL",
	"#define GPIO_PU20_RESET_VAL",
	"#define GPIO_APU0_RESET_VAL",
	"#define GPIO_APU1_RESET_VAL",
	"#define GPIO_JPU0_RESET_VAL",
};

const U8 PdStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_RESET_VAL ",
    "#define GPIO_PD1_RESET_VAL ",
	"#define GPIO_PD8_RESET_VAL ",
	"#define GPIO_PD9_RESET_VAL ",
	"#define GPIO_PD10_RESET_VAL",
	"#define GPIO_PD11_RESET_VAL",
	"#define GPIO_PD12_RESET_VAL",
	"#define GPIO_PD18_RESET_VAL",
	"#define GPIO_PD20_RESET_VAL",
	"#define GPIO_APD0_RESET_VAL",
	"#define GPIO_APD1_RESET_VAL",
	"#define GPIO_JPD0_RESET_VAL",
};

const U8 PdscStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_RESET_VAL ",
    "#define GPIO_PDSC1_RESET_VAL ",
	"#define GPIO_PDSC8_RESET_VAL ",
	"#define GPIO_PDSC9_RESET_VAL ",
	"#define GPIO_PDSC10_RESET_VAL",
	"#define GPIO_PDSC11_RESET_VAL",
	"#define GPIO_PDSC12_RESET_VAL",
	"#define GPIO_PDSC18_RESET_VAL",
	"#define GPIO_PDSC20_RESET_VAL",
};

const U8 PodcStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_RESET_VAL ",
    "#define GPIO_PODC1_RESET_VAL ",
	"#define GPIO_PODC8_RESET_VAL ",
	"#define GPIO_PODC9_RESET_VAL ",
	"#define GPIO_PODC10_RESET_VAL",
	"#define GPIO_PODC11_RESET_VAL",
	"#define GPIO_PODC12_RESET_VAL",
	"#define GPIO_PODC18_RESET_VAL",
	"#define GPIO_PODC20_RESET_VAL",
	"#define GPIO_APODC0_RESET_VAL",
	"#define GPIO_APODC1_RESET_VAL",
	"#define GPIO_JPODC0_RESET_VAL",
};

const U8 PStringReset_144[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_RESET_VAL ",
    "#define GPIO_P1_RESET_VAL ",
	"#define GPIO_P8_RESET_VAL ",
	"#define GPIO_P9_RESET_VAL ",
	"#define GPIO_P10_RESET_VAL",
	"#define GPIO_P11_RESET_VAL",
	"#define GPIO_P12_RESET_VAL",
	"#define GPIO_P18_RESET_VAL",
	"#define GPIO_P20_RESET_VAL",
	"#define GPIO_JP0_RESET_VAL",
	"#define GPIO_AP0_RESET_VAL",
	"#define GPIO_AP1_RESET_VAL",
};

const U8 AlternativeReset_144[10][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_RESET_VAL  ",
		"#define GPIO_PFCE0_RESET_VAL ",
		"#define GPIO_PFCAE0_RESET_VAL",
	},
	{
		"#define GPIO_PFC1_RESET_VAL  ",
		"#define GPIO_PFCE1_RESET_VAL ",
		"#define GPIO_PFCAE1_RESET_VAL",
	},
	{
		"#define GPIO_PFC8_RESET_VAL  ",
		"#define GPIO_PFCE8_RESET_VAL ",
		"#define GPIO_PFCAE8_RESET_VAL",
	},
	{
		"#define GPIO_PFC9_RESET_VAL  ",
		"#define GPIO_PFCE9_RESET_VAL ",
		"#define GPIO_PFCAE9_RESET_VAL",
	},
	{
		"#define GPIO_PFC10_RESET_VAL  ",
		"#define GPIO_PFCE10_RESET_VAL ",
		"#define GPIO_PFCAE10_RESET_VAL",
	},
	{
		"#define GPIO_PFC11_RESET_VAL  ",
		"#define GPIO_PFCE11_RESET_VAL ",
		"#define GPIO_PFCAE11_RESET_VAL",
	},
	{
		"#define GPIO_PFC12_RESET_VAL  ",
		"#define GPIO_PFCE12_RESET_VAL ",
		"#define GPIO_PFCAE12_RESET_VAL",
	},
	{
		"#define GPIO_PFC18_RESET_VAL  ",
		"#define GPIO_PFCE18_RESET_VAL ",
		"#define GPIO_PFCAE18_RESET_VAL",
	},
	{
		"#define GPIO_PFC20_RESET_VAL  ",
		"#define GPIO_PFCE20_RESET_VAL ",
		"#define GPIO_PFCAE20_RESET_VAL",
	},
	{
		"#define GPIO_JPFC0_RESET_VAL  ",
		"#define GPIO_JPFCE0_RESET_VAL ",
		"#define GPIO_JPFCAE0_RESET_VAL",
	}
};

const U8 PipcStringReset_144[][ROW_BUF_MAX] =
{
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_RESET_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC1_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_RESET_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_RESET_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC12_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC18_RESET_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC20_RESET_VAL                   0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

/* STANDBY */
const U8 PmcStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_STANDBY_VAL ",
	"#define GPIO_PMC1_STANDBY_VAL ",
	"#define GPIO_PMC8_STANDBY_VAL ",
	"#define GPIO_PMC9_STANDBY_VAL ",
	"#define GPIO_PMC10_STANDBY_VAL",
	"#define GPIO_PMC11_STANDBY_VAL",
	"#define GPIO_PMC12_STANDBY_VAL",
	"#define GPIO_PMC18_STANDBY_VAL",
	"#define GPIO_PMC20_STANDBY_VAL",
	"#define GPIO_JPMC0_STANDBY_VAL",
};

const U8 PmStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_STANDBY_VAL ",
    "#define GPIO_PM1_STANDBY_VAL ",
	"#define GPIO_PM8_STANDBY_VAL ",
	"#define GPIO_PM9_STANDBY_VAL ",
	"#define GPIO_PM10_STANDBY_VAL",
	"#define GPIO_PM11_STANDBY_VAL",
	"#define GPIO_PM12_STANDBY_VAL",
	"#define GPIO_PM18_STANDBY_VAL",
	"#define GPIO_PM20_STANDBY_VAL",
	"#define GPIO_APM0_STANDBY_VAL",
	"#define GPIO_APM1_STANDBY_VAL",
	"#define GPIO_JPM0_STANDBY_VAL",
};

const U8 PibcStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_STANDBY_VAL ",
    "#define GPIO_PIBC1_STANDBY_VAL ",
	"#define GPIO_PIBC8_STANDBY_VAL ",
	"#define GPIO_PIBC9_STANDBY_VAL ",
	"#define GPIO_PIBC10_STANDBY_VAL",
	"#define GPIO_PIBC11_STANDBY_VAL",
	"#define GPIO_PIBC12_STANDBY_VAL",
	"#define GPIO_PIBC18_STANDBY_VAL",
	"#define GPIO_PIBC20_STANDBY_VAL",
	"#define GPIO_APIBC0_STANDBY_VAL",
	"#define GPIO_APIBC1_STANDBY_VAL",
	"#define GPIO_JPIBC0_STANDBY_VAL",
};

const U8 PbdcStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_STANDBY_VAL ",
    "#define GPIO_PBDC1_STANDBY_VAL ",
	"#define GPIO_PBDC8_STANDBY_VAL ",
	"#define GPIO_PBDC9_STANDBY_VAL ",
	"#define GPIO_PBDC10_STANDBY_VAL",
	"#define GPIO_PBDC11_STANDBY_VAL",
	"#define GPIO_PBDC12_STANDBY_VAL",
	"#define GPIO_PBDC18_STANDBY_VAL",
	"#define GPIO_PBDC20_STANDBY_VAL",
	"#define GPIO_APBDC0_STANDBY_VAL",
	"#define GPIO_APBDC1_STANDBY_VAL",
	"#define GPIO_JPBDC0_STANDBY_VAL",
};

const U8 PuStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_STANDBY_VAL ",
    "#define GPIO_PU1_STANDBY_VAL ",
	"#define GPIO_PU8_STANDBY_VAL ",
	"#define GPIO_PU9_STANDBY_VAL ",
	"#define GPIO_PU10_STANDBY_VAL",
	"#define GPIO_PU11_STANDBY_VAL",
	"#define GPIO_PU12_STANDBY_VAL",
	"#define GPIO_PU18_STANDBY_VAL",
	"#define GPIO_PU20_STANDBY_VAL",
	"#define GPIO_APU0_STANDBY_VAL",
	"#define GPIO_APU1_STANDBY_VAL",
	"#define GPIO_JPU0_STANDBY_VAL",
};

const U8 PdStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_STANDBY_VAL ",
    "#define GPIO_PD1_STANDBY_VAL ",
	"#define GPIO_PD8_STANDBY_VAL ",
	"#define GPIO_PD9_STANDBY_VAL ",
	"#define GPIO_PD10_STANDBY_VAL",
	"#define GPIO_PD11_STANDBY_VAL",
	"#define GPIO_PD12_STANDBY_VAL",
	"#define GPIO_PD18_STANDBY_VAL",
	"#define GPIO_PD20_STANDBY_VAL",
	"#define GPIO_APD0_STANDBY_VAL",
	"#define GPIO_APD1_STANDBY_VAL",
	"#define GPIO_JPD0_STANDBY_VAL",
};

const U8 PdscStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_STANDBY_VAL ",
    "#define GPIO_PDSC1_STANDBY_VAL ",
	"#define GPIO_PDSC8_STANDBY_VAL ",
	"#define GPIO_PDSC9_STANDBY_VAL ",
	"#define GPIO_PDSC10_STANDBY_VAL",
	"#define GPIO_PDSC11_STANDBY_VAL",
	"#define GPIO_PDSC12_STANDBY_VAL",
	"#define GPIO_PDSC18_STANDBY_VAL",
	"#define GPIO_PDSC20_STANDBY_VAL",
};

const U8 PodcStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_STANDBY_VAL ",
    "#define GPIO_PODC1_STANDBY_VAL ",
	"#define GPIO_PODC8_STANDBY_VAL ",
	"#define GPIO_PODC9_STANDBY_VAL ",
	"#define GPIO_PODC10_STANDBY_VAL",
	"#define GPIO_PODC11_STANDBY_VAL",
	"#define GPIO_PODC12_STANDBY_VAL",
	"#define GPIO_PODC18_STANDBY_VAL",
	"#define GPIO_PODC20_STANDBY_VAL",
	"#define GPIO_APODC0_STANDBY_VAL",
	"#define GPIO_APODC1_STANDBY_VAL",
	"#define GPIO_JPODC0_STANDBY_VAL",
};

const U8 PStringStandby_144[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_STANDBY_VAL ",
    "#define GPIO_P1_STANDBY_VAL ",
	"#define GPIO_P8_STANDBY_VAL ",
	"#define GPIO_P9_STANDBY_VAL ",
	"#define GPIO_P10_STANDBY_VAL",
	"#define GPIO_P11_STANDBY_VAL",
	"#define GPIO_P12_STANDBY_VAL",
	"#define GPIO_P18_STANDBY_VAL",
	"#define GPIO_P20_STANDBY_VAL",
	"#define GPIO_JP0_STANDBY_VAL",
	"#define GPIO_AP0_STANDBY_VAL",
	"#define GPIO_AP1_STANDBY_VAL",
};

const U8 AlternativeStandby_144[10][3][ROW_BUF_MAX] =
{
	{
		"#define GPIO_PFC0_STANDBY_VAL  ",
		"#define GPIO_PFCE0_STANDBY_VAL ",
		"#define GPIO_PFCAE0_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC1_STANDBY_VAL  ",
		"#define GPIO_PFCE1_STANDBY_VAL ",
		"#define GPIO_PFCAE1_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC8_STANDBY_VAL  ",
		"#define GPIO_PFCE8_STANDBY_VAL ",
		"#define GPIO_PFCAE8_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC9_STANDBY_VAL  ",
		"#define GPIO_PFCE9_STANDBY_VAL ",
		"#define GPIO_PFCAE9_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC10_STANDBY_VAL  ",
		"#define GPIO_PFCE10_STANDBY_VAL ",
		"#define GPIO_PFCAE10_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC11_STANDBY_VAL  ",
		"#define GPIO_PFCE11_STANDBY_VAL ",
		"#define GPIO_PFCAE11_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC12_STANDBY_VAL  ",
		"#define GPIO_PFCE12_STANDBY_VAL ",
		"#define GPIO_PFCAE12_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC18_STANDBY_VAL  ",
		"#define GPIO_PFCE18_STANDBY_VAL ",
		"#define GPIO_PFCAE18_STANDBY_VAL",
	},
	{
		"#define GPIO_PFC20_STANDBY_VAL  ",
		"#define GPIO_PFCE20_STANDBY_VAL ",
		"#define GPIO_PFCAE20_STANDBY_VAL",
	},
	{
		"#define GPIO_JPFC0_STANDBY_VAL  ",
		"#define GPIO_JPFCE0_STANDBY_VAL ",
		"#define GPIO_JPFCAE0_STANDBY_VAL",
	}
};

const U8 PipcStringStandby_144[][ROW_BUF_MAX] =
{
"                                                                 \n"
"                                                                 \n"
"/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */ \n"
"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 1  1  0  0 */      \n"
"#define GPIO_PIPC0_STANDBY_VAL                   0x000C           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC1_STANDBY_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC8_STANDBY_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC9_STANDBY_VAL                   0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC10_STANDBY_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC11_STANDBY_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC12_STANDBY_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC18_STANDBY_VAL                  0x0000           \n"
"                                                                 \n"
"/* 0  0  0  0  || 0  0  0  0 || 0  0  0  0 || 0  0  0  0 */      \n"
"#define GPIO_PIPC20_STANDBY_VAL                  0x0000           \n"
"//no Jtag                                                        \n"
"//no Anolog                                                      \n"
"                                                                 \n"
"                                                                 \n"
"																  \n"
};

_MacroStr MacroStrActive_144[] = 
{
    PmcStringActive_144,
    PmStringActive_144,
    PibcStringActive_144,
    PbdcStringActive_144,
    PuStringActive_144,
    PdStringActive_144,
    PdscStringActive_144,
    PodcStringActive_144,
    PStringActive_144,
    AlternativeActive_144,
    PipcStringActive_144,
};

_MacroStr MacroStrStandby_144[] =
{
    PmcStringStandby_144,
    PmStringStandby_144,
    PibcStringStandby_144,
    PbdcStringStandby_144,
    PuStringStandby_144,
    PdStringStandby_144,
    PdscStringStandby_144,
    PodcStringStandby_144,
    PStringStandby_144,
    AlternativeStandby_144,
    PipcStringStandby_144,
};

_MacroStr MacroStrReset_144[] =
{
    PmcStringReset_144,
    PmStringReset_144,
    PibcStringReset_144,
    PbdcStringReset_144,
    PuStringReset_144,
    PdStringReset_144,
    PdscStringReset_144,
    PodcStringReset_144,
    PStringReset_144,
    AlternativeReset_144,
    PipcStringReset_144,
};



/*****************************************************************************
 *  Name        : GenPinmux_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenPinmux(void)
{
    if (Pin_Type == Pin_100)
    {
        char* title = {
		"/***********************************************************************\n"
		"*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *\n"
		"*                All Rights Reserved.                                  *\n"
		"*   Department  : ITTI                                                 *\n"
		"*   AUTHOR      : uidp5021                                             *\n"
		"************************************************************************\n"
		"* Object        :                                                       \n"
		"* Module        :                                                       \n"
		"* Instance      :                                                       \n"
		"* Description   :                                                       \n"
		"*-----------------------------------------------------------------------\n"
		"* Version:                                                              \n"
		"* Date:                                                                 \n"
		"* Author:                                                               \n"
		"***********************************************************************/\n"
		"/*-History--------------------------------------------------------------\n"
		"* Version       Date    Name    Changes and comment__DSB__DSBs          \n"
		"------------------------------------------------------------------------\n"
		"* 0.1	   Jun 26,2016   PEI Jingli  Initial version                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.2	   Jun 29,2016   LIU Chenxi  Correct errors during merging		 \n"
		"------------------------------------------------------------------------\n"
		"* 0.3	   July 07,2016  PEI Jingli  Adapt xxpin MCU                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.4	   Oct 24,2016  PEI Jingli   Config reset parameters,            \n"
		"                                p0_6 as general io when active and reset\n"
		"------------------------------------------------------------------------\n"
		"* 0.5     Nov 10,2016  PEI Jingli    Set standby paramters              \n"
		"------------------------------------------------------------------------\n"
		"* 0.6     Nov 17,2016  PEI Jingli    Add Pn register for default setting\n"
		"*=====================================================================*/\n"
		"#ifndef _PIN_MAP_CC_H                                                   \n"
		"#define _PIN_MAP_CC_H                                                   \n"
		"#include \"CONFIG.H\"                                                     \n"
		"#include \"SystemMode_Cfg.h\"                                             \n"
		"                                                                        \n"
		"                                                                        \n"
		"/*--------------------configration method----------------------         \n"
		"* 1. independent IO                                                     \n"
		"    PMCn:bit=0 -> PMn                                                   \n"
		"                         1:input  -> PIBCn=1,PUn,PDn                    \n"
		"                                                                        \n"
		"                         0:output->PBDCn,PDSCn,PODCn                    \n"
		"*2. alternative mode                                                    \n"
		"   PMCn:bit=1 ->PIPCn                                                   \n"
		"                         0   -> PFCn,PFCEn,PFCAEn                       \n"
		"                              ->PMn                                     \n"
		"                                  1: input   -> same as 1.              \n"
		"                                  0:output-> same as 1.                 \n"
		"                                                                        \n"
		"                         1  ->PFCn,PFCEn,PFCAEn                         \n"
		"                             PIBCn=0,PUn,PDn                            \n"
		"                             PBDCn,PDSCn,PODCn                          \n"
		"                       (directIO chapter2.11)                           \n"
		"                                                                        \n"
		"*---------------------------------------------------------*/            \n"
		"#if ( MCU_PIN == PIN100 )                                               \n"
		"/*-- MCU_RH850_F1L:  PORT 0,8,9,10,11,JP0,AP0   --*/                    \n"
		"#define MCU_PORT_NUM      5                                             \n"
		"#define MCU_APORT_NUM     1                                             \n"
		"#define MCU_JPORT_NUM     1                                             \n"
		"\n"
		"\n"
		"/*----------------------- GPIO ACTIVE ---------------------------- */\n"
		"\n"
		"/* PMC: 0=port mode 1=alternative */\n"
		"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
		};
        
        /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
        File = fopen("MCU_PIN_CC.H", "w");
        /* 设置前面的标题 */
        fputs(title, File);
        
        OutputModeString(MacroStrActive_100, ACTIVE);
        fputs("/*----------------------- GPIO STANDBY ---------------------------- */\n", File);
    
	    OutputModeString(MacroStrStandby_100, STANDBY);
        fputs("/*----------------------- GPIO RESET ---------------------------- */\n", File);
    
	    OutputModeString(MacroStrReset_100, RESET);
    }
    else if (Pin_Type == Pin_144)
    {
        char* title = {
		"/***********************************************************************\n"
		"*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *\n"
		"*                All Rights Reserved.                                  *\n"
		"*   Department  : ITTI                                                 *\n"
		"*   AUTHOR      : uidp5021                                             *\n"
		"************************************************************************\n"
		"* Object        :                                                       \n"
		"* Module        :                                                       \n"
		"* Instance      :                                                       \n"
		"* Description   :                                                       \n"
		"*-----------------------------------------------------------------------\n"
		"* Version:                                                              \n"
		"* Date:                                                                 \n"
		"* Author:                                                               \n"
		"***********************************************************************/\n"
		"/*-History--------------------------------------------------------------\n"
		"* Version       Date    Name    Changes and comment__DSB__DSBs          \n"
		"------------------------------------------------------------------------\n"
		"* 0.1	   Jun 26,2016   PEI Jingli  Initial version                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.2	   Jun 29,2016   LIU Chenxi  Correct errors during merging		 \n"
		"------------------------------------------------------------------------\n"
		"* 0.3	   July 07,2016  PEI Jingli  Adapt xxpin MCU                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.4	   Oct 24,2016  PEI Jingli   Config reset parameters,            \n"
		"                                p0_6 as general io when active and reset\n"
		"------------------------------------------------------------------------\n"
		"* 0.5     Nov 10,2016  PEI Jingli    Set standby paramters              \n"
		"------------------------------------------------------------------------\n"
		"* 0.6     Nov 17,2016  PEI Jingli    Add Pn register for default setting\n"
		"*=====================================================================*/\n"
		"#ifndef _PIN_MAP_CC_H                                                   \n"
		"#define _PIN_MAP_CC_H                                                   \n"
		"#include \"CONFIG.H\"                                                     \n"
		"#include \"SystemMode_Cfg.h\"                                             \n"
		"                                                                        \n"
		"                                                                        \n"
		"/*--------------------configration method----------------------         \n"
		"* 1. independent IO                                                     \n"
		"    PMCn:bit=0 -> PMn                                                   \n"
		"                         1:input  -> PIBCn=1,PUn,PDn                    \n"
		"                                                                        \n"
		"                         0:output->PBDCn,PDSCn,PODCn                    \n"
		"*2. alternative mode                                                    \n"
		"   PMCn:bit=1 ->PIPCn                                                   \n"
		"                         0   -> PFCn,PFCEn,PFCAEn                       \n"
		"                              ->PMn                                     \n"
		"                                  1: input   -> same as 1.              \n"
		"                                  0:output-> same as 1.                 \n"
		"                                                                        \n"
		"                         1  ->PFCn,PFCEn,PFCAEn                         \n"
		"                             PIBCn=0,PUn,PDn                            \n"
		"                             PBDCn,PDSCn,PODCn                          \n"
		"                       (directIO chapter2.11)                           \n"
		"                                                                        \n"
		"*---------------------------------------------------------*/            \n"
		"#if ( MCU_PIN == PIN144 )                                               \n"
		"/*-- MCU_RH850_F1L:  PORT 0,1,8,9,10,11,12,18,20,JP0,AP0,AP1   --*/                    \n"
		"#define MCU_PORT_NUM      9                                             \n"
		"#define MCU_APORT_NUM     2                                             \n"
		"#define MCU_JPORT_NUM     1                                             \n"
		"\n"
		"\n"
		"/*----------------------- GPIO ACTIVE ---------------------------- */\n"
		"\n"
		"/* PMC: 0=port mode 1=alternative */\n"
		"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
		};
        
        /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
        File = fopen("MCU_144PIN_CC.H", "w");
        /* 设置前面的标题 */
        fputs(title, File);

        OutputModeString(MacroStrActive_144, ACTIVE);
        fputs("/*----------------------- GPIO STANDBY ---------------------------- */\n", File);
    
	    OutputModeString(MacroStrStandby_144, STANDBY);
        fputs("/*----------------------- GPIO RESET ---------------------------- */\n", File);
    
	    OutputModeString(MacroStrReset_144, RESET);
    }


	fputs("#endif\n", File);
	fputs("#endif /*_PIN_MAP_CC_H*/\n", File);
	fputs("/**************** END OF FILE *****************************************/\n", File);
    fclose(File);
	
}


/*****************************************************************************
 *  Name        : OutputModeString
 *  Description : 向文件中写普通的寄存器配置
 *  Parameter   : _MacroStr* MacroStr：要显示在前面的宏定义，比如"#define GPIO_PIPC0_ACTIVE_VAL"
				  mode：有三种ACTIVE、STANDBY、RESET
 *  Returns     : None
*****************************************************************************/
void OutputModeString(_MacroStr* MacroStr, U8 mode)
{
	_PinmuxString pobj;

	/* 设置GPIO/功能口 */
    if (Pin_Type == Pin_100)
    {
        pobj.num = 6;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 10;
    }
	pobj.MacroString = MacroStr[M_PMC];
	pobj.reg = &PMC[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;
	OutPutGroupPinmuxString(&pobj);

    /* 设置PIP */
    fputs(MacroStr[M_PIPC], File);

    /* 设置输入/输出 */
	fputs("/* PM: 0=output 1=input */\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
    }
	pobj.MacroString = MacroStr[M_PM];
	pobj.reg = &PM[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 设置是否使用输入buffer */
	fputs("\n\n/* Port InputBuffer Control: 0: unused 1: used */\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);


	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
    }
	pobj.MacroString = MacroStr[M_PIBC];
	pobj.reg = &PIBC[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 功能口设置 */
	fputs("\n\n/* PFCAE,PFCE,PFC:IN alternative mode, select a alternative function in 0~4.\n", File);
	fputs("*  binary value [PFCAEn_m,PFCEn_m,PFCn_m]b  from 0~4  is a alternative function.\n", File);
	fputs("*  <RH850.pdf> page 122 */\n", File);

    if (Pin_Type == Pin_100)
    {
        pobj.num = 6;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 10;
    }
	pobj.MacroString = MacroStr[M_ALT];
	OutPutAlternativeString(&pobj, &PFC[mode][0], &PFCE[mode][0], &PFCAE[mode][0]);

	/* Port Bidirection Control */
	fputs("/* Port Bidirection Control: 1= Bidirection */\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
    }
	pobj.MacroString = MacroStr[M_PBDC];
	pobj.reg = &PBDC[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 上拉设置 */
	fputs("\n\n/* PullUp Control: input mode.  1= internal pullup.\n", File);
	fputs("* Care that PUn.PUn_m=1 and PDn.PDn_m=1, then the real Pin is pulldown\n*/\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
        pobj.jump1 = AP0;
        pobj.jump2 = 0;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
        pobj.jump1 = AP0;
        pobj.jump2 = AP1;
    }
	pobj.MacroString = MacroStr[M_PU];
	pobj.reg = &PU[mode][0];
	OutPutGroupPinmuxString(&pobj);

	/* 下拉设置 */
	fputs("\n\n/* PullDown Control: input mode.  1= internal pulldown */\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

    if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
        pobj.jump1 = AP0;
        pobj.jump2 = 0;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
        pobj.jump1 = AP0;
        pobj.jump2 = AP1;
    }
	pobj.MacroString = MacroStr[M_PD];
	pobj.reg = &PD[mode][0];
	OutPutGroupPinmuxString(&pobj);

	/* 驱动能力选择 */
	fputs("\n\n/* Port Driver Strength: output mode. 0:<=10mhz, 1:<=40mhz\n", File);
	fputs("* 40MHZ pin select:P0_2,3,5,6,7,13,14  ; P10_ALL ;P11_0~7 \n*/\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 5;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 9;
    }
	pobj.MacroString = MacroStr[M_PDSC];
	pobj.reg = &PDSC[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 推挽/开漏选择 */
	fputs("\n\n/* Port open drain control: output mode. 0:push-pull, 1:open-drain*/\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
        pobj.jump1 = AP0;
        pobj.jump2 = 0;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
        pobj.jump1 = AP0;
        pobj.jump2 = AP1;
    }
	pobj.MacroString = MacroStr[M_PODC];
	pobj.reg = &PODC[mode][0];
	OutPutGroupPinmuxString(&pobj);

	/* 默认IO电平设置 */
	fputs("\n\n/* Set default for output pin */\n", File);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", File);

	if (Pin_Type == Pin_100)
    {
        pobj.num = 7;
    }
    else if (Pin_Type == Pin_144)
    {
        pobj.num = 12;
    }
	pobj.MacroString = MacroStr[M_P];
	pobj.reg = &P[mode][0];
	pobj.jump1 = 0;
    pobj.jump2 = 0;

	OutPutGroupPinmuxString(&pobj);
}



void GenPinmux_144(void)
{
	char* title = {
		"/***********************************************************************\n"
		"*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *\n"
		"*                All Rights Reserved.                                  *\n"
		"*   Department  : ITTI                                                 *\n"
		"*   AUTHOR      : uidp5021                                             *\n"
		"************************************************************************\n"
		"* Object        :                                                       \n"
		"* Module        :                                                       \n"
		"* Instance      :                                                       \n"
		"* Description   :                                                       \n"
		"*-----------------------------------------------------------------------\n"
		"* Version:                                                              \n"
		"* Date:                                                                 \n"
		"* Author:                                                               \n"
		"***********************************************************************/\n"
		"/*-History--------------------------------------------------------------\n"
		"* Version       Date    Name    Changes and comment__DSB__DSBs          \n"
		"------------------------------------------------------------------------\n"
		"* 0.1	   Jun 26,2016   PEI Jingli  Initial version                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.2	   Jun 29,2016   LIU Chenxi  Correct errors during merging		 \n"
		"------------------------------------------------------------------------\n"
		"* 0.3	   July 07,2016  PEI Jingli  Adapt xxpin MCU                     \n"
		"------------------------------------------------------------------------\n"
		"* 0.4	   Oct 24,2016  PEI Jingli   Config reset parameters,            \n"
		"                                p0_6 as general io when active and reset\n"
		"------------------------------------------------------------------------\n"
		"* 0.5     Nov 10,2016  PEI Jingli    Set standby paramters              \n"
		"------------------------------------------------------------------------\n"
		"* 0.6     Nov 17,2016  PEI Jingli    Add Pn register for default setting\n"
		"*=====================================================================*/\n"
		"#ifndef _PIN_MAP_CC_H                                                   \n"
		"#define _PIN_MAP_CC_H                                                   \n"
		"#include \"CONFIG.H\"                                                     \n"
		"#include \"SystemMode_Cfg.h\"                                             \n"
		"                                                                        \n"
		"                                                                        \n"
		"/*--------------------configration method----------------------         \n"
		"* 1. independent IO                                                     \n"
		"    PMCn:bit=0 -> PMn                                                   \n"
		"                         1:input  -> PIBCn=1,PUn,PDn                    \n"
		"                                                                        \n"
		"                         0:output->PBDCn,PDSCn,PODCn                    \n"
		"*2. alternative mode                                                    \n"
		"   PMCn:bit=1 ->PIPCn                                                   \n"
		"                         0   -> PFCn,PFCEn,PFCAEn                       \n"
		"                              ->PMn                                     \n"
		"                                  1: input   -> same as 1.              \n"
		"                                  0:output-> same as 1.                 \n"
		"                                                                        \n"
		"                         1  ->PFCn,PFCEn,PFCAEn                         \n"
		"                             PIBCn=0,PUn,PDn                            \n"
		"                             PBDCn,PDSCn,PODCn                          \n"
		"                       (directIO chapter2.11)                           \n"
		"                                                                        \n"
		"*---------------------------------------------------------*/            \n"
		"#if ( MCU_PIN == PIN144 )                                               \n"
		"/*-- MCU_RH850_F1L:  PORT 0,1,8,9,10,11,12,18,20,JP0,AP0,AP1   --*/                    \n"
		"#define MCU_PORT_NUM      9                                             \n"
		"#define MCU_APORT_NUM     2                                             \n"
		"#define MCU_JPORT_NUM     1                                             \n"
		"\n"
		"\n"
		"/*----------------------- GPIO ACTIVE ---------------------------- */\n"
		"\n"
		"/* PMC: 0=port mode 1=alternative */\n"
		"/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n"
		};
        
    /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
    File = fopen("MCU_144PIN_CC.H", "w");
    /* 设置前面的标题 */
	fputs(title, File);
    _MacroStr MacroStrActive_144[] = 
	{
		PmcStringActive_144,
		PmStringActive_144,
		PibcStringActive_144,
		PbdcStringActive_144,
		PuStringActive_144,
		PdStringActive_144,
		PdscStringActive_144,
		PodcStringActive_144,
		PStringActive_144,
		AlternativeActive_144,
		PipcStringActive_144,
	};

	OutputModeString(MacroStrActive_144, ACTIVE);
    
    
    fputs("/*----------------------- GPIO STANDBY ---------------------------- */\n", File);
    

	_MacroStr MacroStrStandby_144[] =
	{
		PmcStringStandby_144,
		PmStringStandby_144,
		PibcStringStandby_144,
		PbdcStringStandby_144,
		PuStringStandby_144,
		PdStringStandby_144,
		PdscStringStandby_144,
		PodcStringStandby_144,
		PStringStandby_144,
		AlternativeStandby_144,
		PipcStringStandby_144,
	};

	OutputModeString(MacroStrStandby_144, STANDBY);


   fputs("/*----------------------- GPIO RESET ---------------------------- */\n", File);

	
	_MacroStr MacroStrReset_144[] =
	{
		PmcStringReset_144,
		PmStringReset_144,
		PibcStringReset_144,
		PbdcStringReset_144,
		PuStringReset_144,
		PdStringReset_144,
		PdscStringReset_144,
		PodcStringReset_144,
		PStringReset_144,
		AlternativeReset_144,
		PipcStringReset_144,
	};

	OutputModeString(MacroStrReset_144, RESET);


	fputs("#endif\n", File);
	fputs("#endif /*_PIN_MAP_CC_H*/\n", File);
	fputs("/**************** END OF FILE *****************************************/\n", File);
    fclose(File);
}  

/*****************************************************************************
 *  Name        : StringToBinary
 *  Description : 把16位的输出转成二进制形式的字符串，并按照指定的注释格式显示
 *  Parameter   : n：16位的整形数
				  pszb：转出来的二进制字符串
 *  Returns     : 返回值无意义
*****************************************************************************/
int StringToBinary(int n, char* pszb)
{
	int a = 1, i,j=0;
	U8 cnt = 1;
	U8 tmp[20];

	for (i = 15; i >= 0; i--)
	{
		if (n&a)
			pszb[i] = '1';
		else
			pszb[i] = '0';
		a <<= 1;
	}

	memcpy(tmp, pszb,16);
	
	pszb[j++] = '/';
	pszb[j++] = '*';
	pszb[j++] = ' ';
	for (i = 0; i <= 15; i++)
	{
		pszb[j++] = tmp[i];

		if (i == 0 || i == 1 || i == 2 || \
			i == 4 || i == 5 || i == 6 || \
			i == 8 || i == 9 || i == 10 || \
			i == 12 || i == 13 || i == 14)
		{
			pszb[j++] = ' ';
			pszb[j++] = ' ';
		}
		else if(i == 3)
		{
			pszb[j++] = ' ';
			pszb[j++] = ' ';
			pszb[j++] = '|';
			pszb[j++] = '|';
			pszb[j++] = ' ';
		}
		else if (i == 7 || i== 11)
		{
			pszb[j++] = ' ';
			pszb[j++] = '|';
			pszb[j++] = '|';
			pszb[j++] = ' ';
		}
		
	}
	pszb[j++] = ' ';
	pszb[j++] = '*';
	pszb[j++] = '/';
	pszb[j++] = '\n';
	pszb[j++] = '\0';
	return 0;
}
/*****************************************************************************
 *  Name        : OutPutGroupPinmuxString
 *  Description : 
 *  Parameter   : _PinmuxString *s:要显示的宏定义和组数
				  U16* reg：要转换的寄存器的值
				  jump：要跳过的组，只能是一组，为JP和AP设置的
 *  Returns     : None
*****************************************************************************/
void OutPutGroupPinmuxString(_PinmuxString *s)
{
	U8 temp[500];
	U8 s_Hex[30];
	U8 s_Bin[300];

	/* Tab字符串 */
	U8 tab[10] = 
	{
		"										"
	};

	//printf("%s\n",s->MacroString[0]);

	for(U8 i = 0; i< s->num; i++)
	{
		if (s->jump1 != 0 && i == s->jump1)
		{
			continue;
		}

        if (s->jump2 != 0 && i == s->jump2)
		{
			continue;
		}

		strcpy(temp,s->MacroString[i]);
		strncat(temp, tab, 5);/* 加入5个tab */
		sprintf(s_Hex, "0x%04X", s->reg[i]);
		strcat(temp, s_Hex);
		strcat(temp, " \n\n");
	
		/* 增加注释 */
		StringToBinary(s->reg[i], s_Bin);	/* 字符串转二进制 */   

        fputs(s_Bin, File);
		fputs(temp, File);

	}
}

/*****************************************************************************
 *  Name        : OutPutAlternative
 *  Description : 向文件中写功能口的寄存器配置
 *  Parameter   : _AlternativeString *s：要显示的宏定义和组数
                  RegPfc：PFC寄存器数组的地址
				  RegPfce：PFCE寄存器数组的地址
				  RegPfcae：PFCAE寄存器数组的地址
 *  Returns     : None
*****************************************************************************/
void OutPutAlternativeString(_AlternativeString *s, U16* RegPfc, U16* RegPfce, U16* RegPfcae)
{
	U8 TempPfc[500];
	U8 TempPfce[500];
	U8 TempPfcae[500];

	U8 HexPfc[30];
	U8 HexPfce[30];
	U8 HexPfcae[30];

	U8 BinPfc[300];
	U8 BinPfce[300];
	U8 BinPfcae[300];

	/* Tab字符串 */
	U8 tab[10] =
	{
		"										"
	};

	//printf("%s\n",s->MacroString[0][0]);

	for (U8 i = 0; i < s->num; i++) /* 组别 */
	{

		strcpy(TempPfc, s->MacroString[i][0]);
		strcpy(TempPfce, s->MacroString[i][1]);
		strcpy(TempPfcae, s->MacroString[i][2]);

		strncat(TempPfc, tab, 5);/* 加入5个tab */
		strncat(TempPfce, tab, 5);/* 加入5个tab */
		strncat(TempPfcae, tab, 5);/* 加入5个tab */

		sprintf(HexPfc, "0x%04X", RegPfc[i]);
		sprintf(HexPfce, "0x%04X", RegPfce[i]);
		sprintf(HexPfcae, "0x%04X", RegPfcae[i]);

		strcat(TempPfc, HexPfc);
		strcat(TempPfce, HexPfce);
		strcat(TempPfcae, HexPfcae);

		strcat(TempPfc, " \n");
		strcat(TempPfce, " \n");
		strcat(TempPfcae, " \n");

		/* 增加注释 */
		StringToBinary(RegPfc[i], BinPfc);		/* 字符串转二进制 */
		StringToBinary(RegPfce[i], BinPfce);	/* 字符串转二进制 */
		StringToBinary(RegPfcae[i], BinPfcae);	/* 字符串转二进制 */

		fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2	1  0 */\n", File);
		fputs(BinPfc, File);
		fputs(BinPfce, File);
		fputs(BinPfcae, File);
		fputs(TempPfc, File);
		fputs(TempPfce, File);
		fputs(TempPfcae, File);
		fputs("\n", File);

	}

}
