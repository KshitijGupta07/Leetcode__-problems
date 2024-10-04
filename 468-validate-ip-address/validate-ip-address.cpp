class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.length()==0){
            return "Neither";
        }
        int count1=0;
        int count2=0;
        if(queryIP.back()==':'||queryIP.back()=='.'){
            return "Neither";
        }
        if(queryIP[0]==':'||queryIP[0]=='.'){
            return "Neither";
        }
        for(auto j:queryIP){
            if(j==':'){
                count1++;
            }
            else if(j=='.'){
                count2++;
            }

        }
        if(count1!=0&&count2!=0){
             return "Neither";
        }
       
       
        if(count2!=0){
             if(count2!=3){
             cout<<"idhar"<<endl;
             return "Neither";
        
        }
            if(queryIP[0]=='0'){
                return "Neither";
            }
            int num=0;
              vector<int>pos;
            for(int i=0;i<queryIP.length();i++){
              
                if(queryIP[i]>='1'&&queryIP[i]<='9'){
                    num=num*10+(queryIP[i]-'0');
                    if(num>255){
                        return "Neither";
                    }
            }
                if(queryIP[i]=='.'){
                    if(num>255){
                        return "Neither";
                    
                    }
                    num=0;
                    pos.push_back(i);
                }
                if(queryIP[i]!='.'&&(queryIP[i]<'0'||queryIP[i]>'9')){
                    return "Neither";
                }

            }
            for(int i=0;i<pos.size()-1;i++){
                   if(pos[i+1]-pos[i]>2){
                        if(queryIP[pos[i]+1]=='0'){
                            return "Neither";
                        }
                   }
                   if(pos[i+1]-pos[i]==1){
                      return "Neither";
                   }
                   if(pos[i+1]-pos[i]>4){
                        return "Neither";
                   }
            }
             if(queryIP[pos[pos.size()-1]+1]=='0'){
             return "Neither";
        }
            int index=pos.back();
            int counter=0;
            int number=0;
            index=index+1;
            while(index<queryIP.length()){
                number=number*10+queryIP[index]-'0';
                index++;
                counter++;

            }
            cout<<number<<endl;
            if(counter>3||number>255){
                return "Neither";
            }
            return "IPv4";
        }
       
        if(count1!=0){
             if(count1!=7){
            return "Neither";
        }
            vector<int>pos;
            for(int i=0;i<queryIP.length();i++){
                 if(queryIP[i]==':'){
                    pos.push_back(i);
                 }
                 if(isdigit(queryIP[i])==false&&queryIP[i]!=':'){
                    char ch=queryIP[i];
                    if(ch>='A'&&ch<='F'){
                        continue;
                    }
                    else if(ch>='a'&&ch<='f'){
                        continue;
                    }
                    else{              
                        cout<<"Idhar1"<<endl;     
                          return "Neither";
                    }
                 }
                


            }
            for(int i=0;i<pos.size()-1;i++){
                if(pos[i+1]-pos[i]==1){
                    cout<<"Idhar2"<<endl;
                    return "Neither";
                }
                if(pos[i+1]-pos[i]>5){
                    cout<<"Idhar3"<<endl;
                    return "Neither";
                }
            }
            int y=pos.back();
            int counter=0;
            while(y<queryIP.length()){
                counter++;
                y++;

            }
            cout<<counter<<endl;
            if(counter-1>4){
                return "Neither";
            }
        }
        return "IPv6";
        
    }
};