class ExamRoom {
    int N;
    set<int> seats;

public:
    ExamRoom(int n) : N(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int prev = -1, maxDist = 0, bestSeat = 0;

        for (int s : seats) {
            if (prev == -1) {
                if (s != 0 && s > maxDist) {
                    maxDist = s;
                    bestSeat = 0;
                }
            } else {
                int d = (s - prev) / 2;
                if (d > maxDist) {
                    maxDist = d;
                    bestSeat = prev + d;
                }
            }
            prev = s;
        }

        if (N - 1 - *seats.rbegin() > maxDist) {
            bestSeat = N - 1;
        }

        seats.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};
