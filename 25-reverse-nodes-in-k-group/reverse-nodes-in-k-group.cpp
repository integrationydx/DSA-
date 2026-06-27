/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>f;
        ListNode * temp = head;
        while(temp!=NULL)
        {
            f.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0; i + k <= f.size(); i += k)
{
    reverse(f.begin() + i, f.begin() + i + k);
}
        temp = head;
        int i = 0;
        while(temp!=NULL)
        {
           temp->val = f[i];
           i++;
            temp = temp->next;
        }
        return head;

    }
};