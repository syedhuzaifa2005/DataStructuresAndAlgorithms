#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<pair<int, int>> heap;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left].first > heap[largest].first) {
            largest = left;
        }

        if (right < heap.size() && heap[right].first > heap[largest].first) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heap[parent].first < heap[i].first) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

public:
    void push(pair<int, int> value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    pair<int, int> top() {
        return heap[0];
    }

    void pop() {
        swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }
};

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    vector<int> result;
    MaxHeap maxHeap;

    for (int i = 0; i < nums.size(); i++) {
        maxHeap.push({nums[i], i});

        while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }

        if (i >= k - 1) {
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMaximum(nums, k);
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
