#define ll long long

class Solution{
    int _numOfWays(int n,int x,vector<int>&dp)
    {
        if(n<0)return 0;
        else if(n==0)return 1;
        int mod = 1e9+7;
        if(dp[n]!=-1)return dp[n];
        return  dp[n] = (ll)(_numOfWays(n-1,x,dp)%mod + _numOfWays(n-pow(n,x),x,dp)%mod)%mod;
    }
    public:
    int numOfWays(int n, int x)
    {
        // code here
        int sroot = pow(n,1.0/x);
        vector<int>dp(sroot+1,-1);
        return _numOfWays(sroot,x,dp);
    }
    //O(N^(1/x))
};
