class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;
        int j=0;
        int n=start.length();
        while(i<n||j<n){
            while(start[i]=='_'){
                i++;
            }
            while(target[j]=='_'){
                j++;
            }
            if(i==n||j==n){
                return i==n&&j==n;
            }
            if(start[i]!=target[j]){
                return false;
            }
                if(start[i]=='L'&&i<j){
                    return false;
                }
                if(start[i]=='R'&&i>j){
                    return false;
                }
                
            
            i++;
            j++;
        }
        cout<<i<<j<<endl;
        
        return true;
    }
};