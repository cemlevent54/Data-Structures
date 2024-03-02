#include<iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
    : data(data), left(left), right(right) { }

};

class Tree {
private:
    TreeNode* root;

public:
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

    int getRootVal() {
        return root->data;
    }

    void preorder(TreeNode* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(TreeNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void print() {
        preorder(root); cout << endl;
        inorder(root); cout << endl;
        postorder(root);
    }
};

int main() {
    Tree t;
    cout << t.isEmpty() << endl;
    t.insert(4);
    t.insert(6);
    t.insert(12);
    t.insert(45);
    t.insert(7);
    t.insert(1);
    t.print();

    return 0;
}
