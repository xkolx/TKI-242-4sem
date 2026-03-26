#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

int getLastDigit(int n) {
    return abs(n) % 10;
}

int main() {
    int n1;
    cin >> n1;
    vector<int> V1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> V1[i];
    }

    int n2;
    cin >> n2;
    vector<int> V2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> V2[i];
    }

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