
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        level(root,ans);
        return ans;
    }
    void level(TreeNode * r,vector<int>&ans){
        queue<TreeNode * >q;
        q.push(r);
        while(!q.empty()){
            int n= q.size();
            int temp1;
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(i==n-1)temp1=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(temp1);
        }
    }
};