#include <iostream>
#include <string>
#include <cassert>

int freq[3][256];

int main()
{
	std::string a, b;
	while(std::getline(std::cin, a))
	{
		std::getline(std::cin, b);
		// assert(b.size());
		for(auto c : a)
			freq[0][c]++;
		for(auto c : b)
			freq[1][c]++;
		for(int i = 'a'; i <= 'z'; i++)
		{
			freq[2][i] = std::min(freq[0][i], freq[1][i]);
			while(freq[2][i]--)
				std::cout << (char) i;
			freq[0][i] = freq[1][i] = 0;
		}
		std::cout << '\n';
	}
}