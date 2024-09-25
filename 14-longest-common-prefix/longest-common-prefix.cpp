class trienode{
    public:
     char ch;
     trienode* children[26];
     bool isend;
     trienode(char data){
        ch=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isend=false;
     }
};
     class trie{
    public:
    trienode* root;
    trie(){
        root=new trienode('0');
    }
     void insertit(trienode* root,string word){
            if(word.length()==0){
                root->isend=true;
                return;
            }
            int index=word[0]-'a';
            trienode*child;
            if(root->children[index]==NULL){
                 child=new trienode(word[0]);
                 root->children[index]=child;
            }
            else{
                child=root->children[index];
            }
            insertit(child,word.substr(1));

        }
        void insert(string word){
            insertit(root,word);
        }
        void prefix(trienode* root,string &ans){
            
            if(root->isend){
                return ;
            }
            cout<<ans<<endl;
            int count=0;
            trienode* child;
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    child=root->children[i];
                     count++;
                }
            }
            if(count>1){
                return;
            }
            else{
                
                ans.push_back(child->ch);
            }
             prefix(child,ans);

        }
        void find(string &ans){
             prefix(root,ans);
        }

};
        


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie* t=new trie();
        for(auto j:strs){
            t->insert(j);
        }
        string ans="";
        t->find(ans);
        return ans;
    }
};