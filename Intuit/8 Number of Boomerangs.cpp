class Solution {
    int getDist(vector<int>&p,vector<int>&q)
    {
        int dx = p[0]-q[0];
        int dy = p[1]-q[1];
        return (dx*dx+dy*dy);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        
        int count = 0 ;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>map;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                
                int dist = getDist(points[i],points[j]);
                map[dist]++;
            }
            for(auto &[k,v]:map)
                if(v>1)
                    count+=(v*(v-1));//pemutaion of all points if there are more than 2 points at same distance
            map.clear();
        }
        return count;        
    }
};
