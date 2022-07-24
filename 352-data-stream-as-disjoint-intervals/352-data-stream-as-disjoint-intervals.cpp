class SummaryRanges {
public:
    vector<vector<int>> v;
    set<int> s;     //set of val
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
        if(s.find(val) != s.end())return;
        
        auto it = s.find(val-1);
        auto fit= s.find(val+1);
        
        if(it==s.end() and fit == s.end()){
            int i = v.size();
            v.push_back({val,val});           
        }
        
        else if(it!=s.end() and fit==s.end()){
            
            int idx = findbycol1(val-1); //looks in col1
            v[idx][1] = val;

        }
        
        else if(it==s.end() and fit!=s.end()){
            
            int idx = findbycol0(val+1); //looks in col0

            if(v[idx][0]>val)v[idx][0] = val;
   
        }
        else{ //both present;
            int i = findbycol1(val-1); //looks in col1
            int minn = v[i][0];
            v.erase(v.begin()+i);
            int j = findbycol0(val+1); //looks in col0
            int maxx = v[j][1];
            v.erase(v.begin()+j);
            v.push_back({minn,maxx});
        }
        
         s.insert(val);
        
    }
    
    vector<vector<int>> getIntervals() {
        sort(v.begin(),v.end());
        return v;
    }
    
    int findbycol0(int val){
        for(int i=0;i<v.size();i++){
            if(v[i][0]==val)return i;
        }
        return -1;
    }
     int findbycol1(int val){
        for(int i=0;i<v.size();i++){
            if(v[i][1]==val)return i;
        }
         return -1;
    }
    
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */