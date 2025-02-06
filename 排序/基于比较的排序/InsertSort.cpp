// 插入排序
// 时间复杂度：O(N^2)
// 额外空间复杂度：O(1)
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr[j], arr[j + 1]);
        }
    }
}

void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    vector<int> arr = {8, 3, 2, 1, 8, 9};
    insertionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
