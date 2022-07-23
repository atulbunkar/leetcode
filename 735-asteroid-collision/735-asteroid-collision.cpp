class Solution {
public:
    vector<int> mask;
    vector<int> asteroidCollision(vector<int>& a) {
        mask.resize(a.size(),0);
        int n =a.size();
        
        while(1){
            bool fl = true;
            int i=0;
            
            while(i<n){
                int f = next(i);
                if(f>n-1)break;
                int s = next(f+1);
                if(s>n-1)break;
                 
                
                if(a[f]>0 and a[s]<0){
                   //cout<< f << " " << s;
                    fl = false;
                   
                    if(abs(a[f])>abs(a[s]))
                        mask[s]= 1;
                    else if(abs(a[f])<abs(a[s]))
                        mask[f] = 1;
                    else
                        mask[f] = mask[s] =1;
                    
                }
                i = s;
            }
            if(fl)break;
        }
        
         vector<int> ans;
        for(int i=0;i<n;i++){
            if(!mask[i])
                ans.push_back(a[i]);
        }
        
        return ans;
    }
    
    
    int next(int i){
        while(i<mask.size() and mask[i])i++;
        return i;
    }
};