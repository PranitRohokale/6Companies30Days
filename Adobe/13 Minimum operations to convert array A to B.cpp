class Solution {
    
    int lcs(int i,int j,int a[],int b[],vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
            
        if(a[i]==b[j])
            return  dp[i][j] = lcs(i-1,j-1,a,b,dp) + 1;
            
        return dp[i][j] = max(lcs(i-1,j,a,b,dp) , lcs(i,j-1,a,b,dp));
    }
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        int operations = 0;
        vector<vector<int>>dp(N,vector<int>(M,-1));
        
        int lcs_lenght = lcs(N-1,M-1,A,B,dp);
        
        if(N>lcs_lenght)//deletion
            operations = N-lcs_lenght;
        if(M>lcs_lenght)//insertion
            operations += M-lcs_lenght;
            
        return operations;
    }
};

