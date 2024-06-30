class MyCircularQueue {
public:
    int f;  //front
    int b;  //back
    int size;   
    vector<int> arr;
    int c;  //capacity
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        size = 0;
        vector<int> v(k);
        arr = v;
        c = k;
    }
    
    bool enQueue(int val) {   //push_back
        if (size == c)  return false;
        arr[b] = val;
        b++;
        if(b==c)    b = 0;
        size++;
        return true;
    }
    
    bool deQueue() {    //pop_front
        if(size==0)    return false;
        f++;
        if(f==c)    f = 0;
        size--;
        return true;
    }
    
    int Front() {
        if(size==0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(size==0) return -1;
        else{
            if(b==0)    return arr[c-1];
            else return arr[b-1];
        }
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==c);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */