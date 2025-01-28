class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                fast=fast->next;
                int cnt=1;
                while(fast!=slow)
                {
                    fast=fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};