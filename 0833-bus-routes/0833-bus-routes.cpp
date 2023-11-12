class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stopToBuses;

        for (int busId = 0; busId < routes.size(); busId++) {
            for (int stop : routes[busId]) {
                stopToBuses[stop].push_back(busId);
            }
        }

        if (stopToBuses.find(source) == stopToBuses.end() || stopToBuses.find(target) == stopToBuses.end()) {
            return -1;
        }

        if (source == target) {
            return 0;
        }

        queue<int> q;
        unordered_set<int> busesTaken;
        unordered_set<int> stopsVisited;
        int res = 0;

        q.push(source);

        while (!q.empty()) {
            res++;
            int stopsToProcess = q.size();

            for (int i = 0; i < stopsToProcess; i++) {
                int currentStop = q.front();
                q.pop();

                for (int busId : stopToBuses[currentStop]) {
                    if (busesTaken.count(busId)) {
                        continue;
                    }

                    busesTaken.insert(busId);

                    for (int nextStop : routes[busId]) {
                        if (stopsVisited.count(nextStop)) {
                            continue;
                        }

                        if (nextStop == target) {
                            return res;
                        }

                        q.push(nextStop);
                        stopsVisited.insert(nextStop);
                    }
                }
            }
        }

        return -1;        
    }
};