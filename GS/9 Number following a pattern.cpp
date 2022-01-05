
class Solution{ 

public:
    string printMinNumberForPattern(string S){
        // code here 
        int n =S.size(),i=0;
        S+=S[n-1];
        int maxCount = 1;
        string ans = "";
        stack<int>st;
        
        while(i<=n)
        {
            if(S[i]=='D')
                st.push(maxCount++);
            else{
                st.push(maxCount++);
                while(st.size()){
                    ans = ans + (char)('0'+st.top());
                    st.pop();
                }
            }
            i++;
        }
        
        while(st.size()){
            ans = ans + (char)('0'+st.top());
            st.pop();
        }

        return ans;
    }
};

