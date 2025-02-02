class Solution {
public:
    ListNode* merge(ListNode* temp1,ListNode* temp2)
    {
        if(temp1==NULL)return temp2;
        if(temp2==NULL)return temp1;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val < temp2->val)
            {
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
            else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1)temp->next=temp1;
        if(temp2)temp->next=temp2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        

        ListNode* temp = lists[0];
        for(int i=1;i<lists.size();i++)
        {
            temp = merge(temp,lists[i]);
        }
        return temp;
    }
};

// secodn way using pq

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.size()==0)return NULL;
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
        for(int i=0;i<arr.size();i++)
        {
            Node* temp=arr[i];
            pq.push({temp->data,temp});
        }
        Node* dummy = new Node(0);
        Node* temp=dummy;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if(it.second->next)
            {
                pq.push({it.second->next->data,it.second->next});
            }
            temp->next=it.second;
            temp=it.second;
            
        }
        return dummy->next;
    }
};