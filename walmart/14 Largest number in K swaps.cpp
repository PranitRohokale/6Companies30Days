class Solution
{
    string ans;
    void helper(string str,int k)
    {
        if(str>ans)
            ans = str;
        if(k==0)return;
        
        int n = str.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(str[j]>str[i])
                {
                    swap(str[i],str[j]);
                    helper(str,k-1);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n = str.size();
       ans = str;
       helper(str,k);
       return ans;
    }
};
