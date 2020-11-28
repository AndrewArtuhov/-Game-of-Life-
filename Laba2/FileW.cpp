#include "FileW.h"
#include "Logic.h"
#include "Menu.h"
#include "KeyW.h"

void WorkFile::ReadFromFile()
{
    Logic logic{};
    string path{};
    while (true) {
        cout << "Введите путь к файлу:\n";
        getline(cin, path);
        if (IsFileOpenable(path)) {
            ifstream textFile(path);
            string str{};
            int count{};
            bool isNumber{};
            vector<int> coordination{};
            while (textFile.peek() != EOF) {
                int digit{};
                getline(textFile, str);
                isNumber = AreAllCharsInteger(str);
                if (isNumber) {
                    digit = stoi(str);
                    coordination.emplace_back(digit);
                    cout << digit << endl;
                }
                else
                    break;
            }
            if (!isNumber || coordination.size() % 2 != 0) {
                cout << "Координаты записаны неправильно!";
            }
            else {
                logic.CastVectorToArray(coordination);
                textFile.close();
                break;
            }
        }
        else
            cout << "Такого файла не существует файл\n";
    }
}

bool WorkFile::AreAllCharsInteger(string s)
{
    bool isNumber = false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]))
            isNumber = true;
        else {
            isNumber = false;
            break;
        }
    }
    return isNumber;
}

bool WorkFile::IsFileOpenable(string path)
{
    error_code ec{};
    ifstream textFile(path);
    if (!filesystem::is_regular_file(path, ec)) {

        textFile.close();
        return false;
    }
    else {
        bool isOpen = textFile.is_open();
        if (isOpen) {
            textFile.close();
        }
        return isOpen;
    }
   
}

void WorkFile::WriteToFile(vector<int> coordination)
{
    while (true)
    {
        system("cls");
        cout << "Введите путь к файлу\n";
        string path{};
        getline(cin, path);
        if (IsFileOpenable(path)) {
            cout << "Такой файл существует, хотите его перезаписать?\n"\
                "1 - Да\n"\
                "2 - Нет";
            if (GetAnswer()) {
                ofstream textFile(path);
                textFile.clear();
                for (int i = 0; i < static_cast<int>(coordination.size()); ++i) {
                    if (textFile.is_open())
                        textFile << coordination[i] << endl;
                }
                textFile.close();
                break;
            }
        }
        else {
            if (CreateFile(path)) {
                ofstream textFile(path);
                for (int i = 0; i < static_cast<int>(coordination.size()); ++i) {
                    if (textFile.is_open())
                        textFile << coordination[i] << endl;
                }
                textFile.close();
                break;
            }
        }
    }
}

bool WorkFile::CreateFile(string path) {
    ofstream textFile(path);
    error_code ec{};
    if (filesystem::is_regular_file(path, ec)) {
        textFile.open(path);
        textFile.close();
        return true;
    }
    else
        return false;
}

bool WorkFile::GetAnswer() {
    cout << endl;
    int index{};
    Menu menu;
    while (true) {
        char c{};
        do {
            c = _getch();
            index = menu.toDigit(c);
        } while (index == -1);
        system("cls");
        switch (index)
        {
        case Yes:
            return true;
        case No:
            return false;
        default:
            cout << "Введите верное число" << endl;
            break;
        }
    }
}