#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        if(nums.size()<=3)
            return ans;
        
        
        for(int i=0;i<nums.size();i++)
        {
            //for removing the duplicate of num1
            if(i>0 && nums[i]==nums[i-1])continue;
            
            for(int p=i+1;p<nums.size();p++)
            {
                //imp condition to avoid 
                if(p>(i+1) && nums[p]==nums[p-1])continue;
                
                int j=p+1,k=nums.size()-1;
            
                while(j<k)
                {
                    long long int sum= (ll)( (ll)nums[i] + (ll)nums[p] + (ll)nums[j] +(ll)nums[k] );
                    if(sum==target)
                    {
                        vector<int>v = {nums[i],nums[p],nums[j],nums[k]};
                        ans.push_back(v);
                        //removing duplicates of num2
                        while(j<k && nums[j]==v[2])j++;
                        //removing duplicates of num3
                        while(j<k && nums[k]==v[3])k--;
                    }else if(sum<target)
                        j++;
                    else
                        k--;
                }
            }
        }

        return ans;
    }
};
