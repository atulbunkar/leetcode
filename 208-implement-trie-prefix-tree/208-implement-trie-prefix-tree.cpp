struct TrieNode {
    bool islast; unordered_map<char,TrieNode*> child;
    TrieNode(){
        islast = false;
    }
    TrieNode(bool l){
        islast = l;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n =word.size();
        TrieNode* r = root;
        insrt(0,word,r);
    }
    
    void insrt(int i, string& word, TrieNode* r){
        if(i==word.size()) return;
        
        if(r->child.count(word[i])){
            if(i==word.size()-1)r->child[word[i]]->islast = true;  
            insrt( i+1,word,r->child[word[i]] );
        }
        else{
            r->child[word[i]] = new TrieNode(i==word.size()-1);
            insrt(i+1,word,r->child[word[i]]);
        }
        
        
        //cout<< word[i] << " " << r->child.size()<<endl;
    }
    
    
    bool search(string word){
        TrieNode* r = root;
        for(auto x:word){
            if( r->child.count(x) ){
                r = r->child[x]; 
            } 
            else 
                return 0;
        }
        return r->islast;
        
    }
    
    bool startsWith(string word){
        TrieNode* r = root;
        for(auto x:word){
            if( r->child.count(x) ){
                r = r->child[x]; 
            } 
            else 
                return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */