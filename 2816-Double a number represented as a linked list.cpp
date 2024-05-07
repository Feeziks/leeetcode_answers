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
    ListNode* doubleIt(ListNode* head) {
        double val = 0;
        ListNode *p1 = head;
        while(p1 != nullptr)
        {
            val *= 10;
            val += p1->val;
            p1 = p1->next;
        }

        std::cout << "val " << val << "  val * 2 " << val * 2 << "\n";
        val *= 2;

        std::string s = std::to_string(val);

        p1 = head;
        size_t i = 0;
        size_t len = s.length();
        int x = 0;
        for(i; i < len; i++)
        {
            p1->val = s[x++] - '0';
            if(p1->next == nullptr)
            {
              ListNode *newNode = new ListNode();
              p1->next = newNode;
            }
        }
        
        return head;
    }
};