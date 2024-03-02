#include<iostream>
using namespace std;

// question 4

// AVL tree is a self-balancing Binary Search Tree where the difference between heights of left and
// right subtrees cannot be more than one for all nodes. Create the following menu for the AVL tree. Perform
// necessary actions according to user selection.
// " [ 1 ] Insert Element Into the Tree"
// " [ 2 ] Show Balanced AVL Tree"
// " [ 3 ] InOrder Traversal"
// " [ 4 ] PreOrder Traversal"
// " [ 5 ] PostOrder traversal"
// " [ 6 ] Exit"

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int data = 0, Node* left = NULL, Node* right = NULL) : 
    data(data), left(left), right(right) { }

};

class avl {
    public:
    Node* root;

    avl() : root(NULL) { }

    int height(Node* node) {
        if(!node) return 0;
        return node->height;
    } 

    int max(int a,int b) {
        return (a > b) ? a : b;
    }

    Node* newNode(int key) {
        Node* node = new Node();
        node->data = key;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left),height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(height(y->left),height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* node) {
        if(!node) return 0;

        return height(node->left) - height(node->right);
    }

    Node* insert(Node* node, int data) {
        if(!node) return newNode(data);

        if(data < node->data) {
            node->left = insert(node->left,data);
        }
        else if(data > node->data) {
            node->right = insert(node->right,data);
        }
        else {
            return node;
        }

        node->height = 1 + max(height(node->left),height(node->right));

        int balance = getBalance(node);

        if(balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }

        if(balance < -1 && data > node->right->data) {
            node->right = leftRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while(current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* maxValueNode(Node* node) {
        Node* current = node;
        while(current->right != NULL) {
            current = current->right;
        }
        return current;
    }

    Node* deleteNode(Node* root, int data) {
        
        // find deleted node
        if(!root) return root;
        if(data < root->data) {
            root->left = deleteNode(root->left,data);
        }
        else if(data > root->data) {
            root->right = deleteNode(root->right,data);
        }

        // if the data is same as root's data
        else {

            // one child or no child
            if((!root->left) || (!root->right)) {
                Node* temp = root->left ? root->left : root->right;
                // no child
                if(!temp) {
                    temp = root;
                    root = NULL;
                }

                // one child
                else {
                    *root = *temp; // copy the content of non-empty child
                    free(temp);
                }
            }

            else {

                // node with two children
                // get inorder successor
                Node* temp = minValueNode(root->right);
                root->data = temp->data;

                // delete inorder successor
                root->right = deleteNode(root->right,temp->data);
            }
        }

        // if tree had only one node
        if(!root) return root;
        
        // update height of current node
        root->height = 1 + max(height(root->left),height(root->right));
        
        // get balance factor of that node
        int balance = getBalance(root);
        
        // left left case
        if(balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        // left right case
        if(balance > 1 && getBalance(root->right) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        // right right case
        if(balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        
        // right left case
        if(balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getRoot() {
        return root;
    }

    void preorder(Node* node) {
        if(node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node* node) {
        if(node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(Node* node) {
        if(node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void printTree(Node* node, int space) {
        if (!node) return;

        space += 10;

        printTree(node->right, space);

        cout << endl;

        for (int i = 10; i < space; i++) {
            cout << " ";
        }

        cout << node->data << "\n";

        printTree(node->left, space);
    }

    void printTree(Node* node) {
        printTree(node,0);
    }

    Node* searchData(Node* node,int data) {
        Node* current = node;
        while(current != NULL) {
            if(current->data == data) {
                return current;
            }
            else if(current->data > data) {
                current = current->left; 
            }
            else if(current->data < data) {
                current = current->right;
            }
        }

        return NULL;
    }

    bool searchData(int data) {
        if(searchData(root,data) != NULL) {
            return true;
        }
        else return false;
    }


};





int main() {

    avl tree;

    int input;

    while(1) {
        cout <<  "1- Insert Element Into the Tree\n2- Delete Element\n3- Show Balanced AVL Tree\n4- InOrder Traversal\n5- PreOrder Traversal\n6- PostOrder traversal\n7- Get Balance Factor\n8- Get Max and Min values\n9- Search Data\n10- Exit" << endl;
        cin >> input;
        if(input == 1) {
            cout << "Enter element to be inserted: ";
            int value;
            cin >> value;
            tree.root = tree.insert(tree.root,value);
        }

        else if(input == 2) {
            cout << "Enter delete element: ";
            int value;
            cin >> value;
            tree.root = tree.deleteNode(tree.root,value);
        }

        else if(input == 3) {
            cout << "AVL Tree is: " << endl;
            tree.printTree(tree.root);
        }

        else if(input == 4) {
            cout << "InOrder: ";
            tree.inorder(tree.root);
            cout << endl;
        }
        
        else if(input == 5) {
            cout << "PreOrder: ";
            tree.preorder(tree.root);
            cout << endl;
        }
        
        else if(input == 6) {
            cout << "PostOrder: ";
            tree.postorder(tree.root);
            cout << endl;
        }

        else if(input == 7) {
            cout << "Balance factor is: " << tree.getBalance(tree.root) << endl;
        }

        else if(input == 8) {
            cout << "max value of avl tree is: " << tree.maxValueNode(tree.root)->data << endl;
            cout << "min value of avl tree is: " << tree.minValueNode(tree.root)->data << endl;
        }

        else if(input == 9) {
            int value;
            cout << "Enter the number to search in AVL tree: ";
            cin >> value;
            if(tree.searchData(value)) {
                cout << "Number found" << endl;
            }
            else cout << "Number haven't been found" << endl;
        }

        else if(input == 10) {
            break;
        }

        else {
            cout << "wrong input! try again! " << endl;
        }
        
    }

    return 0;
}