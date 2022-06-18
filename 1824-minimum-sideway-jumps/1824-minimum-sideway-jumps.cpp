class Solution {
public:
    vector<vector<int>> dp;
    
    int minSideJumps(vector<int>& o) {
        dp.resize(o.size(), vector<int>(4,INT_MAX-1));
        int n = o.size();
        
        dp[0][2] = 0;
        
        for(int i=1; i<n-1 ;i++ ){
            
            for(int lane = 1;lane<=3;lane++){
                
                if(o[i] == lane || o[i+1]==lane){
                    dp[i][lane] = INT_MAX-1;
                } 
                else{
                    int x ,y;
                    if(lane == 1){x=2,y=3;}
                    else if(lane ==2){x=1,y=3;}
                    else{x=1;y=2;}
                    
                    dp[i][lane] = min(dp[i-1][lane] ,min(dp[i-1][x]+1 , dp[i-1][y]+1) );
                }
            
            
            }
            
        }
        
        return min(dp[n-2][1] , min(dp[n-2][2],dp[n-2][3] )) ;
    }

};