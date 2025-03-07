class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1; 
        ListNode* dummy = new ListNode(NULL);
        ListNode* temp = dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val < list2->val)
            {
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)temp->next=list1;
        if(list2)temp->next=list2;
        return dummy->next;
    }
};