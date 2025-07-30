class MedianFinder {
public:
 priority_queue<int>p;
        priority_queue<int,vector<int>,greater<int>>q;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(q.empty()==true){
            q.push(num);
        }
        else{
            if(q.top()>num){
                p.push(num);
            }
            else{
                q.push(num);
            }
        }
    }
    
    double findMedian() {
        if(p.size()==q.size())return double(p.top()+q.top())/2.00;
        else if(p.size()-1==q.size()){
            
                return p.top()/1.000;
            
        }
        else if(q.size()-1==p.size()){
            
                return q.top()/1.000;
            
        }
        else{
            if(p.size()>q.size()){
                while(p.size()-q.size()>1){
                    q.push(p.top());
                    p.pop();
                }
                
            }
            else{
               while(q.size()-p.size()>1){
                    p.push(q.top());
                    q.pop();
                } 
        
            }
                     if(p.size()==q.size())return double(p.top()+q.top())/2.00;
        else if(p.size()-1==q.size()){
            
                return p.top()/1.000;
            
        }
        else if(q.size()-1==p.size()){
            
                return q.top()/1.000;
            
            
        }

        }
            

        
        return 0.000;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */