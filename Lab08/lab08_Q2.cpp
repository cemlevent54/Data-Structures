#include<iostream>
using namespace std;
#include<queue>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
    : data(data), left(left), right(right) { }

};

class Tree {

public:
    TreeNode* root;
    Tree(TreeNode* root = NULL) : root(root) { }

    bool isEmpty() {
        return root == NULL;
    }

    TreeNode* insertNode(TreeNode*& root, int data) {
        TreeNode* node = new TreeNode(data);
        if(!root) {
            root = node;
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left != NULL) {
                q.push(temp->left);
            }
            else {
                temp->left = node;
                return root;
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
            else {
                temp->right = node;
                return root;
            }
        }
    }

    TreeNode* insertNode_2(TreeNode*& root,int data) {
        TreeNode* node = new TreeNode(data);
        if(!root) {
            root = node;
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->right != NULL) {
                q.push(temp->right);
            }
            else {
                temp->right = node;
                return root;
            }
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            else {
                temp->left = node;
                return root;
            }


        }
    }

    // void insert(int data) {
    //     root = insertNode(root, data);
    // }

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
    t.root = t.insertNode(t.root,4);
    t.root = t.insertNode(t.root,6);
    t.root = t.insertNode(t.root,12);
    t.root = t.insertNode(t.root,45);
    t.root = t.insertNode(t.root,7);
    t.root = t.insertNode(t.root,1);
    t.print();
    cout << endl;

    Tree t2;
    t2.root = t.insertNode_2(t2.root,4);
    t2.root = t.insertNode_2(t2.root,6);
    t2.root = t.insertNode_2(t2.root,12);
    t2.root = t.insertNode_2(t2.root,45);
    t2.root = t.insertNode_2(t2.root,7);
    t2.root = t.insertNode_2(t2.root,1);
    t2.print();

    return 0;
}
