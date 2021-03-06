#include <iostream>

using namespace std;

struct slistelem
{ 
char* data; 
slistelem* next;
};

class List
{
	public:
	List():h(0){};
	void Release();
	~List(){Release();}
	void Prepend(char* c);
	void Print();
	private:
	slistelem* h;
};

void List::Prepend(char* c)
{
	slistelem* temp = new slistelem;
	temp->next=h;
	temp->data=c;
	h=temp;
}

void List::Print()
{
	cout<< h->data << "->";
	cout<< (h->next)->data << "->";	
	cout<< ((h->next)->next)->data<< endl;
}

void List::Release()
{
	delete h;
}

int main()
{
	List L;
	char* a = "char a";
	char* b= "char b";
	char* c= "char c";
	L.Prepend(a);
	L.Prepend(b);
	L.Prepend(c);
	L.Print();
}