class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        int r = mt.size() , c = mt[0].size();
        int first0row = -1; 
      
        for(int i=0; i < r ; i++ ){
            
            for(int j = 0 ; j < c ; j++){
                
                if(mt[i][j] == 0){
                    if(first0row == -1){
                        first0row = i;
                        break;
                    }
                    else{
                        mt[first0row][j] = 0;         //use first0row as placeholder for 0 columns
                    }
                }
                
            }
        }
        if(first0row == -1)return;
        
        for(int i=0; i < r ; i++ ){          //making all row with 0 as all 0, except first0row;
            if(i==first0row)continue;
            for(int j = 0 ; j < c ; j++){
                if(mt[i][j] == 0){
                    for(int k = 0; k<c; k++){
                        mt[i][k] = 0;
                    }
                    break;
                }
            }
        }
        
                                            //make all column 0 using first0row
        for(int j = 0; j<c; j++){
            if(mt[first0row][j] == 0){
                for(int i=0; i<r;i++){
                    mt[i][j]=0;
                }
            }
        }
        
                                                //make first0row row all 0
        for(int j = 0; j<c; j++){
            mt[first0row][j] = 0;   
        }
        
 
    }
};