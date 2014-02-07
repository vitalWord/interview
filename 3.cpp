struct List
{
      int value;
      List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List* nxt = new List();
	nxt->value = value;
	nxt->next = nullptr;
	if(l) l->next = nxt;
	return nxt;
}

int main(int argc, char* argv[])
{
	List* head = Add(nullptr, 1);
	List* tmp = head;
	for(int i = 2; i < 6; i++)
		tmp = Add(tmp, i);
	return 0;
}