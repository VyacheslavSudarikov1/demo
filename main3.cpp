#include <iostream>
#include <cmath> // Для использования функции pow
#include <limits> // Для использования numeric_limits
using namespace std;

// Прототипы функций
double getValue();
double checkCondition(const double a);

int main() {
    cout << "Введите три вещественных числа: " << endl;
    double a = getValue();
    double b = getValue();
    double c = getValue();
    cout << "Квадрат, если число положительное, иначе в четвертую степень:" << endl;
    cout << a << " -> " << checkCondition(a) << endl;
    cout << b << " -> " << checkCondition(b) << endl;
    cout << c << " -> " << checkCondition(c) << endl;
    return 0;
}

double checkCondition(const double a) {
    if (a >= 0) {
        return pow(a, 2);
    } else {
        return pow(a, 4);
    }
}

double getValue() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear(); // Сбросить состояние потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшиеся символы в потоке
            cout << "Некорректное значение. Пожалуйста, введите число: " << endl;
        } else {
            break; // Выход из цикла, если ввод корректен
        }
    }
    return value;
}

