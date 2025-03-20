#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int n = traversal.size(), idx = 0;

        while (idx < n) {
            int depth = 0;
            while (idx < n && traversal[idx] == '-') {
                depth++;
                idx++;
            }

            int val = 0;
            while (idx < n && isdigit(traversal[idx])) {
                val = val * 10 + (traversal[idx] - '0');
                idx++;
            }

            TreeNode* node = new TreeNode(val);

            while (st.size() > depth) 
                st.pop();

            if (!st.empty()) {
                if (st.top()->left == nullptr)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }

            st.push(node);
        }

        while (st.size() > 1)
            st.pop();

        return st.top();
    }
};

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    string input;
    cout << "Enter the preorder traversal string: ";
    cin >> input; 

    Solution solution;
    TreeNode* root = solution.recoverFromPreorder(input);

    cout << "Level Order Traversal of Reconstructed Tree: ";
    printLevelOrder(root);
    cout << endl;

    return 0;
}
