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
    cout << "��������� ������� ��������� 474 ������ ��������� ������� � ������ ������������� ��������� �� ������.\n"\
        "��������� ������ ��������� �������� ����� ������� ������.\n";
    menu.WaitForKeyPress();
    menu.ShowMenu();
    return 0;
}
