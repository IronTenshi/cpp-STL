#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;


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

public:
    binary_tree(std::vector<datatype>& PreDisplay, std::vector<datatype>& InorderDisplay);//by Inorderdisplay and Preoderdisplay create binary tree;leetcode 105;
    ~binary_tree();
    void release_memory(root<datatype>* root);
    int GetHeight();
    int GetHeight(root<datatype>* node);
    int GetLeavesCount();
    int GetLeavesCount(root<datatype>* node);
    int GetCount();
    int GetCount(root<datatype>* node);
    int PreDisplayLevels();
    int PreDisplayLevels(root<datatype>* node);//degree = 2
    int OnlyOneChildCount();
    int OnlyOneChildCount(root<datatype>* node);
    int OnlyLeftChildCount();
    int OnlyLeftChildCount(root<datatype>* node);
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

template<typename datatype>
int binary_tree<datatype>::GetCount()
{
    return GetCount(tree_root);
}

template<typename datatype>
int binary_tree<datatype>::GetCount(root<datatype>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int count = 0;
    count++;
    count += GetCount(node->left);
    count += GetCount(node->right);
    return count;
}

template<typename datatype>
int binary_tree<datatype>::GetLeavesCount()
{
    return GetLeavesCount(tree_root);
}
template<typename datatype>
int binary_tree<datatype>::GetLeavesCount(root<datatype>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int count = 0;
    if(node->left != nullptr && node ->right != nullptr)
    {
        count++;
    }
    count += GetLeavesCount(node->left);
    count += GetLeavesCount(node->right);
    return count;
}

template<typename datatype>
int binary_tree<datatype>::OnlyOneChildCount()
{
    return OnlyOneChildCount(tree_root);
}

template<typename datatype>
int binary_tree<datatype>::OnlyOneChildCount(root<datatype>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int count = 0;
    if((node->left == nullptr && node->right != nullptr)||(node->left != nullptr && node->right == nullptr))
    {
        count ++;
    }
    count += OnlyOneChildCount(node->left);
    count += OnlyOneChildCount(node->right);
    return count;
}

template<typename datatype>
int binary_tree<datatype>::OnlyLeftChildCount()
{
    return OnlyOneChildCount(tree_root);
}

template<typename datatype>//every count is inside function;before data is not clear;
int binary_tree<datatype>::OnlyLeftChildCount(root<datatype>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int count = 0 ;
    if(node->left != nullptr && node ->right ==nullptr)
    {
        count++;
    }
    count += OnlyLeftChildCount(node->left);
    count += OnlyLeftChildCount(node->right);
    return count;
}

template<typename datatype>
int binary_tree<datatype>::PreDisplayLevels()
{
    return PreDisplayLevels(tree_root);
}

template<typename datatype>
int binary_tree<datatype>::PreDisplayLevels(root<datatype>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int count = 0;
    if(node->left != nullptr && node->right != nullptr)
    {
        count++;
    }
    PreDisplayLevels(node->left);
    PreDisplayLevels(node->right);
    return count;
}


int main()
{
    std::vector<int> v1 = {3,9,20,15,7};
    std::vector<int> v2 = {9,3,15,20,7};
    binary_tree<int> tree1(v1,v2);
    try
    {
        cout<<tree1.GetHeight()<<endl;
        cout<<tree1.GetCount()<<endl;
        cout<<tree1.GetLeavesCount()<<endl;
        cout<<tree1.OnlyLeftChildCount()<<endl;
        cout<<tree1.OnlyOneChildCount()<<endl;
        cout<<tree1.PreDisplayLevels()<<endl;
    }
    catch(char* error)
    {
        cout<<error<<endl;
    }
}
// 3
// 5
// 2
// 0
// 0
// 1
