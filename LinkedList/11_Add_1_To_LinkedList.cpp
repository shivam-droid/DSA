
class Solution {
  public:
    Node* reverse(Node* head)
    {
        if(head->next==NULL)return head;
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* currnext = temp->next;
            temp->next=prev;
            prev = temp;
            temp=currnext;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        Node* temp = head;
        int carry=1;
        while(temp!=NULL)
        {
            temp->data=temp->data+carry;
            if(temp->data<10)
            {
                carry=0;
                break;
            }
            else
            {
                temp->data=0;
                carry=1;
            }
            temp=temp->next;
        }
        if(carry==1)
        {
            Node* newnode = new Node(carry);
            head=reverse(head);
            newnode->next=head;
            return newnode;
        }
        
        head = reverse(head);
        return head;
        
    }
};