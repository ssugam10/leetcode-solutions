class MedianFinder {
public:
    priority_queue<int> maxHeap;    //will be the one holding the first median
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int minSize;
    int maxSize;

    MedianFinder() {
        minSize = 0;
        maxSize = 0;
    }
    
    void addNum(int num) {
        if(maxSize == 0){
            maxHeap.push(num);
            maxSize++;
        }
        else if(num <= maxHeap.top()){
            maxHeap.push(num);
            maxSize++;
        }
        else{
            minHeap.push(num);
            minSize++;
        }


        if(maxSize > minSize + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            minSize++;
            maxSize--;
        }

        else if(minSize > maxSize){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxSize++;
            minSize--;
        }
    }
    
    double findMedian() {
        
        if((maxSize + minSize) % 2 == 0){
            // cout<<maxHeap.top()<<"   "<<minHeap.top()<<endl;
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        else{
            // cout<<endl;
            // cout<<maxHeap.top()<<endl;
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */