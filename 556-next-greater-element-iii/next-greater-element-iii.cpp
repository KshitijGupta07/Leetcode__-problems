class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int a=-1;
        int b=-1;
        for(int i=0;i<s.length()-1;i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]<s[j]){
                a=i;
                b=j;
                }
            }
        }
        
        if(a==-1&&b==-1){
            return -1;
        }
        swap(s[a],s[b]);
        
        for(int i=a+1;i<s.length()-1;i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]>s[j]){
                    swap(s[i],s[j]);
                    
                    
                }
            }
        }

        long long e=stoll(s);
        cout<<e<<endl;
        cout<<INT_MAX<<endl;
        if(e>INT_MAX){
            return -1;
        }
        return stoi(s);

    }
};