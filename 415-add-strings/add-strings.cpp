class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length()>num2.length()){
            while(num2.length()!=num1.length()){
                num2.insert(num2.begin(),'0');
            }
            
        }
        if(num2.length()>num1.length()){
            while(num1.length()!=num2.length()){
                num1.insert(num1.begin(),'0');
            }
            
        }
        
        
        if(num1.size()>1){
        for(int i=0;i<num1.size();i++){
            num1[i]=(num1[i]-'0'+num2[i]-'0')+'0';
        }
    }
        if(num1.size()>1){
        for(int i=num1.size()-1;i>=1;i--){
            if((num1[i]-'0')/10>=1){
                num1[i]=((num1[i]-'0')%10)+'0';
                num1[i-1]=(num1[i-1]-'0'+1)+'0';
            }
        }
        if(num1[0]-'0'>=10){
            num1[0]=(num1[0]-'0')%10+'0';
            num1.insert(num1.begin()+0,'1');
        }
        return num1;
        
    }
    int ans=(num1[0]-'0')+(num2[0]-'0');
    string a=to_string(ans);
    return a;
        
    }
};