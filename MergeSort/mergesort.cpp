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
    // The number of elements in the left and right halves of some_list
    int n = some_list.size();
    int n_left = mid - left + 1;
    int n_right = mid + 1 + right;

    // creating two vectors to store the 2 halves of some_list
    std::vector<T> left_subvector(n_left);
    std::vector<T> right_subvector(n_right);

    // copying the left half of the elements in some_list into left_subvector
    for (size_t i = 0; i < n_left; ++i)
        left_subvector[i] = some_list[i + left];

    // copying the right half of the elements in some_list into right_subvector
    for (size_t i = 0; i < n_right; ++i)
        right_subvector[i] = some_list[i + mid + 1];

    // Counters
    size_t i = 0;
    size_t j = 0;

    // Tracks where the current index is being modified while merging
    size_t curr_index = left;

    // Merging left_subvector and right_subvector back into some_list in ascending order
    while (i < n_left && j < n_right && curr_index < n)
    {
        // Current element in left_subvector is less than the current element in right_subvector
        // Make current index of some_list equal to the current left_subvector element
        if (left_subvector[i] <= right_subvector[j])
        {
            some_list[curr_index] = left_subvector[i];

            ++i;
            ++curr_index;
        }
        // Current element in right_subvector is less than the current element in left_subvector
        // Make current index of some_list equal to the current right_subvector element
        else
        {
            some_list[curr_index] = right_subvector[j];

            ++j;
            ++curr_index;
        }
    }

    // Adding left over items from left_subvector if any exist (when n_left > n_right)
    while (i < n_left)
    {
        some_list[curr_index] = left_subvector[i];

        ++i;
        ++curr_index;
    }

    // Adding left over items from right_subvector if any exist (when n_right > n_left) 
    while (j < n_right)
    {
        some_list[curr_index] = right_subvector[j];
        
        ++j;
        ++curr_index;
    }
}

template <typename T>
void mergeSort(std::vector<T> &some_list, int left, int right) 
{
    // Base case
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Resursively divide and conquering some_list into smaller halves to merge them in order in the next step
    mergeSort(some_list, 0, mid);
    mergeSort(some_list, mid + 1, right);

    // Modifies some_list to be in ascending order by merging the left and right halves of some_list
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