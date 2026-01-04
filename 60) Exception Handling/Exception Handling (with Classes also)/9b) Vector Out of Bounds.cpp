#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(13);
    v.push_back(23);
    v.push_back(33);

    try
    {
        cout << v.at(0) << '\n';
        cout << v.at(5) << '\n';
        //.at() function throws exception inside it which we can catch
    }
    catch(exception& e)
    {
        cout << e.what() << '\n';
    }
    cout << "End of Program\n";
    return 0;
}
