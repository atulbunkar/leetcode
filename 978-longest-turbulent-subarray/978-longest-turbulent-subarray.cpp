class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() ==1)return 1;
        
        int t1 = 0 , t2=0, ans = INT_MIN;
        
        for(int i = 1 ; i < arr.size() ; i++){
            
            if( (i%2 and arr[i] > arr[i-1]) || (!(i%2) and arr[i] < arr[i-1]) ) 
                t1++;
            else
                t1 =0;
            
            ans = max(t1,ans);
            
        }
        
        for(int i = 1 ; i < arr.size() ; i++){
            
            
            if( (i%2 and arr[i] < arr[i-1]) || (!(i%2) and arr[i] > arr[i-1]) ) 
                t2++;
            else
                t2 =0;
        
            ans= max(t2,ans);
            
        }
        
        
        return ans+1;
    }
};