/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: 
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
	U8* RegisterString[30];	/* 寄存器的数值的字符串 */
	U8* BinaryString[30];	/* 二进制的字符串 */
	U8* CommentString[30];	/* 注释的字符串 */

}_PinmuxString;

typedef struct __AlternativeString
{
	U8 num;					/* IO口组的数量 */
	U8(*MacroString)[3][ROW_BUF_MAX];	/* 宏定义的字符串 */
	U8* RegisterString[30];	/* 寄存器的数值的字符串 */
	U8* BinaryString[30];	/* 二进制的字符串 */
	U8* CommentString[30];	/* 注释的字符串 */
}_AlternativeString;

extern void GenPinmux_100pin(void);
extern void OutPutGroupPinmuxString(_PinmuxString *s, U16* reg, U8 jump);
extern void OutPutAlternativeString(_AlternativeString *s, U16* RegPfc, U16* RegPfce, U16* RegPfcae);
extern void OutputModeString(_MacroStr* MacroStr, U8 mode);
#endif