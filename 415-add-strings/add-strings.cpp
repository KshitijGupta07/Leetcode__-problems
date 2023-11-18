class Solution {
public:
    void addRE(string &num1,string &num2,int p1,int p2,string &ans,int carry=0){
        //ek case solve karna
        if(p1<0&&p2<0){
            if(carry!=0){
                ans.push_back(carry+'0');
            }
            return ;
        }
        int n1=(p1>=0 ? num1[p1]:'0')-'0';
        int n2=(p2>=0 ? num2[p2]: '0')-'0';
        int currentsum=n1+n2+carry;
         carry=currentsum/10;
        int digit=currentsum%10;
    
        ans.push_back(digit+'0');
        addRE(num1,num2,p1-1,p2-1,ans,carry);
       
    }
    string addStrings(string num1, string num2) {
        //recursively
        string ans="";
        addRE(num1,num2,num1.size()-1,num2.size()-1,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};