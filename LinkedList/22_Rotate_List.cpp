class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int len=1;
        ListNode* tail = head;
        ListNode* temp=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
            len++;

        }
        if(k%len==0)return head;
        else
        {
            int i = k%len;
            i = len-i;
            tail->next=head;
            while(i>1)
            {
                i--;
                temp=temp->next;
            }
            head=temp->next;
            temp->next=NULL;
        }
        return head;
        
    }
};