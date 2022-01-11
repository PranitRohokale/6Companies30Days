class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // if Perfect BT is Given the it is possble to solve in O(n)&O(1) time
       queue<Node*>q;
       q.push(root);
       
       while(int sz = q.size())
       {
           Node *prev=NULL;
            while(sz--)
            {
               Node *level = q.front();q.pop();
               level->nextRight = prev;
               
               if(level->right) q.push(level->right);
               if(level->left) q.push(level->left);
                
                prev= level;
            }
       }
    }    
      
};
