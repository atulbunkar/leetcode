
class Solution {
public:
    
    unordered_map<int,int> odds; //ele , count
   // int odd[100001]
        int ans=0;
        
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    
    void dfs(TreeNode* r){
        
        if(!r)return;
        
        odds[r->val]++;
        
         if(!r->left and !r->right){
           
             int o = 0;
             for(auto& x:odds){
                 if(x.second%2)o++;
             }
             if(o<=1)ans++;
           
        }
        
        dfs(r->left);
        
        dfs(r->right);
        
        odds[r->val]--;
        if(odds[r->val]<=0)odds.erase(r->val);
        
    }
    
    
};