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
class BSTIterator {
public:
vector<int>f;
int ptr = -1;
    void fun(TreeNode* root)
    {
        if(root == NULL) return;
        fun(root->left);
        f.push_back(root->val);
        fun(root->right);
    }
    BSTIterator(TreeNode* root) {
        fun(root);
    }
    
    int next() {
        ptr++;
        return f[ptr];
    }
    
    bool hasNext() {
        return ptr+1<f.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */