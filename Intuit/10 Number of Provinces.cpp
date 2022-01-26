class Solution {
    void dfs(int u,vector<vector<int>>&graph,vector<bool>&vis)
    {
        vis[u] =  true;
        
        for(int v=0;v<vis.size();v++)
            if(v!=u && graph[u][v] && !vis[v])
                dfs(v,graph,vis);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int ans = 0 ;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;
    }
};
