
class Solution {
    int dirs[5] = {-1,0,1,0,-1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int n = grid.size(), m = grid[0].size();
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push( i*10+j );
            }
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int top = q.front();q.pop();
                int x = top/10 , y = top%10;
            
                
                
                for(int i=0;i<4;i++)
                {
                    int _x = x+dirs[i] , _y = y+dirs[i+1];
                    if(_x>=0 && _y>=0 && _x<n && _y<m && grid[_x][_y]==1){
                        q.push(_x*10+_y);
                        grid[_x][_y] = 2;
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans==-1 ? 0 : ans;
    }
};

