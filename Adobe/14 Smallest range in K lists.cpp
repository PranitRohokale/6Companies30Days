class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>> >minheap;
                        //val,row,col
        int maxvalue = INT_MIN;
        int minrange = INT_MAX;
        pair<int,int>ans;
        for(int i=0;i<k;i++){
            minheap.push({arr[i][0],i,0});
            maxvalue = max(maxvalue,arr[i][0]);
        }
        
        while(true)
        {
            vector<int> it = minheap.top();minheap.pop();
            int val = it[0] , i = it[1] , j = it[2];
            
            if(minrange>(maxvalue-val))
            {
                minrange = maxvalue-val;
                ans = {val,maxvalue};
            }
            if(j>=n)return ans;
            
            minheap.push({arr[i][j+1],i,j+1});
            maxvalue = max(maxvalue,arr[i][j+1]);
        }
        return ans;
    }
};
