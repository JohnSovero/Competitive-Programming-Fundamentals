#include <iostream>
#include<string>
#include<vector>
using namespace std;
void calculateZ(vector<char> input,vector<int> Z,vector<char> pattern) {
    //vector<int> Z(input.size());
    int left = 0;
    int right = 0;
    for (int k = 0; k < input.size(); k++) {
        if (k > right) {
            left = right = k;
            while (right < input.size() && input[right] == input[right -left]) {
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else {
            int k1 = k - left;
            if (Z[k1] < right - k + 1) {
                Z[k] = Z[k1];
            }
            else {
                left = k;
                while (right < input.size() && input[right] == input[right -left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            }
        }
    }
    vector<int>result;
    cout << "\n";
    for (auto& elem : Z) cout << " " << elem;
    cout << "\n";
    cout << "Tamano Z: " << Z.size();
    cout << "\nTamano Patter: " << pattern.size();
    cout << "\n\n";
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == pattern.size()) {
            cout<<"\nIndice: "<<(i - pattern.size() - 1);
        }
    }
}

void matchPattern(vector<char> text, vector<char> pattern) {
    vector<char> newString(text.size() + pattern.size() + 1);
    int i = 0;
    for (char ch : pattern) {
        newString[i] = ch;
        i++;
    }
    newString[i] = '$';
    i++;
    for (char ch : text) {
        newString[i] = ch;
        i++;
    }
    vector<int> Z(newString.size());
    calculateZ(newString,Z,pattern);
}

int main()
{
 /* char text[] = {
'a','a','a','b','c','x','y','a','a','a','a','b','c','z','a','a','c','z','a',
'a','c','z','a','b','b','a','a','a','a','a','a','b','c'};
*/
/* vector <char> text{
'a','a','a','b','c','x','y','a','a','a','a','b','c','z','a','a','c','z','a',
'a','c','z','a','b','b','a','a','a','a','a','a','b','c' };
*/
 //vector <char> text{ 'a','a','a','b','c' };
 vector <char> text{'a','a','a','b','c','x','y','a','a','a','a','b','c','z' };
 vector <char> pattern {'a','a','a','b','c'};
 matchPattern(text, pattern);
 cin.get();
 cin.ignore();
 return 0;
}

