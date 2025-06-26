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
class Trie {
public:
     Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->contain(word[i])==false){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->contain(word[i])==false){
                return false;
            }
        node=node->get(word[i]);
        }
        return node->getend();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(node->contain(prefix[i])==false){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */