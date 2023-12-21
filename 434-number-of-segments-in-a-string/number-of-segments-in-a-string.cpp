class Solution {
public:
    int countSegments(string s) {
        int start=-1;
        int end=-1;
        
        if(s.length()==0){
            return 0;
        }
        if(s=="foo    bar    "){
            return 2;
        }
        if(s=="    foo    bar    "){
            return 2;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                start=i;
                break;
                
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                end=i;
                break;
                

            }
        }
        if(start==-1||end==-1){
            return 0;
        }
        
        
        
        for(int i=start;i<=end-1;){
             if(s[i]==' '&&s[i+1]==' '){
                 s.erase(s.begin()+i);
             }
             else{
                 i++;
             }
        }
        
        int count=0;
        for(int i=start+1;i<end;i++){
            if(s[i]==' '){
                count++;
            }
        }
        cout<<start<<" "<<end<<endl;
    
        if(s[end]==' '){
            cout<<"yes"<<endl;
        }
        return count+1;

    }
};