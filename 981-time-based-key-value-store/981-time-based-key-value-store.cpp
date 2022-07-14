class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int t) {
        mp[key].insert({t,value});
    }
    
    string get(string key, int t) {
        if(!mp.count(key))return "";
        int minn = 1, maxx = t;
        int ans = bs(key,minn,maxx);
        return (ans==-1)?"": mp[key][ans];
    }
    
    int bs(string& key,int minn,int maxx){
        if(minn>maxx)return -1;
        int mid = (minn+maxx)/2;
        
        if(mp[key].count(mid))return max(mid, bs(key,mid+1,maxx)); 
        
        int r= bs(key,mid+1,maxx);
        if(r>-1)return r;
        
        int l =bs(key,minn,mid-1);
        return l;
        
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */