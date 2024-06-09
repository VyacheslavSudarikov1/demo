#include <iostream>
#include <cmath>

// Функция для вычисления суммы последовательности с использованием рекуррентного выражения
void calculateSums(int n, double e) {
    double sum_n = 0; // Сумма первых n членов
    double sum_e = 0; // Сумма членов, не меньших e по модулю

    double term = 1; // Начальное значение для a_0

    for (int k = 0; k <= n; ++k) {
        sum_n += term;
        if (std::abs(term) >= e) {
            sum_e += term;
        }
        // Вычисляем следующий член последовательности
        term = -term / (k + 1);
    }

    std::cout << "Сумма первых " << n << " членов: " << sum_n << std::endl;
    std::cout << "Сумма членов, не меньших " << e << " по модулю: " << sum_e << std::endl;
}

int main() {
    int n;
    double e;

    // Проверка пользовательского ввода
    std::cout << "Введите количество членов последовательности (n): ";
    while (!(std::cin >> n) || n < 1) {
        std::cout << "Ошибка! Введите положительное целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Введите число e: ";
    while (!(std::cin >> e) || e <= 0) {
        std::cout << "Ошибка! Введите положительное число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    calculateSums(n, e);

    return 0;
}
