
class Solution {
public:
    long long ans = 0;
    int maxSumBST(TreeNode* root) {
        h(root);
        return ans;
    }
    
    
    vector<long long> h(TreeNode* r){      //l1 -> min , l2 -> max , l0 ->sum , l3 -> true
        
        
        if(!r)return {0,INT_MAX,INT_MIN,1};
        
        auto l = h(r->left);
        auto ri = h(r->right);
        
        long long sum = l[0] + ri[0];
        sum += r->val;
        
        int bst ;
        
        if(l[2] < r->val and ri[1] > r->val and l[3] and ri[3]){
            ans = max(ans, sum);
            bst = 1;
        }
        else{
            bst = 0;
        }
        
        int minn,maxx;
        
        minn = min({r->val , (int)l[1], (int)ri[1]});
        maxx = max({r->val, (int) l[2], (int)ri[2]});
        
        return {sum, minn,maxx,bst  };
    }
    
    
};