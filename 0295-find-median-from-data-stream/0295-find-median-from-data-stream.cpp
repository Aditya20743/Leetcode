class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int , vector<int> , greater<int> > min_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(max_heap.empty() || max_heap.top() > num){
            max_heap.push(num);
        }
        else if(max_heap.top()<= num){
            min_heap.push(num);
        }
        
        if(max_heap.size() > min_heap.size() + 1 ){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size()== min_heap.size()){
            return (1.0*max_heap.top() + 1.0*min_heap.top())/2;
        }
        // else if(max_heap.size()> min_heap.size()){
        //     return 1.0*max_heap.top();
        // }
        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */