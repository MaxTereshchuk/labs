#pragma once
#include <iostream> 
#include <string>


using namespace std;

template <typename T>
class Queue {
private:
    T* elements;   // ����� ��� ��������� �������� �����
    int front;     // ������ ������� ��������
    int rear;      // ������ ���������� ��������
    int capacity;  // ������ �����
    int size;      // �������� ����� �����

public:
    Queue(int capacity) {
        this->capacity = capacity;
        elements = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] elements;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void push(T element) {
        if (size == capacity) {
            std::cout << "����� �����. ��������� �������� �������." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        elements[rear] = element;
        size++;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "����� �������. ��������� �������� �������." << std::endl;
            return T();  
        }

        T removedElement = elements[front];
        front = (front + 1) % capacity;
        size--;

        return removedElement;
    }
    class Iterator {
    private:
        Queue& queue;
        int currentIndex;

    public:
        Iterator(Queue& queue, int currentIndex = 0)
            : queue(queue), currentIndex(currentIndex) {}

        T& operator*() const {
            return queue.elements[currentIndex];
        }

        Iterator& operator++() {
            currentIndex = (currentIndex + 1) % queue.capacity;
            return *this;
        }

        Iterator& operator--() {
            currentIndex = (currentIndex - 1 + queue.capacity) % queue.capacity;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return currentIndex == other.currentIndex;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        int getIndex() const {
            return currentIndex;
        }
    };



    Iterator begin() {
        return Iterator(*this, front);
    }

    Iterator end() {
        return Iterator(*this, (rear + 1) % capacity);
    }
};
