#include <iostream>
#include "Node_cl.h"

using namespace std;

bool isListEmpty(Node* head) {
    return head == nullptr;
}

Node* initinitList(int num) {
    Node* head = new Node();
    head->next = nullptr;
    head->data = num;
    return head;
}

void addFirstElem(Node*& head, int data) {//это
    if (isListEmpty(head)) {
        head = new Node(data);
        return;
    }
    Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
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

void removeFirst(Node*& List) {
    if (isListEmpty(List)) {
        return;
    }
    Node* tmp = List;
    List = List->next;
    tmp->next = nullptr;
    delete tmp;
    tmp = nullptr;
}

void removeLast(Node*& List) {
    if (isListEmpty(List))
    {
        return;
    }
    if (List->next == nullptr) {
        removeFirst(List);
        return;
    }
    Node* tmp = List;
    while (tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = nullptr;
    tmp = nullptr;
}

void AddAfterElem(Node* head, int num, int data) {
    if (isListEmpty(head))
    {
        cout << "list is empty" << endl;
        return;
    }
    Node* tmp = head;
    while (tmp->data != num) {
        tmp = tmp->next;
        if (tmp == nullptr) {
            return;
        }
    }
    Node* NewNode = new Node(data);
    NewNode->next = tmp->next;
    tmp->next = NewNode;
}

void printList(Node* List) {
    if (isListEmpty(List)) {
        cout << "list is empty" << endl;
        return;
    }

    else {
        Node* tmp = List;
        while (tmp != nullptr) {
            cout << tmp->data << "\t";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void removeAllList(Node*& head) {
    while (head != nullptr) {
        removeFirst(head);
    }
}

void removeAllNessData(Node*& head, int data) {
    if (isListEmpty(head))
    {
        return;
    }
    while (head->data == data) {
        removeFirst(head);
        if (isListEmpty(head)) {
            return;
        }
    }

    Node* tmp = head->next;
    Node* prevTmp = head;

    while (tmp != nullptr) {
        if (tmp->data == data) {
            prevTmp->next = tmp->next;
            delete tmp;
            tmp = prevTmp->next;
        }
        else {
            prevTmp = tmp;
            tmp = tmp->next;
        }
    }
}
