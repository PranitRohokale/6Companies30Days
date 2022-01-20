class Solution{
    vector<vector<bool>>dp;
    bool isSumPosible(int n,int sum,int arr[])
    {
        if(sum==0)return true;
        else if(n<0)return false;
        
        if(dp[n][sum])return 1;
        
        if(arr[n]>sum)
            return dp[n][sum]=isSumPosible(n-1,sum,arr);
            
        return dp[n][sum] = isSumPosible(n-1,sum,arr) || isSumPosible(n-1,sum-arr[n],arr);
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int total = accumulate(arr,arr+N,0);
        if(total&1)
            return false;
        
        total/=2;
        dp.resize(N,vector<bool>(total+1,false));
        return isSumPosible(N-1,total,arr);
    }
};

