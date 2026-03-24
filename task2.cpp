#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    cout << "Print numbers (print any letter to end input):" << endl;
    
    list<int> L{ istream_iterator<int>(cin), istream_iterator<int>() };
    
    if (L.empty()) {
        cout << "The list is empty." << endl;
        return 1;
    }
    
    L.reverse();
    
    auto i = L.begin();
    while (i != L.end()) {
        ++i;
        if (i != L.end()) {
            i = L.erase(i);
        }
    }
    
    L.reverse();
    
    cout << "Modified list: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}
