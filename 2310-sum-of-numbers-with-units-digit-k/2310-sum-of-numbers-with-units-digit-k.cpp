class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0)return 0;
        if(num%2 and k%2==0)return -1;
        if(k==0 and num%10!=k)return -1;
        
        int p=1; 
        while(num>=k){
            if(num%10 == k)return p;

             num = num-k; p++;
        }
        return -1;
        
    }
    
    
};