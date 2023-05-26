#pragma once
namespace classqueue {
    template<typename T>
    class SqQueue {
    private:
        T* base;
        int front, rear;
        const int Qmaxsize = 100;

    public:
        SqQueue() {
            base = new T[Qmaxsize];
            front = rear = 0;
        }

        ~SqQueue() {
            delete[] base;
        }

        bool IsEmpty() const {
            return front == rear;
        }

        bool IsFull() const {
            return (rear + 1) % Qmaxsize == front;
        }

        bool IN(const T& e) {
            if (IsFull())
                return false;
            base[rear] = e;
            rear = (rear + 1) % Qmaxsize;
            return true;
        }

        bool OUT(T* e) {
            if (IsEmpty())
                return false;
            *e = base[front];
            front = (front + 1) % Qmaxsize;
            return true;
        }

        T GetFront() const {
            return base[front];
        }

        int LengthQueue() const {
            return (rear - front + Qmaxsize) % Qmaxsize;
        }
    };

    template<typename T>
    class QueueNode {
    public:
        T data;
        QueueNode<T>* next;
    };

    template<typename T>
    class LinkQueue {
    private:
        QueueNode<T>* front;
        QueueNode<T>* rear;

    public:
        LinkQueue() {
            front = rear = nullptr;
        }

        ~LinkQueue() {
            QueueNode<T>* p;
            while (front) {
                p = front;
                front = p->next;
                delete p;
            }
        }

        bool IsEmpty() const {
            return front == nullptr;
        }

        bool IN(const T& e) {
            QueueNode<T>* p = new QueueNode<T>;
            p->data = e;
            p->next = nullptr;
            if (IsEmpty())
                front = rear = p;
            else {
                rear->next = p;
                rear = p;
            }
            return true;
        }

        T OUT(T* e) {
            if (IsEmpty())
                return false;
            QueueNode<T>* p = front;
            *e = p->data;
            front = p->next;
            delete p;
            if (front == nullptr)
                rear = nullptr;
            return *e;
        }
    };
}