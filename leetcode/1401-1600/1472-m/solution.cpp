// https://leetcode.com/problems/design-browser-history
// 2026/02/13

class BrowserHistory {
    size_t pos;
    vector<string> history;

public:
    BrowserHistory(string homepage) : pos(), history(1) {
        history[0] = move(homepage);
    }
    
    void visit(string url) {
        if (++pos == history.size()) {
            history.emplace_back(move(url));
        } else {
            history.resize(pos + 1);
            history[pos] = move(url);
        }
    }
    
    string back(int steps) {
        pos = steps > pos ? 0 : pos - steps;
        return history[pos];
    }
    
    string forward(int steps) {
        pos = min(history.size() - 1, pos + steps);
        return history[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */