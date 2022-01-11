vector<string> generate(int N)
{
	// Your code here
	vector<string>v;
	queue<string>q;
	if(N<1)
	    return v;
	q.push("1");
	string p;
	while(N--)
	{
	    p=q.front();q.pop();
	    v.push_back(p);
	    q.push(p+"0");
	    q.push(p+"1");
	}
	while(!q.empty())
	    q.pop();
	    
	  return v;

}
