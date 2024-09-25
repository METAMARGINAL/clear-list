#pragma once
class Node {
public:
    Node* next;
    int data;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data) : data(data), next(nullptr) {} // ����������� ��� ������������� ����
};

Node* initinitList(int l);//������� �������������

bool isListEmpty(Node* head);//������� �����������, ���� �� ����

void removeFirst(Node*& List);//������� ��������� ������ �������

void removeLast(Node*& List);//������� ��������� ��������� �������

void AddAfterElem(Node* head, int num, int data);//��������� ���� ����� ��������� �������� 

void addElem(Node*& head, int data);//������� ���������� ���������

bool search(Node* head, int NesData);//����� ��������

void printList(Node* List);//������ ������

void removeAllNessData(Node*& head, int data);//������� ��� ���� � �������� ���������

void removeAllList(Node* head); //������� ��������� ���� ������

void deleteList(Node*& head);  //�������� ��������
