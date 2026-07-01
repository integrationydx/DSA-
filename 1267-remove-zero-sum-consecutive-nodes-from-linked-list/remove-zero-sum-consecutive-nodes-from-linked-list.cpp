class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        vector<int> f;

        while (head) {
            f.push_back(head->val);
            head = head->next;
        }

        bool changed = true;

        while (changed) {

            changed = false;

            for (int i = 0; i < f.size(); i++) {

                int sum = 0;

                for (int j = i; j < f.size(); j++) {

                    sum += f[j];

                    if (sum == 0) {

                        f.erase(f.begin() + i, f.begin() + j + 1);

                        changed = true;
                        break;
                    }
                }

                if (changed)
                    break;
            }
        }

        if (f.empty())
            return nullptr;

        ListNode* newHead = new ListNode(f[0]);
        ListNode* ptr = newHead;

        for (int i = 1; i < f.size(); i++) {
            ptr->next = new ListNode(f[i]);
            ptr = ptr->next;
        }

        return newHead;
    }
};