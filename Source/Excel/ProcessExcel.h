/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: Process Excel
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
#ifndef __PROCESS_EXCEL_
#define __PROCESS_EXCEL_
#include "config.h"
#include "PinmuxRegister.h"
#include "libxl.h"

#define R(a) (a-1)
#define L(b) (b-65)


#define PIN_OUT 0
#define PIN_IN 1

#define		SET_BIT(x, n)		x=( x | ((1U)<<(n)) )
#define		CLEAR_BIT(x,n)		x=(x &~(1U<<(n)))

#define MODE_NUM 3
#define Intrrupt_Num 400     /* 144pin中断总数    */
#define PORT_NUM 12          /* 144pin使用的port个数     */

typedef struct __ExcelResultPinmux
{
	U8 mode;		/* 引脚模式，ACTIVE,STANDBY,RESET */
	U8 whether;		/* 是否配置 */
	U8 gpio_alt;	/* GPIO还是功能口 */
	U8 function;	/* 第几功能 */
	U8 direction;	/* 引脚输出方向 */
	U8 InputBuffer;
	U8 PullUp;
	U8 PullDown;
	U8 bidMode;
	U8 DriverStrength;
	U8 OutputMode;
	U8 PortValue;
	_GroupNumber GroupNumber;
	U8 PortNumber;
	_PORT_TYPE PORT_TYPE;
	U8 RegType;
	U8 AltType;
	U8 AltNum;
}_ExcelResultPinmux;

typedef struct __ExcelResultInterrupt
{
	U8 IntConfigEnable[Intrrupt_Num];		/* 已经配置的中断总数*/
	U16 IntNum;						    /* 配置的中断总数*/
	U16 IntNumber[Intrrupt_Num];				/* 中断号   */
	wchar_t * IntName[Intrrupt_Num][100];	/* 中断源名字     */
	wchar_t * IntFunName[Intrrupt_Num][100];	/* 中断函数名名字*/
}_ExcelResultInterrupt;

extern U16 PMC[MODE_NUM][PORT_NUM];		/* port mode */
extern U16 PIPC[MODE_NUM][PORT_NUM];		/* Port IP Control */
extern U16 PM[MODE_NUM][PORT_NUM];			/* output/input */
extern U16 PIBC[MODE_NUM][PORT_NUM];		/* Port InputBuffer Control */


extern U16 PFC[MODE_NUM][PORT_NUM];		/* alternative mode */
extern U16 PFCE[MODE_NUM][PORT_NUM];
extern U16 PFCAE[MODE_NUM][PORT_NUM];

extern U16 PBDC[MODE_NUM][PORT_NUM];		/* Port Bidirection Control */
extern U16 PU[MODE_NUM][PORT_NUM];			/* PullUp Control */
extern U16 PD[MODE_NUM][PORT_NUM];			/* PullDown Control */
extern U16 PDSC[MODE_NUM][PORT_NUM];		/* Port Driver Strength */
extern U16 PODC[MODE_NUM][PORT_NUM];		/* output mode */
extern U16 P[MODE_NUM][PORT_NUM];			/* Port Value */
extern BookHandle book;
extern _ExcelResultInterrupt ExcelResultInterrupt;

extern S8 OpenExcel(wchar_t* ExcelName);
extern U8 InterruptConfigEnable[Intrrupt_Num];
extern void ProcessExcelPinmux(BookHandle book);
extern void ProcessExcelInterrupt(BookHandle book);
extern U8 SearchAlternativNum(wchar_t* cell, U16 Row, U8* type);
extern S8 OpenExcel(wchar_t* ExcelName);
extern void CloseExcel(BookHandle book);
extern void Pinmux_Config(U8 PinType);
#endif /* PROCESS_EXCEL */