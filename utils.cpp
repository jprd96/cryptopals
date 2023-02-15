#include <string>
#include <cmath>

using namespace std;

constexpr char b64_lookup[64] {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
    'a', 'b', 'c', 'd',	'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' 
};

string hexToB64(const string &input) {
	string res { "" };
	
	// 24 bit blocks, or 6 hex chars
	constexpr int block_size { 6 };
	constexpr int bits_b64_char { 6 };
	const int num_blocks { (int) ceilf(input.size() / (float)block_size) };

	for(int i = 0; i < num_blocks; i++) {
		const string block { input.substr(i*block_size, block_size) };
		int_fast32_t block_bits = stol(block, nullptr, 16);

		// if contents not multiple of 6 bits, left-shift
		block_bits <<= (2 * (block.size() % 3));

		const int num_chars = (int) ceilf(4 * block.size() / (float)block_size);
		for(int j = 0; j < num_chars; j++) {
			constexpr int_fast32_t bitmask { 0x3F };
			const int_fast32_t index { block_bits >> (num_chars - j - 1) * bits_b64_char & bitmask };
			res += b64_lookup[index];
		}
	}

	return res;
}