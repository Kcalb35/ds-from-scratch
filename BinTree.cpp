#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef TreeNode *BinTree;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

void PreOrderTraversal(BinTree tree)
{
    if (tree)
    {
        cout << tree->data;
        PreOrderTraversal(tree->left);
        PreOrderTraversal(tree->right);
    }
}

void InOrderTraversal(BinTree tree)
{
    if (tree)
    {
        InOrderTraversal(tree->left);
        cout << tree->data;
        InOrderTraversal(tree->right);
    }
}

void PostOrderTraversal(BinTree tree)
{
    if (tree)
    {
        PostOrderTraversal(tree->left);
        PostOrderTraversal(tree->right);
        cout << tree->data;
    }
}

void InOrderTraversalWithStack(BinTree tree)
{
    BinTree t = tree;
    stack<TreeNode *> s;
    while (t || !s.empty())
    {
        while (t)
        {
            s.push(t);
            t = t->left;
        }
        if (!s.empty())
        {
            t = s.top();
            s.pop();
            cout << t->data;
            t = t->right;
        }
    }
}

void PreOrderTraversalWithStack(BinTree tree)
{
    BinTree t = tree;
    stack<TreeNode *> s;
    while (t || !s.empty())
    {
        while (t)
        {
            cout << t->data;
            s.push(t);
            t = t->left;
        }
        if (!s.empty())
        {
            t = s.top();
            s.pop();
            t = t->right;
        }
    }
}


void LayerOrderTraversal(BinTree root){
  if (!root) return;
  BinTree t = root;
  queue<TreeNode*> q;
  q.push(root);
  while(q.size()){
    TreeNode* node = q.front();
    cout <<node->data;
    q.pop();
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  
}

TreeNode* IterFind(int x,BinTree BST){
  while(BST){
      if (x > BST->data) BST = BST->right;
      else if (x<BST->data) BST =BST->left;
      else return BST;
  }
  return NULL;
}

TreeNode* FindMax(BinTree BST){
    if (BST)
        while (BST->right) BST = BST->right;
    return BST;
}

TreeNode* FindMin(BinTree BST){
    if (BST)
        while (BST->left) BST= BST->left;
    return BST;
}

BinTree Insert(int x,BinTree BST){
    if (!BST){
        BST = malloc(sizeof(TreeNode));
        BST->data = x;
        BST->left = BST->rifht = NULL;
    }else{
        if (x<BST->data)
            BST->left = Insert(x,BST->left);
        else if (x>BST->data)
            BST->right = Insert(x,BST->right);
    }
    return BST;
}

BinTree Delete(int x,BinTree BST){
    if (!BST) return NULL;
    else if (x<BST->data)
        BST->left = Delete(x,BST->left);
    else if (x>BST->data)
        BST->right = Delete(x,BST->right);
    else {
        if (BST->left && BST->right){
            TreeNode* tmp = FindMin(BST->right);
            BST->data = tmp->data;
            BST->right = Delete(BST->datta,BST->right);
        }
        else {
            TreeNode* tmp = BST;
            if (!BST->left) BST = BST->right;
            else if (!BST->right) BST = BST->left;
            free(tmp);
        }
    }
}