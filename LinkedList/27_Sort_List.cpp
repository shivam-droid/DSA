class Solution {
public:
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* temp1,ListNode* temp2)
    {
        if(temp1==NULL)return temp2;
        if(temp2==NULL)return temp2;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val < temp2->val)
            {
                temp->next=temp1;
                temp=temp1;
                temp1=temp->next;
            }
            else
            {
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }

        }
        if(temp1)temp->next=temp1;
        if(temp2)temp->next=temp2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* middle = findmiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next=NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};