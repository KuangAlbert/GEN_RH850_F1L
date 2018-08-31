/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: 生成100pin的头文件
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
#ifndef __GEN_PINMUX_100PIN_
#define __GEN_PINMUX_100PIN_
#include "config.h"

#define ROW_BUF_MAX 4000

typedef U8(*_MacroStr)[ROW_BUF_MAX];

typedef struct __PinmuxString
{
	U8 num;					/* IO口组的数量 */
	_MacroStr MacroString;	/* 宏定义的字符串 */
	U16 *reg;				/* 要显示的寄存器组指针 */
	U8 jump;				/* 需要跳过输出到文件的IO组，主要针对AP和JP口 */
}_PinmuxString;

typedef struct __AlternativeString
{
	U8 num;					/* IO口组的数量 */
	U8(*MacroString)[3][ROW_BUF_MAX];	/* 宏定义的字符串 */

}_AlternativeString;

extern void GenPinmux_100pin(void);
extern void OutPutGroupPinmuxString(_PinmuxString *s);
extern void OutPutAlternativeString(_AlternativeString *s, U16* RegPfc, U16* RegPfce, U16* RegPfcae);
extern void OutputModeString(_MacroStr* MacroStr, U8 mode);
#endif