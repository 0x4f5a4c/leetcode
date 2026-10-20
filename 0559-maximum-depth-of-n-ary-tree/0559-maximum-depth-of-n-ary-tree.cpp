// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔


#include <bits/stdc++.h>
using namespace std;

// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Solution {
public:
    int maxDepth(Node* root) {
        // using level order traversal
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth += 1;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                for (auto child : node->children)
                    if (child) q.push(child);
            }
        }
        return depth;
    }
    
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();