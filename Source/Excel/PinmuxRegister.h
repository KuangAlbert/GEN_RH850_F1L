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
#ifndef __PINMUX_REGISTER_
#define __PINMUX_REGISTER_

#include "config.h"

typedef enum
{
	P0,
	P8,
	P9,
	P10,
	P11,
	AP,
	JP
} _GroupNumber;

typedef enum
{
	ACTIVE,
	STANDBY,
	RESET
} _PORT_TYPE;

typedef struct _c_pinmux_register_bit_Tag
{
	U32 bit0 : 1;
	U32 bit1 : 1;
	U32 bit2 : 1;
	U32 bit3 : 1;
	U32 bit4 : 1;
	U32 bit5 : 1;
	U32 bit6 : 1;
	U32 bit7 : 1;
	U32 bit8 : 1;
	U32 bit9 : 1;
	U32 bit10 : 1;
	U32 bit11 : 1;
	U32 bit12 : 1;
	U32 bit13 : 1;
	U32 bit14 : 1;
	U32 bit15 : 1;
	U32 bit16 : 1;
	U32 bit17 : 1;
	U32 bit18 : 1;
	U32 bit19 : 1;
	U32 bit20 : 1;
	U32 bit21 : 1;
	U32 bit22 : 1;
	U32 bit23 : 1;
	U32 bit24 : 1;
	U32 bit25 : 1;
	U32 bit26 : 1;
	U32 bit27 : 1;
	U32 bit28 : 1;
	U32 bit29 : 1;
	U32 bit30 : 1;
	U32 bit31 : 1;
} _c_pinmux_register_bit;

typedef union _c_pinmux_register_bit_BufTag
{
	U32 register_int;
	_c_pinmux_register_bit register_bit;
}_c_pinmux_register_bit_Buf;

#endif // __PINMUX_REGISTER_
