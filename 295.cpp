#include "LeetCodeBase.h"

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> heapMax; // 存小的部分
    priority_queue<int, vector<int>, greater<int>> heapMin; // 存大的部分
public:
    MedianFinder(){
        heapMax = priority_queue<int, vector<int>, less<int>>();
        heapMin = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num){
        if(heapMax.empty() && heapMin.empty()){
            heapMin.push(num);
        }else{
            if(!heapMin.empty() && heapMin.top() < num){
                heapMin.push(num);
            }else{
                heapMax.push(num);
            }
        }
    }

    double findMedian(){
        while(heapMax.size() > heapMin.size()){
            heapMin.push(heapMax.top());
            heapMax.pop();
        }
        while(heapMin.size() > heapMax.size() + 1){
            heapMax.push(heapMin.top());
            heapMin.pop();
        }
        
        if(heapMin.size() == heapMax.size()){
            return (heapMax.top() + heapMin.top()) / 2.0;
        }else{
            return heapMin.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder f;
    f.addNum(1);
    auto num = f.findMedian();
    f.addNum(2);
    num = f.findMedian();
    f.addNum(3);
    num = f.findMedian();
    return 0;
}