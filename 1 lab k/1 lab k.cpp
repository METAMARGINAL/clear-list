#include <iostream>
#include<fstream>
#include <string>     
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int data) : data(data), next(nullptr) {} // Конструктор для инициализации узла
};
void initList(Node* list, int data) {
    list->data = data;
    list->next = nullptr;
}

void addElem(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

bool search(Node* head, int NesData) {
    Node* tmp = head;
    while (tmp != nullptr) {
        if (tmp->data == NesData) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void printList(Node* List) {
    Node* tmp = List;
    while (tmp != nullptr) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    ifstream file("list.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Node* head = nullptr; // Начинаем с пустого списка

    int x;
    while (file >> x) {
        if (!search(head, x)) {
            addElem(head, x);
        }
    }

    printList(head);

    // Освобождение памяти
    freeList(head);

    return 0;
}
