class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        string temp="";
        for(int i=0;i<s.length();i++){
            if(temp.empty()==true){
                if(s[i]!='-'&&s[i]!='+'&&isdigit(s[i])==false&&s[i]!=' '){
                    break;
                }
                else{
                    temp.push_back(s[i]);
                }
            }
            else{
                if(temp.back()==' '){
                    if(s[i]==' '||isdigit(s[i])||s[i]=='+'||s[i]=='-'){
                        temp.push_back(s[i]);
                    }
                    else{
                        break;
                    }
                }
                else if(temp.back()=='+'){
                     if(isdigit(s[i])){
                        temp.push_back(s[i]);
                     }
                     else{
                        break;
                     }
                }
                else if(temp.back()=='-'){
                    if(isdigit(s[i])){
                        temp.push_back(s[i]);
                    }
                    else{
                        break;
                    }
                }
                else if(isdigit(temp.back())){
                    if(isdigit(s[i])){
                        temp.push_back(s[i]);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        string a="";
        int i=0;
        while(i<temp.length()){
            if(temp[i]!=' '){
                a.push_back(temp[i]);
            }
            i++;
        }
    
        temp="";
        
        if(a[0]=='+'||a[0]=='-'){
            temp.push_back(a[0]);
            int i=1;
            while(i<a.length()&&(a[i]=='-'||a[i]=='+')){
                i++;
            }
            while(i<a.length()&&a[i]=='0'){
                i++;
            }
            while(i<a.length()){
                temp.push_back(a[i]);
                i++;
            }
        }
        else{
        int j=0;
        while(j<a.length()&&a[j]=='0'){
            j++;
        }
        while(j<a.length()){
            temp.push_back(a[j]);
            j++;
        }
        }
        cout<<temp<<endl;
        if(temp.length()==0){
            return 0;
        }
        if(temp.length()==1){
            if(temp[0]=='-'||temp[0]=='+'){
                return 0;
            }
        }
        if(temp[0]=='+'){
            cout<<"p"<<endl;
            if(temp.length()-1>10){
                return INT_MAX;
            }
            else if(temp.length()-1==10){
                
                string x=to_string(INT_MAX);
                int y=1;
                for(int i=0;i<x.length();i++){
                    if(temp[y]<x[i]){
                        return stoll(temp);
                    }
                    y++;
                }
                return INT_MAX;
            }
            else{
                
                    return stoll(temp);
                
            }
        }
        if(temp[0]=='-'){
        cout<<"m"<<endl;
             if(temp.length()-1>10){
                return INT_MIN;
            }
            else if(temp.length()-1==10){
                string x=to_string(INT_MIN);
                
                for(int i=0;i<x.length();i++){
                    if(temp[i]<x[i]){
                        return stoll(temp);
                    }
                    else if(temp[i]>x[i]){
                        return INT_MIN;
                    }
                }
                return INT_MIN;
            }
            else{
                
                    return stoll(temp);
                
            }
        }
         if(temp.length()>10){
            return INT_MAX;
         }
         else if(temp.length()==10){
            cout<<"x"<<endl;
            string x=to_string(INT_MAX);
            cout<<x.length()<<" "<<temp.length()<<endl;
           for(int i=0;i<x.length();i++){
                    if(temp[i]<x[i]){
                        
                        return stoll(temp);
                    }
                    else if(temp[i]>x[i]){
                        return INT_MAX;
                    }
                }
                return INT_MAX;
         }
         
         return stoll(temp);
        
     
    }
};