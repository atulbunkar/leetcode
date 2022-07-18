class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end()); int n = ints.size();
         vector<vector<int>> ret;
        
   
           
        for(int i=0;i<ints.size();){
            int st = ints[i][0]; int end = ints[i][1];
            int j=i+1;  int newend = end;
            while(j<ints.size() and ints[j][0] <= newend){ newend = max(newend,ints[j][1]); j++;}

            ret.push_back({st,newend});
            i=j;

        }
           
        
     
        return ret;
    }
};