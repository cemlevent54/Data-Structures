#include<iostream>
using namespace std;
#include<queue>
#include<vector>

// question 2

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


};




int main() {

    Tree t;

    vector<int> deliveryData = {5,3,7,2,4,6,8};

    for(int i = 0; i < deliveryData.size(); i++) {
        t.insert(deliveryData[i]);
    }

    t.inorder(); cout << endl;

    Tree t2;

    vector<int> deliveryData2 = {5,7,8,9};

    for(int i = 0; i < deliveryData2.size(); i++) {
        t2.insert(deliveryData2[i]);
    }

    t2.inorder(); cout << endl;

    return 0;
}