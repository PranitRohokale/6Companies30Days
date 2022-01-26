class Solution {
    int dir[5] = {1,0,-1,0,1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                    q.push({i,j});
        
        int dist = -1;
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
                auto it = q.front();q.pop();
                int i = it.first , j = it.second;
                
                for(int k=0;k<4;k++)
                {
                    int x = i + dir[k] , y = j + dir[k+1];
                    if(x<n && y<n && x>=0 && y>=0 && grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y] = 1;
                    }
                }
            }
            dist++;
        }
        return dist==0 ? -1 : dist;
    }
};
