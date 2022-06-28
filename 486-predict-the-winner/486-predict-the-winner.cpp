class Solution {
public:
    int solve(vector<int>&nums,int i,int j,int t){
        
        if(i==j){
            return nums[i];
        }
        if(t){
            return max(nums[i]+solve(nums,i+1,j,!t),nums[j]+solve(nums,i,j-1,!t));
        }
        else{
            return  min(-1*nums[i]+solve(nums,i+1,j,!t),-1*nums[j]+solve(nums,i,j-1,!t));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n =nums.size();
        int x= solve(nums,0,n-1,1);
        //cout<<x<<" ";
        return x<0?0:1;
    }
};