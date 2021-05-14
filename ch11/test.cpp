//
//  test.cpp
//
//  Created by Tang Chengming on 05/13/2021
//
//  @Brief

#include <iostream>

int lowerBound(int const *arr, int size, int target) {
    int left = 0;
    while (size > 0) {
        int mid = left + size / 2;
        if (arr[mid] < target) {
            left = mid + 1;
            size -= size / 2 + 1;
        }
        else {
            size = size / 2;
        }
    }
    return left;
}

int main() {
    int arr[6]{ 1, 2, 3, 4, 5, 6 };
    // 左边界
    std::cout << lowerBound(arr, 6, 1) << std::endl;
    // 右边界
    std::cout << lowerBound(arr, 6, 6) << std::endl;
    // 中间
    std::cout << lowerBound(arr, 6, 4) << std::endl;
    // 不存在
    std::cout << lowerBound(arr, 6, 7) << std::endl;
    // size 错误
    std::cout << lowerBound(arr, -1, 6) << std::endl;
    return 0;
}
