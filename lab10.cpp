#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
};

class splayTree {
public:
    Node* root;

    splayTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void deleteData(int data) {
        root = deleteData(root, data);
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    Node* search(int data) {
        return splay(root, data);
    }

    Node* subtree_max(Node* root) {
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    Node* subtree_min(Node* root) {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void printTree(Node* root, int space = 0, int count = 10) {
        if (root == nullptr) {
            return;
        }

        space += count;

        printTree(root->right, space, count);

        cout << endl;
        for (int i = count; i < space; i++) {
            cout << " ";
        }
        cout << root->data << "\n";

        printTree(root->left, space, count);
    }

private:
    Node* newNode(int data) {
        Node* node = new Node();
        node->data = data;
        node->left = node->right = nullptr;
        return node;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        return x;
    }

    Node* splay(Node* root, int data) {
        if (!root || root->data == data) {
            return root;
        }

        if (root->data > data) {
            if (!root->left) {
                return root;
            }
            if (root->left->data > data) {
                root->left->left = splay(root->left->left, data);
                root = rightRotate(root);
            } else if (root->left->data < data) {
                root->left->right = splay(root->left->right, data);
                if (root->left->right) {
                    root->left = leftRotate(root->left);
                }
            }

            return (root->left == nullptr) ? root : rightRotate(root);
        } else {
            if (!root->right) return root;

            if (root->right->data > data) {
                root->right->left = splay(root->right->left, data);
                if (root->right->left) {
                    root->right = rightRotate(root->right);
                }
            } else if (root->right->data < data) {
                root->right->right = splay(root->right->right, data);
                root = leftRotate(root);
            }
            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }

    Node* insert(Node* root, int data) {
        if (!root) return newNode(data);

        root = splay(root, data);

        if (root->data == data) return root; // Zaten varsa splay işlemi uygula

        Node* temp = newNode(data);

        if (root->data > data) {
            temp->right = root;
            temp->left = root->left;
            root->left = nullptr;
        } else {
            temp->left = root;
            temp->right = root->right;
            root->right = nullptr;
        }

        return temp; // Güncellenen kök düğümü döndür
    }


    Node* deleteData(Node* root, int data) {
        if (!root) return nullptr;

        root = splay(root, data);

        if (data != root->data) return root;

        Node* temp = root;

        if (root->left) {
            root = splay(root->left, data);
            root->right = temp->right;
        } else {
            root = temp->right;
        }

        delete temp;
        return root; // Güncellenen kök düğümü döndür
    }
};

int main() {
    splayTree sply;

    int choice;

    while (1) {
        cout << "1-insert" << endl;
        cout << "2-delete" << endl;
        cout << "3-search" << endl;
        cout << "4-preorder" << endl;
        cout << "5-inorder" << endl;
        cout << "6-postorder" << endl;
        cout << "7-get max and min value" << endl;
        cout << "0-exit" << endl;

        cout << "choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            int value;
            cout << "insert value: ";
            cin >> value;
            sply.insert(value);
        } else if (choice == 2) {
            int value;
            cout << "delete value: ";
            cin >> value;
            sply.deleteData(value);
        } else if (choice == 3) {
            int value;
            cout << "search value: ";
            cin >> value;
            Node* result = sply.search(value);
            if (result) {
                cout << "Element found: " << result->data << endl;
            } else {
                cout << "Element not found." << endl;
            }
        } else if (choice == 4) {
            cout << "preorder: ";
            sply.preorder(sply.root);
            cout << endl;
        } else if (choice == 5) {
            cout << "inorder: ";
            sply.inorder(sply.root);
            cout << endl;
        } else if (choice == 6) {
            cout << "postorder: ";
            sply.postorder(sply.root);
            cout << endl;
        } else if (choice == 7) {
            cout << "max value is: " << sply.subtree_max(sply.root)->data << endl;
            cout << "min value is: " << sply.subtree_min(sply.root)->data << endl;
        }
    }

    return 0;
}
