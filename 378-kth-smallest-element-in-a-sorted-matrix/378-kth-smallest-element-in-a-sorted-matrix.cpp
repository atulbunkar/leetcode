class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int need) {
        int r = m.size() , c = m[0].size();
        long long low=INT_MIN, high=INT_MAX;
        
        
        while(low<=high){
            
            int mid = (low+high)/2;
            int prev=0;
           
            for(int i=0;i<r;i++){
               auto it = upper_bound(m[i].begin(),m[i].end(),mid); 
               prev += it - m[i].begin();
            }
           // cout<< low << " "  << high<< " "<< prev<< endl;
            if(prev>=need){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
    
        }
        return low;
            
        
        
        
    }
};