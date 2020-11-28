#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <filesystem>
#include <vector>

using namespace std;
class WorkFile {
	enum menu_opt
	{
		Yes = 1,
		No,
	};
public:
	void ReadFromFile();
	void WriteToFile(vector<int> coordination);
	bool IsFileOpenable(string path);
	bool GetAnswer();
	bool CreateFile(string path);
	bool AreAllCharsInteger(string s);
};
