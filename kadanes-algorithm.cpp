#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    code int num_tests;
    cin >> num_tests;
    int t, n;

    while (num_tests--) {
        int max_el{-1000000};
        int vec_size;
        cin >> vec_size;
        vector<int> vec;

        for (int i = 0; i < vec_size; ++i) {
            int el;
            cin >> el;

            vec.push_back(el);
        }

        for (int i = 0; i < vec_size; ++i) {
            auto sorted_end = is_sorted_until(vec.begin(), vec.end());
            int sum = accumulate(begin(vec), sorted_end, 0);
            max_el = max(max_el, sum);
            rotate(vec.begin(), vec.begin() + 1, vec.end());
        }
        cout << max_el << endl;
    }

    return 0;
}
