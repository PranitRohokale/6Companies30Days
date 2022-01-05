
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n&1)return false;
        
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
            map[nums[i]%k]++;
        
        int pair=0;
        for(auto it:map)
        {
            int key = it.first , val = it.second;
            if(key==0)continue; 
            if(  val!=map[k-key])
                return false;
        }
        return true;
        
        //corner case
        // if arr[i] is divisible by k the remainder get zero so don'it need to compare map[k-zero] for that particular number
        
        // 4 2
        // 6 14 12 14
        
        //4 2
        //13 13 14 1
    }
};
