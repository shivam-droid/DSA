class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) 
    {
        if (head == nullptr || head->next == nullptr) {
            return;  // No loop if the list is empty or has only one node
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

    // Detect cycle using Floyd’s Cycle-Finding Algorithm (Tortoise and Hare)
        while (fast != nullptr && fast->next != nullptr)
        {
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
    
            if (slow == fast) {
                if(fast==head)
                {
                    prev->next=NULL;
                    return;
                }// Cycle detected
                slow = head; // Move slow pointer to head
    
                // Find the node just before the start of the loop
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
    
                // Remove the loop: set fast->next to nullptr
                fast->next = nullptr; // Break the cycle by setting fast->next to NULL
                return;  // Once the loop is removed, exit immediately
            }
        }
    }
};