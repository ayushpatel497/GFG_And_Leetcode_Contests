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
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int ReturnToRoot(int N, vector<string> &M) {
        // code here
        string res="";
        for(auto s:M){
            if(s=="../")
                res.pop_back();
            else if(s=="./")
                continue;
            else res+=s[0];
        }
        return res.length();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<string> M(N);
        Array::input(M,N);
        
        Solution obj;
        int res = obj.ReturnToRoot(N, M);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends