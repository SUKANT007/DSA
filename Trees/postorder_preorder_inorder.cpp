#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* constructBinaryTreeFromArray(vector<string> values) {
    if (values.empty() || values[0] == "null") {
        return nullptr;
    }

    queue<TreeNode*> nodeQueue;
    TreeNode* root = new TreeNode(stoi(values[0]));
    nodeQueue.push(root);

    int i = 1;

    while (!nodeQueue.empty() && i < values.size()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        // left child
        if (i < values.size() && values[i] != "null") {
            current->left = new TreeNode(stoi(values[i]));
            nodeQueue.push(current->left);
        }

        i++;

        // right child
        if (i < values.size() && values[i] != "null") {
            current->right = new TreeNode(stoi(values[i]));
            nodeQueue.push(current->right);
        }

        i++;
    }

    return root;
}


void preInPostTraversal(TreeNode* root) {
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*, int>> s;

    if (root == NULL) {
        cout << "Empty Tree" << endl;

        return;
    }

    s.push({ root,1 });

    while (!s.empty()) {
        auto& [cur, type] = s.top();
        s.pop();

        if (type == 1) {
            preorder.push_back(cur->val);
            s.push({ cur,2 });

            if (cur->left != nullptr) {
                s.push({ cur->left,1 });
            }
        }
        else if (type == 2) {
            inorder.push_back(cur->val);
            s.push({ cur,3 });

            if (cur->right != nullptr) {
                s.push({ cur->right,1 });
            }
        }
        else {
            postorder.push_back(cur->val);
        }
    }

    cout << "preorder traversal: ";
    for (auto num : preorder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "postorder traversal: ";
    for (auto num : postorder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "inorder traversal: ";
    for (auto num : inorder) {
        cout << num << " ";
    }
    cout << endl;

}

int main() {
    int numberOfNodes;
    cout << "Enter number of nodes: ";
    cin >> numberOfNodes;

    vector<string> values(numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++) {
        cin >> values[i];
    }

    TreeNode* root = constructBinaryTreeFromArray(values);

    preInPostTraversal(root);

    return 0;
}