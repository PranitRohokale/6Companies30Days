class Solution {
    long mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>>arr;
        for(int i=0;i<n;i++)
            arr.push_back({efficiency[i],speed[i]});
        
        sort(arr.begin(),arr.end(),greater<vector<int>>());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        long performance = 0 , totalspeed = 0;
        for(int i=0;i<n;i++)
        {
            if(pq.size()<k)
            {
                totalspeed+=arr[i][1];
                pq.push(arr[i][1]);
            }else{
                totalspeed-=pq.top();pq.pop();
                totalspeed+=arr[i][1];
                pq.push(arr[i][1]);
            }
            long currperformance = (totalspeed * arr[i][0]);
            performance = max(performance,currperformance);
            // cout<<currperformance<<" "<<arr[i][0]<<endl;
        }
        return performance%mod;
    }
