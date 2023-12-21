//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string isSumOfConsecutive(int N) {
        // code here
    for(int i=0;i<32;i++){
        if(N==pow(2,i)){
            return "No";
            break;
        }
    }
    return "Yes";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isSumOfConsecutive(N) << endl;
    }
    return 0;
}
// } Driver Code Ends