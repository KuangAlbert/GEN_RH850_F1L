/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: intvect_c0.c�еĳ����ַ���
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
char* intvect_c0_T1 =
{
	"/* file: D:/AutoSar generated code/intvect_c0.c */\n"
	"/* automatically generated by genRH850.exe, Version: 1.06 */\n"
	"/* Configuration file: D:/PROJECT/VICP/OIL/OIL CFG/BASELINE_EXTEND_EVENT_NOOSTM.oil */\n"
	"/* Generation time: Mon May 16 10:20:54 2016 */\n"
	"/* Unlimited license CBD1500834 for Huizhou Desay SV Automotive, Product License, Instrument Panel */\n"
	"/* Implementation: RH850_D1M */\n"
	"/* Version of general code: 9.01.04 */\n"
	"\n"
	"/*-History--------------------------------------------------------------\n"
	"* Version       Date    Name    Changes and comments\n"
	"*-----------------------------------------------------------------------\n"
	"* 0.1	   Jan 02,2016    Initial version\n"
	"*-----------------------------------------------------------------------\n"
	"* 0.2	   Dec 20,2016   ShangQiuju Add config file according using hw.\n"
	"*----------------------------------------------------------------------\n"
	"* 0.3          Dec 21,2016    PEI Jingli    remove ds03h hw config,using test file instead of.\n"
	"* ----------------------------------------------------------------------\n"
	"* 0.4          Jan 05,2017    ZhangJie     Delete test code for NMI_TEST\n"
	"* ----------------------------------------------------------------------\n"
	"* 0.5          Jan 06,2017    ZhangJie     Repleace NMI exception handle function\n"
	"* ----------------------------------------------------------------------\n"
	"* 0.6          Feb 07,2017    ZhangJie     Change CAN ISR from channel 0 to 2.\n"
	"*=====================================================================*/\n"
	"#if defined USE_QUOTE_INCLUDES\n"
	" #include \"vrm.h\"\n"
	"#else\n"
	" #include <vrm.h>\n"
	"#endif\n"
	"\n"
	"#define osdVrmGenMajRelNum 1\n"
	"#define osdVrmGenMinRelNum 6\n"
	"#if defined USE_QUOTE_INCLUDES\n"
	" #include \"vrm.h\"\n"
	"#else\n"
	" #include <vrm.h>\n"
	"#endif\n"
	"\n"
	"#if defined USE_QUOTE_INCLUDES\n"
	" #include \"Os.h\"\n"
	"#else\n"
	" #include <Os.h>\n"
	"#endif\n"
	"\n"
	"#if defined USE_QUOTE_INCLUDES\n"
	" #include \"osekext.h\"\n"
	"#else\n"
	" #include <osekext.h>\n"
	"#endif\n"
	"\n"
	"#include \"core_cfg.h\"\n"
	"\n"
	"#pragma asm\n"
	"\n"
	"   .align 512\n"
	"   .section \".osExceptionVectorTable_c0\", \"ax\"\n"
	"\n"
	"   .globl _osExceptionVectorTable_c0   /* start of the core exception vector table */\n"
	"_osExceptionVectorTable_c0:\n"
	"\n"
	"   .offset 0x0000\n"
	"   .globl _RESET\n"
	"   jr _RESET\n"
	"\n"
	"   .offset 0x0010\n"
	"   .globl _osCoreException_c0_0x0010\n"
	"_osCoreException_c0_0x0010:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0020\n"
	"   .globl _osCoreException_c0_0x0020\n"
	"_osCoreException_c0_0x0020:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0030\n"
	"   .globl _osCoreException_c0_0x0030\n"
	"_osCoreException_c0_0x0030:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0040\n"
	"   .globl _osCoreException_c0_0x0040\n"
	"_osCoreException_c0_0x0040:\n"
	"   jr _osTrapDispatcher_c0\n"
	"\n"
	"   .offset 0x0050\n"
	"   .globl _osCoreException_c0_0x0050\n"
	"_osCoreException_c0_0x0050:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0060\n"
	"   .globl _osCoreException_c0_0x0060\n"
	"_osCoreException_c0_0x0060:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0070\n"
	"   .globl _osCoreException_c0_0x0070\n"
	"_osCoreException_c0_0x0070:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0080\n"
	"   .globl _osCoreException_c0_0x0080\n"
	"_osCoreException_c0_0x0080:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0090\n"
	"   .globl _osCoreException_c0_0x0090\n"
	"_osCoreException_c0_0x0090:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x00a0\n"
	"   .globl _osCoreException_c0_0x00a0\n"
	"_osCoreException_c0_0x00a0:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x00b0\n"
	"   .globl _osCoreException_c0_0x00b0\n"
	"_osCoreException_c0_0x00b0:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x00c0\n"
	"   .globl _osCoreException_c0_0x00c0\n"
	"_osCoreException_c0_0x00c0:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x00d0\n"
	"   .globl _osCoreException_c0_0x00d0\n"
	"_osCoreException_c0_0x00d0:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x00e0\n"
	"   .globl _osCoreException_c0_0x00e0\n"
	"_osCoreException_c0_0x00e0:\n"
	"   jr _FENMIHandler\n"
	"\n"
	"   .offset 0x00f0\n"
	"   .globl _osCoreException_c0_0x00f0\n"
	"_osCoreException_c0_0x00f0:\n"
	"   jr _osUnhandledCoreException\n"
	"\n"
	"   .offset 0x0100\n"
	"   .globl _osCoreException_c0_0x0100\n"
	"_osCoreException_c0_0x0100:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0110\n"
	"   .globl _osCoreException_c0_0x0110\n"
	"_osCoreException_c0_0x0110:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0120\n"
	"   .globl _osCoreException_c0_0x0120\n"
	"_osCoreException_c0_0x0120:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0130\n"
	"   .globl _osCoreException_c0_0x0130\n"
	"_osCoreException_c0_0x0130:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0140\n"
	"   .globl _osCoreException_c0_0x0140\n"
	"_osCoreException_c0_0x0140:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0150\n"
	"   .globl _osCoreException_c0_0x0150\n"
	"_osCoreException_c0_0x0150:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0160\n"
	"   .globl _osCoreException_c0_0x0160\n"
	"_osCoreException_c0_0x0160:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0170\n"
	"   .globl _osCoreException_c0_0x0170\n"
	"_osCoreException_c0_0x0170:\n"
	"   jr _osUnhandledDirectBranchException		/*test WDT0 NMI INT*/\n"
	"	//jr	_priority7_interrupt\n"
	"\n"
	"   \n"
	"   .offset 0x0180\n"
	"   .globl _osCoreException_c0_0x0180\n"
	"_osCoreException_c0_0x0180:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x0190\n"
	"   .globl _osCoreException_c0_0x0190\n"
	"_osCoreException_c0_0x0190:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01a0\n"
	"   .globl _osCoreException_c0_0x01a0\n"
	"_osCoreException_c0_0x01a0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01b0\n"
	"   .globl _osCoreException_c0_0x01b0\n"
	"_osCoreException_c0_0x01b0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01c0\n"
	"   .globl _osCoreException_c0_0x01c0\n"
	"_osCoreException_c0_0x01c0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01d0\n"
	"   .globl _osCoreException_c0_0x01d0\n"
	"_osCoreException_c0_0x01d0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01e0\n"
	"   .globl _osCoreException_c0_0x01e0\n"
	"_osCoreException_c0_0x01e0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .offset 0x01f0\n"
	"   .globl _osCoreException_c0_0x01f0\n"
	"_osCoreException_c0_0x01f0:\n"
	"   jr _osUnhandledDirectBranchException\n"
	"\n"
	"   .globl _osExceptionVectorTableEnd_c0\n"
	"_osExceptionVectorTableEnd_c0:   /* end of the core exception vector table */\n"
	"\n"
	"#pragma endasm\n"
	"\n"
};