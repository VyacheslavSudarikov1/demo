#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

// Прототипы функций
void fillArray(std::vector<int>& arr, int n, bool random);
int sumOddIndex(const std::vector<int>& arr);
int countElements(const std::vector<int>& arr, int A);
void divideEvenIndex(std::vector<int>& arr);

int main() {
    int n, A;
    std::cout << "Введите размер массива n и число A: ";
    // Проверка ввода для n и A
    while (!(std::cin >> n >> A) || n <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод. Пожалуйста, введите положительное целое число для размера массива и целое число для A: ";
    }

    std::vector<int> arr(n);
    bool randomFill;
    std::cout << "Заполнить массив случайными числами? (1 - да, 0 - нет): ";
    // Проверка ввода для randomFill
    while (!(std::cin >> randomFill)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод. Пожалуйста, введите 1 для заполнения случайными числами или 0 для ручного ввода: ";
    }

    fillArray(arr, n, randomFill);

    std::cout << "Сумма элементов с нечетными индексами: " << sumOddIndex(arr) << std::endl;
    std::cout << "Количество элементов больше " << A << " и кратных 5: " << countElements(arr, A) << std::endl;

    divideEvenIndex(arr);
    std::cout << "Элементы массива после деления: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/**
 * @brief Заполняет массив случайными значениями в диапазоне [-10, 20] или значениями, введенными пользователем.
 * @param arr Массив для заполнения.
 * @param n Размер массива.
 * @param random Флаг, указывающий, заполнять ли массив случайными значениями.
 */
void fillArray(std::vector<int>& arr, int n, bool random) {
    if (random) {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 31 - 10; // Диапазон [-10; 20]
        }
    } else {
        std::cout << "Введите " << n << " чисел: ";
        for (size_t i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    }
}

/**
 * @brief Вычисляет сумму элементов с нечетными индексами.
 * @param arr Входной массив.
 * @return Сумма элементов с нечетными индексами.
 */
int sumOddIndex(const std::vector<int>& arr) {
    int sum = 0;
    for (size_t i = 1; i < arr.size(); i += 2) {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Подсчитывает количество элементов, больших A и кратных 5.
 * @param arr Входной массив.
 * @param A Пороговое значение.
 * @return Количество элементов, больших A и кратных 5.
 */
int countElements(const std::vector<int>& arr, int A) {
    int count = 0;
    for (int num : arr) {
        if (num > A && num % 5 == 0) {
            ++count;
        }
    }
    return count;
}

/**
 * @brief Делит элементы с четными индексами на первый элемент массива.
 * @param arr Входной массив.
 */
void divideEvenIndex(std::vector<int>& arr) {
    if (arr[0] == 0) return; // Проверка, что первый элемент не равен 0
    for (size_t i = 0; i < arr.size(); i += 2) {
        arr[i] /= arr[0];
    }
}

