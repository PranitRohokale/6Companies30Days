class Solution{
public:
    int minSteps(int D , int currpos = 0 , int step = 0){
        // code here
        if(abs(currpos)>abs(currpos))
            return INT_MAX;
        
        if(currpos == D)
            return step;
        
        int nextStep = step+1;
        
        int prev = minSteps(D,currpos+nextStep,nextStep);
        int next = minSteps(D,currpos-nextStep,nextStep);
        
        return min(prev,next);
    }
};
