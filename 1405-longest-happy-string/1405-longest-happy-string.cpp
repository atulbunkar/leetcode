class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)pq.push(make_pair(a,'a'));
        if(b)pq.push(make_pair(b,'b'));
        if(c)pq.push(make_pair(c,'c'));
        
        string ans = "";
        while(pq.size() >1){
            
            int x = pq.top().first; char xx = pq.top().second; pq.pop();
            int y = pq.top().first; char yy = pq.top().second; pq.pop();
            
            if(x>=2){ans += xx;ans+=xx; x-=2;}
            else{ans += xx; x--;}
            
            if( y>=2 and y>=x ){         //if second frequent is now most frequent, can push twice
                                            //imp second condition
                ans += yy; ans+=yy; y-=2;
            }
            else{
               ans += yy; y--;      //if second freq is still less than most freq, push once,
                                    //as we will need later for more partition
            }
            if(x>0)pq.push(make_pair(x,xx));
            if(y>0)pq.push(make_pair(y,yy));
            
        }
        if(!pq.empty()){
            if(pq.top().first >=2){
                ans.push_back(pq.top().second);
                ans.push_back(pq.top().second);
            }
            else ans.push_back(pq.top().second);
        }
        return ans;
    
    }
};