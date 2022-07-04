class Solution {
public:
    int pr[100001];
    //int sz[10001];
    int cnt=0;
    int set;
    int find(int v){
        if(pr[v] == -1)
            return pr[v] = v;
        if(pr[v] == v)
            return pr[v] = v;
        return pr[v] = find(pr[v]);
    }
    void un(int a,int b){
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
        return;
    }

    int makeConnected(int n, vector<vector<int>>& con) {
         memset(pr,-1,sizeof(pr));
        // memset(sz,1,sizeof(sz));
        set =n;
         for(auto &x:con){
            un(x[0],x[1]); 
         }

        //cout<<set<<endl;
        if(set-1>cnt)
            return -1;
        return set-1;
    }
};