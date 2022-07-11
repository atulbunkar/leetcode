
struct TrieNode {
    bool islast;  vector<TrieNode*> child;
    TrieNode(){
        islast = false;
        child.resize(26,NULL);
    }
    TrieNode(bool l){
        islast = l;
        child.resize(26,NULL);
    }
};

class WordDictionary {
private:
     TrieNode* root;
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) {
        return Search(root,word,0);
    }
    
    void insert(string word) {
        int n =word.size();
        TrieNode* r = root;
        for(auto x:word){
            if(r->child[x-'a'])r = r->child[x-'a'];
            else{
                r->child[x-'a'] = new TrieNode();
                r = r->child[x-'a'];
            }
        }
        r->islast = true;
    }

    
    bool Search(TrieNode*r , string word,int i){
        
        if(i==word.size())return r->islast;
        
        if(word[i]=='.'){
            bool f = false;
            for(auto &x: r->child){
                if(x==NULL)continue;
                f = Search(x , word,i+1);
                if(f)return f;
            }
            return false;
        }
        
        if( r->child[word[i]-'a'] ){
           return Search(r->child[word[i]-'a'],word,i+1);
        } 
        else 
            return 0;
       
    }
    
   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */