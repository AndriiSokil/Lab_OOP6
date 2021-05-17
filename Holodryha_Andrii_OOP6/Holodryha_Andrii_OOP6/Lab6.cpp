/*�������� ��������� ���� � ����� �� ����� ���������� ������ ���������. ��� �������� ����� ����������� ���������� �������
(��� �����, ���� �����, ������� ��� �������� �����). ����������� ������� ��� ��������� ����� ��������: ��������� �������� �
�����, ��������� �������� � �����, ��������� ��� �������� ����� �� �����, ���������� ���������� �������� � ����.*/
#include <iostream>
using namespace std;

#define SIZE 10


template <typename T>
class queue
{
    T* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:

    queue(int size = SIZE);   //�����������
    ~queue();                 //����������

    void dequeue();           //��������� �������� � �����
    void enqueue(T t);        //��������� �������� � �����
    int size();
    bool isEmpty();
    bool isFull();
    void ShowQueue();         //���� ��� �������� �����
    void FindMin();
};


template <typename T>
queue<T>::queue(int size)
{
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T>
queue<T>::~queue()
{
    delete[] arr;
}

template <typename T>
void queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "����� �����\n";
        exit(EXIT_FAILURE);
    }

    cout << "�������� " << arr[count - 1] << endl;

    front = (front + 1) % capacity;
    count--;
}

template <typename T>
void queue<T>::FindMin()
{
    int min = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    cout << endl << "���������� ������� � ���� - " << min << endl;
}

template <typename T>
void queue<T>::enqueue(T item)
{
    if (isFull())
    {
        cout << "����� �����������\n";
        exit(EXIT_FAILURE);
    }
    cout << "�������� ������� � ����� " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

template <typename T>
int queue<T>::size() {
    return count;
}


template <typename T>
bool queue<T>::isEmpty() {
    return (size() == 0);
}

template <typename T>
bool queue<T>::isFull() {
    return (size() == capacity);
}

template <typename T>
void queue<T>::ShowQueue() {
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << " " << arr[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    queue<string> obj1(3);
    obj1.enqueue("��������");
    obj1.enqueue("����");
    obj1.enqueue("��");
    obj1.ShowQueue();
    obj1.dequeue();
    obj1.ShowQueue();

    queue<int> obj2(4);
    obj2.enqueue(300);
    obj2.enqueue(8);
    obj2.enqueue(32);
    obj2.enqueue(128);
    obj2.ShowQueue();
    obj2.FindMin();
    obj2.dequeue();
    obj2.dequeue();
    obj2.ShowQueue();


    queue<double> obj3(4);
    obj3.enqueue(11.520);
    obj3.enqueue(15.4);
    obj3.enqueue(10.20);
    obj3.enqueue(25.180);
    obj3.ShowQueue();
    obj3.dequeue();
    obj3.ShowQueue();

    queue<char> obj4(3);
    obj4.enqueue('a');
    obj4.enqueue('b');
    obj4.enqueue('c');
    obj4.ShowQueue();
    obj4.dequeue();
    obj4.dequeue();
    obj4.ShowQueue();

    return 0;
}