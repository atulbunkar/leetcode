class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        int n = nums1.size();
        
        stack<int> st;
        st.push(nums2[0]);
        
        unordered_map<int,int> mp ; //curr, its greater
        vector<int> res;
        
        for(int i=1; i<n2 ;i++){
            
            while(!st.empty() and nums2[i] > st.top()){
                int t = st.top(); st.pop();
                mp[t] = nums2[i];
            }
            
            st.push(nums2[i]);
        }
        
        for(int i=0; i< nums1.size(); i++){
            
            if(mp.find(nums1[i]) != mp.end()){
                res.push_back( mp[nums1[i]]);
            }
            else
                 res.push_back(-1);
        }
        
        return res;
        
        
        
    }
};