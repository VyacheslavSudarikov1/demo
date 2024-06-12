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
std::vector<std::vector<int>> squareFirstThreeColumns(const std::vector<std::vector<int>>& arr) {
    std::vector<std::vector<int>> newArr = arr;
    for (size_t i = 0; i < newArr.size(); i++) {
        for (size_t j = 0; j < 3 && j < newArr[i].size(); j++) {
            newArr[i][j] *= newArr[i][j];
        }
    }
    return newArr;
}

// Функция для вставки первой строки после каждой нечетной строки
std::vector<std::vector<int>> insertFirstRowAfterOdd(const std::vector<std::vector<int>>& arr) {
    std::vector<std::vector<int>> newArr = arr;
    std::vector<int> firstRow = newArr[0];
    for (size_t i = 1; i < newArr.size(); i += 2) {
        newArr.insert(newArr.begin() + i + 1, firstRow);
    }
    return newArr;
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

    std::vector<std::vector<int>> squaredArr = squareFirstThreeColumns(arr);
    std::cout << "Массив после замены элементов на их квадраты:\n";
    printArray(squaredArr);

    std::vector<std::vector<int>> modifiedArr = insertFirstRowAfterOdd(arr);
    std::cout << "Массив после вставки первой строки после каждой нечетной строки:\n";
    printArray(modifiedArr);

    return 0;
}
