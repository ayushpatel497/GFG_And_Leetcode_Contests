//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int candyShop(int n, vector<int> &candies) {
        // code here
        bool dp[10001];
        int sum=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(dp[candies[i]]==0){
                sum+=candies[i];
                dp[candies[i]]=1;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> candies(n);
        Array::input(candies,n);
        
        Solution obj;
        int res = obj.candyShop(n, candies);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends