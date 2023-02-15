#!/usr/bin/env python3

"""set 1"""

import codecs
import binascii

def hexToB64(hex_str):
    b64 = codecs.encode(codecs.decode(hex_str, 'hex'), 'base64').decode().replace("\n", "")
    return b64

def main():
    hex_str = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    # print(hexToB64(hex_str))
    hex_str = bytes(hex_string)
    print(binary)

if __name__ == '__main__':
    main()