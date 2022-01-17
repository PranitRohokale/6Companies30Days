class Solution:

    def amendSentence(self, s):

        # code here
        ans = ""
        
        for ch in s:
            if ch.isupper():
                ans+=" " + ch.lower()
            else:
                ans+=ch
        return ans[1:]

