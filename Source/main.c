/************************************************************************
 *   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
 *                 All Rights Reserved.                                 *
 *   Department :  CT-ITC-OS-Peripheral team                            *
 *   AUTHOR     :  uidp5021                                             *
 ************************************************************************
 * Object		:
 * Module		: main����
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

/* Ϊ�������ɵ�EXE����ʱ����ʾ�ڿ� */
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

wchar_t* ccc = L"wodvfbfb";
int main()
{
	S8 ret = -1;

	logFile = fopen("Excel.log", "w"); /* ��ֻд�ļ������ļ������򳤶���Ϊ 0�������ļ�������ʧ�����������򴴽����ļ� */

	ret = OpenExcel(L"Pin100.xlsx");
	
	if (ret == -1)
	{
		write_log(logFile, "��excel���ʧ��!����\n");
		return ret;
	}
	ProcessExcelPinmux(book);
	ProcessExcelInterrupt(book);
	GenPinmux_100pin();
	GenInterrupt_100pin();
	CloseExcel(book);

	fclose(logFile);/* �ر��ļ� */
	ret = 0;
	printf("\nPress any key to exit...");
	_getch();

	return ret;
}

