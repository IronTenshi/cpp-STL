#include<iostream>

template<typename Datatype>
struct Node
{
	Datatype data;//datas name in the first box;
	Node<Datatype>* next;//next area in the second box;
};

template<typename Datatype>
class Linklist
{
public:
	Linklist();
	Linklist(Datatype data[], int n);
	~Linklist();
	int Getlength()//to get the numbers of datas;
	{
		int count = 0;
		Node<Datatype>* p = nullptr;
		p = first->next;
		while (p != nullptr)  // judge if the p is available
		{
			count++;
			p = p->next;
		}
		return count;
	}
	Datatype Getfindposition(int position);
	int Loact(Datatype x);
	void Insert(int position, Datatype x);
	Datatype Delete(int position);
	void Empty()
	{
		if (first->next == nullptr)
			throw "the singly linked list is empty";
	}
	void PrintList();

private:
	Node<Datatype>* first;//the firstpoint;
};

template<typename Datatype>
Linklist<Datatype>::Linklist()
{
	first = new Node<Datatype>;//a new heap to initial firstpoint;   new node is return the point type;
	first->next = nullptr;
}

template<typename Datatype>
Linklist<Datatype>::Linklist(Datatype data[], int n)
{
	first = new Node<Datatype>;//a new heap to initial firstpoint;
	first->next = nullptr;
	Node<Datatype>* r = first;
	for (int position = 0;position < n;position ++)
	{
		Node<Datatype>* p = nullptr;
		p = new Node<Datatype>;
		p->data = data[position];
		r->next = p;
		r = p;
	}
	r->next = nullptr;
}

template<typename Datatype>
Datatype Linklist<Datatype>::Getfindposition(int position)
{
	if (first->next == nullptr)
		throw "this is a empty linked list";
	int count = 1;
	Node<Datatype>* p = first->next;
	while (position != count)
	{
		p = p->next;
		if (p == nullptr)
			throw "the position is not exsit";
	}
	return (p->data);
}

template<typename Datatype>//change
Linklist<Datatype>::~Linklist() //release memory is  inportant ;;;;
{
	Node<Datatype>* p = first;
	while (p != nullptr)
	{
		Node<Datatype>* temp = p;  // save recent node
		p = p->next;               // move to next node
		delete temp;               // release the node
	}
}

template<typename Datatype>
int Linklist<Datatype>::Loact(Datatype x)
{
	if (first->next == nullptr)
		throw "this is a empty linked list";
	int count = 1;
	Node<Datatype>* p = first->next;
	while (p != nullptr)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	throw "Data not found";
}

template<typename Datatype>
void Linklist<Datatype>::Insert(int position, Datatype x)
{
	Node<Datatype>* p = first;
	int count = 0;
	while (p != nullptr && count < position - 1)//alternate infront postion;
	{
		p = p->next;
		count++;
	}
	if (p == nullptr)
		throw "error location";
	else
	{
		Node<Datatype>* s = new Node<Datatype>;//change
		s->next = p->next;
		s->data = x;
		p->next = s;
	}
}

template<typename Datatype>
Datatype Linklist<Datatype>::Delete(int position)
{
	int count = 1;
	Node<Datatype>* p = nullptr;
	p = first->next;
	while (count != position)
	{
		p = p->next;
		if (p->next == nullptr)
			throw "location is not exist";
		count++;
	}
	Node<Datatype>* temp = p->next;
	Datatype x = temp->data;
	p->next = temp->next;
	delete temp; 
	return x;
}

template<typename Datatype>
void Linklist<Datatype>::PrintList()
{
	Node<Datatype>* p = first->next;
	while (p != nullptr)
	{
		//p = p->next;after cout move point;
		std::cout << p->data << "   ";
		p = p->next;
	}
	std::cout << std::endl;
}

int main(void)
{
	int a[] = { 1,2,3,4,5,6 };
	Linklist<int> linklist(a, 6);
	std::cout << "the linklist print()" << std::endl;
	linklist.PrintList();

	try
	{
		std::cout << "length is  " << linklist.Getlength() << std::endl;
		linklist.Empty();
		std::cout << "2 s location is " << linklist.Loact(2) << std::endl;
		std::cout << "integer in 3 position  is  " << linklist.Getfindposition(3) << std::endl;
	}
	catch (const char* str) { std::cout << str << std::endl; }

	try
	{
		std::cout << "insert  3 in 3rd postion " << std::endl;
		linklist.Insert(3, 88);
		std::cout << "delete data in 1st postion " << std::endl;
		linklist.Delete(1);
		linklist.PrintList();
	}
	catch (const char* str) { std::cout << str << std::endl; }
}