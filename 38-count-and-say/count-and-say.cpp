class Solution {
public:
string help(int n){
    if(n==1){
        return "1";
    }
    string temp=help(n-1);
    string x="";
    int count=1;
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]==temp[i+1]){
            count++;
        }
        else{
            x+=to_string(count)+temp[i];
            count=1;
        }
    }
    return x+to_string(count)+temp[temp.size()-1];
}
    string countAndSay(int n) {
        return help(n);
    }
};