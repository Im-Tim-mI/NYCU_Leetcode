class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            if (source == target) return 0;
    
            unordered_map<int, vector<int>> stopToBuses;
            for (int i = 0; i < routes.size(); ++i) {
                for (int stop : routes[i])
                    stopToBuses[stop].push_back(i);
            }
    
            unordered_set<int> visitedStops;
            unordered_set<int> visitedBuses;
            queue<int> q;
            q.push(source);
            visitedStops.insert(source);
    
            int buses = 0;
            while (!q.empty()) {
                int sz = q.size();
                ++buses;
                for (int i = 0; i < sz; ++i) {
                    int stop = q.front(); q.pop();
                    for (int bus : stopToBuses[stop]) {
                        if (visitedBuses.count(bus)) continue;
                        visitedBuses.insert(bus);
                        for (int nextStop : routes[bus]) {
                            if (nextStop == target) return buses;
                            if (!visitedStops.count(nextStop)) {
                                visitedStops.insert(nextStop);
                                q.push(nextStop);
                            }
                        }
                    }
                }
            }
    
            return -1;
        }
    };
    