class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int n = p.size();
        long long ans = 1; int j =0;
        
        for(int i=1;i<n;i++){
            
            if(p[i] != p[i-1]-1)j = i;
            
            ans += i-j+1;
            // this adds the new number to all prev sets. 
            // say [3,2,1]
            //currently i at idx 2 and j at idx 0
            //prev sets were : {3,2} , {2}.
            //so , we do 2-0+1 = 3 , i,e 3 new sets are got
            //which are {3,2,1} , {2,1} ; {1}
            //even if i==j , one element set is got.
        }
        
        return ans;
    }
};