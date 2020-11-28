#include "KeyW.h"
#include "Logic.h"
#include "FileW.h"

void Keyboard::InputValue() {
    int lenght{};
    int width{};
    while (width < 3 || lenght < 3) {
        cout << "Введите размер ширину поля(минимально 3):";
        width = GetCorrectInt();
        system("cls");
        cout << "Введите длину поля(минимально 3):";
        lenght = GetCorrectInt();
        system("cls");
    }
    width += 2;
    lenght += 2;
    SendCoordinates(width, lenght);
}

int Keyboard::GetCorrectInt() {

    int a;
    while(true){
        cin >> a;
        if (cin.good()) {
            break;
        }
        cin.clear();
        cout << "Не число! Введите заново:";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return a;
}

void Keyboard::SendCoordinates(int width, int length) {
    Logic logic{};
    WorkFile wf{};
    vector<int> coordination{};
    coordination.emplace_back(width - 2);
    coordination.emplace_back(length - 2);
    int** field = new int* [width];
    for (int i = 0; i < width; ++i){
        field[i] = new int[length];
        for (int j = 0; j < length; ++j) {
            field[i][j] = 0;
        }
    }
    int cellsCount{};
    do {
        cout << "Сколько клеток Вы ходите задать:" << endl;
        cellsCount = GetCorrectInt();
        system("cls");
    } while (cellsCount > (width * length) || cellsCount < 0);

    int coordinateCellX{0};
    int coordinateCellY{0};
    int viewCell = 1;
    bool isCellWithinField{};
    for (int i = 0; i < cellsCount; ++i) {
        do {
            isCellWithinField = true;
            cout << "Введите координаты " << i + 1 << " точки по X:";
            coordinateCellX = GetCorrectInt();
            cout << "Введите координаты " << i + 1 << " точки по Y:";
            coordinateCellY = GetCorrectInt();
            system("cls");
            if ((++coordinateCellX > width) || (++coordinateCellY > length)) {
                cout << "Значение выходит за границы поля" << endl;
                isCellWithinField = false;
            }
        } while (!isCellWithinField);
        field[coordinateCellX][coordinateCellY] = viewCell;
        coordination.emplace_back(coordinateCellX);
        coordination.emplace_back(coordinateCellY);
    }
    cout << "Хотите записать данные в файл?\n"\
        "1 - Да\n"\
        "2 - Нет";
    if (wf.GetAnswer())
    {
        wf.WriteToFile(coordination);
    }
    logic.ChangeOfGenerations(field, width, length);
    for (int i = 0; i < width; ++i)
        delete[] field[i];
    delete[] field;
}
