// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	stack<int> s;  int Scc=0;
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> onstack(V+1,false);
        vector<int> stime(V+1,-1);
        vector<int> low(V+1,-1);
    
        int t =0;
        for(int i=0;i<V;i++){
            if(stime[i] == -1){
                tarjan(i, adj,onstack,stime,low, t);
            }
        }
       
        return Scc;
    }
    
    void tarjan(int i,vector<int> adj[] , vector<int>& onstack ,vector<int>& stime ,vector<int>& low,int& t){
        onstack[i] = true;
        stime[i] = low[i] = t++;  s.push(i);
        
        for(auto x:adj[i]){
            
            if(onstack[x]){   // back edge bcoz wo bhi current dfs me hai ,onstack me
                low[i] = min(low[i], stime[x]); // to apna low uske start time kro
            }
            
            if(stime[x]==-1){   // tree edge , not visited even once
                tarjan(x,adj,onstack,stime,low,t);  //age ke nodes pe call kro
                
                low[i] = min(low[i], low[x]); //agey ke node me koi back edge mil gya to
                                        // uska low apne se kam ho jaega
            }
            
        }
   
        //wapas aane ke baad , agar stime == low , mtlb sabse upar ke baap ke paas.
        //to sare stack walo ko khali kro jbtak baap ni nikal jata.
        if(low[i] == stime[i]){
            Scc++; //one SCC found
            while(s.top() != i){
                onstack[s.top()] = false;
                s.pop();
            }
            onstack[s.top()] = false;
            s.pop();
        }
        
        
        
        
        
    }
    
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends