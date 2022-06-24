class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
       int n=str1.size(), m=str2.size();
        if(n!=m)return false;
        unordered_map<char,char> mp;
        unordered_set<char> done;
        
        for(int i=0;i<n;i++){
            
            if( done.find(str2[i]) != done.end() and mp.find(str1[i]) ==mp.end())return false;
 
            if( done.find(str2[i]) == done.end()  and mp.find(str1[i]) ==mp.end()){
                mp[str1[i]] = str2[i];
                done.insert(str2[i]);  
            }
            
            else if(mp[str1[i]] != str2[i])return false;
         
        }
        
        //for(auto x:mp)cout<<x.first << " "<< x.second ;
        return true; 
    }
};