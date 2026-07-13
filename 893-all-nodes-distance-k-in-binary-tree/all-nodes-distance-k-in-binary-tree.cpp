/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;

    void build(TreeNode* root)
    {
        if(root == NULL) return;

        if(root->left)
        {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            build(root->left);
        }

        if(root->right)
        {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            build(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        build(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while(!q.empty())
        {
            int sz = q.size();

            if(dist == k)
                break;

            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();

                for(auto neigh : graph[node])
                {
                    if(vis.find(neigh) == vis.end())
                    {
                        vis.insert(neigh);
                        q.push(neigh);
                    }
                }
            }

            dist++;
        }

        vector<int> ans;

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};