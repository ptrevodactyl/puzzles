/*
https://www.hackerearth.com/problem/algorithm/bobs-journey-5/?utm_source=new_practice
*/

#include <bits/stdc++.h>

int main() {
    std::iostream::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

    int T, N, first_char, i; std::cin >> T;
    bool chars_seen['z' + 1]{}, success;
    std::string city_name;
    
    while(T--) {
        for(i = 'a'; i <= 'z'; i++) chars_seen[i] = false;
        success = true;
        std::cin >> N;
        
        while(N--) {
            std::cin >> city_name;

            #ifdef DEBUG
            std::cout << city_name << "\n";
            #endif

            first_char = (int) city_name[0];
            if(chars_seen[first_char]) success = false;
            else chars_seen[first_char] = true;
        }
        std::cout << (success ? "YES\n" : "NO\n");
    }
}