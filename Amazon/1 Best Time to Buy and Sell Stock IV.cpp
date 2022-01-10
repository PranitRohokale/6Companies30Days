
//using recursion
class Solution {
    int helper(int currday,int currTransaction,int arr[])
    {
        if(currday<=0 || currTransaction==0)
            return 0;
        
        int maxProfitForCurrentDay = helper(currday-1,currTransaction,arr); // k tarnaction are already done on prev day
        
        //or making current transaction
        for(int startDay=0;startDay<currday;startDay++)
            {
                int profitForCurrentTransaction = (arr[currday] - arr[startDay]) 
                                                + helper(startDay-1,currTransaction-1,arr);
                
                maxProfitForCurrentDay = max(maxProfitForCurrentDay , profitForCurrentTransaction);
            }
        return maxProfitForCurrentDay;
    }
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        return helper(N-1,K,A);
    }
};
     

//using memoization

class Solution {
    vector<vector<int>>dp;
    int helper(int currday,int currTransaction,vector<int>&arr)
    {
        if(currday<=0 || currTransaction<=0)
            return 0;
        
        if(dp[currTransaction][currday]!=-1)
            return dp[currTransaction][currday];
        
        int maxProfitForCurrentDay = helper(currday-1,currTransaction,arr); // k tarnaction are already done on prev day
        
        //or making current transaction
        for(int startDay=0;startDay<currday;startDay++)
            {
                int profitForCurrentTransaction = (arr[currday] - arr[startDay]) 
                                                + helper(startDay-1,currTransaction-1,arr);
                
                maxProfitForCurrentDay = max(maxProfitForCurrentDay , profitForCurrentTransaction);
            }
        return dp[currTransaction][currday] = maxProfitForCurrentDay;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(k+1,vector<int>(n,-1));
        return helper(n-1,k,prices);
    }
};
