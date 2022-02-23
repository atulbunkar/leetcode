class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> higher(n),lower(n);
        
        map<int,int> mp;
        
        mp[arr[n-1]] = n-1;
        higher[n-1] = lower[n-1] = 1; 
        int ans=1 ;
        
        for(int i=n-2;i>=0;i--){
            auto hi = mp.lower_bound(arr[i]);  //return iter of next greater element
           
            auto lo = mp.upper_bound(arr[i]);  
             //gets next greater or equal, will --lo to get just lower element as mp is ordered, so prev of lo will be just lower element of arr[i]
       
            
            if(hi!=mp.end()){
                higher[i] = lower[hi->second];
              //  cout<< arr[i] << " " << hi->second<<endl ;
            }
            if(lo!= mp.begin()){
                
                lower[i] = higher[(--lo)->second];
            }
            if(higher[i])ans++;
            mp[arr[i]] = i;
            
            
        }
        return ans;
        
        
        
    }
};