#include <stdio.h>
#include <conio.h>
#include "libxl.h"
#include <windows.h>

char hh[256];
int main()
{
    BookHandle book = xlCreateXMLBook();
	const wchar_t * x = L"Halil Kural";
	const wchar_t * y = L"windows-2723210a07c4e90162b26966a8jcdboe";
	xlBookSetKey(book, x, y);
	if (book)
	{
		if (xlBookLoad(book, L"Pin100.xlsx"))
		{
			SheetHandle sheet = xlBookGetSheet(book, 0);
			if (sheet)
			{
				double d = xlSheetReadNum(sheet, 3, 1, 0);
				const wchar_t* s = xlSheetReadStr(sheet, 1, 5, 0);

				printf("%f\n",d);
				printf("%ls\n", s);
				
				WideCharToMultiByte(CP_ACP, 0, s, wcslen(s) + 1, hh, 256, NULL, NULL);

				printf("%s\n", hh);
				printf("%c\n", hh[0]);
				printf("%c\n", hh[1]);

				xlSheetWriteNum(sheet, 3, 1, d * 2, 0);
				xlSheetWriteStr(sheet, 4, 1, L"1new string", 0);
			}

			if (xlBookSave(book, L"Pin100.xlsx")) printf("\nFile example.xls has been modified.\n");
		}

		xlBookRelease(book);
	}

	printf("\nPress any key to exit...");
	_getch();

	return 0;
}

