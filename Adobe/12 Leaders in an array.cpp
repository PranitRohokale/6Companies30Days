class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        //using monotonically decreasing stack from end of array
        //by keeping max variable from end
        
        int leader = -1;
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=leader)
            {
                leader = a[i];
                ans.push_back(leader);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
