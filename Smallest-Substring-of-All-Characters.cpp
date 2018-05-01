#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) {
  unordered_map<char, int> strMap;
  unordered_set<char> arrSet;
  for(int i=0; i<arr.size(); i++) {
    arrSet.insert(arr[i]);
  }
  
  int start = 0;
  string result = "";
  for(int i=0; i<str.size(); i++) {
    if(arrSet.find(str[i]) != arrSet.end())
      strMap[str[i]]++;
    
    while(start <= i && strMap.size() == arrSet.size()) {
      if(result=="" || result.size() > (i-start+1)) {
        result = str.substr(start, i-start+1);
      }
      if(arrSet.find(str[start]) != arrSet.end()) {
        strMap[str[start]]--;
        if(strMap[str[start]] <= 0)
          strMap.erase(str[start]);
      }
      start++;
    }
  }
  return result;
}

// You can try once runnig it ... looks good ... 
// yes
int main() {
  vector<char> arr = {'x', 'y', 'z'};
  string str = "xyyzyzyx";
  cout << getShortestUniqueSubstring(arr, str) << endl;
  arr = {'A'};
  str = "B";
  cout << getShortestUniqueSubstring(arr, str) << endl;
  arr = {'A','B','C'};
  str = "ADOBECODEBANCDDD";    
  cout << getShortestUniqueSubstring(arr, str) << endl;
  return 0;
}

//but before i proceed - i would like to know if the string contains only the characters in the array or extra characters also?
// extra also .. 


