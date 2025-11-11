#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

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
    void PreDisplay()
    {
        if(tree_root==nullptr)
        {
            return;
        }
        cout<<tree_root->data<<" ";
        PreDisplay(tree_root->left);
        PreDisplay(tree_root->right);
    }
    
public:
    binary_tree(std::vector<datatype>& PreDisplay, std::vector<datatype>& InorderDisplay);//by Inorderdisplay and Preoderdisplay create binary tree;leetcode 105;
    ~binary_tree();
    void release_memory(root<datatype>* root);
    int GetHeight();
    int GetHeight(root<datatype>* node);
    int GetLeavesCount();
    int GetCount();
    int PreDisplayLevels();
    int OnlyChildCount();
    int OnlyLeftChildCount();
    int FullChildCount();//degree 2 nodes count;
};

//leetcode 105;
template<typename datatype>
binary_tree<datatype>::binary_tree(std::vector<datatype>& PreDisplay, std::vector<datatype>& InorderDisplay)
{
    unordered_map<int,int> hashtable;
    int n=InorderDisplay.size();
    for(int i=0;i<InorderDisplay.size();i++)
    {
        hashtable[InorderDisplay[i]]=i;
    }
    tree_root = build_tree(PreDisplay,InorderDisplay,0,n-1,0,n-1,hashtable);
    root<datatype>* build_tree(std::vector<datatype>& PreDisplay, std::vector<datatype>& InorderDisplay,int pre_start,int pre_end,int in_start,int int_end,unordered_map<int,int>& hashtable)
    {
        if(pre_start>pre_end)
        {
            return nullptr;
        }
        int pre_root = pre_start;
        int in_root = hashtable[PreDisplay[pre_root]];
        int left_size = in_root - in_start;
        root<datatype>* node = new root<datatype>(PreDisplay[pre_root]);
        node->left = build_tree(PreDisplay, InorderDisplay, pre_start + 1, pre_start + left_size, in_start, in_root - 1, hashtable);
        node->right = build_tree(PreDisplay, InorderDisplay, pre_start + left_size + 1, pre_end, in_root + 1, int_end, hashtable);
        return node;
    }
}

template<typename datatype>
binary_tree<datatype>::~binary_tree()
{
    //destructor code to free memory
    release_memory(tree_root);
}

template<typename datatype>
void binary_tree<datatype>::release_memory(root<datatype>* root)
{
    if (root == nullptr) return;
    release_memory(root->left);
    release_memory(root->right);
    delete root;
}

template<typename datatype>
int binary_tree<datatype>::GetHeight()
{
    return GetHeight(tree_root);
}

template<typename datatype>
int binary_tree<datatype>::GetHeight(root<datatype>* node)
{
    if (node == nullptr) return 0;
    int left_height = GetHeight(node->left);
    int right_height = GetHeight(node->right);
    return 1 + std::max(left_height, right_height);
}