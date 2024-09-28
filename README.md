`Algorithms: `
# Binary Search Tree
Binary Search Tree is an alogorithm that state that the data value of all descendants 
to the left of any node are less than the data value stored in that node, and all descendants 
of the right have greater data value.

`Insertion`
* If you encounter a non-NULL node, look at its data value. If the data value of that node is larger
than the one you want to insert, continue the process with the left child. If the existing data
value is smaller, continue the process with the right child.
* If you encounter a NULL node, replace it with the new node.

-
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

-

`Removal`
To remove a node we sould first find it.
Once the node is find, we can now remove it.
* When removing a node wit only one child from a binary search tree, the child replaces the node to 
be removed.
* When removing a node wit two children from a binary search tree, repplace it with the smallest node of the right subtree.