/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: ����F1L 100 pin�ж�����
 * Instance		:
 * Description	:
 *-----------------------------------------------------------------------
 * Version		: v1.0
 * Date			: 2018/09/01
 * Author		: uidp5021
 ***********************************************************************/
 /*-History--------------------------------------------------------------
 * Version       Date               Name            Changes and comments
 * 1.0           2018/09/01			Lishi           add Init version
*=========================================================================*/
#include <stdio.h>
#include <stdarg.h>
#include "GenInterrupt100pin.h"
#include "ProcessExcel.h"
#include "const.h"
#include <windows.h>
#include <string.h>

FILE* F_intvect_c0;
FILE* F_tcb;
FILE* F_tcbpost;
FILE* F_osConfigBlock;

static void GenInterrupt_intvect_c0_Tab(wchar_t* IntName, U16 cnt);
/*****************************************************************************
 *  Name        : GenInterrupt_intvect_c0_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_intvect_c0_100pin(void)
{
	_ExcelResultInterrupt* p = &ExcelResultInterrupt;
	U16 IntNum = 0;


	/* ��ֻд�ļ������ļ������򳤶���Ϊ 0�������ļ�������ʧ�����������򴴽����ļ� */
	F_intvect_c0 = fopen("intvect_c0.c", "w");

	/* ����T1 */
	fputs(intvect_c0_T1, F_intvect_c0);

	/* �����жϵ�һ�� */
	fputs("#pragma asm\n\n", F_intvect_c0);
	fputs("   .align 512\n", F_intvect_c0);
	fputs("   .section \".osEIINTVectorTable_c0\", \"ax\"\n\n", F_intvect_c0);
	fputs("   .globl _osEIINTVectorTable_c0   /* start of the EIINT exception vector table */\n", F_intvect_c0);
	fputs("_osEIINTVectorTable_c0:\n\n", F_intvect_c0);

	for (U16 i = 0; i <= 253; i++)
	{
		if (p->IntConfigEnable[i] == 1)
		{
			if (IntNum <= p->IntNum)
			{
				GenInterrupt_intvect_c0_Tab(p->IntName[IntNum++],i);
			}
		}
		else
		{
			fputs("   .word _osUnhandledEIINTException\n", F_intvect_c0);
		}
		
	}
}

/*****************************************************************************
 *  Name        : GenInterrupt_intvect_c0_Tab
 *  Description : IntName���ж�Դ������
				  cnt��Ҫ���õ��ж����
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_intvect_c0_Tab(wchar_t* IntName, U16 cnt)
{
	char temp[500] = "   .word _ISR_";
	char Char_IntName[500];
	char commentTabCnt[50];
	/* Tab�ַ��� */
	U8 tab[10] =
	{
		"										"
	};

	WideCharToMultiByte(CP_ACP, 0, IntName, wcslen(IntName) + 1, Char_IntName, 256, NULL, NULL);
	strcat(temp, Char_IntName);
	strcat(temp, "_CAT2");

	strncat(temp, tab, 5);/* ����5��tab */
	strcat(temp, "/* interrupt index = ");
	sprintf(commentTabCnt, "%03d", cnt);
	strcat(temp, commentTabCnt);
	strcat(temp, " */");

	strcat(temp, "\n");
	fputs(temp, F_intvect_c0);
}
/*****************************************************************************
 *  Name        : GenInterrupt_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenInterrupt_100pin(void)
{
	GenInterrupt_intvect_c0_100pin();
}