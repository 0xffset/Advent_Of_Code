//
// Created by u-0xffset on 05.12.20.
//

#include "2020_05.hpp"

#include <vector>
#include <algorithm>

#define BINARYNONSENSE(s) (((s & 0b1111111000)>>3) * 8 + (s & 0b0000000111))


static short in[] = {0b0000101001, 0b1010011001, 0b1100001011, 0b0101000100, 0b1001000111, 0b1010100101, 0b0001111010,
                     0b1000010000, 0b0000110001, 0b1100100111, 0b0110110010, 0b1010010011, 0b0100100000, 0b0001000101,
                     0b0001011001, 0b1100100010, 0b0000011101, 0b1001011001, 0b0011111011, 0b0110011001, 0b0000011001,
                     0b0110001101, 0b0010110111, 0b0110000010, 0b0010110001, 0b1011110110, 0b0000111001, 0b0010000100,
                     0b0011001010, 0b1100011101, 0b0110110100, 0b0111010111, 0b0111111101, 0b1011011110, 0b0111100101,
                     0b0101011000, 0b0110001010, 0b1001110100, 0b0010011000, 0b0000001100, 0b1001010101, 0b0110111110,
                     0b1010100001, 0b1010101100, 0b0101110010, 0b0100010101, 0b0111111110, 0b1011001000, 0b1000001011,
                     0b1001000010, 0b0111001000, 0b1010100011, 0b1010100110, 0b0111000011, 0b0011001100, 0b1010000011,
                     0b0000110110, 0b0000110010, 0b1001101111, 0b0101101111, 0b0010010001, 0b1000011010, 0b0110100011,
                     0b1001010000, 0b1001010111, 0b0111001100, 0b0100011110, 0b1100100110, 0b1100110001, 0b1100011100,
                     0b0001001010, 0b1100001111, 0b0101101101, 0b1011010001, 0b0010000101, 0b0110001111, 0b0001000000,
                     0b0011000100, 0b0111101011, 0b1000100101, 0b0001101110, 0b0100111000, 0b0100110011, 0b1001001101,
                     0b0111101101, 0b1011110111, 0b0110110001, 0b0111011011, 0b1000100011, 0b0011110011, 0b0101000111,
                     0b0110010010, 0b0110000000, 0b1000111110, 0b0011100000, 0b0001110010, 0b0110011010, 0b1000000100,
                     0b1011011111, 0b0111110010, 0b0010000011, 0b0100110111, 0b0011011100, 0b0100101001, 0b0011001000,
                     0b0100011000, 0b0101101001, 0b1001010001, 0b0101100001, 0b1010101110, 0b1010011110, 0b0010010010,
                     0b0110100010, 0b0100011111, 0b1010000101, 0b1101000011, 0b1011000010, 0b0010101011, 0b1000111010,
                     0b0110101011, 0b0110011101, 0b1011101110, 0b0111011110, 0b1010110000, 0b0011011010, 0b0111010000,
                     0b1001001001, 0b0001011101, 0b0101010011, 0b1100111100, 0b1011011011, 0b1010010100, 0b0111110100,
                     0b0100001111, 0b0001001000, 0b0001001001, 0b1000011100, 0b0110111011, 0b1000111011, 0b1011011100,
                     0b0101101000, 0b0011011111, 0b1100101110, 0b0100000011, 0b0011010110, 0b1010010111, 0b0010110101,
                     0b1011101000, 0b0110101100, 0b1010011111, 0b1001101000, 0b1100010111, 0b0001000110, 0b0001100100,
                     0b1000010101, 0b1001010110, 0b0100000001, 0b0000001111, 0b1100000011, 0b0101001100, 0b0010101000,
                     0b0100100110, 0b0111000100, 0b1000011110, 0b1000011101, 0b0000100100, 0b1100001010, 0b1100100000,
                     0b0100110000, 0b0001010000, 0b1010001010, 0b1000000101, 0b1011111001, 0b0111101111, 0b0000011011,
                     0b0100011101, 0b0100111111, 0b1010010010, 0b1100001110, 0b0001111001, 0b1000001000, 0b1001000011,
                     0b0100000010, 0b0001100001, 0b1011100011, 0b0011001111, 0b0000101110, 0b0110111000, 0b1010011010,
                     0b1010110100, 0b1001110111, 0b1000110110, 0b0000111000, 0b1000000001, 0b0011001011, 0b1010011011,
                     0b0101011011, 0b1010001011, 0b0111010011, 0b0011001101, 0b1001111111, 0b0000111011, 0b1100111010,
                     0b0111010110, 0b0010110010, 0b0011101111, 0b0001010100, 0b0100001000, 0b0100111001, 0b0010110000,
                     0b1001100100, 0b0000010110, 0b0110111010, 0b0111001011, 0b1000111100, 0b0100000101, 0b1011100001,
                     0b1100111111, 0b1010000100, 0b1100110011, 0b1100101001, 0b0110000110, 0b1011010110, 0b0100111011,
                     0b1011001100, 0b1100110110, 0b1100101111, 0b0001010010, 0b0100000100, 0b1000110000, 0b0110010011,
                     0b0101111111, 0b0100110101, 0b0111000111, 0b1000110111, 0b0010101100, 0b1010101011, 0b1100111000,
                     0b1001111100, 0b0101010001, 0b0111111001, 0b1010011100, 0b0101001001, 0b1001101011, 0b1001000000,
                     0b0110110101, 0b0001010001, 0b1001101010, 0b0000111101, 0b0010001101, 0b1100000100, 0b1001110011,
                     0b1100110101, 0b0100000111, 0b0110101101, 0b0001000100, 0b1011000111, 0b0000011110, 0b0110001100,
                     0b0111110101, 0b1011110000, 0b0100001110, 0b1100000101, 0b0001011111, 0b1011100111, 0b1010101000,
                     0b0000101000, 0b0101001011, 0b1000100010, 0b0000100011, 0b0110111111, 0b1010111011, 0b1001011101,
                     0b1010110011, 0b0001100101, 0b1001111101, 0b0101001010, 0b0001110100, 0b1010111111, 0b0001011110,
                     0b0010111100, 0b0101111010, 0b1001100101, 0b1000101001, 0b1001111011, 0b0010010000, 0b0010111011,
                     0b1000110011, 0b1100110010, 0b0110001011, 0b0001110000, 0b0110111001, 0b1000010010, 0b1001010011,
                     0b0110001000, 0b1010110111, 0b0001100010, 0b0110011110, 0b0101000110, 0b0100100001, 0b1011011101,
                     0b1010100100, 0b0010011011, 0b0100110110, 0b0101000101, 0b0101011100, 0b0011101010, 0b0100010110,
                     0b1001001110, 0b0011111100, 0b0001111011, 0b0000100111, 0b0111101100, 0b1100010011, 0b0101001111,
                     0b0011100111, 0b0110010111, 0b1010100111, 0b0001101111, 0b0110100000, 0b0011000000, 0b0001001011,
                     0b0001111111, 0b0100100100, 0b0101001000, 0b0001000111, 0b0111100010, 0b1011000110, 0b1011100000,
                     0b1011000001, 0b1000101111, 0b0000110101, 0b1000001111, 0b1001110000, 0b0100010111, 0b0100001010,
                     0b0010000000, 0b1010110001, 0b0111100011, 0b0011101100, 0b1100001100, 0b1011010011, 0b1100101011,
                     0b1100110111, 0b1000110001, 0b0011100100, 0b0010100001, 0b0010001100, 0b0001100000, 0b1011101111,
                     0b0001001101, 0b1100011111, 0b0010111110, 0b0010011100, 0b0001110011, 0b1011110001, 0b1010001000,
                     0b1100111001, 0b1001100011, 0b0100101011, 0b0010100000, 0b0001111000, 0b0000111010, 0b1100100001,
                     0b1010110101, 0b1000010100, 0b1000011111, 0b0100010001, 0b1000110101, 0b0110011100, 0b0111111111,
                     0b0010100011, 0b0010001001, 0b0000111100, 0b0001110101, 0b0101110110, 0b1000101101, 0b0000111111,
                     0b0001000001, 0b0110010110, 0b0111111100, 0b0111001010, 0b1001000110, 0b0101111001, 0b0101101010,
                     0b1000001001, 0b1011101101, 0b1001001111, 0b0100101111, 0b1100110000, 0b0101110000, 0b0011111010,
                     0b0110110000, 0b0111000101, 0b0101001110, 0b0110011011, 0b0111011010, 0b1001110101, 0b0000110100,
                     0b1000101011, 0b0111110110, 0b0101000001, 0b0011100001, 0b1011111101, 0b1011011010, 0b0111011100,
                     0b0100111101, 0b0100110100, 0b1010001100, 0b0111011000, 0b1100010010, 0b0100101101, 0b0101010100,
                     0b0011101110, 0b0010001110, 0b1010100000, 0b0010011110, 0b1011011001, 0b1011001101, 0b1000000000,
                     0b0101111110, 0b1011000000, 0b0000010011, 0b1100010001, 0b0010001011, 0b0011111101, 0b1010111010,
                     0b1000001110, 0b0011000011, 0b1100001001, 0b0111000001, 0b0110010001, 0b0110010100, 0b0100011100,
                     0b0010000111, 0b1100100011, 0b1001011011, 0b0011101000, 0b1011110010, 0b1100010000, 0b0110110111,
                     0b0011000010, 0b0110110011, 0b1001000101, 0b0011010100, 0b0101010010, 0b1010110110, 0b0000100101,
                     0b1000000110, 0b0000011100, 0b0101001101, 0b0101100101, 0b0000110111, 0b0101111100, 0b0001111101,
                     0b0110100001, 0b0001110110, 0b1010000010, 0b0011100101, 0b1010101001, 0b0000101010, 0b0101000010,
                     0b1011010100, 0b0111101001, 0b0101111101, 0b0001101010, 0b0100011010, 0b0100000110, 0b0011110001,
                     0b0001101100, 0b0101010101, 0b0001100111, 0b1100011010, 0b1001111000, 0b1101000010, 0b0100110010,
                     0b1000000011, 0b0011000110, 0b0000011111, 0b1000100111, 0b1100000111, 0b1100010110, 0b0111010001,
                     0b1001111001, 0b0000001101, 0b0111011111, 0b0010001111, 0b1001001010, 0b1010010110, 0b0101011101,
                     0b0001011010, 0b1011100101, 0b0100101100, 0b0000011000, 0b0000100110, 0b0011110100, 0b0111001111,
                     0b1100001000, 0b1011000100, 0b1010001110, 0b0110111100, 0b0011010101, 0b0001010111, 0b1001100000,
                     0b1001110110, 0b1010000110, 0b0101011010, 0b0101100111, 0b0101110101, 0b0010111000, 0b0001110001,
                     0b0010101101, 0b0101101100, 0b0110101110, 0b0111110111, 0b0111101110, 0b1000101110, 0b0000100000,
                     0b1011010000, 0b1100011000, 0b0101111011, 0b1001111110, 0b0100001101, 0b0100111110, 0b0001000011,
                     0b0110000011, 0b1001001011, 0b0010101111, 0b0101101011, 0b1000010011, 0b1011001010, 0b0011111001,
                     0b0111011001, 0b0001100011, 0b0010000010, 0b0011010011, 0b0101111000, 0b0110001110, 0b0001010011,
                     0b1000100001, 0b1010010000, 0b1010000111, 0b0000001011, 0b0100101010, 0b0110100111, 0b0100111010,
                     0b0100101000, 0b0010100101, 0b0010111111, 0b1011101001, 0b0011100011, 0b0111110001, 0b1001010010,
                     0b1001110010, 0b0010001010, 0b1101000000, 0b0111110011, 0b0010100100, 0b0000101101, 0b0110111101,
                     0b0001111100, 0b1010111101, 0b0000110000, 0b0110100100, 0b0010100111, 0b0110011111, 0b1011001110,
                     0b1011100100, 0b1000001101, 0b0100100101, 0b0010101110, 0b1100111101, 0b0010100010, 0b0001010101,
                     0b1101000001, 0b0110011000, 0b1000101000, 0b1001100001, 0b1001100110, 0b1011111100, 0b1011110101,
                     0b1000001010, 0b0110110110, 0b0110101000, 0b1001011111, 0b0011100010, 0b1100100101, 0b0110001001,
                     0b0110000101, 0b0111101010, 0b1000011000, 0b0010011001, 0b0101101110, 0b1000111111, 0b0110000001,
                     0b0101100010, 0b0011110010, 0b0000010001, 0b1000000010, 0b1000100110, 0b0110100110, 0b1100000000,
                     0b0000010111, 0b0111001001, 0b1001001100, 0b0100010100, 0b0001011000, 0b1010111001, 0b0111101000,
                     0b1010101010, 0b1001000100, 0b1011010010, 0b0110000111, 0b0011110101, 0b0011011110, 0b1010100010,
                     0b0111100001, 0b0101011111, 0b0010101001, 0b1001001000, 0b0010110011, 0b0010011010, 0b0011000001,
                     0b1100101000, 0b0101010110, 0b0010011111, 0b1000000111, 0b1010111110, 0b0010111001, 0b0010110110,
                     0b0011101101, 0b0100011001, 0b0011010111, 0b0100000000, 0b0000001110, 0b0011110110, 0b0100111100,
                     0b1011111010, 0b0011010010, 0b1100101100, 0b0001101001, 0b1100000110, 0b0010010101, 0b1001010100,
                     0b1011111011, 0b0010011101, 0b1000100000, 0b1011101100, 0b0110010101, 0b0010111010, 0b1100010101,
                     0b1000010110, 0b1100000010, 0b1010011000, 0b0000100001, 0b0100100010, 0b1000110010, 0b1011001011,
                     0b0000100010, 0b0000011010, 0b1011110011, 0b1011111110, 0b1000100100, 0b1010111100, 0b1010010101,
                     0b0000101111, 0b1001011000, 0b1011010111, 0b0101011110, 0b0010010110, 0b0110101010, 0b0010000001,
                     0b1000010111, 0b1000001100, 0b0011101001, 0b0010010011, 0b0010100110, 0b1001011110, 0b1100001101,
                     0b0111000010, 0b0101000011, 0b1000111000, 0b0000010000, 0b1011100110, 0b0101000000, 0b1010111000,
                     0b1011111000, 0b0011001001, 0b0110000100, 0b1010001111, 0b1001000001, 0b0101110011, 0b0111000000,
                     0b0111001101, 0b0111111000, 0b1010000000, 0b1001101101, 0b1100011001, 0b1011001111, 0b1001011100,
                     0b1011101011, 0b1000010001, 0b0111100111, 0b0100001011, 0b1011011000, 0b0101010111, 0b0001110111,
                     0b0011000101, 0b0111111010, 0b0001001111, 0b1000011011, 0b0101011001, 0b0011011001, 0b0111001110,
                     0b0100001001, 0b1001011010, 0b0001011011, 0b1010110010, 0b1001101001, 0b1010101101, 0b1000111001,
                     0b0000110011, 0b0110101111, 0b0100110001, 0b1100011110, 0b0101010000, 0b0001111110, 0b0111010101,
                     0b1001110001, 0b1011101010, 0b1011100010, 0b1001101110, 0b0001011100, 0b1001111010, 0b0001101101,
                     0b0010101010, 0b1000011001, 0b0000010101, 0b0000101100, 0b0100011011, 0b0111100110, 0b1001100111,
                     0b1011111111, 0b0010010100, 0b1100101010, 0b0000010010, 0b1011001001, 0b0111010010, 0b1000110100,
                     0b1010010001, 0b0010111101, 0b1001100010, 0b0001010110, 0b1011000101, 0b1010000001, 0b0010000110,
                     0b1100110100, 0b1100111011, 0b0001000010, 0b0101100100, 0b0111011101, 0b0110101001, 0b0010001000,
                     0b0100010010, 0b0111111011, 0b0011110111, 0b1010101111, 0b0100100011, 0b1011000011, 0b1100101101,
                     0b0011110000, 0b1100111110, 0b0001001110, 0b1000111101, 0b0011010001, 0b0100100111, 0b0000010100,
                     0b0101100110, 0b0011011011, 0b1100000001, 0b0011000111, 0b0001101000, 0b0101110001, 0b0000111110,
                     0b1010011101, 0b0101110111, 0b0011100110, 0b0001100110, 0b0101100011, 0b0100101110, 0b1100011011,
                     0b0011111110, 0b0101110100, 0b1010001101, 0b0101100000, 0b1011110100, 0b0111100000, 0b0100001100,
                     0b0011010000, 0b0100010011, 0b0001001100, 0b0011101011, 0b0011001110, 0b0011011000, 0b0011011101,
                     0b0000101011, 0b1011010101, 0b1000101100, 0b1100010100, 0b0001101011, 0b0110100101, 0b0111000110,
                     0b0011111111, 0b0111010100, 0b0111100100, 0b0010110100, 0b1001101100, 0b0010010111, 0b0011111000,
                     0b1000101010, 0b0111110000, 0b0110010000, 0b1100100100, 0b0100010000};

int y2020::day5part1() {
    int highest = 0;
    for (const short &s : in) {
        if (BINARYNONSENSE(s) > highest) {
            highest = BINARYNONSENSE(s);
        }
    }
    return highest;
}

int y2020::day5part2() {
    std::vector<short> IDs;
    for (const short &s : in) {
        IDs.push_back(BINARYNONSENSE(s));
    }
    std::sort(IDs.begin(), IDs.end());
    for (int i = 0; i < IDs.size(); i++) {
        if (IDs.at(i)+1 != IDs.at(i+1)) {
            return IDs.at(i)+1;
        }
    }
    return -1;
}