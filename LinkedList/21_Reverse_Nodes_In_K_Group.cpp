class Solution {
public:
    ListNode* getkth(ListNode* head,int k)
    {
        while(head!=NULL && k>1)
        {
            k--;
            head=head->next;
        }
        return head;
    }
    void reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextnode=NULL;
        ListNode* prev=NULL;
        ListNode* kth = NULL;
        while(temp!=NULL)
        {
            kth = getkth(temp,k);
            if(kth!=NULL)
            {
                nextnode = kth->next;
                kth->next=NULL;
                reverse(temp);
                if(temp==head)
                {
                    head=kth;
                }

                
                else{

                    prev->next=kth;

                }
            }
            else
            {
                if(prev)prev->next=temp;
                break;
            }

            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};