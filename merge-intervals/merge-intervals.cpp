class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end()); int n = ints.size();
        
        vector<vector<int>> ret;
        vector<int> temp(2,0);
        bool flag = false;
        

        for(int i=0; i< n ;i++){
            
            temp[1] = ints[i][1];
            temp[0] = ints[i][0];
            
            while( i<n-1 and temp[1] >= ints[i+1][0]  ) 
            {
                //temp[0] = min(temp[0] , ints[i+1][0]); 
                
                temp[1] = max(temp[1], ints[i+1][1])  ;
                i++;
                flag = true;
 
            }
            
            if(flag){ ret.push_back(temp); }
 
            else { ret.push_back(ints[i]);  }

            flag = false;

        }
        
        return ret;
    }
};