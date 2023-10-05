//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getLastDigit(string a, string b) {
        // code here
        if(b=="0"){
            return 1;
        }
        if( a[a.length()-1]=='1'|| a[a.length()-1]=='5'|| a[a.length()-1]=='6'|| a[a.length()-1]=='0'){
            return a[a.length()-1]-'0';
        }
        
        if(a[a.length()-1]=='4'){
            if((b[b.length()-1]-'0')%2==1){
                return 4;
            }
            else{
                return 6;
            }
        }
        if(a[a.length()-1]=='9'){
            if((b[b.length()-1])%2==1){
                return 9;
            }
            else{
                return 1;
            }
        }
        if(a[a.length()-1]=='3'){
            int element=0;
            if(b.length()>1){
             element=10*(b[b.length()-2]-'0')+(b[b.length()-1]-'0');
            }
            else{
                element=b[b.length()-1];
            }
            
            if(element%4==0){
                return 1;
            }
            if(element%4==1){
                return 3;
            }
            if(element%4==2){
                return 9;
            }
            if(element%4==3){
                return 7;
            }
        }
        if(a[a.length()-1]=='7'){
            int element=0;
            if(b.length()>1){
             element=10*(b[b.length()-2]-'0')+(b[b.length()-1]-'0');
            }
            else{
                element=b[b.length()-1];
            }
            if(element%4==0){
                return 1;
            }
            if(element%4==1){
                return 7;
            }
            if(element%4==2){
                return 9;
            }
            if(element%4==3){
                return 3;
            }
        }
        if(a[a.length()-1]=='2'){
            int element=0;
            if(b.length()>1){
              element=10*(b[b.length()-2]-'0')+(b[b.length()-1]-'0');
            }
            else{
                element=b[b.length()-1];
            }
            if(element%4==0){
                return 6;
            }
            if(element%4==1){
                return 2;
            }
            if(element%4==2){
                return 4;
            }
            if(element%4==3){
                return 8;
            }
            
        }
        if(a[a.length()-1]=='8'){
            int  element=0;
            if(b.length()>1){
             element=10*(b[b.length()-2]-'0')+(b[b.length()-1]-'0');
            }
            else{
                element=b[b.length()-1];
            }
            if(element%4==0){
                return 6;
            }
            if(element%4==1){
                return 8;
            }
            if(element%4==2){
                return 4;
            }
            if(element%4==3){
                return 2;
            }
            
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends