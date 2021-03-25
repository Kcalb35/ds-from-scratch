#include <iostream>
using namespace std;

template <typename T>
class AVL
{
private:
public:
    class node
    {
    public:
        T val;
        node *left;
        node *right;
        int height;
        node(T k)
        {
            height = 1;
            left = right = NULL;
            val = k;
        }
    };

    node *root;
    int size;
    void insert(T x)
    {
        root = insertUtil(root, x);
    }
    void remove(T x)
    {
        removeUtil(root,x);
    }
    node *search(T x)
    {
        return searchUtil(root, x);
    }
    void print()
    {
        printUtil(root);
        cout << endl;
    }

private:
    int height(node *head)
    {
        if (head == NULL)
            return 0;
        return head->height;
    }

    node *searchUtil(node *head, T x)
    {
        if (head == NULL)
            return NULL;
        T k = head->val;
        if (x < k)
            return searchutil(head->left, x);
        if (x > k)
            return searchutil(head->right, x);
        if (x == k)
            return head;
    }

    void printUtil(node *head)
    {
        if (head == NULL)
            return;
        printUtil(head->left);
        cout << head->val << " ";
        printUtil(head->right);
    }

    node *leftRotatation(node *head)
    {
        node *newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        // update height
        updateHeight(newhead);
        updateHeight(head);
        return newhead;
    }

    node *rightRotation(node *head)
    {
        node *newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        // update height
        updateHeight(head);
        updateHeight(newhead);
        return newhead;
    }

    node *insertUtil(node *head, T x)
    {
        if (head == NULL)
        {
            size += 1;
            node *tmp = new node(x);
            return tmp;
        }
        if (x < head->val)
            head->left = insertUtil(head->left, x);
        else if (x > head->val)
            head->right = insertUtil(head->right, x);
        // if x equals head->val then do nothing;
        // and for each node update their height and position
        updateHeight(head);
        int d = height(head->left) - height(head->right);
        if (d > 1)
        {
            if (x < head->left->val)
            {
                // LL
                return rightRotation(head);
            }
            else
            {
                // LR
                head->left = leftRotatation(head->left);
                return rightRotation(head);
            }
        }
        else if (d < -1)
        {
            if (x > head->right->val)
            {
                // RR
                return leftRotatation(head);
            }
            else
            {
                // RL
                head->right = rightRotation(head->right);
                return leftRotatation(head);
            }
        }
        return head;
    }

    void updateHeight(node *node)
    {
        if (node == NULL)
            return;
        node->height = 1 + max(height(node->left), height(node->right));
    }

    node* removeUtil(node *head, T x)
    {
        if (head == NULL)
            return NULL;
        if (x < head->val)
            head->left = removeUtil(head->left, x);
        else if (x > head->val)
            head->right = removeUtil(head->right, x);
        else
        {
            // delete current node
            if (head->left && head->left)
            {
                // 2 son nodes
                // find right min;
                node *tmp = head->right;
                while (!tmp->left)
                    tmp = tmp->left;
                head->val = tmp->val;
                head->right = removeUtil(head->right, tmp->val);
            }
            else
            {
                // 0 or 1 son node
                node *tmp = head;
                if (head->left == NULL)
                    head = head->right;
                else if (head->right == NULL)
                    head = head->left;
                delete (tmp);
            }
        }
        // for each node upgrade their height and position
        if (head == NULL)
            return head;
        updateHeight(head);
        int d = height(head->left) - height(head->right);
        if (d > 1)
        {
            int ld = height(head->left->left) - height(head->left->right);
            if (ld > 1)
            {
                // LL
                return rightRotation(head);
            }
            else
            {
                // LR
                head->left = leftRotatation(head->left);
                return rightRotation(head);
            }
        }
        else if (d < -1)
        {
            int rd = height(head->right->left) - height(head->right->right);
            if (rd > 1)
            {
                // RL
                head->right = rightRotation(head->right);
                return leftRotatation(head);
            }
            else
            {
                // RR
                return leftRotatation(head);
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    AVL<float> t;
    t.insert(100);
    t.insert(90);
    // test LL
    t.insert(80);
    // test RR
    t.insert(110);
    // test LR
    t.insert(95);
    t.insert(94);
    // test RL
    t.insert(99);
    t.insert(98);
    t.print();
}
