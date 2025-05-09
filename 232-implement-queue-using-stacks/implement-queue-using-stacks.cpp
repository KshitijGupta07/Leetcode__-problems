class MyQueue {
public:
stack<int>s;
stack<int>t;
    MyQueue() {
        
    }
    
    void push(int x) {
       s.push(x);

    }
    
    int pop() {
        if(t.empty()==false){
            int a=t.top();
            t.pop();
            return a;
            
        }
       while(s.empty()==false){
        t.push(s.top());
        s.pop();
       }
       int a=t.top();
       t.pop();
       return a;
    }
    
    int peek() {
       if(t.empty()==false){
        return t.top();
       }
       while(s.empty()==false){
        t.push(s.top());
        s.pop();
       }
       int a=t.top();
       return a;

    }
    
    bool empty() {
        return t.empty()&&s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */