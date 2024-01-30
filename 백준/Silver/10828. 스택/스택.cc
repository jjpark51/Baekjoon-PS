#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

int main() {
    int N = 0;
    std::cin >> N;

    std::stack<int>st;



    // How to separate string command and value
    for(int i = 0; i < N; i++) {
        int n = 0;
        std::string s = "";
        std::cin >> s;

        if(s == "push"){
            std::cin >> n;
            st.push(n);
        }
        else if(s == "pop"){
            if(st.empty()){
                std::cout << "-1" << std::endl;
            }
            else {
                std::cout << st.top() << std::endl;;
                st.pop();
            }
        }
        else if(s == "size") {
            std::cout << st.size() << std::endl;;
        }
        else if(s == "empty"){
            if(st.empty()){
                std::cout << "1" << std::endl;;
            }
            else {
                std::cout << "0" << std::endl;;
            }
        }
        else if(s == "top"){
            if(st.empty()){
                std::cout << "-1" << std::endl;
            }
            else {
                std::cout << st.top() << std::endl;;
            }
        }
        else {
            std:: cout << s;
        }
    }
}