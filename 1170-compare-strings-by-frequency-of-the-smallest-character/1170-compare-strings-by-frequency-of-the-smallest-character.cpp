class Solution {
public:
    int pp(string& word){
        int minn = 25; int frq = 0;
        for(auto& x:word){
            if(x-'a' < minn){
                minn = x-'a';
                frq = 1;
            }
            else{
                if(x-'a'==minn)frq++;
            }
        }
        return frq;
    }
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> a,b,ans;
        for(auto& x:q){
            a.push_back(pp(x));
        }
        for(auto& x:w){
            b.push_back(pp(x));
        }
        
       for(int i=0;i<a.size();i++){
           int cnt =0;
           for(int j=0;j<b.size() ; j++){
               if(a[i]<b[j])cnt++;
           }
           ans.push_back(cnt);
       }
        return ans;
        
    }
};