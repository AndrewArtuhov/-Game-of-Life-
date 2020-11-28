#include "KeyW.h"
#include "Logic.h"
#include "FileW.h"

void Keyboard::InputValue() {
    int lenght{};
    int width{};
    while (width < 3 || lenght < 3) {
        cout << "������� ������ ������ ����(���������� 3):";
        width = GetCorrectInt();
        system("cls");
        cout << "������� ����� ����(���������� 3):";
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
        cout << "�� �����! ������� ������:";
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
        cout << "������� ������ �� ������ ������:" << endl;
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
            cout << "������� ���������� " << i + 1 << " ����� �� X:";
            coordinateCellX = GetCorrectInt();
            cout << "������� ���������� " << i + 1 << " ����� �� Y:";
            coordinateCellY = GetCorrectInt();
            system("cls");
            if ((++coordinateCellX > width) || (++coordinateCellY > length)) {
                cout << "�������� ������� �� ������� ����" << endl;
                isCellWithinField = false;
            }
        } while (!isCellWithinField);
        field[coordinateCellX][coordinateCellY] = viewCell;
        coordination.emplace_back(coordinateCellX);
        coordination.emplace_back(coordinateCellY);
    }
    cout << "������ �������� ������ � ����?\n"\
        "1 - ��\n"\
        "2 - ���";
    if (wf.GetAnswer())
    {
        wf.WriteToFile(coordination);
    }
    logic.ChangeOfGenerations(field, width, length);
    for (int i = 0; i < width; ++i)
        delete[] field[i];
    delete[] field;
}
