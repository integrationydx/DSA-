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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * temp = list2;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        int count = 1;
        ListNode * ptr1 = list1;
        while(count<a)
        {
            ptr1= ptr1->next;
            count++;
        }
        ListNode * ptr2 = list1;
        int count_2 = 1;
        while(count_2<b+2)
        {
           ptr2= ptr2->next;
           count_2++;
        }
        ptr1->next = list2;
        temp->next = ptr2;
        return list1;
    }
};