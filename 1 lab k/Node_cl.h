#pragma once
class Node {
public:
    Node* next;
    int data;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data) : data(data), next(nullptr) {} // Конструктор для инициализации узла
};

Node* initinitList(int l);//функция инициализации

bool isListEmpty(Node* head);//функция проверяющая, пуст ли лист

void removeFirst(Node*& List);//функция удаляющая первый элемент

void removeLast(Node*& List);//функция убирающая последний элемент

void AddAfterElem(Node* head, int num, int data);//добавляет узел после заданнаго значения 

void addElem(Node*& head, int data);//функция добавления элементов

bool search(Node* head, int NesData);//поиск элемента

void printList(Node* List);//печать списка

void removeAllNessData(Node*& head, int data);//удаляет все узлы с заданным значением

void removeAllList(Node* head); //функция цдаляющая весь список

void deleteList(Node*& head);  //удаление элемента
