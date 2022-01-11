
//Function to find if the given edge is a bridge in graph.
    void dfs(int u,int c,int d,int V,vector<int>adj[],vector<bool>&vis)
    {
        vis[u] = true;
        for(int v:adj[u])
            if(vis[v]==false)
                if((u==c && v==d))
                    continue;
                else
                    dfs(v,c,d,V,adj,vis);
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool>visited(V,false);
        dfs(c,c,d,V,adj,visited);

        return !(visited[d]);
    }
    /* we basically check for c to d is there anyu indirect edge or not*/

