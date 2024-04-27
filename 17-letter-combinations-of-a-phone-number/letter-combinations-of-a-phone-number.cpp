class Solution {
public:
void combination(string &digits,string output,int index,vector<string>&ans,vector<string>& mapping){
    if(index>=digits.length()){
       ans.push_back(output);
       return;
    }
    cout<<index<<endl;
    string a=mapping[digits[index]-'0'];
    for(int i=0;i<a.length();i++){
        output.push_back(a[i]);
        combination(digits,output,index+1,ans,mapping);
        output.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        int index=0;
        if(digits.length()==0){
            return ans;
        }
        vector<string>mapping{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        combination(digits,output,index,ans,mapping);
        return ans;
    }
};