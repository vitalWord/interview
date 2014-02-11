#include <iostream>

struct List
{
	int value;
	List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List * newListObject = new List;
	newListObject->next = NULL;
	newListObject->value = value;
	if (l != NULL)
	{
		while (l->next != NULL)
		{
			l = l->next;
		}
		l->next = newListObject;
	}
	return newListObject;
}

int main(int argc, char* argv[])
{
	List * list = Add(NULL, 1);
	List * temp = list;
	for (int i = 2; i <= 5; i++)
	{
		Add(list, i);
	}
	return 0;
}
