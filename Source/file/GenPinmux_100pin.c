/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: 生成F1L 100pin的pinmux
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
#include <stdio.h>
#include <stdarg.h>
#include "GenPinmux100pin.h"

FILE* F100;


/*****************************************************************************
 *  Name        : ProcessExcel
 *  Description :
 *  Parameter   :
 *  Returns     : None
*****************************************************************************/
void GenPinmux_100pin(void)
{
	char* str= "/***********************************************************************\n
		*   Copyright(C) Huizhou Desay SV Automotive Co., Ltd.                *\n
		*   All Rights Reserved.                                               *\n
		*   Department : RN RD SW1                                             *\n
		*   AUTHOR : Shao Guangxian                                        *\";

	F100 = fopen("MCU_PIN_CC.H", "w"); /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */
	fputs(str, F100);
	fclose(F100);
}