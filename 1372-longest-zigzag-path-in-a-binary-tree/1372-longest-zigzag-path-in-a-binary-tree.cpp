
class Solution {
public:
    map<TreeNode* ,map<int,int>> mem;
    
    int longestZigZag(TreeNode* root) {
        return help(root);
    }
    
    int help(TreeNode* r){
        if(!r)return 0;
        return max({rec(r,0),rec(r,1) , help(r->left) , help(r->right) });
    }
    
    int rec(TreeNode* r, int left){
        if(mem.find(r) != mem.end() and mem[r].find(left) != mem[r].end() )return mem[r][left];
        
        if(!r)return -1;
        
        if(left){
            return mem[r][left] =  1+rec(r->left,0);
        }
        else{
            return mem[r][left]= 1+rec(r->right,1);
        }
    }
};