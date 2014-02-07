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

	List * temp = l;	
	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			temp->next = newListObject;
			return newListObject;
		}
		temp = temp->next;
	}
}

void display(List * head) {
	List * list = head;
	while (list != NULL) {
		std::cout << list->value << " ";
		list = list->next;
	}
}

int main(int argc, char* argv[])
{
	List * list = new List;
	list->value = 1;
	list->next = NULL;

	for (int i = 2; i <= 5; i++)
	{
		Add(list, i);
	}

	display(list);
	return 0;
}
