#include <bits/stdc++.h>
using namespace std;

class BiNode
{
public:
    int val;
    BiNode *left;
    BiNode *right;

    BiNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

BiNode *binary_tree_input()
{
    int val;
    cin >> val;
    BiNode *root;
    if (val == -1)
        root == NULL;
    else
        root = new BiNode(val);
    queue<BiNode *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        BiNode *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        BiNode *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new BiNode(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new BiNode(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

void levelOrder(BiNode *root)
{
    queue<BiNode *> q;
    q.push(root);

    while (!q.empty())
    {
        BiNode *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{

    BiNode *root = binary_tree_input();

    levelOrder(root);

    return 0;
}