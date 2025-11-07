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
    root(): leftchild(nullptr), rightchild(nullptr) {}
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
    void createtree(root<datatype>*& bt); //function to create tree
    root<datatype>* getroot()
    {
        return root0;
    }
    root<datatype>* inputroot(root<datatype>* root0)
    {
        this->root0 = root0;
    }
private:
    root<datatype>* root0;
};

template<typename datatype>//it is preorder create tree
void Bitree<datatype>::createtree(root<datatype>*& bt)
{
    datatype ch;
    cin>>ch;
    cout<<"input data:(if input the #, it means NULL)"<<ch<<endl;
    if(ch == '#')
    {
        bt = nullptr;
    }
    else
    {
        bt = new root<datatype>;
        bt -> data = ch;
        createtree(bt -> leftchild);
        createtree(bt -> rightchild);
    }
}

template<typename datatype>
Bitree<datatype>::Bitree()
{
    root0 = new root<datatype>;
    root0 = nullptr;
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
        cout<<bt ->data<<"  ";
        frontshow(bt -> leftchild);
        frontshow(bt -> rightchild);
    }
    cout<<endl;
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
        cout<<bt ->data<<"  ";
        midshow(bt -> rightchild);
    }
    cout<<endl;
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
        cout<<bt ->data<<"  ";
    }
    cout<<endl;
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
        cout<<current->data<<"  ";
        if(current->leftchild != nullptr)
        {
            q.push(current->leftchild);
        }
        if(current->rightchild != nullptr)
        {
            q.push(current->rightchild);
        }
    }
    cout<<endl;
}

int main()
{
    cout<<"create a binary tree:"<<endl;
    Bitree<char> btree;
    root<char>* root0 = btree.getroot();
    btree.createtree(root0);
    cout<<"front show:"<<endl;
    btree.frontshow(root0);
    cout<<"mid show:"<<endl;
    btree.midshow(root0);
    cout<<"after show:"<<endl;
    btree.aftershow(root0);
    cout<<"level show:"<<endl;
    btree.levelshow(root0);
}
