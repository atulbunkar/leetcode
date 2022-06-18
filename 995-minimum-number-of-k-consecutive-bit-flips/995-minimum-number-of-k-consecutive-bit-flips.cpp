class Solution {
public:
    int ans =0; bool np= false;
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(); int ans=0;
        queue<int> q; 
        
        for(int i=0;i <n ;i++){
            
            if(q.empty() and nums[i]==0){
                q.push(i+k-1); ans++;
            }
         
            else{
                if(nums[i]==1 and q.size()%2 == 1){ //i has been flipped to 0 virtually
                    ans++ ; q.push(i+k-1);
                }
                else if(nums[i]==0 and q.size()%2 == 0){ //i has not been flipped
                    ans++; q.push(i+k-1);
                }
            }
             if(!q.empty() and  i >= q.front())q.pop();
            
            
           
        }
        
        if(!q.empty())return -1;
        else return ans;
    }
};