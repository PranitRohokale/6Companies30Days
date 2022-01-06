
class Solution {
public:
    int longestMountain(vector<int>& security) {
        int n = security.size();
        if(n<3)
            return 0;
        
        vector<int>before(n,0),after(n,0);
        int ans=0;

        for(int i=1;i<n;i++)
            before[i] = security[i-1]<security[i] ? before[i-1]+1 : 0;

        for(int i=n-2;i>=0;i--)
            after[i] = security[i]>security[i+1] ? after[i+1]+1 : 0;
        
        for(int i=1;i<n-1;i++)
            if(before[i] && after[i] && before[i]+after[i]>ans)
                ans = before[i]+after[i];
        
//         for(int i:before)
//             cout<<i<<" ";
//         cout<<"\n";
//         for(int i:after)
//             cout<<i<<" ";
        
        return ans+1>=3 ? ans+1 : 0;
    
    }
};
