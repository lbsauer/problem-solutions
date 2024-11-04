// https://leetcode.com/problems/frequency-tracker
// 2024-11-02

class FrequencyTracker {
    unordered_map<int, int> freq;
    unordered_map<int, int> nums;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        --freq[nums[number]];
        ++freq[++nums[number]];
    }
    
    void deleteOne(int number) {
        if (nums[number] == 0) return;
        
        --freq[nums[number]];
        ++freq[--nums[number]];
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */