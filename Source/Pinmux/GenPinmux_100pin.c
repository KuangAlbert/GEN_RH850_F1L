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
#include "GenPinmux100pin.h"
#include "ProcessExcel.h"

FILE* F100;

/* ACTIVE */
const U8 PmcStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_ACTIVE_VAL ",
	"#define GPIO_PMC8_ACTIVE_VAL ",
	"#define GPIO_PMC9_ACTIVE_VAL ",
	"#define GPIO_PMC10_ACTIVE_VAL",
	"#define GPIO_PMC11_ACTIVE_VAL",
	"#define GPIO_JPMC0_ACTIVE_VAL",
};

const U8 PmStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_ACTIVE_VAL ",
	"#define GPIO_PM8_ACTIVE_VAL ",
	"#define GPIO_PM9_ACTIVE_VAL ",
	"#define GPIO_PM10_ACTIVE_VAL",
	"#define GPIO_PM11_ACTIVE_VAL",
	"#define GPIO_APM0_ACTIVE_VAL",
	"#define GPIO_JPM0_ACTIVE_VAL",
};

const U8 PibcStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_ACTIVE_VAL ",
	"#define GPIO_PIBC8_ACTIVE_VAL ",
	"#define GPIO_PIBC9_ACTIVE_VAL ",
	"#define GPIO_PIBC10_ACTIVE_VAL",
	"#define GPIO_PIBC11_ACTIVE_VAL",
	"#define GPIO_APIBC0_ACTIVE_VAL",
	"#define GPIO_JPIBC0_ACTIVE_VAL",
};

const U8 PbdcStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_ACTIVE_VAL ",
	"#define GPIO_PBDC8_ACTIVE_VAL ",
	"#define GPIO_PBDC9_ACTIVE_VAL ",
	"#define GPIO_PBDC10_ACTIVE_VAL",
	"#define GPIO_PBDC11_ACTIVE_VAL",
	"#define GPIO_APBDC0_ACTIVE_VAL",
	"#define GPIO_JPBDC0_ACTIVE_VAL",
};

const U8 PuStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_ACTIVE_VAL ",
	"#define GPIO_PU8_ACTIVE_VAL ",
	"#define GPIO_PU9_ACTIVE_VAL ",
	"#define GPIO_PU10_ACTIVE_VAL",
	"#define GPIO_PU11_ACTIVE_VAL",
	"#define GPIO_APU0_ACTIVE_VAL",
	"#define GPIO_JPU0_ACTIVE_VAL",
};

const U8 PdStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_ACTIVE_VAL ",
	"#define GPIO_PD8_ACTIVE_VAL ",
	"#define GPIO_PD9_ACTIVE_VAL ",
	"#define GPIO_PD10_ACTIVE_VAL",
	"#define GPIO_PD11_ACTIVE_VAL",
	"#define GPIO_APD0_ACTIVE_VAL",
	"#define GPIO_JPD0_ACTIVE_VAL",
};

const U8 PdscStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_ACTIVE_VAL ",
	"#define GPIO_PDSC8_ACTIVE_VAL ",
	"#define GPIO_PDSC9_ACTIVE_VAL ",
	"#define GPIO_PDSC10_ACTIVE_VAL",
	"#define GPIO_PDSC11_ACTIVE_VAL",
};

const U8 PodcStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_ACTIVE_VAL ",
	"#define GPIO_PODC8_ACTIVE_VAL ",
	"#define GPIO_PODC9_ACTIVE_VAL ",
	"#define GPIO_PODC10_ACTIVE_VAL",
	"#define GPIO_PODC11_ACTIVE_VAL",
	"#define GPIO_APODC0_ACTIVE_VAL",
	"#define GPIO_JPODC0_ACTIVE_VAL",
};

const U8 PStringActive[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_ACTIVE_VAL ",
	"#define GPIO_P8_ACTIVE_VAL ",
	"#define GPIO_P9_ACTIVE_VAL ",
	"#define GPIO_P10_ACTIVE_VAL",
	"#define GPIO_P11_ACTIVE_VAL",
	"#define GPIO_JP0_ACTIVE_VAL",
	"#define GPIO_AP0_ACTIVE_VAL",
};

const U8 AlternativeActive[6][3][ROW_BUF_MAX] =
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

const U8 PipcStringActive[][ROW_BUF_MAX] =
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
const U8 PmcStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_RESET_VAL ",
	"#define GPIO_PMC8_RESET_VAL ",
	"#define GPIO_PMC9_RESET_VAL ",
	"#define GPIO_PMC10_RESET_VAL",
	"#define GPIO_PMC11_RESET_VAL",
	"#define GPIO_JPMC0_RESET_VAL",
};

const U8 PmStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_RESET_VAL ",
	"#define GPIO_PM8_RESET_VAL ",
	"#define GPIO_PM9_RESET_VAL ",
	"#define GPIO_PM10_RESET_VAL",
	"#define GPIO_PM11_RESET_VAL",
	"#define GPIO_APM0_RESET_VAL",
	"#define GPIO_JPM0_RESET_VAL",
};

const U8 PibcStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_RESET_VAL ",
	"#define GPIO_PIBC8_RESET_VAL ",
	"#define GPIO_PIBC9_RESET_VAL ",
	"#define GPIO_PIBC10_RESET_VAL",
	"#define GPIO_PIBC11_RESET_VAL",
	"#define GPIO_APIBC0_RESET_VAL",
	"#define GPIO_JPIBC0_RESET_VAL",
};

const U8 PbdcStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_RESET_VAL ",
	"#define GPIO_PBDC8_RESET_VAL ",
	"#define GPIO_PBDC9_RESET_VAL ",
	"#define GPIO_PBDC10_RESET_VAL",
	"#define GPIO_PBDC11_RESET_VAL",
	"#define GPIO_APBDC0_RESET_VAL",
	"#define GPIO_JPBDC0_RESET_VAL",
};

const U8 PuStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_RESET_VAL ",
	"#define GPIO_PU8_RESET_VAL ",
	"#define GPIO_PU9_RESET_VAL ",
	"#define GPIO_PU10_RESET_VAL",
	"#define GPIO_PU11_RESET_VAL",
	"#define GPIO_APU0_RESET_VAL",
	"#define GPIO_JPU0_RESET_VAL",
};

const U8 PdStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_RESET_VAL ",
	"#define GPIO_PD8_RESET_VAL ",
	"#define GPIO_PD9_RESET_VAL ",
	"#define GPIO_PD10_RESET_VAL",
	"#define GPIO_PD11_RESET_VAL",
	"#define GPIO_APD0_RESET_VAL",
	"#define GPIO_JPD0_RESET_VAL",
};

const U8 PdscStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_RESET_VAL ",
	"#define GPIO_PDSC8_RESET_VAL ",
	"#define GPIO_PDSC9_RESET_VAL ",
	"#define GPIO_PDSC10_RESET_VAL",
	"#define GPIO_PDSC11_RESET_VAL",
};

const U8 PodcStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_RESET_VAL ",
	"#define GPIO_PODC8_RESET_VAL ",
	"#define GPIO_PODC9_RESET_VAL ",
	"#define GPIO_PODC10_RESET_VAL",
	"#define GPIO_PODC11_RESET_VAL",
	"#define GPIO_APODC0_RESET_VAL",
	"#define GPIO_JPODC0_RESET_VAL",
};

const U8 PStringReset[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_RESET_VAL ",
	"#define GPIO_P8_RESET_VAL ",
	"#define GPIO_P9_RESET_VAL ",
	"#define GPIO_P10_RESET_VAL",
	"#define GPIO_P11_RESET_VAL",
	"#define GPIO_JP0_RESET_VAL",
	"#define GPIO_AP0_RESET_VAL",
};

const U8 AlternativeReset[6][3][ROW_BUF_MAX] =
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

const U8 PipcStringReset[][ROW_BUF_MAX] =
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
const U8 PmcStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PMC0_STANDBY_VAL ",
	"#define GPIO_PMC8_STANDBY_VAL ",
	"#define GPIO_PMC9_STANDBY_VAL ",
	"#define GPIO_PMC10_STANDBY_VAL",
	"#define GPIO_PMC11_STANDBY_VAL",
	"#define GPIO_JPMC0_STANDBY_VAL",
};

const U8 PmStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PM0_STANDBY_VAL ",
	"#define GPIO_PM8_STANDBY_VAL ",
	"#define GPIO_PM9_STANDBY_VAL ",
	"#define GPIO_PM10_STANDBY_VAL",
	"#define GPIO_PM11_STANDBY_VAL",
	"#define GPIO_APM0_STANDBY_VAL",
	"#define GPIO_JPM0_STANDBY_VAL",
};

const U8 PibcStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PIBC0_STANDBY_VAL ",
	"#define GPIO_PIBC8_STANDBY_VAL ",
	"#define GPIO_PIBC9_STANDBY_VAL ",
	"#define GPIO_PIBC10_STANDBY_VAL",
	"#define GPIO_PIBC11_STANDBY_VAL",
	"#define GPIO_APIBC0_STANDBY_VAL",
	"#define GPIO_JPIBC0_STANDBY_VAL",
};

const U8 PbdcStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PBDC0_STANDBY_VAL ",
	"#define GPIO_PBDC8_STANDBY_VAL ",
	"#define GPIO_PBDC9_STANDBY_VAL ",
	"#define GPIO_PBDC10_STANDBY_VAL",
	"#define GPIO_PBDC11_STANDBY_VAL",
	"#define GPIO_APBDC0_STANDBY_VAL",
	"#define GPIO_JPBDC0_STANDBY_VAL",
};

const U8 PuStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PU0_STANDBY_VAL ",
	"#define GPIO_PU8_STANDBY_VAL ",
	"#define GPIO_PU9_STANDBY_VAL ",
	"#define GPIO_PU10_STANDBY_VAL",
	"#define GPIO_PU11_STANDBY_VAL",
	"#define GPIO_APU0_STANDBY_VAL",
	"#define GPIO_JPU0_STANDBY_VAL",
};

const U8 PdStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PD0_STANDBY_VAL ",
	"#define GPIO_PD8_STANDBY_VAL ",
	"#define GPIO_PD9_STANDBY_VAL ",
	"#define GPIO_PD10_STANDBY_VAL",
	"#define GPIO_PD11_STANDBY_VAL",
	"#define GPIO_APD0_STANDBY_VAL",
	"#define GPIO_JPD0_STANDBY_VAL",
};

const U8 PdscStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PDSC0_STANDBY_VAL ",
	"#define GPIO_PDSC8_STANDBY_VAL ",
	"#define GPIO_PDSC9_STANDBY_VAL ",
	"#define GPIO_PDSC10_STANDBY_VAL",
	"#define GPIO_PDSC11_STANDBY_VAL",
};

const U8 PodcStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_PODC0_STANDBY_VAL ",
	"#define GPIO_PODC8_STANDBY_VAL ",
	"#define GPIO_PODC9_STANDBY_VAL ",
	"#define GPIO_PODC10_STANDBY_VAL",
	"#define GPIO_PODC11_STANDBY_VAL",
	"#define GPIO_APODC0_STANDBY_VAL",
	"#define GPIO_JPODC0_STANDBY_VAL",
};

const U8 PStringStandby[][ROW_BUF_MAX] =
{
	"#define GPIO_P0_STANDBY_VAL ",
	"#define GPIO_P8_STANDBY_VAL ",
	"#define GPIO_P9_STANDBY_VAL ",
	"#define GPIO_P10_STANDBY_VAL",
	"#define GPIO_P11_STANDBY_VAL",
	"#define GPIO_JP0_STANDBY_VAL",
	"#define GPIO_AP0_STANDBY_VAL",
};

const U8 AlternativeStandby[6][3][ROW_BUF_MAX] =
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

const U8 PipcStringStandby[][ROW_BUF_MAX] =
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
/*****************************************************************************
 *  Name        : GenPinmux_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenPinmux_100pin(void)
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
	F100 = fopen("MCU_PIN_CC.H", "w"); 
	
	/* 设置前面的标题 */
	fputs(title, F100);

	_MacroStr MacroStrActive[] = 
	{
		PmcStringActive,
		PmStringActive,
		PibcStringActive,
		PbdcStringActive,
		PuStringActive,
		PdStringActive,
		PdscStringActive,
		PodcStringActive,
		PStringActive,
		AlternativeActive,
		PipcStringActive,
	};

	OutputModeString(MacroStrActive, ACTIVE);

	fputs("/*----------------------- GPIO STANDBY ---------------------------- */\n", F100);

	_MacroStr MacroStrStandby[] =
	{
		PmcStringStandby,
		PmStringStandby,
		PibcStringStandby,
		PbdcStringStandby,
		PuStringStandby,
		PdStringStandby,
		PdscStringStandby,
		PodcStringStandby,
		PStringStandby,
		AlternativeStandby,
		PipcStringStandby,
	};

	OutputModeString(MacroStrStandby, STANDBY);

	fputs("/*----------------------- GPIO RESET ---------------------------- */\n", F100);
	_MacroStr MacroStrReset[] =
	{
		PmcStringReset,
		PmStringReset,
		PibcStringReset,
		PbdcStringReset,
		PuStringReset,
		PdStringReset,
		PdscStringReset,
		PodcStringReset,
		PStringReset,
		AlternativeReset,
		PipcStringReset,
	};

	OutputModeString(MacroStrReset, RESET);

	fputs("#endif\n", F100);
	fputs("#endif /*_PIN_MAP_CC_H*/\n", F100);
	fputs("/**************** END OF FILE *****************************************/\n", F100);


	fclose(F100);
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
		if (s->jump != 0 && i == s->jump)
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

		fputs(s_Bin, F100);
		fputs(temp, F100);
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
		StringToBinary(RegPfc[i], BinPfc);	/* 字符串转二进制 */
		StringToBinary(RegPfce[i], BinPfce);	/* 字符串转二进制 */
		StringToBinary(RegPfcae[i], BinPfcae);	/* 字符串转二进制 */

		
		fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2	1  0 */\n", F100);
		fputs(BinPfc, F100);
		fputs(BinPfce, F100);
		fputs(BinPfcae, F100);
		fputs(TempPfc, F100);
		fputs(TempPfce, F100);
		fputs(TempPfcae, F100);
		fputs("\n", F100);
	}

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
	pobj.num = 6;
	pobj.MacroString = MacroStr[M_PMC];
	pobj.reg = &PMC[mode][0];
	pobj.jump = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 设置PIP */
	fputs(MacroStr[M_PIPC], F100);

	/* 设置输入/输出 */
	fputs("/* PM: 0=output 1=input */\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PM];
	pobj.reg = &PM[mode][0];
	pobj.jump = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 设置是否使用输入buffer */
	fputs("\n\n/* Port InputBuffer Control: 0: unused 1: used */\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PIBC];
	pobj.reg = &PIBC[mode][0];
	pobj.jump = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 功能口设置 */
	fputs("\n\n/* PFCAE,PFCE,PFC:IN alternative mode, select a alternative function in 0~4.\n", F100);
	fputs("*  binary value [PFCAEn_m,PFCEn_m,PFCn_m]b  from 0~4  is a alternative function.\n", F100);
	fputs("*  <RH850.pdf> page 122 */\n", F100);

	pobj.num = 6;
	pobj.MacroString = MacroStr[M_ALT];
	OutPutAlternativeString(&pobj, &PFC[mode][0], &PFCE[mode][0], &PFCAE[mode][0]);

	/* Port Bidirection Control */
	fputs("/* Port Bidirection Control: 1= Bidirection */\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PBDC];
	pobj.reg = &PBDC[mode][0];
	pobj.jump = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 上拉设置 */
	fputs("\n\n/* PullUp Control: input mode.  1= internal pullup.\n", F100);
	fputs("* Care that PUn.PUn_m=1 and PDn.PDn_m=1, then the real Pin is pulldown\n*/\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PU];
	pobj.reg = &PU[mode][0];
	pobj.jump = AP;
	OutPutGroupPinmuxString(&pobj);

	/* 下拉设置 */
	fputs("\n\n/* PullDown Control: input mode.  1= internal pulldown */\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PD];
	pobj.reg = &PD[mode][0];
	pobj.jump = AP;
	OutPutGroupPinmuxString(&pobj);

	/* 驱动能力选择 */
	fputs("\n\n/* Port Driver Strength: output mode. 0:<=10mhz, 1:<=40mhz\n", F100);
	fputs("* 40MHZ pin select:P0_2,3,5,6,7,13,14  ; P10_ALL ;P11_0~7 \n*/\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 5;
	pobj.MacroString = MacroStr[M_PDSC];
	pobj.reg = &PDSC[mode][0];
	pobj.jump = 0;
	OutPutGroupPinmuxString(&pobj);

	/* 推挽/开漏选择 */
	fputs("\n\n/* Port open drain control: output mode. 0:push-pull, 1:open-drain*/\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_PODC];
	pobj.reg = &PODC[mode][0];
	pobj.jump = AP;
	OutPutGroupPinmuxString(&pobj);

	/* 默认IO电平设置 */
	fputs("\n\n/* Set default for output pin */\n", F100);
	fputs("/* 15 14 13 12 || 11 10 9  8 || 7  6  5  4 || 3  2  1  0 */\n", F100);

	pobj.num = 7;
	pobj.MacroString = MacroStr[M_P];
	pobj.reg = &P[mode][0];
	pobj.jump = 0;

	OutPutGroupPinmuxString(&pobj);
}