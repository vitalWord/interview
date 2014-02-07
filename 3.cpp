// Напишите функцию Add(), которая создает новый объект List, инициализирует
// его входным значением value и добавляет его в конец списка l, полученного на вход.
// В функции main() создайте проинициализированный список, со значениями value равными: 1, 2, 3, 4 и 5.

#include <stdio.h>
#include <stdlib.h>

struct List
{
      int value;
      List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List *newElem, *curElem;

	newElem = (List *) calloc(1, sizeof(List));
	newElem->value = value;

	if(NULL == l) {
		l = newElem;
	}
	else {
		curElem = l;
		while(curElem->next != NULL)
			curElem = curElem->next;
		curElem->next = newElem;
	}

	return l;

}

void printList(List *l);

int main(int argc, char* argv[])
{
	List *l = NULL;

	l = Add(l, 1);
	l = Add(l, 2);
	l = Add(l, 3);
	l = Add(l, 4);
	l = Add(l, 5);

	printList(l);

	return 0;
}
void printList(List *l)
{
	printf("The list is: ");
	while (l) {
		printf("%d ", l->value);
		l = l->next;
	}
	printf("\n");
}