class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++)
        {
            int zeros = 0, j=n-1;
            while(j>0 && grid[i][j]==0)
                zeros++,j--;
            dp[i] = zeros;
        }
        int ans = 0;
        
        cout<<endl;
        for(int i=0;i<n-1;i++)
        {
            int requiredZeros = n-i-1;
            if(dp[i]>=requiredZeros)
                continue;
            int j = i+1;
            while(j<n && dp[j]<requiredZeros)
                j++;
            
            if(j==n)return -1;
            
            ans += j-i;
            while(j>i){
                dp[j] = dp[j-1];
                j--;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};
