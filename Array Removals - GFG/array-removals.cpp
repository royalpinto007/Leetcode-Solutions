//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
       sort(arr.begin(),arr.end());
       int n=arr.size();
       int res=INT_MIN;
       for(int i=0;i<n;i++)
       {
           for(int j=i;j<n;j++)
           {
               if((arr[j]-arr[i])<=k)
               {
                   res=max(res,j-i+1);
               }
           }
       }
       return n-res;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends