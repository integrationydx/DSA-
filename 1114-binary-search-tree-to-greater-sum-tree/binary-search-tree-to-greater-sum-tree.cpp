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
vector<int>temp;
vector<int>f;

void fun(TreeNode * root)
{
    if(root == NULL)return;
    fun(root->left);
    f.push_back(root->val);
    fun(root->right);
}
    TreeNode* bstToGst(TreeNode* root) {
        fun(root);
        int sum = 0;
        for(int i = f.size()-1;i>=0;i--)
        {
            sum+= f[i];
            f[i] = sum;
        }
        int index = 0;
        function<void(TreeNode*)> update = [&](TreeNode* node)
        {
            if(node == NULL)
                return;

            update(node->left);

            node->val = f[index++];

            update(node->right);
        };

        update(root);

        return root;
        


    }
};