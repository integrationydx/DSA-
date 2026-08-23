class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;

        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int s = q.size();
            long long sum = 0;

            for(int i = 0; i < s; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }

            res.push_back(sum);
        }

        sort(res.begin(), res.end());

        int n = res.size();

        if(k > n)
            return -1;

        return res[n - k];
    }
};