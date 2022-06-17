class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans; vector<int> t(2);
        
        int i=0, j=0; int n= f.size(), m= s.size();
        
        if(!n || !m)return {};
        
        while(i<n and j<m){
            
            while(1){
            
                while(i<n and j<m and f[i][1] < s[j][0] )i++;

                while(j<m and i<n and s[j][1] < f[i][0])j++;
                
                if(i<n and j<m and (f[i][1] < s[j][0] || s[j][1] < f[i][0] ) )continue;
                else break;
            }
            
            if( i>=n || j>=m )break;
            
            if(f[i][0] <= s[j][0])t[0] = s[j][0];
            else t[0] = f[i][0];
            
            if(f[i][1] <= s[j][1])t[1] = f[i][1];
            else t[1] = s[j][1];
                
            ans.push_back(t);
            
            if(i<n-1 and j<m and f[i+1][0] <= s[j][1] )i++;
            
            else if(i<n and j<m-1 and s[j+1][0] <=f[i][1])j++;
            
            else{
                i++; j++;
            }
        }
        //cout<< i << " "<< j;
        
        return ans;
    }
};