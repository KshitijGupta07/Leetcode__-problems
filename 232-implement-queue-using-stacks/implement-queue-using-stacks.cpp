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
        while(s.size()>1){
            t.push(s.top());
            s.pop();
        }
        int a=s.top();
        s.pop();
        while(t.empty()==false){
            s.push(t.top());
            t.pop();
        }
        return a;
        
    }
    
    int peek() {
        while(s.size()>1){
            t.push(s.top());
            s.pop();
        }
        int a=s.top();
        while(t.empty()==false){
            s.push(t.top());
            t.pop();
        }
        return a;

    }
    
    bool empty() {
        return s.empty();
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