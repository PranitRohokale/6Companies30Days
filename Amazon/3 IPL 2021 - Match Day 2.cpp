class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq; //monotonically decreasing deque
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            while(dq.size() && arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);
            while(dq.size() && arr[dq.back()]<=arr[i])
                dq.pop_back();
                
            dq.push_back(i);
            if(dq.front()==i-k)
                dq.pop_front();
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};
