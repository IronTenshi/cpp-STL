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
    ~Bitree();//not have premeter不带有参数!!!!!;
    void frontshow(root<datatype>* bt);
    void midshow(root<datatype>* bt);
    void aftershow(root<datatype>* bt);
    void levelshow(root<datatype>* bt);
    void releasememory(root<datatype>* bt);
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
Bitree<datatype>::~Bitree()//not have premeter不带有参数!!!!!
{
    //  if(bt == nullptr)
    // {
    //     return;
    // }
    // else
    // {
    //     cout<<bt ->data<<endl;
    //     frontshow(bt -> leftchild);
    //     frontshow(bt -> rightchild);
    // }
    releasememory(root0);
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

template<typename datatype>
void Bitree<datatype>::releasememory(root<datatype>* bt)
{
    if(bt == nullptr)
    {
        return;
    }
    else
    {
        releasememory(bt -> leftchild);
        releasememory(bt -> rightchild);
        delete bt;
    }
}

int main()
{
    
}
