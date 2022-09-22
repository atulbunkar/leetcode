class Solution {
public:
    int ans = 1e8;
    
   // map<long,bool> mem;
    
    int mem[31][30001];
    
    int lastStoneWeightII(vector<int>& s) {
        int sum = accumulate(s.begin(),s.end(),0);
        memset(mem,-1,sizeof(mem));
        dp(0,0,sum,s);
        return ans;
        
    }
    
    void dp(int i,int cursum, int sum ,vector<int>& s ){
        
        //long k = 7*i + 13*cursum ;
        if(mem[i][cursum] >-1)return ;
        mem[i][cursum] = 1;
        
        if(i==s.size())return;
        
        ans = min(ans, abs( (sum-cursum) - cursum ) );
        
        dp(i+1,cursum+s[i],sum,s);
        dp(i+1,cursum,sum,s);
        
        
        
    }
    
};