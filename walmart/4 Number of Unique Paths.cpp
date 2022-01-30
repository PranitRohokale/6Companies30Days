class Solution
{
    int arr[16][16]={{}};
    // memset(arr,-1,sizeof(arr));
    int getWays(int x,int y,vector<vector<int>>&dp)
    {
        if(x==0 && y==0)
            return 1;
        
        int r = dp.size();    
        int c = dp[0].size();    
            
        int ans = 0;
        int X = x + 0,Y = y -1;
        if(X>=0 && Y>=0 && X<r && Y<c)
            ans += getWays(X,Y,dp);
            
        X = x -1 , Y = y + 0;    
        if(X>=0 && Y>=0 && X<r && Y<c)
            ans += getWays(X,Y,dp);
        return ans;
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        // vector<vector<int>>dp(a,vector<int>(b,0));
        // return getWays(a-1,b-1,dp);
        if(a==1 || b==1)return 1;
        if(arr[a][b]!=0)return arr[a][b];
        
        return arr[a][b] = NumberOfPath(a,b-1) + NumberOfPath(a-1,b);
    }
};
