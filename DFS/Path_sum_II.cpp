#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

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


class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL)
            return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL && targetSum == 0)
            ans.push_back(path);

        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
};


vector<string> split(const string& str) {
    stringstream ss(str);
    string word;
    vector<string> result;
    while (ss >> word) result.push_back(word);
    return result;
}

void solve() {
    // cout << "Enter the binary tree in level order (use 'null' for no node):\n";
    string input;
    getline(cin, input);

    vector<string> nodes = split(input);

    TreeNode* root = buildTree(nodes);

    int targetSum;
    // cout << "Enter the target sum: ";
    cin >> targetSum;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    cout << "Paths that sum to " << targetSum << ":\n";
    cout<<"[";
    for (int i=0;i<result.size();i++) {
        cout<<"[";
        for (int j=0;j<result[i].size();j++ ){
            cout<<result[i][j];
            if(j!=result[i].size()-1)
            cout<<",";
        }
        
        cout<<"]";

        if(i!=result.size()-1)
        cout<<",";
    }
    cout<<"]";


    
}

int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();

    return 0;

}
