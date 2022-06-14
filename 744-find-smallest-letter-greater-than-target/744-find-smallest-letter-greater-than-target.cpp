class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        int n = l.size();
        
        if(t >= l[n-1])return l[0];
        
        int i=0,j= n-1;

        while(i<j){
            int mid = (i+j)/2;
            
            //if(l[mid]==t)return l[mid];
            
            if(l[mid]>t)j = mid;
            
            else
                i = mid+1;
        }
        
        return l[i];
    }
};