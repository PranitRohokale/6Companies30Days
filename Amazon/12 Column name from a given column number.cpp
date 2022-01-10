
class Solution{
    char getColoum(int ch)
    {
        if(ch==0)
            return 'Z';
        return (char)('A'+ch-1);
    }
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        
        while(n)
        {
            ans+=getColoum((n)%26);
            n = n%26 ? n : n-1;
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
