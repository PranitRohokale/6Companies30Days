class Solution
{
    //memoization
    long long possibleWays(int len,int k,vector<vector<long long>>&dp)
    {
        if(len==0)return 1;
        long long mod = 1e9+7;
        
        if(dp[len][k]!=-1)return dp[len][k];
        
        long long ways = (possibleWays(len-1,k,dp)*21)%mod; //21 consonants for curr position
        
        if(k>0)
            ways = (long long)(ways + possibleWays(len-1,k-1,dp)*5%mod)%mod; //
        
        
        return dp[len][k] = ways;
    }
  public:
    int kvowelwords(int N, int k) {
        // Write Your Code here
        long long mod = 1e9+7;
        vector<vector<long long>>dp(N+1,vector<long long>(k+1,-1));
        // return (int)possibleWays(N,k,dp);
        
        //bottom-up - tabular way
        for(int len=0;len<=N;len++)
        {
            for(int j=0;j<=k;j++)
            {
                if(len==0)
                    dp[len][j] = 1;
                else{
                    dp[len][j] = dp[len-1][j]*21%mod;
                    if(j>0)
                        dp[len][j] = (dp[len][j] + dp[len-1][j-1]*5%mod)%mod;
                }
            }
        }
        return dp[N][k];
    }
};
