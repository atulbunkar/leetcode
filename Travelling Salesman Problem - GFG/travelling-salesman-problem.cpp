// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    public:
    int total_cost(vector<vector<int>>cost){
        int n = cost.size();
        vector<pair<int,int>> adj[n+1];
        vector<bool> mask(n,false);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)
                    adj[i].push_back( {j,cost[i][j]} );
            }
        }
        
        mask[0] = true;
        int x = dfs(0,mask,adj,cost) ;
            
        return x;
     
        
    }
    
    int dfs(int node,vector<bool>& mask ,vector<pair<int,int>> adj[],vector<vector<int>>&cost){
        int ans = INT_MAX;
        //cout<< node << " -> ";
        bool last = true;
        for(int i=1;i<cost.size();i++)last &= mask[i];
        
        if(last){
            
            return cost[node][0];
        }
        
        //cout<< node << " -> ";
        for(auto x:adj[node]){
            
            if(mask[x.first])continue;
           // cout<< x.first << " ";
            mask[x.first] = true;
            ans = min(ans, dfs(x.first,mask,adj,cost)+x.second );
            mask[x.first] = false;
        }
        //cout<< endl;
        return ans==INT_MAX ? 0:ans;
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends