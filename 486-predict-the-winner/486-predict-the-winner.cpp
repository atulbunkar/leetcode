class Solution {
public:
    vector<int> nums;
    bool PredictTheWinner(vector<int>& num) {
        nums = num;
        int sum = accumulate(num.begin(),num.end(),0);
        
        return can(0,num.size()-1,1) >= (double)sum*1.0/2;    
    }
    
    int can(int i,int j, int p){
        
        if(i>j){
            return 0;
        }
        
        if(p){
            return max(can(i+1,j,1-p)+nums[i] , can(i,j-1,1-p)+nums[j]) ;
        }
        else{
            return min( can(i+1,j,1-p) , can(i,j-1,1-p) );
        }
        
    }
};