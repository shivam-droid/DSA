class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp=head;
        Node* temp2 = temp->next;
        while(temp2!=NULL)
        {
            
            if(temp->data==temp2->data)
            {
                temp->next=temp2->next;
                if(temp2->next)temp2->next->prev=temp;
                delete(temp2);
                temp2=temp->next;
            }
            else
            {
                temp=temp->next;
                temp2=temp2->next;
            }
        }
        return head;
    }
};