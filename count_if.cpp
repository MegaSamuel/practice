#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CountStartsWithA(const vector<string>& xs) {
    // посчитайте число строк, начинающихся на букву A
    return count_if(xs.begin(), xs.end(), [](string str){ if(('A' == str[0]) || (('a' == str[0]))) return true; return false; });
}

int main() {
    // не меняйте тело main
    cout << CountStartsWithA({"And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s});
		return 0;
} 
