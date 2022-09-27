class trienode{
    public:
    unordered_map<char,trienode*> nxt;
   // unordered_map<char,int> pref;
    bool last; int vst=0;
    trienode(){last = false; vst=0;}
    trienode(bool l){last = l;}
};



class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        trienode *r = new trienode();
        trienode* tmp = r;
        vector<int> ans;
        
        for(auto &s:words){
            tmp = r; 
            
            for(auto &c:s){
                
                if(tmp->nxt.count(c)){
                    
                    tmp= tmp->nxt[c];
                    //cnt += tmp->vst;   
                }
                else{
                    trienode* n = new trienode();
                    //tmp->vst = 1;
                    tmp->nxt[c] = n;
                    tmp = n;
                }
                tmp->vst++;
            }
            tmp->last = 1;
            
        }
        
        for(auto w:words){
            int cnt = 0;
            tmp = r;
            for(auto c:w){
              //  cout<< c << " " << tmp->vst << endl;
                if(tmp->nxt[c])cnt += tmp->nxt[c]->vst;
                tmp = tmp->nxt[c];   
            }
            //cout<<endl;
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};