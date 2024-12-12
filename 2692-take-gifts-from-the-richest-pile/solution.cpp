class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        long long total_gifts = accumulate(gifts.begin(), gifts.end(), 0LL);
        cout << total_gifts << endl;
        long long total_gifts_taken = 0;

        for (int i = 0; i < k; i++) {
            pop_heap(gifts.begin(), gifts.end());
            int biggest = gifts.back();
            gifts.pop_back();
            int remaining = floor(sqrt(biggest));
            total_gifts_taken += (biggest - remaining);

            gifts.push_back(remaining);
            push_heap(gifts.begin(), gifts.end());
        }

        return total_gifts - total_gifts_taken;
    }
};
