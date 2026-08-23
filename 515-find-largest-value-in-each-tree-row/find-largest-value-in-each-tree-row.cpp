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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>>ds;
                vector<int>res;
        if(root == NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int>ans;
            for(int i=0;i<s;i++)
            {
                TreeNode * node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                ans.push_back(node->val);
            }
            ds.push_back(ans);
        }
     
        for(int i=0;i<ds.size();i++)
        {
               int maxi = INT_MIN;
            for(int j=0;j<ds[i].size();j++)
            {
                maxi = max(maxi,ds[i][j]);
            }
            res.push_back(maxi);
        }
        return res;

    }
};