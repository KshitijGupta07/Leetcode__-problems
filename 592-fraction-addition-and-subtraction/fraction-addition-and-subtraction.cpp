class Solution {
public:
   int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a>0&&b>0){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
   }
   string addfraction(string a,string b){
    int n1=0;
    int n2=0;
    int d1=0;
    int d2=0;
       int x=a.find('/')-1;
       int i=0;
       int k=1;
       cout<<x<<endl;
       while(x>0){
        
          n1=n1+(a[x]-'0')*pow(10,i);
          i++;
          x--;
       }
      if(a[0]=='-'){
        n1=-n1;
      }
       int l=a.length()-1;
       i=0;
       
       while(l>a.find('/')){
          d1=d1+(a[l]-'0')*pow(10,i);
          i++;
          l--;
       }
       
       x=b.find('/')-1;
       i=0;
          while(x>0){
          n2=n2+(b[x]-'0')*pow(10,i);
          i++;
          x--;
       }
       if(b[0]=='-'){
        n2=-n2;
       }
       i=0;
       l=b.length()-1;
       while(l>b.find('/')){
        d2=d2+(b[l]-'0')*pow(10,i);
        i++;
        l--;
       }


    
      int d=d1*d2;
      int n=n1*d2+n2*d1;

      int c=gcd(abs(n),abs(d));


       n=n/c;
       d=d/c;
       string ans="";
       if(n>=0){
        ans+="+";
       }
        ans+=to_string(n)+"/"+to_string(d);
       return ans;

   }
    string fractionAddition(string expression) {
        vector<string>ans;
        
        string element="";
      int  i=1;
        if(expression[0]=='-'){
            element.push_back('-');
        }
        else{
            element.push_back('+');
            element.push_back(expression[0]);
    
        
        }
         for( i=1;i<expression.length();i++){
            if(expression[i]=='/'){
                element.push_back('/');
                break;
            }
            else{
                element.push_back(expression[i]);
            }
        }
        int v=0;
        for(int j=i+1;j<expression.length();j++){
            if(expression[j]=='+'||expression[j]=='-'){
                break;
            }
            else{
                element.push_back(expression[j]);
                v++;
            }
        }
        cout<<i+v<<endl;
        ans.push_back(element);
        int k=i+v+1;
         while(k<expression.length()){
             element="";
           while(k<expression.length()&&expression[k]!='/'){
            element.push_back(expression[k]);
            k++;
           }
           while(k<expression.length()&&expression[k]!='+'&&expression[k]!='-'){
            element.push_back(expression[k]);
            k++;
           }
           ans.push_back(element);
     }
     if(ans.size()==1){
        if(ans[0][0]=='+'){
            ans[0].erase(ans[0].begin());
        }
        return ans[0];
     }
     string f=addfraction(ans[0],ans[1]);
     cout<<f<<endl;
     for(int i=2;i<ans.size();i++){
        f=addfraction(ans[i],f);
     }
       if(f[0]=='+'){
        
        f.erase(f.begin());
       }
        return f;
    }
};