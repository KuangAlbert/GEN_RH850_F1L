/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: 生成F1L 100 pin中断配置
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
static void GenInterrupt_intvect_c0_Text(_ExcelResultInterrupt* p);
static void GenInterrupt_intvect_c0_100pin(void);
static void GenInterrupt_tcb_100pin(void);
static void GenInterrupt_tcbpost_100pin(void);
static void GenInterrupt_osConfigBlock_100pin(void);

/*****************************************************************************
 *  Name        : GenInterrupt_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenInterrupt_100pin(void)
{
	GenInterrupt_intvect_c0_100pin();
	GenInterrupt_tcb_100pin();
	GenInterrupt_tcbpost_100pin();
	GenInterrupt_osConfigBlock_100pin();
}

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

	/* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	F_intvect_c0 = fopen("intvect_c0.c", "w");

	/* 设置T1 */
	fputs(intvect_c0_T1, F_intvect_c0);

	/* 第一部分 */
	fputs("#pragma asm\n\n", F_intvect_c0);
	fputs("   .align 512\n", F_intvect_c0);
	fputs("   .section \".osEIINTVectorTable_c0\", \"ax\"\n\n", F_intvect_c0);
	fputs("   .globl _osEIINTVectorTable_c0   /* start of the EIINT exception vector table */\n", F_intvect_c0);
	fputs("_osEIINTVectorTable_c0:\n\n", F_intvect_c0);

	for (U16 i = 0; i < 256; i++)
	{
		if (p->IntConfigEnable[i] == 1)
		{
			if (IntNum <= p->IntNum)
			{
				GenInterrupt_intvect_c0_Tab(p->IntName[IntNum++], i);
			}
		}
		else
		{
			fputs("   .word _osUnhandledEIINTException\n", F_intvect_c0);
		}

	}

	fputs("_osEIINTVectorTableEnd_c0:						/* end of the EIINT exception vector table */\n\n", F_intvect_c0);
	fputs("#pragma endasm\n", F_intvect_c0);

	/* 第二部分 */
	fputs("   	.section \".os_text\", \"ax\"\n", F_intvect_c0);
	fputs("   	/* MISRA RULE 14.1 not violated: ISR_TAUD0I0 is branched via EIINT vector table. */\n", F_intvect_c0);

	GenInterrupt_intvect_c0_Text(p);

	fputs("#pragma endasm\n", F_intvect_c0);
	fclose(F_intvect_c0);
}

/*****************************************************************************
 *  Name        : GenInterrupt_intvect_c0_Tab
 *  Description : IntName：中断源的名字
				  cnt：要配置的中断序号
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_intvect_c0_Tab(wchar_t* IntName, U16 cnt)
{
	char temp[500] = "   .word _ISR_";
	char Char_IntName[500];
	char commentTabCnt[50];
	/* Tab字符串 */
	U8 tab[10] =
	{
		"										"
	};

	WideCharToMultiByte(CP_ACP, 0, IntName, wcslen(IntName) + 1, Char_IntName, 256, NULL, NULL);
	strcat(temp, Char_IntName);
	strcat(temp, "_CAT2");

	strncat(temp, tab, 5);/* 加入5个tab */
	strcat(temp, "/* interrupt index = ");
	sprintf(commentTabCnt, "%03d", cnt);
	strcat(temp, commentTabCnt);
	strcat(temp, " */");

	strcat(temp, "\n");
	fputs(temp, F_intvect_c0);
}

/*****************************************************************************
 *  Name        : GenInterrupt_intvect_c0_Text
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_intvect_c0_Text(_ExcelResultInterrupt* p)
{
	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "	osCAT2ISRC0(ISR_";
		char Char_IntName[500] = { 0 };

		WideCharToMultiByte(CP_ACP, 0, p->IntName[Num], wcslen(p->IntName[Num]) + 1, Char_IntName, 256, NULL, NULL);
		strcat(temp, Char_IntName);

		//printf("p->IntNum:%d   %s\n", p->IntNum, temp);
		if (0 == wcscmp(p->IntName[Num], L"TAUD0I15"))
		{
			fputs("\n   /* MISRA RULE 14.1 not violated: ISR_TAUD0I0 is branched via EIINT vector table. */\n", F_intvect_c0);
			strcat(temp, ", 0)\n");
			fputs(temp, F_intvect_c0);
		}
		else
		{
			strcat(temp, ", 1)\n");
			fputs(temp, F_intvect_c0);
		}
	}

}

/*****************************************************************************
 *  Name        : GenInterrupt_tcb_index
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcb_index(_ExcelResultInterrupt* p)
{
	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "#define ISR_";
		char Char_IntName[500] = { 0 };
		char index[10];

		WideCharToMultiByte(CP_ACP, 0, p->IntName[Num], wcslen(p->IntName[Num]) + 1, Char_IntName, 256, NULL, NULL);
		strcat(temp, Char_IntName);

		strcat(temp, "_index  ");
		sprintf(index, "%d", Num);
		strcat(temp, index);
		strcat(temp, "\n");
		fputs(temp, F_tcb);
	}
}

/*****************************************************************************
 *  Name        : GenInterrupt_tcb_AllISRs
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcb_AllISRs(_ExcelResultInterrupt* p)
{
	char temp[500] = "#define osdNumberOfAllISRs  ";
	char temp1[500] = "#define osdNumberOfCat2ISRs ";
	char Char_IntName[500] = { 0 };
	char AllISRs[10];

	sprintf(AllISRs, "%d", p->IntNum + 1);
	strcat(temp, AllISRs);
	strcat(temp, "\n");
	fputs(temp, F_tcb);
	fputs("#define osdNumberOfAllTasks 7\n", F_tcb);
	fputs("#define osdNumberOfCat1ISRs 0\n", F_tcb);

	fputs(temp, F_tcb);
	strcat(temp, AllISRs);
	strcat(temp, "\n\n");
}
/*****************************************************************************
 *  Name        : GenInterrupt_tcb_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcb_100pin(void)
{
	_ExcelResultInterrupt* p = &ExcelResultInterrupt;

	/* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	F_tcb = fopen("tcb.h", "w");

	/* 设置T1 */
	fputs(tcb_T1, F_tcb);

	/* 设置index */
	GenInterrupt_tcb_index(p);

	/* 设置T2 */
	fputs(tcb_T2, F_tcb);

	/* 设置中断总数量 */
	GenInterrupt_tcb_AllISRs(p);

	/* 设置T3 */
	fputs(tcb_T3, F_tcb);

	fclose(F_tcb);
}

/*****************************************************************************
 *  Name        : GenInterrupt_tcbpost_ID
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcbpost_ID(_ExcelResultInterrupt* p)
{
	char temp[500] = "#define osdNumberOfAllISRs  ";
	char temp1[500] = "#define osdNumberOfCat2ISRs ";
	char Char_IntName[500] = { 0 };
	char AllISRs[10];

	fputs("/* ISR IDs */\n", F_tcbpost);

	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "#define ISR_";
		char Char_IntName[500] = { 0 };
		char ID[10];

		WideCharToMultiByte(CP_ACP, 0, p->IntName[Num], wcslen(p->IntName[Num]) + 1, Char_IntName, 256, NULL, NULL);
		strcat(temp, Char_IntName);

		strcat(temp, " ((ISRType)");
		sprintf(ID, "%d", Num);
		strcat(temp, ID);
		strcat(temp, "\n");
		fputs(temp, F_tcbpost);
	}
}

/*****************************************************************************
 *  Name        : GenInterrupt_tcbpost_function
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcbpost_function(_ExcelResultInterrupt* p)
{

	fputs("/* ISR function prototypes */ \n", F_tcbpost);

	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "void ";
		char Char_IntName[500] = { 0 };
		char ID[10];

		if (NULL == p->IntFunName[Num])
		{
			continue;
		}

		WideCharToMultiByte(CP_ACP, 0, p->IntFunName[Num], wcslen(p->IntFunName[Num]) + 1, Char_IntName, 256, NULL, NULL);

		strcat(temp, Char_IntName);

		strcat(temp, "(void);");
		strcat(temp, "\n");
		fputs(temp, F_tcbpost);
	}
}

/*****************************************************************************
 *  Name        : GenInterrupt_tcbpost_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_tcbpost_100pin(void)
{
	_ExcelResultInterrupt* p = &ExcelResultInterrupt;

	/* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	F_tcbpost = fopen("tcbpost.h", "w");

	/* 设置T1 */
	fputs(tcbpost_T1, F_tcbpost);

	/* 设置ID */
	GenInterrupt_tcbpost_ID(p);

	/* 设置中断函数申明 */
	fputs("\n#if ((osdSC== SC3) || (osdSC== SC4))\n", F_tcbpost);
	fputs("#endif\n\n", F_tcbpost);
	GenInterrupt_tcbpost_function(p);

	/* 设置T2 */
	fputs(tcbpost_T2, F_tcbpost);

	fclose(F_tcbpost);
}

/*****************************************************************************
 *  Name        : GenInterrupt_osConfigBlock_7
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_osConfigBlock_7(_ExcelResultInterrupt* p)
{
	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "      0,";
		char Char_IntName[500] = { 0 };
		char index[10];
		/* Tab字符串 */
		U8 tab[10] =
		{
			"										"
		};

		strncat(temp, tab, 2); /* 增加两个tab */
		strcat(temp, "/* ");

		sprintf(index, "%3d", Num);
		strcat(temp, index);

		strcat(temp, " ISR_");

		WideCharToMultiByte(CP_ACP, 0, p->IntName[Num], wcslen(p->IntName[Num]) + 1, Char_IntName, 256, NULL, NULL);

		strcat(temp, Char_IntName);

		strcat(temp, " */");
		strcat(temp, "\n");
		fputs(temp, F_osConfigBlock);
	}
	fputs("      0,		/* do not move */\n", F_osConfigBlock);
}

/*****************************************************************************
 *  Name        : GenInterrupt_osConfigBlock_8
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_osConfigBlock_8(_ExcelResultInterrupt* p)
{
	for (U16 Num = 0; Num < p->IntNum; Num++)
	{
		char temp[500] = "      INVALID_OSAPPLICATION,";
		char Char_IntName[500] = { 0 };
		char index[10];
		/* Tab字符串 */
		U8 tab[10] =
		{
			"										"
		};

		strncat(temp, tab, 2); /* 增加两个tab */
		strcat(temp, "/* ");

		sprintf(index, "%3d", Num);
		strcat(temp, index);

		strcat(temp, " ISR_");

		WideCharToMultiByte(CP_ACP, 0, p->IntName[Num], wcslen(p->IntName[Num]) + 1, Char_IntName, 256, NULL, NULL);

		strcat(temp, Char_IntName);

		strcat(temp, " */");
		strcat(temp, "\n");
		fputs(temp, F_osConfigBlock);
	}
	fputs("      INVALID_OSAPPLICATION,		/* do not move */\n", F_osConfigBlock);
}
/*****************************************************************************
 *  Name        : GenInterrupt_osConfigBlock_100pin
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
static void GenInterrupt_osConfigBlock_100pin(void)
{
	_ExcelResultInterrupt* p = &ExcelResultInterrupt;

	/* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	F_osConfigBlock = fopen("osConfigBlock.c", "w");

	/* 设置T1 */
	fputs(osConfigBlock_T1, F_osConfigBlock);

	/* Sub-Container 7, isr trusted */
	fputs("   /* Sub-Container 7, isr trusted */\n", F_osConfigBlock);
	fputs("   {\n", F_osConfigBlock);
	GenInterrupt_osConfigBlock_7(p);
	fputs("   },\n", F_osConfigBlock);

	/* Sub-Container 8, translation table: isr -> os-application */
	fputs("   /* Sub-Container 8, translation table: isr -> os-application */\n", F_osConfigBlock);
	fputs("   {\n", F_osConfigBlock);
	GenInterrupt_osConfigBlock_8(p);
	fputs("   },\n", F_osConfigBlock);

	fclose(F_osConfigBlock);
}




