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


#endif // __PINMUX_REGISTER_
