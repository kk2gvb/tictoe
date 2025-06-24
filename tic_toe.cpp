#include <iostream>
using namespace std;

// Функция для вывода игрового поля
void printField(char field[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
            if (j < 2) cout << "| ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Функция для проверки победы
bool checkWin(char field[3][3], char player) {
    // Проверка строк
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == player && field[i][1] == player && field[i][2] == player) return true;
    }
    // Проверка столбцов
    for (int i = 0; i < 3; i++) {
        if (field[0][i] == player && field[1][i] == player && field[2][i] == player) return true;
    }
    // Проверка диагоналей
    if ((field[0][0] == player && field[1][1] == player && field[2][2] == player) ||
        (field[0][2] == player && field[1][1] == player && field[2][0] == player)) return true;
    return false;
}

// Функция для проверки ничьей
bool checkDraw(char field[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (field[i][j] != 'X' && field[i][j] != 'O') return false;
        }
    }
    return true;
}

int main() {
    char field[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    int move;

    while (true) {
        printField(field);
        cout << "Игрок " << player << ", введите номер клетки: ";
        cin >> move;

        // Проверка правильности ввода
        if (move < 1 || move > 9) {
            cout << "Неправильный номер клетки. Попробуйте еще раз." << endl;
            continue;
        }

        // Преобразование номера клетки в координаты
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Проверка занятости клетки
        if (field[row][col] == 'X' || field[row][col] == 'O') {
            cout << "Клетка уже занята. Выберите другую." << endl;
            continue;
        }

        // Сделать ход
        field[row][col] = player;

        // Проверка победы
        if (checkWin(field, player)) {
            printField(field);
            cout << "Игрок " << player << " выиграл!" << endl;
            break;
        }

        // Проверка ничьей
        if (checkDraw(field)) {
            printField(field);
            cout << "Ничья!" << endl;
            break;
        }

        // Смена игрока
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
