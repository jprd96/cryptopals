#include "utils.hpp"
#include <iostream>

using namespace std;

int main() {
  // challenge one: convert hex to base64
  string s1 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string s2 = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  if(s2.compare(hexToB64(s1)) == 0) {
    cout << "one yay" << endl;
  } else {
    cout << "one boo" << endl;
  }

  // challenge two: fixed xor
  string s3 = "1c0111001f010100061a024b53535009181c";
  string s4 = "686974207468652062756c6c277320657965";
  string s5 = "746865206b696420646f6e277420706c6179";
  if(s5.compare(hexXOR(s3, s4)) == 0) {
    cout << "two yay" << endl;
  } else {
    cout << "two boo" << endl;
  }
  
  return 0;
}