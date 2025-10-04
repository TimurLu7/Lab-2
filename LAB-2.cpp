#include <windows.h>
#include <iostream>
#include <stdexcept>
#include "Array.h"

DWORD WINAPI Min_max(LPVOID iNum);
DWORD WINAPI Average(LPVOID iNum);

int main() {
    setlocale(LC_ALL, "rus");
    Array Arr{};
    Arr.arr = nullptr;
    Arr.size = 0;
    Arr.average = 0.0;
    Arr.min = -1;
    Arr.max = -1;

    try {
        std::cout << "Введите размер массива (n > 0): ";
        std::cin >> Arr.size;

        if (std::cin.fail()) {
            throw std::runtime_error("Ошибка ввода");
        }

        if (Arr.size <= 0) {
            throw std::invalid_argument("Размер массива должен быть положительным");
        }

        Arr.arr = new int[Arr.size];

        std::cout << "Введите " << Arr.size << " целых чисел:\n";
        for (int i = 0; i < Arr.size; i++) {
            std::cin >> Arr.arr[i];
            if (std::cin.fail()) {
                throw std::runtime_error("Ошибка ввода элемента массива");
            }
        }

        DWORD IDMin_max, IDAverage;
        HANDLE hMin_max = CreateThread(NULL, 0, Min_max, &Arr, 0, &IDMin_max);
        HANDLE hAverage = CreateThread(NULL, 0, Average, &Arr, 0, &IDAverage);

        if (!hMin_max || !hAverage) {
            DWORD error = GetLastError();
            throw std::runtime_error("Ошибка создания потоков." + error);
        }

        WaitForSingleObject(hMin_max, INFINITE);
        WaitForSingleObject(hAverage, INFINITE);

        CloseHandle(hMin_max);
        CloseHandle(hAverage);

        if (Arr.min < 0 || Arr.min >= Arr.size) {
            throw std::out_of_range("Неверный индекс мин элемента: " + Arr.min);
        }
        if (Arr.max < 0 || Arr.max >= Arr.size) {
            throw std::out_of_range("Неверный индекс макс элемента: " + Arr.max);
        }
        int val = static_cast<int>(Arr.average + 0.5);
        Arr.arr[Arr.min] = val;
        Arr.arr[Arr.max] = val;

        std::cout << "\nСреднее арифметическое = " << Arr.average << std::endl;
        std::cout << "Минимум заменён [" << Arr.min << "] на " << val << std::endl;
        std::cout << "Максимум заменён [" << Arr.max << "] на " << val << std::endl;

        std::cout << "Итоговый массив:\n";
        for (int i = 0; i < Arr.size; i++) {
            std::cout << Arr.arr[i] << " ";
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Ошибка выделения памяти: не удалось создать массив размером " << Arr.size << std::endl;
        if (Arr.arr) {
            delete[] Arr.arr;
            Arr.arr = nullptr;
        }
        return 1;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        if (Arr.arr) {
            delete[] Arr.arr;
            Arr.arr = nullptr;
        }
        return 1;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка диапазона: " << e.what() << std::endl;
        if (Arr.arr) {
            delete[] Arr.arr;
            Arr.arr = nullptr;
        }
        return 1;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Ошибка выполнения: " << e.what() << std::endl;
        if (Arr.arr) {
            delete[] Arr.arr;
            Arr.arr = nullptr;
        }
        return 1;
    }
    
    if (Arr.arr) {
        delete[] Arr.arr;
        Arr.arr = nullptr;
    }
    return 0;
    }

DWORD WINAPI Min_max(LPVOID iNum) {
    try {
        Array* a = static_cast<Array*>(iNum);
        int n = a->size;
        if (n <= 0) {
            throw std::invalid_argument("Неверный размер массива");
        }

        int Min = 0, Max = 0;
        for (int i = 1; i < n; i++) {
            if (a->arr[i] < a->arr[Min])
                Min = i;
            Sleep(7);

            if (a->arr[i] > a->arr[Max])
                Max = i;
            Sleep(7);
        }
        a->min = Min;
        a->max = Max;

        std::cout << "\nМинимум = " << a->arr[Min] << ", Максимум = " << a->arr[Max] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка в потоке Min_max: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

DWORD WINAPI Average(LPVOID iNum) {
    try {
        Array* a = static_cast<Array*>(iNum);
        int n = a->size;
        if (n <= 0) {
            throw std::invalid_argument("Неверный размер массива");
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a->arr[i];
            Sleep(12);
        }
        a->average = static_cast<double>(sum) / n;
        std::cout << "Среднее = " << a->average << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка в потоке Average: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
