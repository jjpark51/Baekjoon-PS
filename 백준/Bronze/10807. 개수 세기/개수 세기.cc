#include <stdio.h>
#include <iostream>
#include <vector>

int main() {

	int N = 0;
	
	std::cin >> N;

	std::vector<int>numbers;

	for (int i = 0; i < N; i++) {
		int num = 0;
		std::cin >> num;
		numbers.push_back(num);
	}

	int target;
	std::cin >> target;

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (numbers[i] == target) {
			count++;
		}
	}

	std::cout << count;




}