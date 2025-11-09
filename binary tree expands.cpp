#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;

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
    binary_tree();//by Inorderdisplay and Preoderdisplay create binary tree;
    ~binary_tree();
    int GetHeight(root<datatype>* node);
    int GetLeavesCount();
    int GetCount();
    int PreDisplayLevels();
    int OnlyChildCount();
    int OnlyLeftChildCount();
    int FullChildCount();//degree 2 nodes count;
};