class Solution {
public:
   vector<vector<int>> ans ;
    void gameOfLife(vector<vector<int>>& b) {
        int n =b.size(); int m = b[0].size();
        ans = b;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(b[i][j])liv(i,j,b);
                else
                    ded(i,j,b);
            }
        }
        
        b = ans;
        
    }
    
    void ded(int i,int j ,vector<vector<int>>& b){
        pair<int,int> a = baju(i,j,b);
        int wan = a.first , o = a.second;
        
        if(wan==3)ans[i][j] =1;
        
    }
    
    void liv(int i,int j ,vector<vector<int>>& b){
         pair<int,int> a = baju(i,j,b);
        int wan = a.first , o = a.second;
        
        if(wan<2)ans[i][j] = 0;
        if(wan==2 || wan==3)ans[i][j] = 1;
        if(wan>3)ans[i][j] = 0;
        
    }
    
    pair<int,int> baju(int i,int j ,vector<vector<int>>& b){
        int n =b.size(); int m = b[0].size();
        int dir[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1},{1,-1},{-1,1} };
        
         pair<int,int> a; int x=0,y=0;
        for(auto d:dir){
            
            if(i+d[0] <0 || i+d[0]>=n || j+d[1] <0 || j+d[1]>=m)continue ;
            //cout<< i+d[0] << " " << j+d[1]<<endl;
           if(b[i+d[0]][j+d[1]])x++;
            else y++;
            
        }
        a.first = x;
        a.second = y;
        return a;
        
    }
};