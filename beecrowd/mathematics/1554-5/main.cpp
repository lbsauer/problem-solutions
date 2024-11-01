// https://judge.beecrowd.com/en/problems/view/1554
// 2024/06/15

#include <bits/stdc++.h>

int main(void) {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;

    for (int i = 0; i < c; ++i) {
        int n;
        std::cin >> n;

        int wx, wy;
        std::cin >> wx >> wy;

        double min_dist = INT_MAX;
        int ball;

        for (int j = 0; j < n; ++j) {
            int x, y;
            std::cin >> x >> y;

            double dist = std::sqrt((wx - x) * (wx - x) + (wy - y) * (wy - y));

            if (dist < (min_dist - 0.01)) {
                min_dist = dist;
                ball = j + 1;
            }
        }

        std::cout << ball << '\n';
    }

    return 0;
}