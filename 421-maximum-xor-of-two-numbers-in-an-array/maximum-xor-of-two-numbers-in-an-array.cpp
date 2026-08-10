class Node {
public:
    Node* child[2];

    Node() {
        child[0] = NULL;
        child[1] = NULL;
    }
};

class Solution {
public:

    void insert(Node* root, int num)
    {
        Node* curr = root;

        for(int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(curr->child[bit] == NULL)
                curr->child[bit] = new Node();

            curr = curr->child[bit];
        }
    }

    int getMax(Node* root, int num)
    {
        Node* curr = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if(curr->child[opposite] != NULL)
            {
                ans = ans | (1 << i);
                curr = curr->child[opposite];
            }
            else
            {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums)
    {
        Node* root = new Node();

        for(int num : nums)
            insert(root, num);

        int maxi = 0;

        for(int num : nums)
            maxi = max(maxi, getMax(root, num));

        return maxi;
    }
};