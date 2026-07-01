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
    ListNode* mergeNodes(ListNode* head) {
         ListNode* temp = head;
ListNode* ptr = head->next;

vector<int> f;

while (ptr != nullptr)
{
    if (ptr->val == 0)
    {
        int sum = 0;

        ListNode* curr = temp->next;

        while (curr != ptr)
        {
            sum += curr->val;
            curr = curr->next;
        }

        f.push_back(sum);

        temp = ptr;
    }

    ptr = ptr->next;
}

ListNode* newHead = new ListNode(f[0]);
        ptr = newHead;

        for (int i = 1; i < f.size(); i++) {
            ptr->next = new ListNode(f[i]);
            ptr = ptr->next;
        }

        return newHead;
      

    }
};