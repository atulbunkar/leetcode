class StockSpanner {
public:
    stack<pair<int,int>> s; int days = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        days++;
        while(!s.empty() and price >= s.top().first)s.pop();
        
        int ans = s.empty() ? days : days - s.top().second;
        s.push({price,days});
        return ans;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */