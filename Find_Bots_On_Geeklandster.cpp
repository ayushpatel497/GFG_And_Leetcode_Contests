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
    bool check(string user) {
        vector<int> mp(26,0);
        int count = 0;
        int n = user.length();
        for(int i = 0; i < n; i+=2) {
            if(mp[user[i] - 'a'] == 0) {
                mp[user[i] - 'a']++;
                count++;
            }
        }
        if(count == 1) 
            return false;
        for(int i = 2; i < count; i++)
            if(count % i == 0) 
                return false; 
        return true;
    }
    
    public:
    vector<int> findBots(vector<string> &usernames, int n) {
        vector<int> res(n,0);
        for(int i = 0; i < n; i++)
            if(check(usernames[i])) 
                res[i]++;
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<string> usernames(n);
        Array::input(usernames,n);
        
        Solution obj;
        vector<int> res = obj.findBots(usernames, n);
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
        
    }
}

// } Driver Code Ends