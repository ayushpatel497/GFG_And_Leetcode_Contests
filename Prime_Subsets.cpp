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
    int mod=1000000007;
public:
    int primeSubsets(int n, vector<int> &arr) {
        // code here
        int primes[] ={2,3,5,7,11,13,17,19,23,29} ;
        vector<long long>dp(1<<10) ;
        dp[0] =1 ;
        map<int,int>mp ;
        for(auto x:arr){
            mp[x]++ ;
        }
        for(auto x:mp){
            int g=x.first ;
            if(g==1){
                continue ;
            }
            int c=0 ;
            bool flag=true;
            for(int p=0;p<10;p++){
                int cnt =0 ;
                while(g%primes[p]==0){
                    cnt++ ;
                    g/=primes[p] ;
                }
                if(cnt==1) c+= (1<<p) ;
                else if(cnt>=2) flag=false ;
            }
            if(!flag)continue ;
            for(int mask=0;mask<(1<<10);mask++){
                if(dp[mask] and ((mask & c)==0)){
                    dp[mask^c]+= (dp[mask]*(x.second)) ;
                    dp[mask^c]%=mod ;
                }
            }
        }
        long long ans =0 ;
        for(int mask=1;mask<(1<<10);mask++){
            if(dp[mask]){
                ans+= dp[mask] ;
                ans%=mod ;
            }
           
        }
        long long k=1 ;
        for(int i=1;i<=mp[1];i++){
            k*=2 ;
            k%=mod ;
        }
        ans *= k;
        ans%=mod ;
        return ans ;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> Arr(N);
        Array::input(Arr,N);
        
        Solution obj;
        int res = obj.primeSubsets(N, Arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends