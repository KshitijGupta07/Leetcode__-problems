class LRUCache {
public:
   class Node{
      public:
      int key;
      int val;
      Node* left;
      Node* right;
      Node(int key,int val){
        this->key=key;
        this->val=val;
      }
   };
   int count=0;
   map<int,Node*>m;
   Node* head=new Node(-1,-1);
   Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        count=capacity;
        head->right=tail;
        tail->left=head;
    }
    
    int get(int key) {
      if(m.find(key)==m.end()){
        return -1;
      }
      Node* curr=m[key];
       remove(curr);
       insert(curr);
       return curr->val;
    }
    void insert(Node* node){
        Node* temp=head->right;
        head->right=node;
        node->right=temp;
        temp->left=node;
        node->left=head;
        
    }
    void remove(Node* node){
        Node* temp=node->right;
        node->right=NULL;
        Node* temp2=node->left;
        node->left=NULL;
        temp2->right=temp;
        temp->left=temp2;
    }
    void put(int key, int value) {
         if(m.find(key)!=m.end()){
            Node* x=m[key];
            m.erase(key);
            remove(x);
         }
         if(m.size()==count){
            m.erase(tail->left->key);
             remove(tail->left);
         }
         insert(new Node(key,value));
         m[key]=head->right;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */