
/*https://practice.geeksforgeeks.org/problems/run-length-encoding/1/ */

string encode(string src)
{     
  //Your code here 
  int count=1,n=src.size(),i=1;
  string ans = "";
  
      while(i<n)
      {
            if(src[i]==src[i-1])
                count++;
            else{
                ans+=src[i-1] + to_string(count);
                count=1;
            }
        i++;
      }
    ans+=src[i-1] + to_string(count);

    return ans;
}     

