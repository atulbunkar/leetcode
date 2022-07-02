class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char , pair< int , int > > mp;
        int n = s.size();
        for(int i = 0; i < n ;i++){
            if(mp.find(s[i]) != mp.end())
            {
                int mini = mp[s[i]].first;
                int mazi = mp[s[i]].second;
                if(i<mini)
                    mp[s[i]]={i,mazi};
                if(i>mazi)
                    mp[s[i]] = {mp[s[i]].first,i};
            }
            else{
                mp[s[i]] ={i,i};
            }
        
        }
        vector<pair<int,int>>ranges; vector<bool> vstd(26,false);
        
        for(int i =0;i<n;i++)
        {
            
            auto x =mp.find(s[i]) ; if(vstd[s[i] -'a'])continue;
            
            vstd[s[i] -'a'] = true;
            
            //cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
            bool f =0;
            for(auto &y:ranges){
                if(y.first < x->second.first && y.second > x->second.second){
                    f=1;break;
                    continue;
                }
                else if(y.first > x->second.first && y.second < x->second.second){
                    y.first =x->second.first;
                    y.second = x->second.second;f=1;break;
                    continue;
                }
                else if(y.first < x->second.first && y.second < x->second.second && y.second > x->second.first){
                     y.second = x->second.second; f=1;
                     break;
                }
                else if(y.first > x->second.first && y.second > x->second.second && y.first < x->second.second){
                    y.first = x->second.first; f=1;
                    break;   
                }
               
            }
            if(f==0){
                ranges.push_back({x->second.first,x->second.second});
            }
        }
        vector<int>ans;
        for(auto &x:ranges){
            //cout<<x.first<<" "<<x.second<<endl;
           
            ans.push_back(x.second-x.first+1);
        }
       // sort(ans.begin(),ans.end());
        return ans;
    }
    
    
};