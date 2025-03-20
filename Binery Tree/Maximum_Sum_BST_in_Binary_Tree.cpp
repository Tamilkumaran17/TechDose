#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct Node {
    int minn, maxx, sum;
    Node(int minn, int maxx, int sum) {
        this->minn = minn;
        this->maxx = maxx;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxSum = 0;

    
    Node longest(TreeNode* root) {
        if (root == nullptr)
            return Node(INT_MAX, INT_MIN, 0); 

        auto left = longest(root->left);
        auto right = longest(root->right);

       
        if (left.maxx < root->val && root->val < right.minn) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum); 
            return Node(
                min(root->val, left.minn),
                max(root->val, right.maxx),
                currSum
            );
        }

        
        return Node(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

    int maxSumBST(TreeNode* root) {
        longest(root);
        return maxSum;
    }
};


TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

       
        if (values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter node values (use -1 for NULL): ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    TreeNode* root = buildTree(values);
    Solution solution;
    int result = solution.maxSumBST(root);

    cout << "Maximum Sum of Largest BST Subtree: " << result << endl;
    return 0;
}
