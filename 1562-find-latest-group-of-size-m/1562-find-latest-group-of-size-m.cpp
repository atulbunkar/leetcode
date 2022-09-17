class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        // map -> 0-3,5-5
        map<int,int> mp;
        int n = arr.size();
        if(m==n)return n;
        
        mp[1] = n;
        
        for(int i = n-1;i>=0;i--){
            
            auto it = mp.upper_bound(arr[i]);
            --it;
            
            if(it->second - arr[i] ==m || arr[i] - it->first ==m)return i;
            
            if(it->first == it->second){
                mp.erase(it);
            }
           else{
                int tmp = it->second;

                if(it->first != arr[i])
                    it->second = arr[i]-1;
                else
                    mp.erase(arr[i]);

                if(arr[i]+1 <= tmp) 
                    mp[arr[i]+1] = tmp;

           }
            
            
//             for(auto x:mp){
//                 cout<< x.first << " " << x.second << " ";
//             }
//             cout<<endl;
            
           
            
        }
        
        return -1;
    }
};