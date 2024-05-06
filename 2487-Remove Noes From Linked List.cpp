// 2487 Remove nodes from linked list

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
 
// leecode doesnt like my calls to free - makes sense
// My thinking was that we have a memory leak if we dont clear up the memory of removed nodes though
// Unsure how we are supposed to actually handle that in leetcodes enviornment

class Solution
{
	public:
		ListNode* removeNodes(ListNode* head)
    {
      // Early exit if list is only 1 entry
      if(head->next == nullptr)
        return head;
      
      // Find the max value in the list
      ListNode *p1 = head;
      ListNode *p2 = head;
      int max = head->val;
      while(p1 != nullptr)
      {
        if(p1->val > max)
        {
          max = p1->val;
          p2 = p1;
        }
        p1 = p1->next;
      }
      
      // Remove all entries to the left of the max entry
      // Memory leaking here?
      /*
      p1 = head;
      while(p1 != p2)
      {
        ListNode *tmp = p1->next;
        free(p1);
        p1 = tmp;
      }
      head = p1;
      */
      head = p2;
      
      // Find the next max until we are done
      ListNode* p0 = head;
      p1 = head;
      while(p1 != nullptr)
      {
        ListNode* pMax = findNextMax(p1);
        std::cout << "Current value is " << p1->val << "\n";
        std::cout << "the next max value is " << pMax->val << "\n";
      
        if(pMax == p1)
        {
          // We are done?
          break;
        }
        else
        {
          p0->next = pMax;
          //free(p1);
          p1 = p0->next;
        }      
      }
      
      return head;
    }
    
    
    
	private:
    ListNode* findNextMax(ListNode* start)
    {
      ListNode* nextMax = start;
      ListNode* iter = start;
      while(iter != nullptr)
      {
        if(iter->val > nextMax->val)
        {
          nextMax = iter;
        }
        iter = iter->next;
      }
      
      return nextMax;
    }

};