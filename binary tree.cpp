#include<iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename datatype>
struct root
{
    datatype data;
    root* leftchild;
    root* rightchild;
};

template<typename datatype>
class Bitree
{
public:
    Bitree();
    ~Bitree();
    void frontshow(root<datatype>* bt);
    void midshow(root<datatype>* bt);
    void aftershow(root<datatype>* bt);
    void levelshow(root<datatype>* bt);

private:
    root<datatype>* root0;
};

template<typename datatype>
Bitree<datatype>::Bitree()
{
    root<datatype>* bt;//bt is pointer to the root node
    char ch;
    cout<<"please input the data of the new node(if you input a '#',it means NULL): "<<endl;
    cin>>ch;
    if(ch == '#')
    {
        bt = nullptr;
    }
    else
    {
        bt = new root<datatype>;
        bt -> data = ch;//initialize the data of the root node
        bt ->leftchild = Bitree<datatype>();
        bt ->rightchild = Bitree<datatype>();
    }
}

template<typename datatype>
Bitree<datatype>::~Bitree()
{
    if(bt == nullptr)
    {
        return;
    }
    else
    {
        //after deleting left and right subtrees, delete the root node
        ~Bitree<datatype>(bt -> leftchild);
        ~Bitree<datatype>(bt -> rightchild);
        delete bt;
    }
}

template<typename datatype>
void Bitree<datatype>::frontshow(root<datatype>* bt)
{
    if(bt == nullptr)
    {
        return;
    }
    else
    {
        cout<<bt ->data<<endl;
        frontshow(bt -> leftchild);
        frontshow(bt -> rightchild);
    }
}

int main()
{
    
}
