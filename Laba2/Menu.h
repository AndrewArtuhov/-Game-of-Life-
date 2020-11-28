#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
class Menu {
	enum menu_opt
	{
		one = 1,
		two,
		three
	};
public:
	void WaitForKeyPress();
	void ShowMenu();
	int toDigit(char c);
	void SelectInputMode();
	bool SelectFieldDisplayMode();
};
