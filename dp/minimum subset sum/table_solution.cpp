//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n) { 
	    int sum=accumulate(arr,arr+n,0);
	    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
	    for(int i=0;i<n+1;i++)dp[i][0]=true;
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            if(i==0||j==0)continue;
	            if(arr[i-1]>j)dp[i][j]=dp[i-1][j];
	            else dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	        }
	    }
	    int mini=INT_MAX;
	    for(int i=sum/2;i>=0;i--){
	        if(dp[n][i]&&abs(sum-2*i)<mini)mini=abs(sum-2*i);
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
