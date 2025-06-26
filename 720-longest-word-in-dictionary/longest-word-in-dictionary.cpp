class Solution {
public:
    struct Node{
       Node* links[26];
       bool isend=false;

       bool contain(char ch){
          return links[ch-'a']!=NULL;
       }
       void put(char ch,Node* node){
        links[ch-'a']=node;
       }
       Node* get(char ch){
        return links[ch-'a'];
       }
       void setend(){
        isend=true;
       }
       bool getend(){
        return isend;
       }
    };
    class TrieNode{
        public:
        Node* root;
        TrieNode(){
            root=new Node();
        }
        void insert(string &word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(node->contain(word[i])==false){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setend();
        }
        bool check(string &word){
            Node* node=root;
            
            for(int i=0;i<word.length();i++){
                 if(node->contain(word[i])){
                    node=node->get(word[i]);
                 }
                 else{
                    return false;
                 }
            }
            return node->getend();
        }
    };
    string longestWord(vector<string>& words) {
        vector<string>temp;
        TrieNode* te=new TrieNode();
        int maxi=0;
        for(int i=0;i<words.size();i++){
           te->insert(words[i]);

        }
        for(int i=0;i<words.size();i++){
             string t="";
            bool signal=false;
            for(int j=0;j<words[i].length();j++){
                   t.push_back(words[i][j]);
                   
                   if(te->check(t)==false){
                    signal=true;
                    break;
                   }
            }
            if(signal==false){
                int a=t.length();
               maxi=max(maxi,a);
                temp.push_back(t);
            }
        }
        sort(temp.begin(),temp.end());
        for(auto j:temp){
             if(j.length()==maxi){
                return j;
             }
        }
        return "";
    }
};