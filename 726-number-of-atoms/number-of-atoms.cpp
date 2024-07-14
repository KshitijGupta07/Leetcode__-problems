class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>>st;
        int n=formula.length();
        int i,j,k;
        for(i=0;i<n;i++){
            
            char curr=formula[i];
            cout<<i<<" ";
            
            if(isupper(curr)){
                string a="";
                a.push_back(curr);
                for( j=i+1;j<n;j++){
                    cout<<j<<" ";
                     curr=formula[j];
                    if(islower(curr)==false){
                        break;
                    }
                    a+=curr;
                }
                string digit="";
                
                for(k=j;k<n;k++){
                    cout<<k<<" ";
                    curr=formula[k];
                    if(isdigit(curr)==false){
                        break;
                    }
                    digit+=curr;
                }
            
                if(digit==""){
                     digit="1";
                }
                int digits=stoi(digit);
                st.push({a,digits});
                i=k-1;
            }
            else if(curr=='('){
                st.push({"(",-1});
            }
            else if(curr==')'){
               string digit="";
                for( j=i+1;j<n;j++){
                   char ch=formula[j];
                     if(isdigit(ch)==false){
                        break;
                     }
                     digit+=ch;
                }
                if(digit=="")digit="1";
                int digits=stoi(digit);
                vector<pair<string,int>>temp;
                pair<string,int>p={"(",-1};
                while(st.empty()==false&&st.top()!=p){
                     temp.push_back({st.top().first,st.top().second*digits});
                     st.pop();
                }
                st.pop();
                while(temp.size()>0){
                    st.push(temp[temp.size()-1]);
                    temp.pop_back();
                }
                i=j-1;
            }
        }
        map<string,int>mpp;
        vector<pair<string,int>>temp;
        while(st.empty()==false){
            mpp[st.top().first]+=st.top().second;
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(),temp.end());
        string ans="";
        for(auto v:mpp){
            for(auto x:v.first){
                ans+=x;
            }
            string t=to_string(mpp[v.first]);
            if(t!="1"){
            for(auto y:t){
                
                ans+=y;
            }
            }
        }
        return ans;
    }
};