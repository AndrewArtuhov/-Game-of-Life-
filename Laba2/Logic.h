#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
class Logic {
public:
	void ChangeOfGenerations(int** field, int width, int length);
	void CastVectorToArray(vector<int> checkedText);
	void PrintField(int** field, int width, int length);
	void CreateOrDestroyCell(int** field, int** newfield, int i, int j);
};