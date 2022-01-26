class Solution {
    int isPossibleToEatAllBanans(vector<int>&piles,int k)
    {
        int requiredTiem = 0;
        for(int pile:piles)
        {
            pile+=k-1;
            requiredTiem+=(pile/k);
        }
        return requiredTiem;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int ans = 0,low = 1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            int k = isPossibleToEatAllBanans(piles,mid);
            // cout<<mid<<" "<<k<<endl;
            // if(k==h)
            //     return mid;
            if(k<=h)
                ans = mid ,high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};
