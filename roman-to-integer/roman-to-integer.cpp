class Solution {
public:
    int romanToInt(string s) {
        
        map<char , int> rtoi ;
        
        int val = 0;
        
        rtoi['I'] = 1;
        rtoi['V'] = 5;
        rtoi['X'] = 10;
        rtoi['L'] = 50;
        rtoi['C'] = 100;
        rtoi['D'] = 500;
        rtoi['M'] = 1000;
        
        for(int i = 0 ; i < s.size()-1 ; i++){
            if(rtoi[s[i]] == 1 || rtoi[s[i]] == 10 ||rtoi[s[i]] == 100 )
            {
                if(rtoi[s[i+1]] > rtoi[s[i]] ){
                    val -= rtoi[s[i]];
                    }
                else
                    val += rtoi[s[i]];
                
            }
            else
                val += rtoi[s[i]];
                    
        }
        val += rtoi[s[s.size()-1]];
        
        return val;
        
    }
};