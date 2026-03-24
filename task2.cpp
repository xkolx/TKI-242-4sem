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

    cout << "Modified list: ";

    int count = 0;

    copy_if(L.begin(), 
            L.end(), 
            ostream_iterator<int>(cout, " "),
            [&count](int) { return count++ % 2 == 0; });

    cout << endl;

    return 0;
}
