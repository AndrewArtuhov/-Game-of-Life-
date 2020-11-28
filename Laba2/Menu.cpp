#include "Menu.h"
#include "Logic.h"
#include "KeyW.h"
#include "FileW.h"

void Menu::SelectInputMode()
{
    Keyboard key{};
    WorkFile wf{};
    while (true) {
        int index{};
        cout << "Как Вы планируете ввести размер матрицы и раставить клетки?:\n"\
            "1 - Ввести с клавиатуры\n"\
            "2 - Добавить из файла\n"\
            "3 - Перейти в меню\n";
        char c{};
        do {
            c = _getch();
            index = toDigit(c);
        } while (index == -1);
        system("cls");
        switch (index) {
        case one:
            key.InputValue();
            return;
        case two:
            wf.ReadFromFile();
            return;
        case three:
            return;
        default:
            system("cls");
            cout << "Введено неверное значение\n";
        }
    }
}

void Menu::WaitForKeyPress()
{
    cout << "Press Space...";
    char key{};
    while (true) {
        key = _getch();
        if (key == ' ') {
            system("cls");
            break;
        }
    }
}

int Menu::toDigit(char c) {
    if (isdigit(c)) {
        return c - ('1' - 1);
    }
    return -1;
}

void Menu::ShowMenu() {
    while (true) {
        int index{};
        cout << "Что Вы хотите сделать?:\n"\
            "1 - Начать\n"\
            "2 - Выход\n";
        char c{};
        do {
            c = _getch();
            index = toDigit(c);
        } while (index == -1);

        system("cls");
        switch (index) {
        case one:
            SelectInputMode();
            break;
        case two:
            return;
        default:
            break;
        }
    }
}

bool Menu::SelectFieldDisplayMode() {
    while (true) {
        int index{};
        cout << "Что Вы хотите сделать?:\n"\
            "1 - Непрерывный вывод поля\n"\
            "2 - Вывод поля по нажатию на кнопку\n";
        char c{};
        do {
            c = _getch();
            index = toDigit(c);
        } while (index == -1);

        system("cls");
        switch (index) {
        case one:
            return false;
        case two:
            return true;
        default:
            break;
        }
    }
}