#include "queue.h"
#include <Windows.h>

template<typename T>
void processQueue() {
    int capacity;
    std::cout << "Введіть розмір черги: ";
    std::cin >> capacity;

    Queue<T> queue(capacity);
    typename Queue<T>::Iterator currentIterator = queue.begin();

    int choice;
    do {
        std::cout << "\nОберіть операцію:"
            << "\n1. Перевірка черги на пустоту"
            << "\n2. Очищення черги"
            << "\n3. Видалення елемента з черги"
            << "\n4. Включення нового елемента у чергу"
            << "\n5. Переглянути чергу"
            << "\n6. Встановити ітератор на початок черги"
            << "\n7. Встановити ітератор в кінець черги"
            << "\n8. Перехід до попереднього елемента черги"
            << "\n9. Перехід до наступного елемента черги"
            << "\n0. Вийти"
            << "\nВаш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (queue.isEmpty()) {
                std::cout << "Черга порожня." << std::endl;
            }
            else {
                std::cout << "Черга не порожня." << std::endl;
            }
            break;

        case 2:
            queue.clear();
            std::cout << "Черга очищена." << std::endl;
            break;

        case 3:
            if (queue.isEmpty()) {
                std::cout << "Черга порожня. Неможливо видалити елемент." << std::endl;
            }
            else {
                std::cout << "Видалений елемент: " << queue.pop() << std::endl;
            }
            break;

        case 4:
            if (queue.getSize() == capacity) {
                std::cout << "Черга повна. Неможливо включити елемент." << std::endl;
            }
            else {
                T element;
                std::cout << "Введіть елемент для включення у чергу: ";
                std::cin >> element;
                queue.push(element);
                std::cout << "Елемент включено у чергу." << std::endl;
            }
            break;

        case 5:
            std::cout << "Елементи черги: ";
            for (const auto& element : queue) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
            break;

        case 6:
        {
            auto iter = queue.begin();
            std::cout << "Ітератор встановлено на початок черги. Поточний елемент: " << *iter << std::endl;
        }
        break;

        case 7:
        {
            auto iter = queue.end();
            --iter;  
            std::cout << "Ітератор встановлено в кінець черги. Поточний елемент: " << *iter << std::endl;
        }
        break;

        case 8:
        {
            --currentIterator;
            std::cout << "Перейшли до попереднього елемента: " << *currentIterator << std::endl;
        }
        break;

        case 9:
        {
            ++currentIterator;
            std::cout << "Перейшли до наступного елемента: " << *currentIterator << std::endl;
        }
        break;

        case 0:
            std::cout << "Програма завершена." << std::endl;
            return;  

        default:
            std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
        }
    } while (choice != 0);
}