//
//  main.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Cell.h"
#include "Board.h"
#include "NumberSet.h"
#include "Game.h"
using namespace cs31;
using namespace std;

void clearScreen();
void beep();

int main()
{
	using namespace cs31;
	using namespace std;

	clearScreen();

	Game game;
	game.buildRandomBoard();

	int row, column, value;
	bool result = true;
	std::string action, message = "(s)et (e)valuate (q)uit: ";
	cout << game.display(message) << endl;

	do
	{
		getline(cin, action);
		while (action.size() == 0)
		{
			getline(cin, action);  // no blank entries allowed....
		}
		switch (action[0])
		{
		default:   // if bad move, nobody moves
			beep();  // beep
			continue;
		case 'Q':
		case 'q':
			return 0;
		case 'S':
		case 's':
			cout << "row:";
			cin >> row;
			cout << "column:";
			cin >> column;
			cout << "value:";
			cin >> value;
			cout << endl;

			result = game.acceptValue(value, row, column);
			if (!result)
				beep();  // beep
			cout << game.display(message) << endl;
			break;
		case 'E':
		case 'e':
			cout << "evaluate:" << game.evaluate() << endl;
			cout << game.display(message) << endl;
			break;
		}

	} while (!game.completed());

	return(0);
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen and beep implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	COORD upperLeft = { 0, 0 };
	DWORD dwCharsWritten;
	FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
		&dwCharsWritten);
	SetConsoleCursorPosition(hConsole, upperLeft);
}

void beep()
{
	cout << '\a' << endl;
}

#endif

#ifdef __APPLE__

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

void beep()
{
	// system( "/usr/bin/osascript -e  \"beep 1\"" );
	// printf("%c", 7);
	// system( "echo $'\\a'" );
	// NSBeep();
}

#endif

#if __unix__ // not Microsoft Visual C++, not Mac, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
	using namespace std;
	static const char* term = getenv("TERM");
	if (term == nullptr || strcmp(term, "dumb") == 0)
	{
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
	}
	else
	{
		static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
		cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
	}
}

void beep()
{
	cout << '\a' << endl;
}

#endif

