#include<iostream>
#include<queue>

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
    root<datatype>* getroot()
    {
        return root0;
    }
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
        // bt ->leftchild = Bitree<datatype>();
        // bt ->rightchild = Bitree<datatype>();
        bt -> leftchild = Bitree<datatype>().getroot();//create the left child tree
        bt -> rightchild = Bitree<datatype>().getroot();//create the right child tree
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

template<typename datatype>
void Bitree<datatype>::midshow(root<datatype>* bt)
{
    if(bt == nullptr)
    {
        return;
    }
    else
    {
        midshow(bt -> leftchild);
        cout<<bt ->data<<endl;
        midshow(bt -> rightchild);
    }
}

template<typename datatype>
void Bitree<datatype>::aftershow(root<datatype>* bt)
{
    if(bt == nullptr)
    {
        return;
    }
    else
    {
        aftershow(bt -> leftchild);
        aftershow(bt -> rightchild);
        cout<<bt ->data<<endl;
    }
}

template<typename datatype>
void Bitree<datatype>::levelshow(root<datatype>* bt)
{
    //using the queue to store the node
    std::queue<root<datatype>*> q;
    if(bt != nullptr)
    {
        q.push(bt);
    }
    while(!q.empty())
    {
        //get the front node
        root<datatype>* current = q.front();
        q.pop();
        cout<<current->data<<endl;
        if(current->leftchild != nullptr)
        {
            q.push(current->leftchild);
        }
        if(current->rightchild != nullptr)
        {
            q.push(current->rightchild);
        }
    }
}

int main()
{
    cout<<"create a binary tree:"<<endl;
    Bitree<char> bitree;
    cout<<"front show:"<<endl;
    bitree.frontshow(bitree.getroot());
    cout<<"mid show:"<<endl;
    bitree.midshow(bitree.getroot());
    cout<<"after show:"<<endl;
    bitree.aftershow(bitree.getroot());
    cout<<"level show:"<<endl;
    bitree.levelshow(bitree.getroot());
}
