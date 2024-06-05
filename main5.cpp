#include <iostream>
#include <cmath>

// Функция для вычисления факториала числа
double factorial(int k) {
    double result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= i;
    }
    return result;
}

// Функция для вычисления суммы последовательности
void calculateSums(int n, double e) {
    double sum_n = 0; // Сумма первых n членов
    double sum_e = 0; // Сумма членов, не меньших e по модулю

    for (int k = 0; k <= n; ++k) {
        double term = std::pow(-1, k) / factorial(k);
        sum_n += term;
        if (std::abs(term) >= e) {
            sum_e += term;
        }
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