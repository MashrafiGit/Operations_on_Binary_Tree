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
        root = NULL;
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

int max_height(BiNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL & root->right == NULL)
        return 0;

    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}

int main()
{
    BiNode *root = binary_tree_input();

    cout << max_height(root);
    return 0;
}