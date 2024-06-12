#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Функция для создания массива
std::vector<std::vector<int>> createArray(int n, int m) {
    std::vector<std::vector<int>> arr(n, std::vector<int>(m));
    return arr;
}

// Функция для заполнения массива
void fillArray(std::vector<std::vector<int>>& arr, bool random = true) {
    if (random) {
        srand((unsigned)time(0));
        int range;
        std::cout << "Введите диапазон случайных чисел (0 до ?): ";
        std::cin >> range;

        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr[i].size(); j++) {
                arr[i][j] = rand() % (range + 1);
            }
        }
    } else {
        std::cout << "Введите элементы массива:\n";
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr[i].size(); j++) {
                std::cin >> arr[i][j];
            }
        }
    }
}

// Функция для вывода массива
void printArray(const std::vector<std::vector<int>>& arr) {
    for (const auto& row : arr) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}

// Функция для замены элементов на их квадраты
void squareFirstThreeColumns(std::vector<std::vector<int>>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < 3 && j < arr[i].size(); j++) {
            arr[i][j] *= arr[i][j];
        }
    }
}

// Функция для вставки первой строки после каждой нечетной строки
void insertFirstRowAfterOdd(std::vector<std::vector<int>>& arr) {
    std::vector<int> firstRow = arr[0];
    for (size_t i = 1; i < arr.size(); i += 2) {
        arr.insert(arr.begin() + i + 1, firstRow);
    }
}

int main() {
    int n, m;
    std::cout << "Введите размеры массива n и m: ";
    std::cin >> n >> m;

    if (std::cin.fail() || n <= 0 || m <= 0) {
        std::cerr << "Некорректные размеры массива!\n";
        return 1;
    }

    std::vector<std::vector<int>> arr = createArray(n, m);

    std::cout << "Заполнить массив случайными числами? (1 - да, 0 - нет): ";
    int option;
    std::cin >> option;

    if (std::cin.fail() || (option != 0 && option != 1)) {
        std::cerr << "Некорректный ввод!\n";
        return 1;
    }

    fillArray(arr, option);

    std::cout << "Исходный массив:\n";
    printArray(arr);

    squareFirstThreeColumns(arr);
    std::cout << "Массив после замены элементов на их квадраты:\n";
    printArray(arr);

    insertFirstRowAfterOdd(arr);
    std::cout << "Массив после вставки первой строки после каждой нечетной строки:\n";
    printArray(arr);

    return 0;
}

