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
    ListNode* doubleIt(ListNode* head)
    {
        head = reverseList(head);

        // Traverse backwards
        ListNode* p1 = head;
        int carry = 0;
        while(p1 != nullptr)
        {
          //std::cout << "val " << p1->val << " val * 2 " << p1->val*2 << "\n";
          int val = p1->val * 2;
          if(val >= 10)
          {
            //std::cout << "val > 10 adding to next node\n";
            p1->val = val % 10 + carry;
            if(p1->next == nullptr)
            {
                //std::cout << "There was no next node to add the carry value to, creating a new one\n";
                ListNode *newNode = new ListNode();
                p1->next = newNode;
            }
            //std::cout << "Adding a carry value of " << val / 10 << " to the next node\n";
            carry = val / 10;
          }
          else
          {
            p1->val = val + carry;
            carry = 0;
          }
          p1 = p1->next;
        }

        head = reverseList(head);
        return head;
    }

    ListNode* reverseList(ListNode *head)
    {
      ListNode *curr = head;
      ListNode *prev = nullptr;

      while(curr != nullptr)
      {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;        
      }

      return prev;
    }
};