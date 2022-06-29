class Solution {
public:
    int mem[41][41] , maxi[41][41];
    int mctFromLeafValues(vector<int>& arr) {
        memset(mem,-1,sizeof(mem));
        for(int i=0;i<arr.size();i++){
            maxi[i][i] = arr[i];
            for(int j=i+1;j<arr.size();j++)
                maxi[i][j] = max(maxi[i][j-1], arr[j]);
        }
        return dp(0,arr.size()-1,arr);
        
    }
    
    int dp(int i,int j,vector<int>& a){
        
        if(i>=j)return 0;
        
        if(mem[i][j] != -1 )return mem[i][j];
        
        int maxleft = INT_MIN , maxright = INT_MIN , minn = INT_MAX;
        
        for(int k=i ;k<j ;k++){
            
            minn = min(minn , dp(i,k,a)+ maxi[i][k]*maxi[k+1][j] +dp(k+1,j,a) );
            
        }
        return mem[i][j]= minn;
    }
    
};