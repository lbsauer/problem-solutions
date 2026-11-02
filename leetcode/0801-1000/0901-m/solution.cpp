// https://leetcode.com/problems/online-stock-span
// 2026/02/13

class StockSpanner {
    stack<pair<int, int>, vector<pair<int, int>>> s; 

public:
    StockSpanner() {}
    
    int next(int price) {
        int days = 1;
        while (!s.empty() && s.top().first <= price) {
            days += s.top().second;
            s.pop();
        }

        s.emplace(price, days);

        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */