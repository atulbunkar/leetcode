class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int> pq; int n= mat.size() , m= mat[0].size();
        
        if(n==1)return mat[0][k-1];
        int ans ;
        
        int i= 0, j=0;
        
        for(int i=0; i<n ;i++)
            for(int j=0; j<m ;j++){
                if(pq.size() < k)           //not reached k elements
                    pq.push(mat[i][j]);
                
                else{   //k elements in pq 
                    if(mat[i][j] < pq.top()  ){  //curr element is less than largest element
                        pq.pop(); pq.push(mat[i][j]); // remove largest and fill curr
                    }
                       
                }
            }
        return pq.top();
        
    }
};