#include <assert.h>
#include <iostream>
#include <random>

using namespace std;

class AVLNode {
public:
    int value;
    AVLNode *left, *right;
    int height;
    AVLNode(int val)
    {
        value = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    AVLNode *root = nullptr;

    int height(){return height(root);}
    int height(AVLNode *node) {return node == nullptr ? 0 : node->height;}

    int balance(AVLNode *node) {return height(node->right) - height(node->left);}

    void update(AVLNode *node)
    {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    AVLNode* rotateLeft(AVLNode* node)
    {
        AVLNode *r = node->right;
        node->right = r->left;
        r->left = node;
        update(node);
        update(r); // root
        return r;
    }

    AVLNode* rotateRight(AVLNode* node)
    {
        AVLNode *l = node->left;
        node->left = l->right;
        l->right = node;
        update(node);
        update(l); // root
        return l;
    }

    bool contains(int x){return contains(x, root);}
    bool contains(int x, AVLNode *node)
    {
        if (node ==  nullptr) return false;
        if (node->value == x) return true;
        else if (x < node->value) return contains(x, node->left);
        else return contains(x, node->right);
    }

    void insert(int x) {root = insert(x, root);}
    AVLNode* insert(int x, AVLNode *node)
    {
        if (node == nullptr) return new AVLNode(x); // new vrne pointer na novo ustvarjen object
        if (x <= node->value) node->left = insert(x, node->left);
        else node->right = insert(x, node->right);
        update(node);

        // po potrebi uravnotezi
        int const b = balance(node);
        if (b == 2)
        {
            if (int const br = balance(node->right); br == 0 || br == 1)
                return rotateLeft(node);

            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        if (b == -2)
        {
            if (int const bl = balance(node->left); bl == 0 || bl == -1)
                return rotateRight(node);

            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }

    bool check(AVLNode *node)
    {
        if (node == nullptr) return true;
        int const b = balance(node);
        if ( b <-1 || b > 1) return false;
        return check(node->left) && check(node->right);
    }

};


int main(int argc, char *argv[])
{
    int n = 1'000'000;
    mt19937 rnd(123);
    AVLTree avl;
    for (int i = 0; i < n; i++)
    {
        int x = rnd()%1000000;
        avl.insert(x);

        assert(avl.contains(x));
        //assert(!avl.contains(x+1));
    }

    cout << avl.height() << endl;
    cout << avl.check(avl.root) << endl;

    return 0;
}
