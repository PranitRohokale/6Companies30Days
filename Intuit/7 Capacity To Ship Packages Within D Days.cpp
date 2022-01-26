class Solution {
    int requiredDays(int capacity,vector<int>& wt)
    {
        int k=1,sum=0;
        for(int i:wt)   
        {
            sum+=i;
            if(sum>capacity)
                sum=i,k++;
        }
        return k;
    }
public:
    int shipWithinDays(vector<int>& wt, int days) {
        int capacity = *max_element(wt.begin(),wt.end());
        int total = accumulate(wt.begin(),wt.end(),0);
        
        for(;capacity<=total;capacity++)
        {
            int k = requiredDays(capacity,wt);
            if(k<=days)
                return capacity;
        }
        return -1;
    }
};
