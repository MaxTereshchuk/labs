#include "queue.h"
#include <Windows.h>

template<typename T>
void processQueue() {
    int capacity;
    std::cout << "������ ����� �����: ";
    std::cin >> capacity;

    Queue<T> queue(capacity);
    typename Queue<T>::Iterator currentIterator = queue.begin();

    int choice;
    do {
        std::cout << "\n������ ��������:"
            << "\n1. �������� ����� �� �������"
            << "\n2. �������� �����"
            << "\n3. ��������� �������� � �����"
            << "\n4. ��������� ������ �������� � �����"
            << "\n5. ����������� �����"
            << "\n6. ���������� �������� �� ������� �����"
            << "\n7. ���������� �������� � ����� �����"
            << "\n8. ������� �� ������������ �������� �����"
            << "\n9. ������� �� ���������� �������� �����"
            << "\n0. �����"
            << "\n��� ����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (queue.isEmpty()) {
                std::cout << "����� �������." << std::endl;
            }
            else {
                std::cout << "����� �� �������." << std::endl;
            }
            break;

        case 2:
            queue.clear();
            std::cout << "����� �������." << std::endl;
            break;

        case 3:
            if (queue.isEmpty()) {
                std::cout << "����� �������. ��������� �������� �������." << std::endl;
            }
            else {
                std::cout << "��������� �������: " << queue.pop() << std::endl;
            }
            break;

        case 4:
            if (queue.getSize() == capacity) {
                std::cout << "����� �����. ��������� �������� �������." << std::endl;
            }
            else {
                T element;
                std::cout << "������ ������� ��� ��������� � �����: ";
                std::cin >> element;
                queue.push(element);
                std::cout << "������� �������� � �����." << std::endl;
            }
            break;

        case 5:
            std::cout << "�������� �����: ";
            for (const auto& element : queue) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
            break;

        case 6:
        {
            auto iter = queue.begin();
            std::cout << "�������� ����������� �� ������� �����. �������� �������: " << *iter << std::endl;
        }
        break;

        case 7:
        {
            auto iter = queue.end();
            --iter;  
            std::cout << "�������� ����������� � ����� �����. �������� �������: " << *iter << std::endl;
        }
        break;

        case 8:
        {
            --currentIterator;
            std::cout << "�������� �� ������������ ��������: " << *currentIterator << std::endl;
        }
        break;

        case 9:
        {
            ++currentIterator;
            std::cout << "�������� �� ���������� ��������: " << *currentIterator << std::endl;
        }
        break;

        case 0:
            std::cout << "�������� ���������." << std::endl;
            return;  

        default:
            std::cout << "������� ����. ��������� �� ���." << std::endl;
        }
    } while (choice != 0);
}