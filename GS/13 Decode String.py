
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        stack = []
        currnum , currstr = 0 , ''
        
        for c in s:
            if c.isdigit():
                currnum = currnum*10 + int(c)
            elif c=='[':
                stack.append(currstr)
                stack.append(currnum)
                currstr,currnum = '',0
            elif c==']':
                num = stack.pop()
                prevstr = stack.pop()
                
                currstr = prevstr + currstr*num
            else:
                currstr+=c
        return currstr
        
