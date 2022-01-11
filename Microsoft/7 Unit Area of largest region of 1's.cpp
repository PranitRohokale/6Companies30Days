class Solution
{
    
    public:
    //Function to find the number of islands.
    vector<vector<bool>>vis;
    int dx[8]={-1,0,1,0,-1,-1,1,1};
    int dy[8]={0,1,0,-1,-1,1,-1,1};
    bool isValid(int i,int j,vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || j <0 || i>=n || j>=m || vis[i][j] || grid[i][j]==0)
            return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,int &area)
    {
        vis[i][j] = true;
        area++;
        for(int x=0;x<8;x++)
        {
            int X = dx[x] + i;
            int Y = dy[x] + j;
            if(isValid(X,Y,grid))
                dfs(X,Y,grid,area);
        }
    }
    int findMaxArea(vector<vector<int>>& grid) 
    {
        // Code here
        vis.resize(grid.size(),vector<bool>(grid[0].size(),false));
        int area =0 ;
        int ans = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==0)
                    continue;
                else if(isValid(i,j,grid))
                {
                    area = 0;
                    dfs(i,j,grid,area);
                    ans = max(ans,area);
                }
        return ans;
    }
};

