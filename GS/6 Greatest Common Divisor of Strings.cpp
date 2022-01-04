
// https://leetcode.com/problems/greatest-common-divisor-of-strings/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        if(n<m){
            swap(str1,str2);
            swap(n,m);
        }
        
        if(m==0)return str1;
        if(str1.substr(0,m)!=str2) // string is not divisible
            return "";
        return gcdOfStrings(str1.substr(m),str2); //string is divisible so return the remender(i.e. module part in int)
    }
};

