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
  private:
    bool solve(string &a, string &b){
        int f1[26]{0};
        int f2[26]{0};
        for(int i=0; i<a.length(); ++i){
            f1[a[i]-'a']++;
            f2[b[i]-'a']++;
        }
        int cum = 0, g = 0;
        for(int i=0; i<26; ++i){
            cum += f1[i]-f2[i];
            if(cum<0) return false;
            g = __gcd(cum,g);
        }
        return g!=1;
    }
    
  public:
    vector<int> CompatibleStrings(int N, vector<string> &A1, vector<string> &A2) {
        vector<int> ans(N,0);
        for(int i=0; i<N; ++i){
         if(solve(A1[i],A2[i])) ans[i] = 1;   
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        vector<string> A1(N),A2(N);
        for(int i=0;i<N;i++) cin>>A1[i];
        for(int i=0;i<N;i++) cin>>A2[i];
        
        Solution obj;
        vector<int> res = obj.CompatibleStrings(N, A1, A2);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends