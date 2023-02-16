#include "utils.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

string hexToB64(string &str) {
	string lookup_b16 = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
		'a', 'b', 'c', 'd',	'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' 	
	};
	char lookup_b64[64];
	for(int i = 0; i < 64; i++) {
		lookup_b64[i] = lookup_b16[i];
	}

	string res;
	int block_size = 6;
	int b64_bits = 6;
	int block_nums = ceilf(str.size() / block_size);

	for(int i = 0; i < block_nums; i++) {
		string block = str.substr(i*block_size, block_size);
		int block_bits = stol(block, nullptr, 16);

		// if contents not multiple of 6 bits, left-shift
		block_bits <<= (2 * (block.size() % 3));

		int num_chars = ceilf(4 * block.size() / block_size);
		for(int j = 0; j < num_chars; j++) {
			int mask = 0x3F;
			int idx = block_bits >> (num_chars - j - 1) * b64_bits & mask;
			res += lookup_b64[idx];
		}
	}

	return res;
}

string hexXOR(string &str1, string &str2) {
	stringstream res;
	res << setfill('0') << setw(2) << hex;

	for(int i = 0; i < str1.length(); i += 2) {
		int int1 = stoi(str1.substr(i, 2), nullptr, 16);
		int int2 = stoi(str2.substr(i, 2), nullptr, 16);
		res << (int1 ^ int2);
	}

	return res.str();
}