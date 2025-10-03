#include <windows.h>
#include <iostream>

struct Array {
    int* arr;         
    int size;
    double average;   
    int min;     
    int max;     
};

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

    std::cout << "Введите размер массива (n > 0): ";
    std::cin >> Arr.size;
    if (Arr.size <= 0) {
        std::cout << "Ошибка ввода числа";
        return 0;
    }
    Arr.arr = new int[Arr.size];
    std::cout << "Введите " << Arr.size << " целых чисел:\n";
    for (int i = 0; i < Arr.size; i++) {
        std::cin >> Arr.arr[i];
    }

    DWORD IDMin_max, IDAverage;
    HANDLE hMin_max = CreateThread(NULL, 0, Min_max, &Arr, 0, &IDMin_max);
    HANDLE hAverage = CreateThread(NULL, 0, Average, &Arr, 0, &IDAverage);

    if (!hMin_max || !hAverage) {
        std::cout << "Ошибка создания потоков" << std::endl;
        delete[] Arr.arr;
        return 1;
    }

    WaitForSingleObject(hMin_max, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    CloseHandle(hMin_max);
    CloseHandle(hAverage);

    int val = static_cast<int>(Arr.average + 0.5);
    if (Arr.min >= 0 && Arr.min < Arr.size)
        Arr.arr[Arr.min] = val;
    if (Arr.max >= 0 && Arr.max < Arr.size)
        Arr.arr[Arr.max] = val;

    std::cout << "\nСреднее арифметическое = " << Arr.average << std::endl;
    std::cout << "Минимум заменён [" << Arr.min << "] на " << val << std::endl;
    std::cout << "Максимум заменён [" << Arr.max << "] на " << val << std::endl;

    std::cout << "Итоговый массив:\n";
    for (int i = 0; i < Arr.size; i++) {
        std::cout << Arr.arr[i]<<" ";
    }
    delete[] Arr.arr;
    return 0;
}

DWORD WINAPI Min_max(LPVOID iNum) {
    Array* a = static_cast<Array*>(iNum);
    int n = a->size;
    if (n <= 0) 
        return 0;

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

    std::cout << "\nМинимум = " << a->arr[Min]<< ", Максимум = " << a->arr[Max] << std::endl;
    return 0;
}

DWORD WINAPI Average(LPVOID iNum) {
    Array* a = static_cast<Array*>(iNum);
    int n = a->size;
    if (n <= 0) 
        return 0;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a->arr[i];
        Sleep(12); 
    }
    a->average = static_cast<double>(sum) / n;

    std::cout<< "Среднее = " << a->average << std::endl;
    return 0;
}
