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


FILE* F100;

const U8 PmcString[][255] =
{
	"#define GPIO_PMC0_ACTIVE_VAL ",
	"#define GPIO_PMC8_ACTIVE_VAL ",
	"#define GPIO_PMC9_ACTIVE_VAL ",
	"#define GPIO_PMC10_ACTIVE_VAL",
	"#define GPIO_PMC11_ACTIVE_VAL",
	"#define GPIO_JPMC0_ACTIVE_VAL",
};


/*****************************************************************************
 *  Name        : GenPinmux_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenPinmux_100pin(void)
{
char* str = { 
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
"/* PMC: 0=port mode 1=alternative */\n"
};


	F100 = fopen("MCU_PIN_CC.H", "w"); /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	fputs(str, F100);

	_PinmuxString pobj;
	pobj.num = 6;
	pobj.MacroString = PmcString;
	OutPutGroupPinmuxString(&pobj,0x23);

	fputs("#define GPIO_PMC0_ACTIVE_VAL", F100);
	fclose(F100);
}
int binary(int n, char* pszb)
{
	int a = 1, i;
	for (i = 15; i >= 0; i--)
	{
		if (n&a)
			pszb[i] = '1';
		else
			pszb[i] = '0';
		a <<= 1;
	}
	pszb[16] = '\0';
	return 0;
}
/*****************************************************************************
 *  Name        : OutPutGroupPinmuxString
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void OutPutGroupPinmuxString(_PinmuxString *s, U16 reg)
{
	U8 temp[500];
	U8 s_Hex[30];
	U8 s_Bin[30];
	/* Tab字符串 */
	U8 tab[10] = 
	{
		"										"
	};

	//printf("%s\n",s->MacroString[0]);
	printf("%x\n", reg);

	for(U8 i = 0; i< s->num; i++)
	{
		strcpy(temp,s->MacroString[i]);
		strncat(temp, tab, 3);/* 加入3个tab */
		sprintf(s_Hex, "0x%08X", reg);
		strcat(temp, s_Hex);
		strncat(temp, tab, 1);/* 加入1个tab */
		binary(reg, s_Bin);
		strcat(temp, "\n");

		printf("%s\n", s_Bin);
		fputs(temp, F100);
	}
}