#include<iostream>
using namespace std;

const int MaxSize = 100;
template<typename Datatype>
class SeqList
{
public:
	SeqList();
	SeqList(Datatype a[], int n);
	~SeqList() {};
	int Length();
	Datatype Get(int i);
	int Locate(Datatype x);
	void Insert(int i, Datatype x);
	Datatype Delete(int i);
	int Empty();
	void PrintList();

private:
	Datatype Data[MaxSize];
	int length;
};

template<typename Datatype>
SeqList<Datatype>::SeqList()
{
	length = 0;
}

template<typename Datatype>
SeqList<Datatype>::SeqList(Datatype a[], int n)
{
	if (n > MaxSize)
		throw "lager than MaxSize";
	else
	{
		for (int i = 0; i < n;i++)
		{
			Data[i] = a[i];
		}
		length = n;
	}
}

template<typename Datatype>
int SeqList<Datatype>::Length()
{
	return length;//can return empty seqlist
}

template<typename Datatype>
Datatype SeqList<Datatype>::Get(int i)
{
	if (i > length)
		throw "getlocate error";
	return Data[i - 1];
}

template<typename Datatype>
void SeqList<Datatype>::Insert(int i, Datatype x)
{
	if (i > length + 1 || i < 1)
		throw "error locate";
	if (length == MaxSize)
		throw "lager than MaxSize";
	for (int j = length; j >= i; j--)
	{
		Data[j] = Data[j - 1];
	}
	length++;
	Data[i - 1] = x;
}

template<typename Datatype>
int SeqList<Datatype>::Locate(Datatype x)
{
	for (int i = 0; i < length; i++)
	{
		if (Data[i] == x)
		{
			return i + 1;
		}
	}
	return 0;
}

template<typename Datatype>
Datatype SeqList<Datatype>::Delete(int i)
{
	if (i > length || i < 1)
		throw "error delete";
	return Data[i - 1];
	for (int j = i; j < length; j++)
	{
		Data[j - 1] = Data[j];
	}
	length--;
}

template<typename Datatype>
int SeqList<Datatype>::Empty()
{
	if (length == 0)
	{
		throw "the seqlist is empty";
	}
}

template<typename Datatype>
void SeqList<Datatype>::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		cout << Data[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int r[5] = { 1,2,3,4,5 }, x, i;
	SeqList<int> L(r, 5);
	cout << "print" << endl;
	L.PrintList();
	try
	{
		L.Insert(2, 8);
		cout << "after insert" << endl;
		L.PrintList();
	}
	catch (char* str) { cout << str << endl; }
	cout << "length is " << L.Length() << endl;
	cout << "input you wanna find number" << endl;
	cin >> x;
	i = L.Locate(x);
	if (i == 0)
		cout << "which position you wanna find" << endl;
	else
		cout << "this number is " << i << endl;
	try
	{
		cout << "which number do you wanna find" << endl;
		cin >> i;
		cout << "the " << i << "element is " << L.Get(i) << endl;
	}
	catch (char* str) { cout << str << endl; }
	try
	{
		cout << "which position do you wanna delete" << endl;
		cin >> i;
		x = L.Delete(i);
		cout << "the delete number is " << x << endl;
		cout << "after deleting seqlist is" << endl;
		L.PrintList();
	}
	catch (char* str) { cout << str << endl; }
}