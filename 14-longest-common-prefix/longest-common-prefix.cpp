class Solution {
public:
    struct Node{
        Node* link[26];
        bool isend=false;
           
        void insert(char ch,Node* node){
            link[ch-'a']=node;
        }
        bool contain(char ch){
            return link[ch-'a']!=NULL;
        }
        Node* get(char ch){
            return link[ch-'a'];
        }
        void setend(){
            isend=true;
        }
        bool getend(){
            return isend;
        }
    };
    
          
    
    string longestCommonPrefix(vector<string>& strs) {
        Node* trie=new Node();
        string ans=strs[0];

        
            Node* node=trie;
            for(int i=0;i<strs[0].length();i++){
                if(node->contain(strs[0][i])==false){
                    node->insert(strs[0][i],new Node());
                }
                node=node->get(strs[0][i]);
            }
            int len=0;
             
            
            for(int i=1;i<strs.size();i++){
                string temp="";
                Node* node=trie;
                for(int j=0;j<strs[i].length();j++){
                    
                     if(node->contain(strs[i][j])){
                        node=node->get(strs[i][j]);
                        temp.push_back(strs[i][j]);
                             
                     }
                     else{
                        break;
                     }
                }
                if(ans.length()>=temp.length()){
                ans=temp;
                }
            }

        if(strs.size()==1){
            return strs[0];
        }
        return ans;
    }
};