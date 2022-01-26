class Solution {
    
    void dfs(int v, vector<int> g[],vector<bool>&visited,stack<int>&s)
    {
        visited[v] = true;
        
        for(auto it:g[v])
            if( !visited[it])
                dfs(it,g,visited,s);
           
        s.push(v);
    }
public:
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<vector<int>>graph(v);
        vector<int>indegree(v,0);
        
        for(auto v:pre){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count = 0;
        vector<int>sequence;
        
        while(!q.empty())
        {
            int currentCourse = q.front();q.pop();
            sequence.push_back(currentCourse);
            for(auto v:graph[currentCourse])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
            count++;
        }
        if(count!=v)return {};
        return sequence;
    }
};
