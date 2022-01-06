
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        
        Node *temp = head;
        while(temp)
        {
            int m = M , n = N;
            Node* prev = NULL;
            
            while(temp && m){
                prev = temp;
                temp = temp->next , m-=1;
            }
            while(temp && n)
                temp = temp->next,n-=1;
            if(prev)
                prev->next = temp;
        }
    }
};

