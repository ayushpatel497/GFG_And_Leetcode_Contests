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
    int maximumBattalions(int N, vector<string> &names) {
        // code here
        unordered_map<string,int>um;
        for(int i=0;i<N;i++){
            um[names[i]]=i;
        }
        int ans=0;
        for(int i=0;i<N;){
            int to=um[names[i]];
            int j=i;
            while(j<N && j<=to){
                to=max(to,um[names[j++]]);
            }
            ans++;
            i=j;
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
        
        
        vector<string> names(N);
        Array::input(names,N);
        
        Solution obj;
        int res = obj.maximumBattalions(N, names);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends