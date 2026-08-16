class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx = target[0];
        int ty = target[1];

        int best_idx = -1;
        int best_dist = INT_MAX;

        for (int i = 0; i < drones.size(); ++i) {
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(x - tx) + abs(y - ty);
            if (dist <= range && dist < best_dist) {
                best_dist = dist;
                best_idx = i;
            }
        }

        return best_idx;
    }
};