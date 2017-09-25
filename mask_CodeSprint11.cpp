#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* Function to get no of set bits in binary
   representation of passed binary no. */
unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

bool check(vector<int> &nums, int mask) {
    // cout << "Checking mask: " << mask << endl;
    for (int i = 0; i < nums.size(); ++i) {
        // cout << nums[i] << " and " << mask << " = " << (nums[i] & mask) << endl;
        if (nums[i] & mask) {
            
        }
        else {
            return false;
        }
    }
    return true;
}

int solve(vector<int> &nums, int max_num) {
    
    int max_bits = -1;
    for (; max_num > 0; max_num >>= 1) {
        max_bits++;
    }
    
    
    int min_num = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        min_num &= nums[i];
    }
    int min_bits = 0;
    for (; min_bits > 0; min_num >>= 1) {
        min_bits++;
    }
    
    // int max_bits = countSetBits(max_num) + 5;
    // cout << "maxbit, num : " << max_bits << ", " << max_num << endl;
    for (int set_bit = min_bits + 1; set_bit < max_bits; ++set_bit) {
        vector<int> set(max_bits, 0);
        for (int i = 0; i < set_bit; ++i) {
            set[set.size() - 1 - i] = 1;
        }
        
        do {
            int mask = 0;
            for (int i = 0; i < set.size(); ++i) {
                mask = (mask << 1) + set[i];
            }
            // cout << mask << endl;
            if (check(nums, mask))
                return mask;
        } while (next_permutation(set.begin(), set.end()));
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int max_num = 0;
    
    for(int a_i = 0; a_i < n; a_i++) {
        int input;
        cin >> input;
        nums.push_back(input);
        if (input > max_num) {
            max_num = input;
        }
    }
    
    int result = solve(nums, max_num);
    cout << result << endl;
    return 0;
}
