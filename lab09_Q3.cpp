#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
        : data(data), left(left), right(right) { }

};

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) return new TreeNode(data);

    if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        root->left = insertNode(root->left, data);
    return root;
}

TreeNode* findNode(TreeNode* root, int data) {
    TreeNode* itr = root;

    while (itr != NULL) {
        if (itr->data == data) return itr;
        else if (data > itr->data) itr = itr->right;
        else if (data < itr->data) itr = itr->left;
    }

    return NULL;
}

bool checkMainPath(TreeNode* start, vector<int>& v) {
    TreeNode* itr = start;

    for (int i = 0; i < v.size(); i++) {
        if (itr == NULL) return false;  // Check if itr is NULL before accessing left or right

        if (itr->left != NULL && itr->left->data == v[i]) itr = itr->left;
        else if (itr->right != NULL && itr->right->data == v[i]) itr = itr->right;
        else return false;
    }

    return true;
}

int main() {
    vector<int> deliveryData = {5, 3, 7, 2, 4, 6, 8};
    vector<int> subtreeData1 = {5, 3, 4};
    vector<int> subtreeData2 = {7, 8};

    TreeNode* root = new TreeNode(5);
    root = insertNode(root, deliveryData[1]);
    root = insertNode(root, deliveryData[2]);
    root = insertNode(root, deliveryData[3]);
    root = insertNode(root, deliveryData[4]);
    root = insertNode(root, deliveryData[5]);
    root = insertNode(root, deliveryData[6]);

    TreeNode* start = findNode(root, subtreeData1[0]);  // Pass root instead of start

    cout << checkMainPath(start, subtreeData1) << " " << checkMainPath(start, subtreeData2);

    return 0;
}
