class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans=0;
        while(a[2]>0 and a[1]>0){
            ans++; a[2]--; a[1]--;
            sort(a.begin(),a.end());
        }
       
        while(a[2]>0){
            ans++; a[2]--;
        }
        return ans;
    }
};