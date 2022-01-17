class Solution:
    
    #Complete this function
    
    #Function to return the name of candidate that received maximum votes.
    def winner(self,arr,n):
        # Your code here
        # return the name of the winning candidate and the votes he recieved
        hashmap = {}
        winner,vote = "",0
        for name in arr:
            hashmap[name] = hashmap.get(name,0) + 1
            
            if hashmap.get(name)>vote:
                vote = hashmap[name]
                winner = name
            elif hashmap.get(name)==vote and name < winner:
                winner = name
        
        return winner,vote
