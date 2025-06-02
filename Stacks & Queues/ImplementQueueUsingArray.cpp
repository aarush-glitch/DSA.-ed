int SIZE=10;

class QImpl {
    int start=-1, end=-1, curSize=0;
    int q[SIZE];
    
    bool push(int x) {
        if(curSize>=SIZE) {
            cout << "Overflow" << endl;
            return false;
        }
        if(curSize==0) {
            start=0, end=0;
        }
        else end = (end+1)%SIZE;
        q[end] = x;
        curSize++;
        return true;
    }
    
    bool pop() {
        if(curSize==0) {
            cout << "Queue Empty" << endl;
            return false;
        }
        if(curSize==1) {
            start=-1, end=-1;
        }
        else start = (start+1)%SIZE;
        curSize-=1;
        return true;
    }

    int front() {
        if(curSize==0) {
            cout << "Queue Empty" << endl;
            return -1;
        }
        else {
            return q[start];
        }
    }
    
    int size() {
        return curSize;
    }
};
