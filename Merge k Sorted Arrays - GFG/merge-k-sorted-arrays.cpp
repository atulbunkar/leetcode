// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        
        while(arr.size()>1){
            int n1 = arr[0].size(); int n2 = arr[1].size();
            
            int i=0,j=0; vector<int> tmp;
            
            while(i<n1 and j<n2){
                if(arr[0][i] < arr[1][j]){tmp.push_back(arr[0][i]); i++;}
                else { tmp.push_back(arr[1][j]); j++; }
            }
            
            while(i<n1){tmp.push_back(arr[0][i]); i++;}
            while(j<n2){tmp.push_back(arr[1][j]); j++;}
            
            arr.erase(arr.begin()); arr.erase(arr.begin());
            arr.push_back(tmp);
            tmp.clear();
        }
        //code here
        
         return arr[0];
        
    }
    
   
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends