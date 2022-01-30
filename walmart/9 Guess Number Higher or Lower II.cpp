class Solution {
    vector<vector<int>>dp;
    int getMoneyAmountUtil(int lr,int hr)
    {
        if(lr > hr)//outoff range
            return 0;
        else if( lr==hr )//only one element in range do this is answer but won't gave penulty
            return 0;
        else if(dp[lr][hr]!=-1)
            return dp[lr][hr];
        
        int answer = INT_MAX;
        for(int root=lr;root<=hr;root++)
        {
            int lower = getMoneyAmountUtil(lr,root-1);
            int higher = getMoneyAmountUtil(root+1,hr);
        
            answer = min( answer , max(lower,higher) + root  );
        }
        return dp[lr][hr] = answer;
    }
public:
    int getMoneyAmount(int n) {
        
        dp.resize(n+1,vector<int>(n+1,-1));
        return getMoneyAmountUtil(1,n);
    }
};
