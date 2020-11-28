#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <limits>

using namespace std;
class Keyboard {
	enum mag_numbers
	{
		one = 1,
		two,
		three
	};
public:
	void InputValue();
	int GetCorrectInt();
	void SendCoordinates(int widht, int leght);
};
