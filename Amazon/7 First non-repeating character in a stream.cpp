
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    queue<char>q;
		    vector<int>freq(26,0);
		    for(int i=0;i<A.size();i++)
		    {
		        freq[A[i]-'a']++;
		        q.push(A[i]);
		        while(q.size() && freq[q.front()-'a']>1)
		            q.pop();
		      
		        ans+= (q.size() ? q.front() : '#');
		    }
		    return ans;
		}

};

