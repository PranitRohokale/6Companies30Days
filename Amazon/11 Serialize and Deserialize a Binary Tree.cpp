
class Solution
{

    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(!root)return {0};
        vector<int>ans = {root->data};
        
        vector<int>v = serialize(root->left);
        ans.insert(ans.end(),v.begin(),v.end());
        
        v = serialize(root->right);
        ans.insert(ans.end(),v.begin(),v.end());
        
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
    
        int i=0;
       return deSerializeUtil(A,i);
       
    }
    private:
    Node* deSerializeUtil(vector<int>&a,int &i)
    {
        int n = a.size();
        if(i>=n)
                return NULL;
        if(a[i]==0)
        {
            i++;
            return NULL;
        }
        int num = 0;
        num = a[i++];
        // i++;
        Node* temp = new Node(num);
        temp->left = deSerializeUtil(a,i);
        temp->right = deSerializeUtil(a,i);
    }

};

