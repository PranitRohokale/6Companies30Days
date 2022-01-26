class Solution {
    int requiredSplit(vector<int>& nums, int m)
    {
        int k = 1;
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
            if(sum>m)
            {
                sum = i ;
                k++;
            }
        }
        return k;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end()) ,
            high = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int k = requiredSplit(nums,mid);
            if(k<=m)
            {
                 ans = mid;
                high = mid-1;
            }else
                low = mid+1;
        }
        return ans;
    }
};
