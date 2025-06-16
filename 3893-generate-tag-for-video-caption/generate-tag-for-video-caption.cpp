class Solution {
public:
    string generateTag(string caption) {
        string ans="";
        int n=caption.length();
        ans.push_back('#');
        for(int i=0;i<n;i++){
            if(ans.length()==100){
                break;
            }
            if(i>0&&caption[i-1]!=' '&&caption[i]>='A'&&caption[i]<='Z'){
                int a=caption[i]-'A';
                caption[i]='a'+a;

            }
            if(caption[i]!=' '){
                ans.push_back(caption[i]);
            }
            else{
                if(i+1<n&&caption[i+1]>='a'&&caption[i+1]<='z'){
                int a=caption[i+1]-'a';
                caption[i+1]='A'+a;
                }
            }
        }
        cout<<ans.length()<<endl;
        if(ans[1]>='A'&&ans[1]<='Z'){
        int a=ans[1]-'A';
        ans[1]='a'+a;
        }
       
       
       
        return ans;
    }
};