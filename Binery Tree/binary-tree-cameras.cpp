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
    int ans = 0;
    
    int dfs(TreeNode* node) {
        if (!node) return 2; 
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if (left == 0 || right == 0) {
            ans++;
            return 1; 
        }
        
        if (left == 1 || right == 1) return 2;
        
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) ans++; 
        return ans;
    }
};

TreeNode* buildTree(vector<string> nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "Empty tree\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << "\n";
    }
}

int main() {
    string input;
    cout << "Enter tree nodes in level-order (use 'null' for empty nodes):\n";
    getline(cin, input);
    
    vector<string> nodes;
    stringstream ss(input);
    string token;
    while (ss >> token) {
        nodes.push_back(token);
    }

    TreeNode* root = buildTree(nodes);
    
    cout << "Tree in level-order:\n";
    printTree(root);
    
    Solution sol;
    int cameras = sol.minCameraCover(root);
    cout << "Minimum cameras needed: " << cameras << endl;

    return 0;
}
