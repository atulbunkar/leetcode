class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2){ ans.push_back(0) ; n--;}
        
        int i = 1; n /=2;
        while(n--){
            ans.push_back(i);
            ans.push_back(-1*i);
            i++;
        }
        
        return ans;
        
        
    }
};