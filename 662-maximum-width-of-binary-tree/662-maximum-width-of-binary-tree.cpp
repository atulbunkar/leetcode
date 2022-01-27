class Solution {
public:
    typedef unsigned long long int ull;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        map<ull,pair<ull,ull>> mp; //lvl , max-min
       
        dfs(root,0,mp,1);
        ull maxx = 0;
        for(auto itr = mp.begin() ; itr != mp.end() ; itr++){
            auto z = itr->second;
            maxx = maxx > z.second-z.first+1 ? maxx : z.second-z.first+1 ;
        }
        return maxx;
        
    }
    
    void dfs(TreeNode* root, ull lvl , map<ull,pair<ull,ull>>& mp,ull h){
        if(!root)return;
        
        dfs(root->left,lvl*2,mp,h+1);
        dfs(root->right,lvl*2+1,mp,h+1);
        
        if(mp.find(h) == mp.end()){
           mp[h] = make_pair(lvl,lvl);
        }
        else{
            auto x = mp[h];
           
            x.second = x.second > lvl ? x.second:lvl; 
            x.first = x.first < lvl ? x.first:lvl; 
            mp[h] = x;
            
        }
        
    }
    
    
    
    
};