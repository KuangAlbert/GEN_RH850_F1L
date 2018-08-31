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
	M_PMC,
	M_PM,
	M_PIBC,
	M_PBDC,
	M_PU,
	M_PD,
	M_PDSC,
	M_PODC,
	M_P,
	M_ALT,
	M_PIPC
} _MacroArr;

typedef enum
{
	ACTIVE,
	STANDBY,
	RESET
} _PORT_TYPE;

typedef enum
{
	GPIO,
	ALT,
} _GPIO_ALT;

#define YES 1
#define NO	0

#define ENABLE 1
#define DISABLE 0

#endif // __PINMUX_REGISTER_
