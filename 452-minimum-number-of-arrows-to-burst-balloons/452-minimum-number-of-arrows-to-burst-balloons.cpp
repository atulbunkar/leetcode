class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        vector<pair<int,int>> v;
        
        sort(p.begin(),p.end());
        
        int ans =  p.size() , n = p.size();
        int s,e , curr_s,curr_e; bool got;
        
        for(int i=0; i< n; i++){
            curr_s = p[i][0] ; curr_e = p[i][1];
            //cout<<endl;
            got = false;
            
            for(auto& x:v){
                s = x.first; e = x.second;
                //cout<< curr_s << " " << curr_e << " ";
                //cout<< s << " " << e<< endl;
                
                if(curr_s==s || curr_e <= e || curr_s<= e){
                    ans--; got = true;
                    x.first = max(curr_s,s);
                    x.second = min(curr_e,e);
                    break;
                }
            }
            if(!got)v.push_back(make_pair(curr_s,curr_e));
        }
        return ans;
    }
};