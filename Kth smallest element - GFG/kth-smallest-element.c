// { Driver Code Starts
//Initial Template for C

#include<stdio.h>

 // } Driver Code Ends
//User function Template for C

int kthSmallest(int arr[], int l, int r, int k)
    {
        int max = 1e5;  int n = r-l+1;
        int min = 1;    int ans;
        
        while(min<max){
            
            int mid = (min+max)/2; int small=0;
            
            for(int i=0;i<n;i++)if(arr[i]<=mid)small++;
            
            if(small>=k){
                ans = mid;
                max = mid;
            }
            else{
               
                min = mid+1;
            }
            
        }
        ans;
        
    }

// { Driver Code Starts.
 
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            scanf("%d", &a[i]);
            
        int k;
        scanf("%d",&k);
        printf("%d",kthSmallest(a, 0, number_of_elements-1, k));
        printf("\n");
    }
    return 0;
}  // } Driver Code Ends