#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <sstream>

using namespace std;

int getLastDigit(int n) {
    return abs(n) % 10;
}

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    
    istringstream iss1(line1);
    istringstream iss2(line2);
    
    vector<int> V1{ istream_iterator<int>(iss1), istream_iterator<int>() };
    vector<int> V2{ istream_iterator<int>(iss2), istream_iterator<int>() };

    multimap<int, int> M;
    for (vector<int>::iterator it = V2.begin(); it != V2.end(); ++it) {
        M.insert(make_pair(getLastDigit(*it), *it));
    }

    vector<pair<int, int> > V;
    for (vector<int>::iterator it1 = V1.begin(); it1 != V1.end(); ++it1) {
        int key = getLastDigit(*it1);
        pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range;
        range = M.equal_range(key);
        for (multimap<int, int>::iterator it2 = range.first; it2 != range.second; ++it2) {
            V.push_back(make_pair(*it1, it2->second));
        }
    }

    cout << V.size() << endl;
    for (vector<pair<int, int> >::iterator it = V.begin(); it != V.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
