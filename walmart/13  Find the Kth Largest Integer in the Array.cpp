string kthLargestNumber(vector<string>& nums, int k) {
        
        sort( nums.begin() , nums.end() ,[](string a,string b)
                {
                    if(a.size()==b.size())
                        return a<b;
                    return a.size() < b.size();
                }
            );
        
        // unique(nums.begin(),nums.end());
        int n = nums.size();
         
        for(int i=n-1,j=1;i>=0;i--,j++)
            if(k==j)
                return nums[i];
         
        return "-1";
    }
