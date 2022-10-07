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