class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<pair<int,int>> st; //val,ind
        
       st.push(make_pair(nums[0],0));
       unordered_map<int,int> mp ; //ind,value
        
        
        vector<int> res(n);
        
        for(int j=1; j<2*n ;j++){
            int i = j%n;
            
            while(!st.empty()and nums[i] > st.top().first ){
                auto t = st.top(); st.pop();
                
                mp[t.second] = nums[i];
            }
            
            st.push(make_pair(nums[i],i));
        }
        
        for(int i=0; i < n; i++){
            if(mp.find(i) != mp.end())
                res[i] = mp[i];
            else
                res[i]= -1;
            
        }
        
        
        return res;
    }
};