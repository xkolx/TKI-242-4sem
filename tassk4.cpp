#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cmath>

using namespace std;

struct less_abs : public binary_function<int, int, bool> {
    bool operator()(int a, int b) const {
        return abs(a) < abs(b);
    }
};

int main() {
    string name = "input.txt";
    ifstream infile(name);

    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    istream_iterator<int> start(infile), end;
    vector<int> V(start, end);
    
    vector<int>::iterator it = adjacent_find(V.begin(), V.end(), not2(less_abs()));
    
    if (it != V.end()) {
        cout << *it << " " << *(it + 1) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}