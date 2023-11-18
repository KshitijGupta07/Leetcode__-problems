class Solution {
public:
    string addRE(string num1,string num2,int p1,int p2,int carry=0){
        //ek case solve karna
        if(p1<0&&p2<0){
            if(carry!=0){
                return string(1,carry+'0');
            }
            return "";
        }
        int n1=(p1>=0 ? num1[p1]:'0')-'0';
        int n2=(p2>=0 ? num2[p2]: '0')-'0';
        int currentsum=n1+n2+carry;
         carry=currentsum/10;
        int digit=currentsum%10;
        string ans="";
        ans.push_back(digit+'0');
       ans+= addRE(num1,num2,p1-1,p2-1,carry);
       return ans;
    }
    string addStrings(string num1, string num2) {
        //recursively
        string ans=addRE(num1,num2,num1.size()-1,num2.size()-1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};