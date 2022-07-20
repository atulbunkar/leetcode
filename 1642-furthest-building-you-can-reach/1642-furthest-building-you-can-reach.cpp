class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        
        int n = h.size(); int maxb = b;
     
        priority_queue<int,vector<int> ,greater<int> > pq; //min heap
        int i=0;
        
        for(;i<n-1;i++){
            
            if(h[i+1]<=h[i]){
                continue;
            }
            int diff = h[i+1]-h[i];
            
            pq.push(diff);
            if(pq.size()>l)
            {
               
                int minb = pq.top();    
                pq.pop();                //ladder++ 
                if(b<minb)break; 
                b -= minb; 
                
            }
        }
        
        while(i<n-1 and h[i+1]<=h[i])i++;
        
        
        return i;
    }
};