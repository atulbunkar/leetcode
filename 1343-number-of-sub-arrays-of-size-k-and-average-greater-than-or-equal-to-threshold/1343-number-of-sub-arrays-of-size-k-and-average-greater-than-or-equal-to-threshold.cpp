class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        
        long sum =0; int n= arr.size(); 
        
        int j=0; int ans=0;
        
        for(int i=0; i< n;i++){
            
            if(i<k-1)sum+=arr[i];
            
            else{
                
                sum += arr[i];
                if((double)sum*1.0/k >= t)ans++;
                sum -= arr[j++];
                
            }
            
        }
        return ans;
        
    }
};