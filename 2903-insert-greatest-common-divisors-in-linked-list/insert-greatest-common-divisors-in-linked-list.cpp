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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * temp = head;
        ListNode * ptr = head;
        ptr = ptr->next;
        vector<int>f;
       
        while(ptr!=NULL)
        {
             int x = max(temp->val,ptr->val);
        int gcd = 1;
          for(int i=1;i<=x;i++)
          {
            if(temp->val % i == 0 && ptr->val % i == 0)
            {
                gcd = i;
                
            }
           
          }
           f.push_back(gcd);
          ptr = ptr->next;
          temp = temp->next;
        }
        temp = head;
        vector<int>g;
        while(temp!=NULL)
        {
            g.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ans;

for(int i = 0; i < g.size() - 1; i++)
{
    ans.push_back(g[i]);   
    ans.push_back(f[i]);  
}

ans.push_back(g.back());   

        ListNode * newHead = new ListNode(ans[0]);
        ListNode * ptr2 = newHead;
        for(int i=1;i<ans.size();i++)
        {
           ptr2->next = new ListNode(ans[i]);
           ptr2 = ptr2->next;
        }
        return newHead;
        
    }
};