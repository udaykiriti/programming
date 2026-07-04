#include<bits/stdc++.h>
#include<type_traits>

#define endl '\n'

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type maxi(T1 a, T2 b) {
    return (b < a ? a : b);
}

int main(){
    std::vector<std::string> arr;
    std::string s;

    // Read until EOF (Ctrl+D on Linux/Mac, Ctrl+Z on Windows)
    while (std::cin >> s) {
        arr.push_back(s);
    }
    // while (cin >> s) {
    //     cout << s << ".h" << endl;
    // }
    // std::sort(arr.begin(), arr.end());

    // for (const auto& x : arr) {
    //     std::cout << x << "\n";
    // }

    // Read input until EOF
    // while (std::cin >> s) {
    //     arr.push_back(s);
    // }

    // Sort strings
    std::sort(arr.begin(), arr.end());

    // Print each string with ".h"
    for (const auto& x : arr) {
        std::cout << x << ".h" << std::endl;
    }
}
