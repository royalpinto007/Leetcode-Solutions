class MyCalendarThree {
private:
    map<int, int> diff;

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        int cur = 0, res = 0;
        diff[start]++;
        diff[end]--;
        for (auto& [_, delta] : diff) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

/*
class MyCalendarThree {
private:
    unordered_map<int, int> vals;
    unordered_map<int, int> lazy;

public:
    MyCalendarThree() {}

    void update(int start, int end, int left, int right, int idx) {
        if (start > right || end < left) return;
        if (left >= start && right <= end) {
            lazy[idx]++;
            vals[idx]++;
        } else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);
            vals[idx] = lazy[idx] + max(vals[idx * 2], vals[idx * 2 + 1]);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 1, 1000000000, 1);
        return vals[1];
    }
};
*/

/*
class MyCalendarThree {
private:
    map<int, int> starts;
    int res;

public:
    MyCalendarThree() {
        starts[0] = 0, starts[1e9 + 1] = 0;
        res = 0;
    }
    void split(int x) { starts[x] = (--starts.upper_bound(x))->second; }
    int book(int start, int end) {
        split(start), split(end);
        for (auto it = starts.find(start); it->first < end; it++) {
            res = max(res, ++(it->second));
        }
        return res;
    }
};
*/