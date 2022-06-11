class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        vector<pair<int,int>> v;
        
        sort(p.begin(),p.end());
        
        int ans =  p.size() , n = p.size();
        int s,e , curr_s,curr_e; bool got;
        
        v.push_back(make_pair(p[0][0],p[0][1]));
        
        for(int i=1; i< n; i++){
            curr_s = p[i][0] ; curr_e = p[i][1];
            got = false;
         
            pair<int,int> x= v.back(); 
      
            s = x.first; e = x.second;
       
            if(curr_s==s || curr_e <= e || curr_s<= e){
                ans--; got = true;
                s = max(curr_s,s);
                e = min(curr_e,e);
                v.pop_back();
                v.push_back(make_pair(s,e));
            }
      
            if(!got)v.push_back(make_pair(curr_s,curr_e));
        }
        return ans;
    }
};