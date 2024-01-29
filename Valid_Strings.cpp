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
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int validStrings(int n, int k, vector<string> &arr) {
        // code here
        int ans=0;
        for(int i=0;i<n;i++){
            int ct=0;
            for(int j=0;j<arr[i].size();j++){
                if(isVowel(arr[i][j]))ct++;
            }
            if (ct==k) ans++;
        }
        return ans;
    }
    
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<string> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.validStrings(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends