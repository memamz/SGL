#include "sgwin.h"
#include <iostream>
#include <Windows.h>

namespace sgl
{
	void SetConsoleWindowSize(int width, int height)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		if (h == INVALID_HANDLE_VALUE)
			throw std::runtime_error("Unable to get stdout handle.");

		// If either dimension is greater than the largest console window we can have,
		// there is no point in attempting the change.
		{
			COORD largestSize = GetLargestConsoleWindowSize(h);
			if (width > largestSize.X)
				throw std::invalid_argument("The width is too large.");
			if (height > largestSize.Y)
				throw std::invalid_argument("The height is too large.");
		}


		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
			throw std::runtime_error("Unable to retrieve screen buffer info.");

		SMALL_RECT& winInfo = bufferInfo.srWindow;
		COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

		if (windowSize.X > width || windowSize.Y > height)
		{
			// window size needs to be adjusted before the buffer size can be reduced.
			SMALL_RECT info =
			{
				0,
				0,
				width < windowSize.X ? width - 1 : windowSize.X - 1,
				height < windowSize.Y ? height - 1 : windowSize.Y - 1
			};

			if (!SetConsoleWindowInfo(h, TRUE, &info))
				throw std::runtime_error("Unable to resize window before resizing buffer.");
		}

		COORD size = { width, height };
		if (!SetConsoleScreenBufferSize(h, size))
			throw std::runtime_error("Unable to resize screen buffer.");


		SMALL_RECT info = { 0, 0, width - 1, height - 1 };
		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window after resizing buffer.");
	}

	void ClearScreen(char fill)
	{
		COORD tl = { 0,0 };
		CONSOLE_SCREEN_BUFFER_INFO s;
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(console, &s);
		DWORD written, cells = s.dwSize.X * s.dwSize.Y;
		FillConsoleOutputCharacter(console, fill, cells, tl, &written);
		FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
		SetConsoleCursorPosition(console, tl);
	}

	wchar_t* CreateScreenBuffer(int width, int height)
	{
		wchar_t* screen = new wchar_t[width * height];
		HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		DWORD dwBytesWritten = 0;

		return screen;
	}

	void SetConsoleColor(unsigned int fg_color, unsigned int bg_color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, fg_color | (bg_color * 16));
	}

	void CopyToClipboard(const std::string& s)
	{
		const size_t len = s.length() + 1;

		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
		memcpy(GlobalLock(hMem), s.c_str(), len);
		GlobalUnlock(hMem);

		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_TEXT, hMem);
		CloseClipboard();
	}

	void ShowLastSystemError()
	{
		LPSTR messageBuffer;
		FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			0,          // source
			GetLastError(),
			0,          // lang
			(LPSTR)&messageBuffer,
			0,
			NULL);

		std::cerr << messageBuffer << '\n';
		LocalFree(messageBuffer);
	}

	void MoveWindow(unsigned int left, unsigned int top)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, left, top, (r.right-r.left), (r.top - r.bottom), TRUE);
	}
}