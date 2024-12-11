#include <iostream>
#include <vector>
#include <set>

int removeDuplicates(std::vector<int> &nums) {
    std::set<int> st;
    for (int num : nums) {
        st.insert(num);
    }
    nums.assign(st.begin(), st.end());
    return nums.size();
}

int main() {
    int n;
    std::cout << "Enter the size of array: ";
    std::cin >> n;
    
    std::vector<int> nums;
    nums.reserve(n); // Reserve space to avoid reallocations
    std::cout << "Enter the elements of array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }
    
    int newSize = removeDuplicates(nums);
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
