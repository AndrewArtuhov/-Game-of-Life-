#include <Windows.h>
#include "Logic.h"
#include <locale.h>
#include <iostream>
#include <string>
#include "Menu.h"


using namespace std;
int main()
{
    Menu menu{};
    const string colorWhite = "color F0";
    system(colorWhite.c_str());
    setlocale(LC_ALL, "");
    cout << "Программа создана студентом 474 группы Артюховым Андреем в рамках лабораторного практимуа по ЛиПОАС.\n"\
        "Программа должна выполнять имитацию жизни колонии клеток.\n";
    menu.WaitForKeyPress();
    menu.ShowMenu();
    return 0;
}
