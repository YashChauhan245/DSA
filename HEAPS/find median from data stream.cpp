https://leetcode.com/problems/find-median-from-data-stream/description/

BRUTE:TLE
class MedianFinder {
public:
    vector<int> vec;
    int i = 0;
    MedianFinder() {
        // GIVEN SIZE
        vec.resize(5*10000+1);
    }
    
    void addNum(int num) {
        if(i == 0) {
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] > num) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;
        if(n%2 == 0) {
            int l = n/2-1;
            int r = n/2;
            return (float)(vec[l]+vec[r])/2;
        }
        
        return vec[n/2];
    }
};


OPTIMISED:
class MedianFinder {
public:
    priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
    }
    
    void addNum(int num) {
        // left heap is empty or arr[i]<st.top -->push in left else in right
        if(left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        
        //always maintain left_max_heap size one greater than rigfht_min_heap size
        //ya fir, dono ka size equal ho
        // **if diff is greater than 1 to left se right dalo
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
    // else right se left push 
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }   
    }


    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            // matlab even number of elements hue honge  
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        } 
        //else hamare paas odd number of elemenes hue honge
        return left_max_heap.top();
    }
};

