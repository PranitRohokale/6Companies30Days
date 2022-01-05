
// https://leetcode.com/problems/minimum-size-subarray-sum/solution/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX , sum = 0;
        int start = 0,end = 0, n = nums.size();
        
        while(end<n)
        {
            sum+=nums[end];
            while(sum>=target){
                ans = min(ans,end-start+1);
                sum-=nums[start++];
            }
            end++;
        }
        return (ans==INT_MAX ? 0 : ans);
    }
};

