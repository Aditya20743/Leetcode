class MyQueue {
public:
    stack<int> s;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while( s.size()>1){
            temp.push(s.top());
            s.pop();
        }
        int res= s.top();
        s.pop();
        
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        
        return res;
    }
    
    int peek() {
        while( s.size()>1){
            temp.push(s.top());
            s.pop();
        }
        int res= s.top();
        
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        
        return res;
    }
    
    bool empty() {
        return s.size()==0;
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