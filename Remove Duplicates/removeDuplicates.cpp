// Simple algorithm to remove duplicate int values from a vector 

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_set>

// DOESN'T keep the orginal vector order
void removeDuplicates(std::vector<int> &nums) {
    if (!nums.empty()) {
        std::sort(nums.begin(), nums.end());

        std::unique_ptr<int> prev = nullptr;

        std::vector<int> tmp;

        for (const int num : nums) {
            if (prev) {
                if (*prev != num) {
                    tmp.push_back(num);
                    *prev = num;
                }
            }
            else 
            {
                tmp.push_back(num);
                prev = std::make_unique<int>(num);
            }
        }

        nums.clear();

        nums = tmp;
    }
}

// KEEPS the original vector order
void removeDuplicatesKeepOrder(std::vector<int> &nums) {
    std::vector<int> tmp;
    std::unordered_set<int> seen;

    for (const int num : nums) {
        if (seen.find(num) == seen.end()) {
            tmp.push_back(num);
            seen.insert(num);
        }
    }

    nums = tmp;
}

void printVector(const std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); i++)
        if (i < nums.size() - 1)
            std::cout << nums[i] << ", ";
        else
            std::cout << nums[i] << std::endl;
}

int main(int argc, char *args[]) {
    std::vector<int> test_vector = {2,2,2,2,2,1,5,3,7,1,4,8,6,7,10,9,10};
 
    std::cout << "Before removing duplicates: ";

    printVector(test_vector);

    std::cout << "\nAfter removing duplicates: ";

    removeDuplicatesKeepOrder(test_vector);

    printVector(test_vector);

    return 0;
}