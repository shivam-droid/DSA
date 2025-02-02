class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* nextnode = temp->next;
            Node* newnode = new Node(temp->val);
            newnode->next=nextnode;
            temp->next=newnode;
            temp=nextnode;

        }
        temp=head;
        while(temp!=NULL)
        {
            Node* copy = temp->next;
            if(temp->random)
            copy->random = temp->random->next;
            else copy->random=NULL;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp!=NULL)
        {
            res->next=temp->next;
            res=res->next;
            temp->next=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};