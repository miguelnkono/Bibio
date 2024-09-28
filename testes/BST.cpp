#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
    void insert_node(TreeNode *new_node);
    void print_nodes() const;
    bool find(string value) const;

private:
    string data;
    TreeNode *left;
    TreeNode *right;
    friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
    BinarySearchTree();
    void insert(string data);
    void erase(string data);
    int count(string data) const;
    void print() const;

private:
    TreeNode *root;
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

void BinarySearchTree::print() const
{
    if (root != NULL)
    {
        root->print_nodes();
    }
}

void TreeNode::print_nodes() const
{
    if (left != NULL)
        left->print_nodes();
    cout << data << endl;
    if (right != NULL)
        right->print_nodes();
}

void BinarySearchTree::insert(string data)
{
    TreeNode *new_node = new TreeNode;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL)
        root = new_node;
    else
        root->insert_node(new_node);
}

void TreeNode::insert_node(TreeNode *new_node)
{
    if (new_node->data < data)
    {
        if (left == NULL)
            left = new_node;
        else
            left->insert_node(new_node);
    }
    else if (data < new_node->data)
    {
        if (right == NULL)
            right = new_node;
        else
            right->insert_node(new_node);
    }
}

int BinarySearchTree::count(string data) const
{
    if (root == NULL)
        return 0;
    else if (root->find(data))
        return 1;
    else
        return 0;
}

void BinarySearchTree::erase(string data)
{
    // Find node to be removed.
    TreeNode *to_be_remove = root;
    TreeNode *parent = NULL;
    bool found = false;
    while (!found && to_be_remove != NULL)
    {
        if (to_be_remove->data < data)
        {
            parent = to_be_remove;
            to_be_remove = to_be_remove->right;
        }
        else if (to_be_remove->data > data)
        {
            parent = to_be_remove;
            to_be_remove = to_be_remove->left;
        }
        else
            found = true;
    }
    if (!found)
        return;

    // to_re_remove contains the data.

    // if one of the child is empty, use the other.
    if (to_be_remove->left == NULL || to_be_remove == NULL)
    {
        TreeNode *new_child;
        if (to_be_remove->left == NULL)
            new_child = to_be_remove->right;
        else
            new_child = to_be_remove->left;

        if (parent == NULL) // found at the root.
            parent = new_child;
        else if (parent->left == to_be_remove)
            parent->right = new_child;
        else
            parent->left = new_child;
    }

    // neither subtree is enpty.

    // find smallest element of the right tree subtree.
    TreeNode *smallest_parent = to_be_remove;
    TreeNode *smallest = to_be_remove->right;
    while (smallest->left != NULL)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in the right subtree.

    // Move contents, unlink child.
    to_be_remove->data = smallest->data;
    if (smallest_parent == to_be_remove)
        smallest_parent->right = smallest->right;
    else
        smallest_parent->left = smallest->right;
}

bool TreeNode::find(string value) const
{
    if (value < data)
    {
        if (left == NULL)
            return false;
        else
            return left->find(value);
    }
    else if (data < value)
    {
        if (right == NULL)
            return false;
        else
            return right->find(value);
    }
    else
        return true;
}

int main()
{
    BinarySearchTree bst;
    bst.insert("D");
    bst.insert("B");
    bst.insert("A");
    bst.insert("C");
    bst.insert("F");
    bst.insert("E");
    bst.insert("I");
    bst.insert("G");
    bst.insert("H");
    bst.insert("J");
    bst.print();

    cout << bst.count("E") << endl;
}