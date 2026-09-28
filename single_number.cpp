#include <iostream>

// 相同数字异或后为 0，0 与任何数字异或仍是该数字。
int singleNumber(const int nums[], int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    const int example1[] = {2, 2, 1};
    const int example2[] = {4, 1, 2, 1, 2};

    // sizeof 求出数组中的元素个数。
    std::cout << singleNumber(example1, sizeof(example1) / sizeof(example1[0])) << '\n';
    std::cout << singleNumber(example2, sizeof(example2) / sizeof(example2[0])) << '\n';
    return 0;
}
