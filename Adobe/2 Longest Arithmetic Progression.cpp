class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(10001,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d = arr[j]-arr[i];
                
                dp[j][d] = max(dp[i][d]+1,2);
                
                ans = max(ans,dp[j][d]);
            }
        }
        return ans;
    }
};
