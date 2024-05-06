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
      
      // Create our iters
      ListNode* p0 = head;
      ListNode* p1 = head;
      ListNode* p2 = head->next;
      
      // Very very naive approach - essentially bubble sort the list
      while(p1 != nullptr && p1->next != nullptr)
      {
        //std::cout << "*****\nBeginning comparison with p1 value " << p1->val << "\n";
        p2 = p1;
        while(p2->next != nullptr)
        {
          p2 = p2->next;
          //std::cout << "\tp1 " << p1->val << "\tp2 " << p2->val << "\n";
          if(p2->val > p1->val)
          {
            //std::cout << "\t\tRemoving the node at p1\n";
            // Remove the current p1
            // Check if we are still at the head / front of the list
            if(p1 == head)
            {
              // Update the head and the p1 and p0 values
              head = head->next;
              //free(p1);
              p1 = head;
              p0 = head;
            }            
            else
            {
              // If we are not at the head / front of the list we want to remove the node at p1
              // We use the node p0 to do this, p0 points at the node p1->prev(if that existed)
              // Update p0 to skip the node at the current p1
              p0->next = p1->next;
              //free(p1)
              // Update p1 to be the node 1 after p0 again
              p1 = p0->next;
            }
            //std::cout << "*****\nBeginning comparison with p1 value " << p1->val << "\n";
            // Reset our loop now that we removed p1
            p2 = p1;
          }
        }
        p1 = p1->next;
        // Update the node we are storing that is 1 behind p1
        while(p0->next != p1)
        {
          p0 = p0->next;
        }
      }
      
      return head;
    }
	private:

};