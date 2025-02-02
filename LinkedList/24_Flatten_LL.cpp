class Solution {
  public:
  
    Node* merge(Node* temp1,Node* temp2)
    {
        if(temp1==NULL)return temp2;
        if(temp2==NULL)return temp1;
        Node* dummy = new Node(0);
        Node* temp=dummy;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data < temp2->data)
            {
                temp->bottom = temp1;
                temp=temp1;
                temp1=temp1->bottom;
            }
            else
            {
                temp->bottom=temp2;
                temp=temp2;
                temp2=temp2->bottom;
            }
        }
        if(temp1)temp->bottom=temp1;
        if(temp2)temp->bottom=temp2;
        return dummy->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if (root == NULL || root->next == NULL) return root;
        Node* nextnode = flatten(root->next);
        return merge(root,nextnode);
        
    }
};