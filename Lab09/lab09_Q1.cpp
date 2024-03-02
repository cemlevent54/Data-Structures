#include<iostream>
using namespace std;
#include<queue>
#include<vector>

// question 1
// + bst delete

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0, TreeNode* left = NULL, TreeNode* right = NULL) 
    : data(data) , left(left) , right(right) { }

};

class Tree {
    public:
    TreeNode* root;
    Tree(TreeNode* root = NULL) : root(root) { }

    bool isEmpty() {
        return root == NULL;
    }

    void insert(TreeNode*& root, int data) {
        TreeNode* node = new TreeNode(data);
        if (!root) {
            root = node;
            return;
        }
        TreeNode* prev = NULL;
        TreeNode* temp = root;

        while (temp) {
            if (temp->data > data) {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->data < data) {
                prev = temp;
                temp = temp->right;
            }
        }

        if (prev->data > data) {
            prev->left = node;
        }
        else {
            prev->right = node;
        }
    }

    void insert(int data) {
        insert(root, data);
    }

    void preorder(TreeNode* root) {
        if(root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void preorder() {
        preorder(root);
    }

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void inorder() {
        inorder(root);
    }

    void postorder(TreeNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void postorder() {
        postorder(root);
    }
    
    TreeNode* deleteNode(TreeNode* root,int data) {
        
        // base case
        if(!root) return root;

        //recursive calls for deleted node
        if(root->data > data) {
            root->left = deleteNode(root->left,data);
            return root;
        }
        else if(root->data < data) {
            root->right = deleteNode(root->right,data);
            return root;
        }

        // if one of the children is empty
        if(!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // if both children exist
        else {
            TreeNode* succParent = root;
            TreeNode* succ = root->right;

            // find successor
            while(!succ->left) {
                succParent = succ;
                succ = succ->left;
            }

            // delete successor
            if(succParent != root) {
                succParent->left = succ->right;
            }
            else {
                succParent->right = succ->right;
            }

            root->data = succ->data;

            delete succ;
            return root;
        }
    }

    void deleteNode(int data) {
        root = deleteNode(root,data);
    }

};




int main() {

    Tree t;

    while(1) {

        cout << "1-insert element" << endl;
        cout << "2-delete element" << endl;
        cout << "3-preorder" << endl;
        cout << "4-inorder" << endl;
        cout << "5-postorder" << endl;
        cout << "6-exit" << endl;
        int choice;
        cin >> choice;

        if(choice == 1) {
            // insert
            int data;
            cout << "insert data: ";
            cin >> data;
            t.insert(data);
        }

        else if(choice == 2) {
            int data;
            cout << "enter deleted value: ";
            cin >> data;
            t.deleteNode(data);
        }

        else if(choice == 3) {
            //preorder
            cout << "preorder: ";
            t.preorder();
            cout << endl;
        }

        else if(choice == 4) {
            //inorder
            cout << "inorder: ";
            t.inorder();
            cout << endl;
        }
        
        else if(choice == 5) {
            // postorder
            cout << "postorder: ";
            t.postorder();
            cout << endl;
        }

        else if(choice == 6) {
            // exit
            break;
        }

        else {
            cout << "Invalid Choice, Try Again" << endl;
        }
    }

    return 0;
}