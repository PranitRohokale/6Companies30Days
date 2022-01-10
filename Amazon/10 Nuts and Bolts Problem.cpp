
class Solution{
public:	
    //using hash map
    /*
        1.we hash all the nuts 
        2. then for every bolt we look into hashmap check where for current bolt is the any nut available
    */
    
    //using nesting loop O(n^2)
    // using quick sort technique O(nlogn)
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    unordered_map<char,int>map;
	    for(int i=0;i<n;i++)
	        map[nuts[i]]++;
	   
	   string order = "!#$%&*@^~";
	    for(int i=0,k=0;i<order.size() && k<n;i++)
	    {
	        while(map[order[i]])
	        {
	            nuts[k] = order[i];
	            bolts[k++] = order[i];
	            map[order[i]]--;
	        }
	    }
	}

};

