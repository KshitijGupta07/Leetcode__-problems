class Solution {
public:
    bool canTransform(string start, string result) {
        int i=0;
        int j=0;
        if(start==result){
            return true;
        }
        int n=start.length();
        while(i<n&&j<n){
            if(start[i]==result[j]){
               
                swap(start[i],start[j]);
                i=min(i,j);
                j=min(i,j);
                if(start[i]==result[j]){
                i++;
                j++;
                }
                  
            }
            else{
                if(start[i]=='R'&&result[j]=='L'){
                    return false;
                }
                if(start[i]=='L'&&result[j]=='R'){
                    return false;
                }
                if(start[i]=='L'&&result[j]=='X'){
                    return false;
                }
                if(start[i]=='X'&&result[j]=='R'){
                    return false;
                }
                else{
                    i++;
                }
            }
        }
        if(start==result){
            return true;
        }
        cout<<start<<" "<<result<<endl;
        return false;
    }
};