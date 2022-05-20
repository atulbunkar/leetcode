class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        sort(c.begin(),c.end()) ;
        vector<vector<int>> ret ;
        vector<int> temp ;
        
        help(c,temp,ret,target,0);
        
        return ret;
        
        
    }
    
    void help(vector<int>& c ,vector<int>& temp , vector<vector<int>>& ret ,int target ,int x ){
        if(target == 0)
        {
            if(find(ret.begin(),ret.end() , temp) == ret.end())
                ret.push_back(temp);
            return;
        }
        
        if(x >= c.size())
            return;
        
        if(c[x] > target)
            help(c, temp, ret, target,x+1);
        
        else{
            
            temp.push_back(c[x]);
            help(c,temp, ret, target-c[x],x+1);
            help(c,temp, ret, target-c[x],x);
            temp.pop_back();

            help(c, temp, ret, target,x+1);
        }
        

     }
    
    
    
};

