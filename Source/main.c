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
#include "GenPinmux_pin.h"

/* Ϊ�������ɵ�EXE����ʱ����ʾ�ڿ� */
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

wchar_t* ccc = L"wodvfbfb";
U8 Pin_Type;




long long SignedTypeConversion(long long dat, U8 nbit)
{
	long long result;
	unsigned long long sys = 1 << (nbit - 1);

	printf("%d %d\n", dat,sys);

	if (dat <= sys)
	{
		result = dat;
		printf("haha");
	}
	else
	{
		result = (1 << nbit) - dat;
	}

	printf("%f \n",  result);
	return result;
}
int main(int argc,char *argv[])
{

    //int main(int argc,char *argv[])
	S8 ret = -1;
    char Filename_100 = "Pin100.xlsx";
    char Filename_144 = "Pin144.xlsx";
        
	logFile = fopen("Excel.log", "w"); /* ��ֻд�ļ������ļ������򳤶���Ϊ 0�������ļ�������ʧ�����������򴴽����ļ� */

	SignedTypeConversion(122l, 8);


    ret = OpenExcel(L"Pin144.xlsx");
    Pin_Type = Pin_144;
    Pinmux_Config(Pin_Type);
    
    if (ret == -1)
    {
		write_log(logFile, "��excel���ʧ��!����\n");
		return ret;
	}
    
    /*if (strcmp(argv[0],Filename_100) == 0)
    {
        ret = OpenExcel(L"Pin100.xlsx");
        Pin_Type = Pin_100;
        Pinmux_Config(Pin_Type);
        
    }

    else if ((strcmp(argv[0],Filename_144) == 0))
    {
        ret = OpenExcel(L"Pin144.xlsx");
        Pin_Type = Pin_144;
        Pinmux_Config(Pin_Type);
    }
    else if (ret == -1)
    {
		write_log(logFile, "��excel���ʧ��!����\n");
		return ret;
	}
    */
    
	ProcessExcelPinmux(book);
	ProcessExcelInterrupt(book);
	GenPinmux();
	GenInterrupt_100pin();
	CloseExcel(book);

	fclose(logFile);/* �ر��ļ� */
	ret = 0;
	printf("\nPress any key to exit...");
	_getch();

	return ret;
}

