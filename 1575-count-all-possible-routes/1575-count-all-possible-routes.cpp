class Solution {
public:
    int ans = 0 , finish; int mem[102][202];
    
    int countRoutes(vector<int>& locs , int s, int f, int fuel) {
        finish = f;  memset(mem,-1,sizeof(mem));
        return dp(s,fuel,locs)%(1000000000+7) ;
    
    }
    // varying : idx, fuel  .
    
    int dp(int s ,int fuel , vector<int>& locs){
 
        unsigned long long ways = 0; 
        if(s==finish){ ways = 1; } //not doing return as we have to check ahead as well
        
        if(mem[s][fuel] >-1)return mem[s][fuel] ;
        
         int fuelused; 
   
        for(int i=0; i<locs.size()  ; i++ ){        
            if(i==s)continue;
            
            fuelused = abs(locs[i]-locs[s] );
            
            if(fuel >= fuelused  ){   
                ways += dp( i, fuel-fuelused ,locs )%(1000000000+7) ;  
            }
        }
        
        return mem[s][fuel] = ways%(1000000000+7) ;
    }
    
};