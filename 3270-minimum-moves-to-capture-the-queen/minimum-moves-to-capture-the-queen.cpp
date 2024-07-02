class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e||b==f){
            if(a==c){
            if(d>min(b,f)&&d<max(b,f)){
                return 2;
            }
            }
              if(b==d){
            if(c>min(a,e)&&c<max(a,e)){
                return 2;
            }
              }
              return 1;
        }
        else if(abs(c-e)==abs(d-f)){
            if(abs(a-c)==abs(b-d)&&abs(a-e)==abs(b-f)){
                if(a>min(c,e)&&a<max(c,e)){
                    return 2;
                }
            }
            return 1;
        }
        return 2;
    }
};