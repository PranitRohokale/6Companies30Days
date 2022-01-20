class Solution
{
    vector<string>ans;
    void helper(int open ,int close,string temp,int n)
    {
        if(temp.size()==2*n)
        {
            ans.push_back(temp);
            return ;
        }
        if(open<n)
            helper(open+1,close,temp+"(",n);
        if(close<open)
            helper(open,close+1,temp+")",n);
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        helper(0,0,"",n);
        return ans;
    }
};

