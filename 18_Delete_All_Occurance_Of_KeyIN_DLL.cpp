class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // Write your code here
        Node* temp=*head;
        Node* prevnode=NULL;
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                if(temp==*head)
                {
                    *head=temp->next;
                }
                else
                {
                    Node* newnode = temp->next;
                    prevnode = temp->prev;
                    if(newnode)newnode->prev=prevnode;
                    if(prevnode)prevnode->next=newnode;
                    delete(temp);
                    temp=newnode;
                }
            }
            else
            {
                temp=temp->next;
            }
        }
    }
};