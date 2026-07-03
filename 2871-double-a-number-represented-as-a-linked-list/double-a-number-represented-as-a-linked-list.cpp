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
    int solve(ListNode* head)
    {
        if(head == NULL)
            return 0;

        int carry = solve(head->next);

        int val = head->val * 2 + carry;

        head->val = val % 10;

        return val / 10;
    }

    ListNode* doubleIt(ListNode* head) {

        int carry = solve(head);

        if(carry)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};