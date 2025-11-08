#include<iostream>

template<typename datatype>
struct root
{
    datatype data;
    root<datatype>* left;
    root<datatype>* right;
    root(datatype value) : data(value), left(nullptr), right(nullptr) {}//constructor,initializing nullptrs;
};

template<typename datatype>
class binary_tree
{
private:
    root<datatype>* tree_root;
    void PreDisplay();

public:
    binary_tree()//initailizing the root 
    {
        tree_root = new root<datatype>(datatype());//create a stack object of the datatype;
        tree_root = nullptr;
    }

    void PreCreate();
    void InorderCreate();
    int GetHeight(root<datatype>* node);
    int GetLeavesCount();
    int GetCount();
    int PreDisplayLevels();
    int OnlyChildCount();
    int OnlyLeftChildCount();
    int FullChildCount();
};