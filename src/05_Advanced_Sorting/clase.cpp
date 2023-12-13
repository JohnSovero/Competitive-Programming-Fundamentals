#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v_1{1, 6, 4, 22, 8};
    vector<int> v_2{5, 8, 1, 6, 70};
    sort(v_1.begin(), v_1.end());
    sort(v_2.begin(), v_2.end());
    for (int i = 0; i < v_1.size(); i++)
    {
        cout << v_1[i] << " ";
    }
    
    for (int i = 0; i < v_2.size(); i++)
    {
        cout << v_2[i] << " ";
    }
    cout<<endl;
    v_1.insert(v_1.end(), v_2.begin(), v_2.end());
    sort(v_1.begin(), v_1.end());
    for (int i = 0; i < v_1.size(); i++)
    {
        cout << v_1[i] << " ";
    }
    return 0;
}