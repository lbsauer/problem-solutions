// https://leetcode.com/problems/traffic-signal-color
// 2026/08/16

class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0) return "Green";
        if (timer == 30) return "Orange";
        return timer > 30 && timer <= 90 ? "Red" : "Invalid";
    }
};