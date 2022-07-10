class SmallestInfiniteSet {
public:
    vector<int> popped; int small=1; 
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
       sort(popped.begin(),popped.end());
    
        int small = 1;
        for(auto x:popped){
            if(x==small)small++;
            else break;
        }
        popped.push_back(small);
        return small;
        
    }
    
    void addBack(int num) {
        auto it = find(popped.begin(),popped.end(),num);
        if(it!=popped.end())popped.erase(it);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */