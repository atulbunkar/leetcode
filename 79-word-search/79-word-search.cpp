class Solution {
public:
    bool found = false;
    bool exist(vector<vector<char>>& board, string word) {
        string s = "";
        int n = board.size(), m= board[0].size(); int len = word.size(); 
        
        for(int i = 0; i< n ;i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == word[0] ){
                    vector<vector<int>> vstd(n , vector<int>(m,0));
                    string str = "";
                    if(len == 1)return true;
                    bt(board , word , 0 , i,j,str, vstd);
                    cout << str ;
                }
                if(found)return true;
            }
        }
        return false;
        
    }
    
    void bt(vector<vector<char>>& board, string word, int curr , int i, int j, string str,vector<vector<int>>& vstd){
         if(str == word){
            found = true; return;
        }
        
        if(i<0 || j<0 || i >= board.size() || j>= board[0].size() || found || vstd[i][j])return;
        
        if(board[i][j] != word[curr] )return;
        vstd[i][j] = 1; 
       
        str += word[curr];
       // cout << curr << " " << i << " " << j << " " << str << endl ;
        bt(board, word , curr+1 , i-1,j, str , vstd  );
        bt(board, word , curr+1 , i+1,j, str ,vstd );
        bt(board, word , curr+1 , i,j-1, str ,vstd );
        bt(board, word , curr+1 , i,j+1, str ,vstd );
        
        vstd[i][j] = 0;
        
    }
};