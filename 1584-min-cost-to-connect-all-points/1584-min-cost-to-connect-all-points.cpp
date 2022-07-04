class Solution {
public:
    int pr[1001];
    //int sz[1001];
    int cnt=0;
    int cost=0;
    int set;
    int find(int v){
        //cout<<" 3";
        if(pr[v] == -1)
            return pr[v] = v;
        if(pr[v] == v)
            return pr[v] = v;
        return pr[v] = find(pr[v]);
    }
    void un(pair<int,int>cr ,int dis){
        //cout<<" 2";
        
        int a =cr.first;
        int b =cr.second;
        
        a = find(a);
        b = find(b);
        if(a == b){
            cnt++;
             return ;
        } 
        // if(sz[a]<sz[b])
        //     swap(a,b);
        
        pr[b] = a;
       // sz[a] = sz[a]+sz[b];
        set--;
        cost += dis;
        return;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        multimap<int,pair<int,int>> mp;
        memset(pr,-1,sizeof(pr));
        
        for(int i =0; i<n-1;i++){
            for(int j =i+1;j<n;j++){
                int dis = abs(points[i][0] - points[j][0]) +  abs(points[i][1] - points[j][1]);
    
                mp.insert(make_pair(dis,make_pair(i,j)));
           }
        }
        //cout<<" 1";
        for(auto &x:mp){
            //cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
            un(x.second,x.first);
        }
        return cost;
    }
};