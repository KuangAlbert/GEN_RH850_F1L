/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: main函数
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
#include <conio.h>
#include "libxl.h"
#include <windows.h>
#include "ProcessExcel.h"
#include "log.h"
#include "GenPinmux100pin.h"

/* 为了让生成的EXE运行时不显示黑框 */
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

wchar_t* ccc = L"wodvfbfb";
int main()
{
	logFile = fopen("Excel.log", "w"); /* 打开只写文件，若文件存在则长度清为 0，即该文件内容消失，若不存在则创建该文件 */

	ProcessExcel();
	GenPinmux_100pin();

	fclose(logFile);/* 关闭文件 */

	//printf("\nPress any key to exit...");
	//_getch();

	return 0;
}

