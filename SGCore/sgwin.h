/*
* Copyright (c) 2020 Mohamed E. Saleh
* The code is licensed under the MIT License.
* You can check the file LICENSE for the full license.
*
* A file for windows specific functions.
*/

#pragma once
#include <string>

namespace sgl
{
	const unsigned int CL_BLACK = 0;
	const unsigned int CL_GREY = 8;
	const unsigned int CL_BLUE = 1;
	const unsigned int CL_BLUEI = CL_BLUE | CL_GREY;
	const unsigned int CL_GREEN = 2;
	const unsigned int CL_GREENI = CL_GREEN | CL_GREY;
	const unsigned int CL_RED = 4;
	const unsigned int CL_REDI = CL_RED | CL_GREY;
	const unsigned int CL_YELLOW = CL_GREEN | CL_RED;
	const unsigned int CL_YELLOWI = CL_YELLOW | CL_GREY;
	const unsigned int CL_CYAN = CL_GREEN | CL_BLUE;
	const unsigned int CL_CYANI = CL_CYAN | CL_GREY;
	const unsigned int CL_MAGENTA = CL_GREEN | CL_BLUE;
	const unsigned int CL_MAGENTAI = CL_MAGENTA | CL_GREY;
	const unsigned int CL_WHITE = CL_RED | CL_GREEN | CL_BLUE;
	const unsigned int CL_WHITEI = CL_WHITE | CL_GREY;

	void SetConsoleWindowSize(int width, int height);
	void ClearScreen(char fill = ' ');
	wchar_t* CreateScreenBuffer(int width, int height);
	void SetConsoleColor(unsigned int fg_color, unsigned int bg_color = CL_BLACK);
	void CopyToClipboard(const std::string& s);
	void ShowLastSystemError();
	void MoveWindow(unsigned int left, unsigned int top);
}