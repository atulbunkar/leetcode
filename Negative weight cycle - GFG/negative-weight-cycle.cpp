// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<pair<int,int>> adj[n] ;
	    
	    for(auto x:edges)
	        adj[x[0]].push_back({x[1] ,x[2] }); // dest, dist
	
	    vector<int> dist(n+1,INT_MAX-1);
	    dist[0] = 0;
	    
	    int v = n;
	    while(v--){
	        bool flag =0;
	        for(int i=0;i<n;i++){
	            if(dist[i] == INT_MAX-1)continue;
	            
	            for(auto& x:adj[i]){
	                if(dist[x.first] > dist[i] + x.second ){
	                    flag = 1;
	                    dist[x.first] = dist[i] + x.second;
	                }
	            }
	        }
	        if(!flag){ return false; }
	        
	    }
	    return true;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends