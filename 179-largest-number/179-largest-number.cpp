class Solution {
public:
    static bool cmp(const string& a , const string& b){
        return a+b > b+a;
        
    }
    string largestNumber(vector<int>& nums) {
        vector<string> st;
        for(auto x:nums)
            st.push_back(to_string(x));
        
        sort(st.begin(),st.end(),cmp);
        string ans = "";
        for(auto x:st)
            ans += x;
        
        int j=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                j=i;
                break;
            }           
        }
        int m= ans.size();
        
        return j ==-1? "0": ans.substr(j,m-j);
    }
};