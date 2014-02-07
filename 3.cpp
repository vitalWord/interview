// Напишите функцию Add(), которая создает новый объект List, инициализирует
// его входным значением value и добавляет его в конец списка l, полученного на вход.
// В функции main() создайте проинициализированный список, со значениями value равными: 1, 2, 3, 4 и 5.

#include <iostream>
using namespace std;

struct List
{
	int value;
	List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List *newElem;

	newElem = new List;
	newElem->value = value;
	newElem->next = NULL;

	if (!l) {
		return newElem;
		/*NOTREACHED*/
	}

	List *curElem = l;

	while (curElem->next)
		curElem = curElem->next;

	curElem->next = newElem;

	return l;

}

void printList(List *l);

int main(int argc, char* argv[])
{
	List *l = NULL;

	l = Add(l, 1);
	for (size_t i = 2; i < 6; i++)
		Add(l, i);

	printList(l);

	return 0;
}
void printList(List *l)
{
	cout << "The list is: ";
	while (l) {
		cout << l->value << " ";
		l = l->next;
	}
	cout << endl;
}