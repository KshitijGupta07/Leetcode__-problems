class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>g;
    
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
    
           
        if(p.empty()){
           p.push(num); 
          
        }
        else{
           if(num>p.top()){
            g.push(num);
           }
           else{
            p.push(num);
           }
        }
        

          
    }

    
    double findMedian() {
        int a=p.size()-g.size();
        if(p.size()==g.size()){
            double a=p.top();
            double b=g.top();
            return (a+b)/2.00;
        }
        else if(g.size()-p.size()==1){
            return g.top()/1.00;
        }
        else if(p.size()-g.size()==1){
            return p.top()/1.00;
        }
        
        else if(p.size()>g.size()){
           
            while(p.size()-g.size()>1){
                g.push(p.top());
                p.pop();
            }
            
            if(p.size()==g.size()){
                  double a=p.top();
            double b=g.top();
            return (a+b)/2.00;
            }
    
                else if(g.size()-p.size()==1){
            return g.top()/1.00;
        }
        else if(p.size()-g.size()==1){
            return p.top()/1.00;
        }

        }
        else if(g.size()>p.size()){
               while(g.size()-p.size()>1){
                p.push(g.top());
                g.pop();
            }
            if(p.size()==g.size()){
                  double a=p.top();
            double b=g.top();
            return (a+b)/2.00;
            }
          else if(g.size()-p.size()==1){
            return g.top()/1.00;
        }
        else if(p.size()-g.size()==1){
            return p.top()/1.00;
        }
    
        
        }
        
        return -1.0000;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */