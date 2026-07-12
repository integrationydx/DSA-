/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void fun(TreeNode * root,int row, int col,vector<pair<pair<int,int>,int>> &nodes)
{
    if(root == NULL) return;
 
nodes.push_back({{col,row}, root->val});

fun(root->left,row+1,col-1,nodes);
fun(root->right,row+1,col+1,nodes);
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
       vector<pair<pair<int,int>, int>> nodes;
        fun(root,0,0,nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;

int prevCol = INT_MIN;

for (auto &it : nodes)
{
    int col = it.first.first;
    int val = it.second;

    if (col != prevCol)
    {
        ans.push_back({});
        prevCol = col;
    }

    ans.back().push_back(val);
}

return ans;
      
    }
};