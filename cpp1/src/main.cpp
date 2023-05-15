#include <iostream>
#include "./include/DynamicIntArray.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DynamicIntArray dynamicIntArray0;
    std::cout << "Конструктор без параметров: " << dynamicIntArray0 << std::endl;

    DynamicIntArray dynamicIntArray1(3);
    std::cout << "Конструктор по размеру: " << dynamicIntArray1 << std::endl;

    DynamicIntArray dynamicIntArray2(5, 999);
    std::cout << "Конструктор по размеру и числу n: " << dynamicIntArray2 << std::endl;

    DynamicIntArray copy(3, 7);
    auto *dynamicIntArray3 = new DynamicIntArray(copy);
    std::cout << "Конструктор копирования: " << *dynamicIntArray3 << ", Скопированный объект: " << copy << "."
              << std::endl;

    DynamicIntArray move(5, 42);
    DynamicIntArray dynamicIntArray4(std::move(move));
    std::cout << "Конструктор перемещения: " << dynamicIntArray4 << ", Перемещённый объект: " << move << "."
              << std::endl;

    DynamicIntArray dynamicIntArray5(777);
    std::cout << "Длина массива: " << dynamicIntArray5.getSize() << std::endl;

    DynamicIntArray dynamicIntArray6(3);
    for (int i = 0; i < dynamicIntArray6.getSize(); ++i) {
        std::cout << i << ": ";
        std::cin >> dynamicIntArray6[i];
    }
    std::cout << "Оператор []: " << dynamicIntArray6 << std::endl;;

    DynamicIntArray dynamicIntArray7 = dynamicIntArray6;
    std::cout << "Оператор копирования: " << dynamicIntArray7 << ", Скопированный объект: " << dynamicIntArray6
              << std::endl;

    DynamicIntArray dynamicIntArray8 = std::move(dynamicIntArray6);
    std::cout << "Оператор перемещения: " << dynamicIntArray8 << ", Перемещённый объект: " << dynamicIntArray6 << "."
              << std::endl;

    DynamicIntArray dynamicIntArray9(3, 3);
    DynamicIntArray dynamicIntArray10(3, 3);
    std::cout << (dynamicIntArray9 == dynamicIntArray10) << std::endl;
    std::cout << (dynamicIntArray9 != dynamicIntArray10) << std::endl;

    DynamicIntArray dynamicIntArray11(3);
    for (int i = 0; i < dynamicIntArray11.getSize(); ++i) {
        std::cout << i << ": ";
        std::cin >> dynamicIntArray11[i];
    }
    std::cout << dynamicIntArray11 << std::endl;
    DynamicIntArray dynamicIntArray12(4);
    for (int i = 0; i < dynamicIntArray12.getSize(); ++i) {
        std::cout << i << ": ";
        std::cin >> dynamicIntArray12[i];
    }
    std::cout << dynamicIntArray12 << std::endl;
    std::cout << "< : " << (dynamicIntArray11 < dynamicIntArray12) << std::endl;
    std::cout << "<= : " << (dynamicIntArray11 <= dynamicIntArray12) << std::endl;
    std::cout << "> : " << (dynamicIntArray11 > dynamicIntArray12) << std::endl;
    std::cout << ">= : " << (dynamicIntArray11 >= dynamicIntArray12) << std::endl;

    DynamicIntArray dynamicIntArray13(2);
    for (int i = 0; i < dynamicIntArray13.getSize(); ++i) {
        std::cout << i << ": ";
        std::cin >> dynamicIntArray13[i];
    }
    std::cout << dynamicIntArray13 << std::endl;
    DynamicIntArray dynamicIntArray14(3);
    for (int i = 0; i < dynamicIntArray14.getSize(); ++i) {
        std::cout << i << ": ";
        std::cin >> dynamicIntArray14[i];
    }
    std::cout << dynamicIntArray14 << std::endl;
    std::cout << "+ : " << dynamicIntArray13 + dynamicIntArray14 << std::endl;

    DynamicIntArray dynamicIntArray15(3, 999);
    dynamicIntArray15.reserve(4);
    std::cout << "Capacity: " << dynamicIntArray15.capacity() << std::endl;
    dynamicIntArray15.resize(5);
    std::cout << "Capacity: " << dynamicIntArray15.capacity() << std::endl;
    dynamicIntArray15.resize(7);
    std::cout << dynamicIntArray15 << std::endl;
    std::cout << "Capacity: " << dynamicIntArray15.capacity() << std::endl;

    dynamicIntArray15.reserve(4);
    dynamicIntArray15.pushBack(777);
    std::cout << dynamicIntArray15.popBack() << std::endl;
    dynamicIntArray15.pushBack(7771);
    dynamicIntArray15.pushBack(7772);
    dynamicIntArray15.pushBack(7773);
    std::cout << dynamicIntArray15 << std::endl;

    DynamicIntArray dynamicIntArray16(3, 5, 999);
    std::cout << "Конструктор с резервом: " << dynamicIntArray16 << std::endl;
    std::cout << "Capacity: " << dynamicIntArray16.capacity() << std::endl;
    return 0;
}
