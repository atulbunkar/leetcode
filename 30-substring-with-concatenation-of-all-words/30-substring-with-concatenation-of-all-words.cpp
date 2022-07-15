class Solution { // "in any order" is said so no kmp here
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans; 
        
        int hash = 0; 
        unordered_map<string,int> mp1,mp2;
        
        for(auto x:words){
            mp1[x]++; mp2[x]++;
            for(auto c:x)
                hash += (c-'a'+1);
        }
        
        int len =words[0].size();
        int n = s.size();  int cnt = words.size();
        
        int h =0,j=0; 
                    
        for(int i=0;i<n ; i++){
            
            h += s[i]-'a'+1 ;
            if(i<cnt*len-1){ continue;}
            
           
            if(h == hash){
               bool f = true; mp1 = mp2;
                
                for(int k=j; k<i; k+=len){
                    
                    string ss =s.substr(k,len); 
                    if(mp1[ss]>0){
                        mp1[ss]--;
                    }
                    else{
                        //cout<<ss<< endl;
                        f= false; break;
                    }
                }
                
                if(f)ans.push_back(j); 
            }
            
            h -= (s[j]-'a'+1);
            j++; 
            
        }
        
        return ans;
    }
};