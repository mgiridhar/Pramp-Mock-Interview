/*
Merging 2 Packages

Given a package with a weight limit limit and an array arr of item weights, implement a function getIndicesOfItemWeights that finds two items whose sum of weights equals the weight limit limit. Your function should return a pair [i, j] of the indices of the item weights, ordered such that i > j. If such a pair doesn’t exist, return an empty array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [4, 6, 10, 15, 16],  lim = 21

output: [3, 1] # since these are the indices of the
               # weights 6 and 15 whose sum equals to 21
Constraints:

[time limit] 5000ms

[input] array.integer arr

0 ≤ arr.length ≤ 100
[input] integer limit

[output] array.integer
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  // your code goes here
  vector<int> result;
  unordered_map<int, int> hash;
  for(int i=0; i<arr.size(); i++) {
    int toFind = limit - arr[i];
    if(hash.find(toFind) != hash.end()) {
      result = {i, hash[toFind]};
      return result;
    }
    hash[arr[i]] = i;
  }
  return result;
}

int main() {
  return 0;
}

/*
Brute force: O(n^2)

sort the array: 
i=0, j=n-1
i < j 
curr_sum > lim
  j--
curr_sum < lim
  i++

O(n log n) time and O(n) space

[<4,0>, <6,1>, < ...>]
[<]


hashing:
hash[4] = 0
lim - arr[i] is present in hash => the sum exists
O(n)
O(n)

*/
