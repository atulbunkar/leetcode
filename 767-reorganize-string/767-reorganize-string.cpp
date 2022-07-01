class Solution {
	static bool compare(pair<char, int>p1, pair<char, int>p2) {
		return p1.second > p2.second;
	}
public:
	string reorganizeString(string S) {
	    vector<int> cnt(26,0);
	    
        for(auto c:S)cnt[c-'a']++;
        
        int n = S.size();
        int mx = *max_element(cnt.begin(), cnt.end());
        
        if(mx * 2 > S.size()+1)return "";
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<26;i++){
            if(cnt[i])
                pq.push(make_pair(cnt[i] , i ));
        }
        
        vector<bool> vstd(n,false);
        int i=0;
        
        while(!pq.empty()){
            int x = pq.top().second ;
            int count = pq.top().first ;
            pq.pop();
             while(count--){ 
                if(i>=S.size())i=0;
                while(vstd[i]){
                    i++;
                    if(i>=S.size())i=0;
                }
                vstd[i] = true;
                S[i] = x +'a';
                i +=2;
                
            }
        }
        
        
        
        return S;
        
    }

};