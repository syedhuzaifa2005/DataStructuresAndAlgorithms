#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MinHeap {
private:
    vector<ListNode*> heap;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left]->val < heap[smallest]->val) {
            smallest = left;
        }

        if (right < heap.size() && heap[right]->val < heap[smallest]->val) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heap[parent]->val > heap[i]->val) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

public:
    void push(ListNode* node) {
        heap.push_back(node);
        heapifyUp(heap.size() - 1);
    }

    ListNode* top() {
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

ListNode* mergeKSortedLists(vector<ListNode*>& lists) {
    MinHeap minHeap;

    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();

        tail->next = node;
        tail = tail->next;

        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy->next;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* mergedList = mergeKSortedLists(lists);

    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }

    return 0;
}
