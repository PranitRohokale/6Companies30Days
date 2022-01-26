class Solution {
    int dir[5] = {1,0,-1,0,1};
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&heights)
    {
        int n = heights.size() , m = heights[0].size();
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j])return;
        vis[i][j] = true;
        
        for(int k=0;k<4;k++)
        {
            int x = i + dir[k] , y = j + dir[k+1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && heights[i][j]<=heights[x][y])
            {
                dfs(x,y,vis,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false)),atlantic(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)//vertical
        {
            dfs(i,0,pacific,heights);
            dfs(i,m-1,atlantic,heights);
        }
        
        for(int i=0;i<m;i++)//horizontal
        {
            dfs(0,i,pacific,heights);
            dfs(n-1,i,atlantic,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
        return ans;
    }
};
