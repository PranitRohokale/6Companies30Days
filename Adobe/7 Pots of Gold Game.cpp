class Solution {
    int ans = 0;
    vector<vector<int>>dp;
    int helper(int l,int h,vector<int>&arr)
    {
        if(l>h)return 0;
        else if(l==h)return arr[l];
        else if(abs(h-l)==1)return max(arr[l],arr[h]);
        
        if(dp[l][h]!=-1)return dp[l][h];
        
        int left = arr[l] + min(helper(l+2,h,arr),helper(l+1,h-1,arr)); 
        // opponent range (l+1,h)
        
        int right = arr[h] + min(helper(l+1,h-1,arr),helper(l,h-2,arr)); 
        // opponent range (l,h-1)
        
        return dp[l][h] = max(left,right);
    }
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    dp.resize(n,vector<int>(n,-1));
	    return helper(0,n-1,A);
    }
};

