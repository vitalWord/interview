// Напишите функцию Add(), которая создает новый объект List, инициализирует
// его входным значением value и добавляет его в конец списка l, полученного на вход.
// В функции main() создайте проинициализированный список, со значениями value равными: 1, 2, 3, 4 и 5.

#include <iostream>

struct List
{
	int value;
	List* next;
	
	~List();

	void printList() const;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List *newElem = new List;
	newElem->value = value;
	newElem->next = NULL;

	if (l) {
		while (l->next)
			l = l->next;

		l->next = newElem;
	}

	return newElem;
}

int main(int argc, char* argv[])
{
	List *l, *tmpList;
	size_t i;

	l = Add(NULL, 1);
	for (i = 2, tmpList = l; i < 6; i++)
		tmpList = Add(tmpList, i);

	l->printList();

	delete l;

	return 0;
}

List::~List()
{
	delete next;
}

void List::printList() const
{
	std::cout << "The list is:";
	for (const List *iter = this; iter; iter = iter->next)
		std::cout << " " << iter->value;
	std::cout << std::endl;
}