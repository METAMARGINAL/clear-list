#include <iostream>
#include<fstream>
#include <string>
#include"Node_cl.h"

using namespace std;

void printMenu() {
    cout << "Выберите, что вы хотите сделать из меню" << endl;
    cout << "1 - Проверить текущий лист на пустоту" << endl;
    cout << "2 - удалить первый элемент" << endl;
    cout << "3 - удалить последний элемент" << endl;
    cout << "4 - добавить узел после заданного значения" << endl;
    cout << "5 - поиск элемента" << endl;
    cout << "6 - печать списка" << endl;
    cout << "7 - удалить все узлы с заданным значением" << endl;
    cout << "8 - удалить весь список" << endl;
    cout << "9 - добавить элемент в конец" << endl;
    cout << "10 - добавить элемент в начало" << endl;
    cout << "0 - закончить выполнение программы" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    ifstream file("list.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    Node* head = nullptr; // Начинаем с пустого списка
    int x;

    while (file >> x) {
        if (!search(head, x)) {
            addElem(head, x);
        }
    }

    cout << "Список без повторений" << endl;
    printList(head);

    int add = 0;
    int NAdd = 0;
    int deletable = 0;
    int searched = 0;
    x = 1;

    int O = -1;

    while (O != 0) {
        printMenu();  // Выводим меню для выбора
        cin >> O;     // Запрашиваем у пользователя вариант

        switch (O) {
        case 1:
            cout << (isListEmpty(head) ? "Список пуст." : "Список не пуст.") << endl;
            break;

        case 2:
            if (isListEmpty(head)) {
                cout << "Список и так пуст" << endl;
                break;
            }
            removeFirst(head);
            printList(head);
            break;

        case 3:
            removeLast(head);
            printList(head);
            break;

        case 4:
            cout << "Чего изволите добавить? (Интового)" << endl;
            cin >> add;
            cout << "После чего изволите добавить? (Интового)" << endl;
            cin >> NAdd;
            AddAfterElem(head, NAdd, add);
            printList(head);
            break;

        case 5:
            cout << "Чего изволите найти?" << endl;
            cin >> searched;
            cout << (search(head, searched) ? "Найдено." : "Не найдено.") << endl;
            break;

        case 6:
            printList(head);
            break;

        case 7:
            cout << "Чего изволите удалить?" << endl;
            cin >> deletable;
            removeAllNessData(head, deletable);
            printList(head);
            break;
        case 8:            
            if (isListEmpty(head)) {
                break;
            }
            removeAllList(head);
            break;
        case 9:
            cout << "Чего изволите добавить? (Интового)" << endl;
            cin >> add;
            addElem(head, add);
            printList(head);
            break;

        case 10:
            cout << "Чего изволите добавить? (Интового)" << endl;
            cin >> add;
            addFirstElem(head, add);
            printList(head);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Некорректный вариант. Пожалуйста, выберите снова." << endl;
            break;
        }
    }


    // Освобождение памяти
    removeAllList(head);

    return 0;
}
