// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&c,vector<int>&t,int N)
	{
	     queue<pair<int,int>> q;
	     q.push({c[0]-1,c[1]-1}); 
	     if(c[0] == t[0] and c[1] == t[1])return 0;
	     
	     for(auto &x:t)x = x-1; int step =0;
	     int dir[8][2] = { {2,1}, {1,2} ,{2,-1} ,{1,-2} , {-1,2} , {-1,-2} , {-2,-1} , {-2,1} };
	     bool vstd[1001][1001] ;
	     memset(vstd,false,sizeof(vstd));
	     
	     
	     while(!q.empty()){
	         
	         int n=q.size();
	         
	         for(int i=0;i<n;i++){
	             auto x= q.front(); q.pop();
	             int p = x.first, o = x.second;
	             
	             if(p == t[0] and o == t[1])return step;
	             
	             for(auto d:dir){
	                 if(p+d[0] < N and p+d[0] >=0 and o+d[1] < N and o+d[1] >=0 and !vstd[p+d[0]][o+d[1]]){
	                     vstd[p+d[0]][o+d[1]] = true;
	                     q.push({p+d[0],o+d[1]});
	                 }
	             }
	             
	         }
	         step++;
	     }
	     
	     return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends