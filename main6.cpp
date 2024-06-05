#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Функция для заполнения массива
void fillArray(std::vector<int>& arr, int n, bool random) {
    if (random) {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 31 - 10; // Интервал [-10; 20]
        }
    } else {
        std::cout << "Введите " << n << " чисел: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    }
}

// Задание 1: Сумма элементов с нечетными индексами
int sumOddIndex(const std::vector<int>& arr) {
    int sum = 0;
    for (size_t i = 1; i < arr.size(); i += 2) {
        sum += arr[i];
    }
    return sum;
}

// Задание 2: Количество элементов больше A и кратных 5
int countElements(const std::vector<int>& arr, int A) {
    int count = 0;
    for (int num : arr) {
        if (num > A && num % 5 == 0) {
            ++count;
        }
    }
    return count;
}

// Задание 3: Деление элементов с четными номерами на первый элемент
void divideEvenIndex(std::vector<int>& arr) {
    if (arr[0] == 0) return; // Проверка, что первый элемент не равен 0
    for (size_t i = 0; i < arr.size(); i += 2) {
        arr[i] /= arr[0];
    }
}

int main() {
    int n, A;
    std::cout << "Введите размер массива n и число A: ";
    std::cin >> n >> A;
    
    std::vector<int> arr(n);
    bool randomFill;
    std::cout << "Заполнить массив случайными числами? (1 - да, 0 - нет): ";
    std::cin >> randomFill;
    
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