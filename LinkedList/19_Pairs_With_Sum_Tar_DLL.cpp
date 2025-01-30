class Solution
{
public:
    Node* findtail(Node* head)
    {
        Node* tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>> dp;
        if(head==NULL)return dp;
        
        Node* left=head;
        Node* right=findtail(head);
        while(left->data < right->data)
        {
            if((left->data+right->data)==target)
            {
                dp.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if((left->data+right->data)<target)
            {
                left=left->next;
            }
            else  right=right->prev;
        }
        return dp;
    }
};