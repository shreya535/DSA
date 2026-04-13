class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
    
        for (auto &o : overlaps) {
            if (max(startTime, o.first) < min(endTime, o.second)) {
                return false;
            }
        }

        // Step 2: Update overlaps
        for (auto &b : bookings) {
            int s = max(startTime, b.first);
            int e = min(endTime, b.second);

            if (s < e) {
                overlaps.push_back({s, e});
            }
        }

        
        bookings.push_back({startTime, endTime});
        return true;
    }
};
