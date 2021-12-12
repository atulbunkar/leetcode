class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1);
        
        steps[1] = 1;
        if(n==1)return 1;
        
        steps[2] = 2;
        
        for(int i = 3; i<= n; i++){
            steps[i] = steps[i-1] + steps[i-2];
            
        }
        
        return steps[n];
        
        
    }
};