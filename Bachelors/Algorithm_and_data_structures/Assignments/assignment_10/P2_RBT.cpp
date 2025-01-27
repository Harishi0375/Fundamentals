#include <iostream>

enum Colour { RED, BLACK };

struct Node {
    int data;
    Colour colour;
    Node *left, *right, *parent;

    Node(int data): data(data), colour(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    private:
        Node *root;

    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        void transplant(Node*&, Node*&);
        Node* minimum(Node*);
        Node* maximum(Node*);

    public:
        RedBlackTree();
        void insertRB(int);
        void deleteRB(int);
        Node* predecessor(const Node *&);
        Node* successor(const Node *&);
        Node* getMinimum();
        Node* getMaximum();
        Node* search(int);
        void inorderHelper(Node *node);
        void inorder();
};

// Constructor
RedBlackTree::RedBlackTree() {
    root = nullptr;
}

// Rotate left
void RedBlackTree::rotateLeft(Node *&x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Rotate right
void RedBlackTree::rotateRight(Node *&x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// Fix the red-black tree after insertion
void RedBlackTree::fixInsertRBTree(Node *&z) {
    while (z != root && z->parent->colour == RED) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;
            if (y != nullptr && y->colour == RED) {
                z->parent->colour = BLACK;
                y->colour = BLACK;
                z->parent->parent->colour = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->colour = BLACK;
                z->parent->parent->colour = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;
            if (y != nullptr && y->colour == RED) {
                z->parent->colour = BLACK;
                y->colour = BLACK;
                z->parent->parent->colour = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->colour = BLACK;
                z->parent->parent->colour = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->colour = BLACK;
}

// Insert a new node with given data
void RedBlackTree::insertRB(int data) {
    Node *z = new Node(data);
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    if (z->parent == nullptr) {
        z->colour = BLACK;
        return;
    }

    if (z->parent->parent == nullptr) {
        return;
    }

    fixInsertRBTree(z);
}

// Helper function to transplant nodes
void RedBlackTree::transplant(Node *&u, Node *&v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

// Minimum node
Node* RedBlackTree::minimum(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node *RedBlackTree::maximum(Node *node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

// Fix the red-black tree after deletion
void RedBlackTree::fixDeleteRBTree(Node *&x) {
    while (x != root && x->colour == BLACK) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w->colour == RED) {
                w->colour = BLACK;
                x->parent->colour = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->colour == BLACK && w->right->colour == BLACK) {
                w->colour = RED;
                x = x->parent;
            } else {
                if (w->right->colour == BLACK) {
                    w->left->colour = BLACK;
                    w->colour = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->colour = x->parent->colour;
                x->parent->colour = BLACK;
                w->right->colour = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            Node *w = x->parent->left;
            if (w->colour == RED) {
                w->colour = BLACK;
                x->parent->colour = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->colour == BLACK && w->left->colour == BLACK) {
                w->colour = RED;
                x = x->parent;
            } else {
                if (w->left->colour == BLACK) {
                    w->right->colour = BLACK;
                    w->colour = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->colour = x->parent->colour;
                x->parent->colour = BLACK;
                w->left->colour = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->colour = BLACK;
}

// Delete a node with given data
void RedBlackTree::deleteRB(int data) {
    Node *z = search(data);
    if (z == nullptr) return;

    Node *y = z;
    Node *x;
    Colour yOriginalColour = y->colour;

    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        yOriginalColour = y->colour;
        x = y->right;
        if (y->parent == z) {
            if (x != nullptr) x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->colour = z->colour;
    }
    delete z;
    if (yOriginalColour == BLACK) {
        fixDeleteRBTree(x);
    }
}

// Search for a node with given data
Node* RedBlackTree::search(int data) {
    Node *current = root;
    while (current != nullptr) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

// Find the predecessor of a node
Node* RedBlackTree::predecessor(const Node *&node) {
    if (node->left != nullptr) {
        return maximum(node->left);
    }
    Node *current = node->parent;
    while (current != nullptr && node == current->left) {
        node = current;
        current = current->parent;
    }
    return current;
}

// Find the successor of a node
Node* RedBlackTree::successor(const Node *&node) {
    if (node->right != nullptr) {
        return minimum(node->right);
    }
    Node *current = node->parent;
    while (current != nullptr && node == current->right) {
        node = current;
        current = current->parent;
    }
    return current;
}

// Find the minimum node in the tree
Node* RedBlackTree::getMinimum() {
    return minimum(root);
}

// Find the maximum node in the tree
Node* RedBlackTree::getMaximum() {
    Node *current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

// In-order traversal helper function
void RedBlackTree::inorderHelper(Node *node) {
    if (node != nullptr) {
        inorderHelper(node->left);
        std::cout << node->data << " ";
        inorderHelper(node->right);
    }
}

// In-order traversal
void RedBlackTree::inorder() {
    inorderHelper(root);
    std::cout << std::endl;
}


int main() 
{
    RedBlackTree tree;

    // Test insertion
    int valuesToInsert[] = {13, 44, 37, 7, 22, 16};
    std::cout << "Inserting values: ";
    for (int value : valuesToInsert) {
        std::cout << value << " ";
        tree.insertRB(value);
    }
    std::cout << std::endl;

    // Print the tree in in-order traversal after insertion
    std::cout << "In-order traversal after insertion: ";
    tree.inorder();

    // Test search
    int searchValue = 22;
    Node* foundNode = tree.search(searchValue);
    if (foundNode) {
        std::cout << "Found node with data: " << foundNode->data << std::endl;
    } else {
        std::cout << "Node with data " << searchValue << " not found." << std::endl;
    }

    // Test deletion
    int valuesToDelete[] = {22, 13};
    std::cout << "Deleting values: ";
    for (int value : valuesToDelete) {
        std::cout << value << " ";
        tree.deleteRB(value);
    }
    std::cout << std::endl;

    // Print the tree in in-order traversal after deletion
    std::cout << "In-order traversal after deletion: ";
    tree.inorder();

    // Test getMinimum and getMaximum
    Node* minNode = tree.getMinimum();
    Node* maxNode = tree.getMaximum();
    if (minNode) {
        std::cout << "Minimum value in the tree: " << minNode->data << std::endl;
    }
    if (maxNode) {
        std::cout << "Maximum value in the tree: " << maxNode->data << std::endl;
    }

    return 0;
}