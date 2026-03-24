#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "Enter numbers (any letter to stop): " << endl;
    
    vector<int> nums{ istream_iterator<int>(cin), istream_iterator<int>() };

    replace_copy(nums.begin(), 
                 nums.end(), 
                 ostream_iterator<int>(cout, "  "), 
                 0, 
                 10); 

    cout << endl;

    return 0;
}