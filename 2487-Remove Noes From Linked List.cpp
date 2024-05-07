// 2487 Remove nodes from linked list


//  Definition for singly-linked list.
struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leecode doesnt like my calls to free - makes sense
// My thinking was that we have a memory leak if we dont clear up the memory of removed nodes though
// Unsure how we are supposed to actually handle that in leetcodes enviornment

class Solution
{
	public:
		ListNode* removeNodes(ListNode* head)
    {
      head = reverseList(head);
      ListNode *p1 = head;
      ListNode *p2 = head->next;
      
      // Move through the list in reverse order
      while(p2 != nullptr)
      {
        std::cout << "P1: " << p1->val << "P2: " << p2->val << '\n';
        if(p2->val >= p1->val)
        {
          // delete all the nodes between p1 and p2
          p1->next = p2;
          p1 = p2;
        }

        // Check if we are at the end of the list and havent hit a new max
        // Corner case if they are matching values
        if(p2->next == nullptr)
        {
          if(p2->val != p1->val)
          {
            p1->next = nullptr;
            break;
          }
        }

        p2 = p2->next;
      }

      head = reverseList(head);

      return head;
    }
    
    
    
	private:
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