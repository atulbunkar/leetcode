class Solution {
public:
    string removeKdigits(string num, int k) {
        //yaad kr kya krna tha
        
        int n = num.size();
        
        if(k>=n)return "0";
        
       // string s = to_string(num);
        string ans = "";
        

        for(int i=0;i<n;i++){
            
            while(!ans.empty() and k>0 and ans.back() > num[i]){
                ans.pop_back();
                k--;
                
            }
            ans += num[i];

            

        }
        
        if(ans.empty())return "0";
        
        while(!ans.empty() and k-- >0)ans.pop_back(); 
        if(ans.empty())return "0";
    
        int i=0;
        while(i<ans.size()){
            if(ans[i] != '0')
                return ans.substr(i,ans.size()-i);
            i++;
        }
        
        return "0";
        
    }
};