#include "KeyW.h"
#include "Logic.h"
#include "Menu.h"
#include "FileW.h"


void Logic::ChangeOfGenerations(int** field, int width, int length) {
	WorkFile wf{};
	Menu menu{};
	int** newfield = new int* [width];
	for (int i = 0; i < width; ++i){
		newfield[i] = new int[length];
	}
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < length; ++j) {
			newfield[i][j] = field[i][j];
		}
	}
	vector<int> coordination{};
	coordination.emplace_back(width - 2);
	coordination.emplace_back(length - 2);
	bool shouldChangeOnKeyPress = menu.SelectFieldDisplayMode();
	PrintField(field, width, length);
	int exit{};
	while (exit < width*length) {
		exit = 0;
		for (int i = 1; i < width - 1; ++i) {
			for (int j = 1; j < length - 1; ++j) {
				CreateOrDestroyCell(field, newfield, i, j);				
				if (field[i][j] == 1) {
					coordination.emplace_back(i);
					coordination.emplace_back(j);
				}
			}
		}	
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < length; ++j) {
				if (field[i][j] == newfield[i][j])
					++exit;
				field[i][j] = newfield[i][j];
			}
		}
		while (shouldChangeOnKeyPress) {
			cout << "Нажмите D, чтобы продолжить дальше или R, чтобы сохранить текущее состояние поля:";
			string option;
			cin >> option;
			if (option == "D") 
				break;
			else if(option == "R")
				wf.WriteToFile(coordination);
			else {
				system("cls");
				cout << "Введено неверное значение";
			}
		}

		PrintField(field, width, length);
	}
	for (int i = 0; i < width; ++i)
		delete[] newfield[i];
	delete[] newfield;
}

void Logic::CastVectorToArray(vector<int> coordination)
{
	Keyboard key{};
	int width = coordination[0] + 2;
	int length = coordination[1] + 2;
	int** field = new int* [width];
	for (int i = 0; i < width; ++i) {
		field[i] = new int[length];
		for (int j = 0; j < length; ++j) {
			field[i][j] = 0;
		}
	}
	int count{2};
	while (count < static_cast<int>(coordination.size())) {		
		field[++coordination[count]][++coordination[count + 1]] = 1;
		count += 2;
	}
	ChangeOfGenerations(field, width, length);
}

void Logic::PrintField(int** field, int width, int length)
{
	system("cls");
	for (int i = 1; i < width - 1; ++i) {
		for (int j = 1; j < length - 1; ++j) {
			if (field[i][j] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Logic::CreateOrDestroyCell(int** field, int** newfield, int i, int j)
{
	int coutNeighbor{};
	for (int n = i - 1; n < i + 2; ++n) {
		for (int m = j - 1; m < j + 2; ++m) {
			coutNeighbor = coutNeighbor + field[n][m];
		}
	}
	coutNeighbor = coutNeighbor - field[i][j];
	if (coutNeighbor == 3 && field[i][j] == 0) 
			newfield[i][j] = 1;
	if((coutNeighbor < 2 || coutNeighbor > 3) && field[i][j] == 1)
			newfield[i][j] = 0;
}

