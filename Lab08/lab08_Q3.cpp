#include<iostream>
using namespace std;
#include<queue>
#include<vector>

// question 3.1

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
    : data(data), left(left), right(right) { }

};

TreeNode* node;

class Tree {

public:
    TreeNode* root;
    Tree(TreeNode* root = NULL) : root(root) { }

    bool isEmpty() {
        return root == NULL;
    }




    

    TreeNode* createNode(TreeNode* node, int data) {
        if(node == NULL) {
            node = new TreeNode(data);
        }
        if(node->data > data) {
            node->left = createNode(node->left,data);
        }
        else if(node->data < data) {
            node->right = createNode(node->right,data);
        }
        return node;
    }

    void create(int data) {
        node = createNode(node,data);
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

    
};

int main() {
    Tree t;
    vector<int> treeData = { 10, 5, 1, 7, 40, 50};
    vector<int> bfsData = {7, 4, 12, 3, 6, 8, 1, 5, 10};

    for(int i = 0; i < treeData.size(); i++) {
        t.create(treeData[i]);
    }
    t.preorder(node); cout << endl;
    t.inorder(node); cout << endl;

    


    return 0;
}
