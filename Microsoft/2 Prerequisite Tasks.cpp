class Solution {
    
public:
    //USING BFS:KHAN ALGORITHM
// 	bool isPossible(int n, vector<pair<int, int> >& pre) {
// 	    // Code here
// 	    vector<int>g[n];
// 	    vector<int>vis(n,0);
	    
// 	    for(auto task:pre)
// 	    {
// 	        g[ task.second ].push_back(task.first);
// 	        vis[task.first]++;
// 	    }
	    
// 	    queue<int>q;
//     	    for(int i=0;i<n;i++)
//     	        if(vis[i]==0)
//     	            q.push(i);
	            
//     	   int taskCompleted = 0;
//     	   while(!q.empty())
//     	   {
//     	       int u  = q.front();q.pop();
//     	       taskCompleted++;
    	       
//     	       //reducing the indegee of all dependant tasks
//     	       for(auto v:g[u])
//     	           if(--vis[v] == 0)
//     	                q.push(v);
//     	   }
// 	    return taskCompleted==n;
// 	}

    //  USING DFS: Finding cycle in directed graph
    bool isCycle(int u,vector<int>g[],vector<bool>&vis,vector<bool>onpath)
    {
        vis[u] = true;
        onpath[u] = true;
        
        for(int v:g[u])
            if(onpath[v] || (vis[v]==false && isCycle(v,g,vis,onpath)))
                return true;
        
        onpath[u] = false;
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>g[n];

	    for(auto task:pre)
	    {
	        g[ task.second ].push_back(task.first);
	    }
	    
	    vector<bool>vis(n,false),onpath(n,false);
	    
	    for(int i=0;i<n;i++)
	        if(vis[i]==false && isCycle(i,g,vis,onpath))
	            return false;
	            
        return true;
	}
};
