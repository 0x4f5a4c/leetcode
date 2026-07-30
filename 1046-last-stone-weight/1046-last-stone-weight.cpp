class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int x : stones) heap.push(x);
        while (heap.size() > 1) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();

            if (x != y) {
                heap.push(x-y);
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};