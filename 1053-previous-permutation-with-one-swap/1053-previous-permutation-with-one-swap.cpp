class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size(); int j=n-1;
        
        while(j>0){
            
            if(arr[j-1] > arr[j])break;
            j--;
        }
        
        if(j==0)return arr;
        
        j--;
        
        int i = n-1;
        
        while(i>j){
            
            if(arr[i] < arr[j])break;
            i--;
            
        }
        
        while(i>j and arr[i] == arr[i-1])i--;
        
        swap(arr[i],arr[j]);
        return arr;
    }
};