//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int repeatedSumOfDigits(int N){
        // code here 
        
        if(N%9==0){
            return 9;
        }
        return N%9;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.repeatedSumOfDigits(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends