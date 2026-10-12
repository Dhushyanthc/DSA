class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max.push(num);

        min.push(max.top());
        max.pop();

        if(max.size() < min.size()){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if(max.size() > min.size()){
            return max.top();
        }else if(max.size() < min.size()){
            return min.top();
        }else{
            return (max.top() + min.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */