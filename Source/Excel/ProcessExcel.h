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

#define R(a) (a-1)
#define L(b) (b-65)

#define R_STAET_100 R(2)		/* 行开始检索 */
#define R_END_100	R(301)		/* 行检索结束 */

#define L_STAET_100 L('C')		/* 列开始检索 */
#define L_END_100	L('P')		/* 列检索结束 */

#define PIN_OUT 0
#define PIN_IN 1

#define		SET_BIT(x, n)		x=( x | ((1U)<<(n)) )
#define		CLEAR_BIT(x,n)		x=(x &~(1U<<(n)))

typedef struct __ExcelResult
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
}_ExcelResult;

extern void ProcessExcel(void);
extern U8 SearchAlternativNum(wchar_t* cell, U16 Row, U8* type);

#endif /* PROCESS_EXCEL */