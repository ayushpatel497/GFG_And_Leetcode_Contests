//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long greatCount(int N, string S) {
        // code here
        vector<long long> vect(2*N+1,0);
        vect[N]=1;
        long long prev=0,res=0;
        int count=N;
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                prev+=vect[count];
                res+=prev;
                count++;
                vect[count]++;
            }
            else{
                prev-=vect[count-1];
                res+=prev;
                count--;
                vect[count]++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        cin>>N;
        
        
        string S;
        cin>>S;

        Solution obj;
        long long res = obj.greatCount(N, S);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends