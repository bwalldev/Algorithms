#include <iostream>
#include <vector>
#include <memory>

void removeDuplicates(std::vector<int> &nums) {
    if (!nums.empty()) {
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

void printVector(const std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); i++)
        if (i < nums.size() - 1)
            std::cout << nums[i] << ", ";
        else
            std::cout << nums[i] << std::endl;
}

int main(int argc, char *args[]) {
    std::vector<int> test_vector = {1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 8, 9, 10, 11, 11};
 
    std::cout << "Before removing duplicates: ";

    printVector(test_vector);

    std::cout << "\nAfter removing duplicates: ";

    removeDuplicates(test_vector);

    printVector(test_vector);

    return 0;
}