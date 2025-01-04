
class FrontMiddleBackQueue {
    deque<int> queue;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        queue.push_front(val);
    }

    void pushMiddle(int val) {
        int mid = queue.size() / 2;
        queue.insert(queue.begin() + mid, val);
    }

    void pushBack(int val) {
        queue.push_back(val);
    }

    int popFront() {
        if (queue.empty()) return -1;
        int val = queue.front();
        queue.pop_front();
        return val;
    }

    int popMiddle() {
        if (queue.empty()) return -1;
        int mid = (queue.size() - 1) / 2;
        int val = queue[mid];
        queue.erase(queue.begin() + mid);
        return val;
    }

    int popBack() {
        if (queue.empty()) return -1;
        int val = queue.back();
        queue.pop_back();
        return val;
    }
};
