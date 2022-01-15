class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int>s; // monotonically decreasing stack
       int i=0;
       vector<int>ans(n,1);
       
       while(i<n)
       {
            while(!s.empty() && price[s.top()]<=price[i])
            {
              s.pop();
            }
            ans[i] = (s.empty() ? i+1 : i-s.top());
            s.push(i++);    
       }
        return ans;
    }
};

