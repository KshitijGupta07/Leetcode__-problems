class MyStack {
public:
    queue<int>q;
    queue<int>d;

    MyStack() {
        
    }
    
    void push(int x) {
        if(d.empty()==true){
            q.push(x);
        }
        else{
            d.push(x);
        }
    }
    
    int pop() {
        if(d.size()==0){
        while(q.size()>1){
            d.push(q.front());
            q.pop();
        }
        int a=q.front();
        
        q.pop();
        return a;
        }
        
        while(d.size()>1){
            q.push(d.front());
            d.pop();
        }
        int a=d.front();
        d.pop();
    
        return a;
    }
    
    int top() {
         if(d.size()==0){
        while(q.size()>1){
            d.push(q.front());
            q.pop();
        }
        int a=q.front();
        
        q.pop();
        d.push(a);
        return a;
        }
        
        while(d.size()>1){
            q.push(d.front());
            d.pop();
        }
        int a=d.front();
        d.pop();
        q.push(a);
    
        return a;
    }
    
    bool empty() {
        return q.empty()&&d.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */