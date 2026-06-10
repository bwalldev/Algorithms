////////////////////////////////////////////////////////////////////////
//
//                         MERGE SORT ALGORITHM
//   ---------------------------------------------------------------      
//   Description: A divide and conquer algorithm that recursively
//                divides a list into n subarrays of length 1. Then
//                the algorithm recursively sorts them and merges back 
//                into a sorted list in ascending order.  
// 
//   Time Complexity: O(n * log(n)) 
//
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &some_list, int left, int mid, int right)
{
    int n_left = mid - left + 1;
    int n_right = mid + 1 + right;

    std::vector<T> left_subvector(n_left);
    std::vector<T> right_subvector(n_right);

    for (size_t i = 0; i < n_left; ++i)
        left_subvector[i] = some_list[i + left];

    for (size_t i = 0; i < n_right; ++i)
        right_subvector[i] = some_list[i + mid + 1];

    size_t i = 0;
    size_t j = 0;
    size_t L = left;

    while (i < n_left && j < n_right)
    {
        if (left_subvector[i] <= right_subvector[j])
        {
            some_list[L] = left_subvector[i];
            ++i;
            ++L;
        }
        else
        {
            some_list[L] = right_subvector[j];
            ++j;
            ++L;
        }
    }

    while (i < n_left)
    {
        some_list[L] = left_subvector[i];
        ++i;
        ++L;
    }

    while (j < n_right)
    {
        some_list[L] = right_subvector[j];
        ++j;
        ++L;
    }
}

template <typename T>
void mergeSort(std::vector<T> &some_list, int left, int right) 
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(some_list, 0, mid);
    mergeSort(some_list, mid + 1, right);
    merge(some_list, left, mid, right);
}

template <typename T>
void printList(const std::vector<T> &some_list)
{
    size_t i = 0;

    while (i < some_list.size() - 1)
    {
        std::cout << some_list[i] << ", ";
        ++i;
    }

    std::cout << some_list[i] << "\n";
}

int main()
{
    std::vector<int> nums = {4,7,4,2,9,8,4,6,8,1};

    std::cout << "The list before mergeSort():\n";

    printList(nums);

    mergeSort(nums, 0, nums.size());

    std::cout << "\nThe list after mergeSort():\n";

    printList(nums);
}