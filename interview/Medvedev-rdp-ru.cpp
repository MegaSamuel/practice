// тестовое задание 
// к собеседованию на должность Программист C/C++ (Linux) в компанию "RDP.RU"
// соискатель: Медведев Сергей Александрович, cepaleme@gmail.com

#include <cassert>
#include <iostream>

class Ring
{
public:
    // конструктор кольца
    Ring(int size) {
        // ! new может кинуть исключение
        ringBuffer = new int [size]; // хранилице размера size
        head = 0;                    // изначально индекс головы равен нулю
        tail = 0;                    // изначально индекс хвоста равен нулю
        cur_size = 0;                // изначально очередь пустая
        max_size = size;             // максимальный размер

        // инициализируем память нулями
        // это нужно для тестового вывода содержимого
        for(int i = 0; i < max_size; i++) {
            ringBuffer[i] = 0;
        }
    }

    // деструктор кольца
    ~Ring() {
        delete[] ringBuffer;
    }

    // добавить элемент
    bool Add(int x) {
        // если есть место, то добавляем
        if(max_size != cur_size) {
            // добавляем элемент
            ringBuffer[tail] = x;

            // индекс хвоста смещаем "вправо" с проверкой на переход максимума
            tail = (tail+1) % max_size;

            // увеличиваем текущий размер очереди
            cur_size++;

            // возвращаем признак, что все хорошо
            return true;
        }

        // возвращаем признак неудачи
        return false;
    }

    // забрать элемент
    bool Take(int* x) {
        // если что-то есть, то возвращаем
        if(0 != cur_size) {
            // возвращаем элемент
            *x = ringBuffer[head];

            // индекс головы смещаем "вправо" с проверкой на переход максимума
            head = (head+1) % max_size;

            // уменьшаем текущий размер очереди
            cur_size--;

            // возвращаем признак, что все хорошо
            return true;
        }

        // возвращаем признак неудачи
        return false;
    }

    // для отладки
    void PrintСontents() const {
        // вывод содержимого буфера
        for(int i = 0; i < max_size; i++) {
            std::cout << *(ringBuffer+i) << " ";
        }
        std::cout << '\n';

        // вывод значения индекса головы и хвоста
        std::cout << "h " << head << " t " << tail << " s " << cur_size << '\n';

        std::cout << std::endl;
    }

    // для отладки
    int GetHead() const {
        return head;
    }

    // для отладки
    int GetTail() const {
        return tail;
    }

    // для отладки
    int GetSize() const {
        return cur_size;
    }

private:
    int *ringBuffer;        // кольцевой буфер
    int  head;              // индекс головы
    int  tail;              // индекс хвоста
    int  cur_size;          // текущий размер очереди
    int  max_size;          // максимальный размер очереди
};

int main()
{
    // проверяем наше кольцо
    //TODO по хорошему нужно написать отдельные юнит тесты

    // создаем кольцо на 4-ре элемента
    Ring myRing(4);

    // проверяем кольцо
   assert(0 == myRing.GetHead());
   assert(0 == myRing.GetTail());
   assert(0 == myRing.GetSize());

    // ожидаемый вывод:
    // 0 0 0 0
    // h 0 t 0 s 0
    myRing.PrintСontents();

    int value;

    // забираем из пустого кольца
    assert(!myRing.Take(&value));

    // добавляем в пустое кольцо
    assert(myRing.Add(1));
    assert(myRing.Add(0));

    // проверяем кольцо
    assert(0 == myRing.GetHead());
    assert(2 == myRing.GetTail());
    assert(2 == myRing.GetSize());

    // ожидаемый вывод:
    // 1 0 0 0
    // h 0 t 2 s 2
    myRing.PrintСontents();

    // добавляем в кольцо со свободным местом
    assert(myRing.Add(-1));
    assert(myRing.Add(2));
    // добавляем в заполненное кольцо
    assert(!myRing.Add(3));

    // проверяем кольцо
    assert(0 == myRing.GetHead());
    assert(0 == myRing.GetTail());
    assert(4 == myRing.GetSize());

    // ожидаемый вывод:
    // 1 0 -1 2
    // h 0 t 0 s 4
    myRing.PrintСontents();

    // забираем из заполненного кольца
    assert(myRing.Take(&value));
    assert(1 == value);
    assert(myRing.Take(&value));
    assert(0 == value);

    // проверяем кольцо
    assert(2 == myRing.GetHead());
    assert(0 == myRing.GetTail());
    assert(2 == myRing.GetSize());

    // ожидаемый вывод:
    // 1 0 -1 2
    // h 2 t 0 s 2
    myRing.PrintСontents();

    // добавляем, должны перейти в начало массива
    assert(myRing.Add(4));
    assert(myRing.Add(5));

    // проверяем кольцо
    assert(2 == myRing.GetHead());
    assert(2 == myRing.GetTail());
    assert(4 == myRing.GetSize());

    // ожидаемый вывод:
    // 4 5 -1 2
    // h 2 t 2 s 4
    myRing.PrintСontents();

    // забираем
    assert(myRing.Take(&value));
    assert(-1 == value);

    // проверяем кольцо
    assert(3 == myRing.GetHead());
    assert(2 == myRing.GetTail());
    assert(3 == myRing.GetSize());

    // ожидаемый вывод:
    // 4 5 -1 2
    // h 3 t 2 s 3
    myRing.PrintСontents();
}
