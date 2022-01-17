class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int sign = (str[0]=='-' ? -1 : 1);
        
        int i=0,ans=0;
        if(str[0]=='-')i++;
        
        for(;i<str.size();i++)
        {
            if(!isdigit(str[i]))return -1;
            
            ans = ans*10 + (str[i]-'0');
        }
        return ans*sign;
    }
};
