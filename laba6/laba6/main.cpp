#include "queue.h"
#include <Windows.h>
#include "queue.cpp"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Виберіть тип даних (1 - int, 2 - double, 3 - char): ";
    int type;
    std::cin >> type;

    if (type == 1) {
        processQueue<int>();
    }
    else if (type == 2) {
        processQueue<double>();
    }
    else if (type == 3) {
        processQueue<char>();
    }
    else {
        std::cout << "Невірний вибір типу даних." << std::endl;
    }

    return 0;
}