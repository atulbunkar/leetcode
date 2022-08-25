
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        
        string ans = "";
         ans +=  to_string(root->val) + ",";
        if(root->left)
            ans += serialize(root->left);
        
       
        
        if(root->right)
            ans +=  serialize(root->right) + ",";
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
       // if(i==s.size()-1)return NULL;
        int n = s.size();
       cout<< s;
        int i =0;
        return h(s,i,INT_MIN,INT_MAX);
        return NULL;
        
    }
    
    TreeNode* h( string s, int &idx,int mini, int maxi){
        if(idx >= s.size())return NULL;
        
        //while(s[idx]==',')i++;
        
        int i = idx; string x= "";
        while(s[i] != ',')x += s[i++];
       
        int c = stoi(x);
        if(c < mini || c > maxi) return NULL;
        TreeNode* r = new TreeNode(c);
         idx=i;
        while(s[idx]==',')idx++;
        
        r->left = h(s,idx,mini,c);
        r->right = h(s,idx,c,maxi);
        
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;