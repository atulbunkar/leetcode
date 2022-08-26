
class Solution {
public:
    
   // unordered_map<int,int> odds; //ele , count
    int odd[100001] ; int mx = -1;
        int ans=0;
        
    int pseudoPalindromicPaths (TreeNode* root) {
        memset(odd,0,sizeof(odd));
        dfs(root);
        return ans;
    }
    
    
    void dfs(TreeNode* r){
        
        if(!r)return;
        
        mx = max(mx,r->val);
        odd[r->val]++;
        
         if(!r->left and !r->right){
             int o = 0;
             for(int i=0;i<=mx;i++){
                 if(odd[i]%2)o++;
             }
             if(o<=1)ans++;
        }
        
        dfs(r->left);
        dfs(r->right);
        odd[r->val]--;
        if(odd[r->val] <0)odd[r->val] =0; 
        
    }
    
    
};