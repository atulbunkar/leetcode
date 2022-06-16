class Solution {
public:
    bool found = false;
    bool canPartition(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int sum =0;
        for(auto x:arr)sum += x;
         if(sum%2)return false;
        sum /= 2;
        

        vector<vector<int>> mem(arr.size(), vector<int>(sum+1,0));
        
        return dfs(0,arr,sum,mem); 
    }

    
    bool dfs(int i,vector<int>arr, int sum, vector<vector<int>>& mem ){
        
        if(i>=arr.size())return false;
        if(found)return true;
        
        if(sum==0){
            found = true;
            return true;
        }
        
        if(mem[i][sum]){
            return mem[i][sum] == 1? true:false ;
        }
        
        if(arr[i] > sum){
            return false;
        }
            
        else{
            bool x = dfs(i+1 ,arr,sum-arr[i],mem) || dfs(i+1,arr,sum,mem);
            if(x)mem[i][sum] = 1;
            else mem[i][sum] = 2;
            return x;
        }
    }
        
    
};