// Very IMP
// See soln https://leetcode.com/problems/find-the-duplicate-number/discuss/72844/Two-Solutions-(with-explanation)%3A-O(nlog(n))-and-O(n)-time-O(1)-space-without-changing-the-input-array

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1 ;
        int mid , cnt;
        
        while(l<=h){
            mid = (l+h)/2;
            cnt = 0;
            for(auto x:nums)
                if(x <= mid)cnt++;
            
            if(cnt>mid){
                h = mid-1;
               
            }
            else
                l = mid+1;
            
            cout << h << " " << l << endl;
                
        }
        
        return l;
    }
};