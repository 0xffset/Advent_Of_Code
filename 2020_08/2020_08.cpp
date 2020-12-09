//
// Created by u-0xffset on 08.12.20.
//

#include "2020_08.hpp"

#include <vector>
#include <algorithm>


static int accumulator = 0;

static int in[638][2] = {{1, -1},
                         {2, 1},
                         {2, 117},
                         {2, 70},
                         {2, 473},
                         {1, 11},
                         {1, 48},
                         {1, -10},
                         {1, -2},
                         {2, 253},
                         {2, 597},
                         {1, -19},
                         {1, -5},
                         {2, 328},
                         {1, 41},
                         {1, 23},
                         {1, 35},
                         {1, 24},
                         {2, 465},
                         {1, 20},
                         {0, 338},
                         {1, 17},
                         {2, 1},
                         {2, 549},
                         {1, 15},
                         {2, 131},
                         {1, 35},
                         {2, 63},
                         {1, 29},
                         {2, 81},
                         {1, 30},
                         {1, 16},
                         {2, 75},
                         {2, 28},
                         {1, 20},
                         {1, -13},
                         {2, 1},
                         {2, 79},
                         {1, 16},
                         {1, -5},
                         {2, -36},
                         {0, 361},
                         {1, 33},
                         {1, 46},
                         {2, 270},
                         {1, 12},
                         {1, 13},
                         {1, 2},
                         {2, 254},
                         {1, 37},
                         {1, -10},
                         {1, 2},
                         {1, 27},
                         {2, 535},
                         {1, 18},
                         {1, 32},
                         {2, 252},
                         {1, -2},
                         {2, 1},
                         {1, -6},
                         {2, 565},
                         {1, 40},
                         {2, 200},
                         {1, -15},
                         {0, 419},
                         {0, 265},
                         {2, 340},
                         {1, 46},
                         {1, 23},
                         {0, 527},
                         {1, 32},
                         {2, 202},
                         {2, 47},
                         {1, 12},
                         {2, 493},
                         {2, -71},
                         {0, 491},
                         {1, 18},
                         {2, 38},
                         {2, 5},
                         {0, 311},
                         {2, -43},
                         {0, 197},
                         {2, 275},
                         {1, 40},
                         {1, 27},
                         {2, 440},
                         {1, 7},
                         {1, 44},
                         {2, 131},
                         {1, 2},
                         {2, 283},
                         {2, 415},
                         {1, -12},
                         {1, -4},
                         {1, -8},
                         {1, 40},
                         {2, -30},
                         {1, 43},
                         {0, -15},
                         {1, -2},
                         {2, 74},
                         {2, 421},
                         {2, 1},
                         {1, 16},
                         {1, 23},
                         {2, -96},
                         {1, -9},
                         {2, 181},
                         {2, 1},
                         {2, 482},
                         {1, -5},
                         {1, 15},
                         {1, 8},
                         {1, 12},
                         {2, 323},
                         {1, -16},
                         {2, 417},
                         {2, 483},
                         {1, 0},
                         {1, 31},
                         {1, 11},
                         {1, -9},
                         {2, 46},
                         {1, 50},
                         {1, 41},
                         {2, 153},
                         {1, 12},
                         {1, 23},
                         {1, -6},
                         {1, 38},
                         {2, 191},
                         {1, 28},
                         {0, 75},
                         {2, 462},
                         {1, 40},
                         {0, -52},
                         {2, 404},
                         {1, 16},
                         {0, 273},
                         {2, 105},
                         {1, 8},
                         {1, -4},
                         {2, -59},
                         {1, 47},
                         {1, 0},
                         {2, 1},
                         {2, -45},
                         {1, 15},
                         {1, -14},
                         {0, 373},
                         {1, 25},
                         {2, -50},
                         {1, 43},
                         {0, 154},
                         {2, 368},
                         {1, 32},
                         {1, -2},
                         {1, 28},
                         {2, 273},
                         {1, -9},
                         {2, 1},
                         {0, -69},
                         {2, 82},
                         {1, 20},
                         {2, 1},
                         {2, 282},
                         {1, 14},
                         {2, 296},
                         {0, 61},
                         {2, 1},
                         {1, 9},
                         {2, 202},
                         {1, -2},
                         {2, 441},
                         {1, 23},
                         {1, 16},
                         {1, 12},
                         {0, -117},
                         {2, 247},
                         {1, 19},
                         {1, -10},
                         {1, -15},
                         {1, 39},
                         {2, 213},
                         {1, -18},
                         {1, 29},
                         {2, -80},
                         {1, 43},
                         {1, 10},
                         {1, 47},
                         {2, 98},
                         {1, 49},
                         {1, 17},
                         {1, 24},
                         {2, 430},
                         {1, -11},
                         {1, 36},
                         {1, -5},
                         {1, 23},
                         {2, 108},
                         {1, -14},
                         {2, 10},
                         {1, 31},
                         {1, 1},
                         {1, 3},
                         {1, 5},
                         {2, 184},
                         {1, 48},
                         {2, 70},
                         {1, 13},
                         {2, 130},
                         {1, 26},
                         {1, 29},
                         {1, 25},
                         {2, 165},
                         {0, 112},
                         {1, 11},
                         {1, 6},
                         {2, 103},
                         {2, 1},
                         {1, -2},
                         {1, 31},
                         {1, 0},
                         {2, 123},
                         {1, -12},
                         {1, -5},
                         {1, -11},
                         {0, -161},
                         {2, 112},
                         {1, 10},
                         {1, 19},
                         {2, 132},
                         {2, -157},
                         {0, 80},
                         {2, 101},
                         {1, 12},
                         {1, 39},
                         {1, -11},
                         {2, -75},
                         {0, -10},
                         {2, 179},
                         {1, 37},
                         {1, -14},
                         {2, 204},
                         {0, 380},
                         {1, 1},
                         {1, 43},
                         {1, 18},
                         {2, -41},
                         {1, -8},
                         {1, 32},
                         {1, 50},
                         {0, -45},
                         {2, 233},
                         {0, -182},
                         {1, 16},
                         {1, 16},
                         {2, -131},
                         {1, 17},
                         {1, 21},
                         {2, 92},
                         {2, 179},
                         {1, -14},
                         {2, 296},
                         {1, 44},
                         {1, -5},
                         {0, 12},
                         {2, 134},
                         {1, 39},
                         {0, -30},
                         {1, 31},
                         {2, -131},
                         {1, 7},
                         {1, 46},
                         {1, 14},
                         {0, 82},
                         {2, -187},
                         {2, 242},
                         {0, 178},
                         {1, -17},
                         {1, -8},
                         {0, 267},
                         {2, 101},
                         {0, -50},
                         {2, 1},
                         {1, -19},
                         {1, 10},
                         {2, -172},
                         {1, 20},
                         {1, 39},
                         {1, 46},
                         {1, 41},
                         {2, 340},
                         {2, -266},
                         {1, 46},
                         {0, 45},
                         {1, 15},
                         {1, 16},
                         {2, 158},
                         {1, 21},
                         {2, 300},
                         {1, 35},
                         {2, 190},
                         {0, -70},
                         {1, 49},
                         {1, 31},
                         {2, 184},
                         {2, 275},
                         {1, 8},
                         {0, -76},
                         {1, 30},
                         {1, 9},
                         {2, -5},
                         {1, 28},
                         {1, 19},
                         {2, 37},
                         {1, 5},
                         {1, 5},
                         {0, -200},
                         {0, 281},
                         {2, -202},
                         {1, -4},
                         {1, -7},
                         {1, 0},
                         {2, -252},
                         {1, 7},
                         {2, 298},
                         {2, 279},
                         {2, 7},
                         {1, 30},
                         {1, -6},
                         {1, -19},
                         {2, 201},
                         {1, 33},
                         {2, 12},
                         {1, 47},
                         {1, 20},
                         {1, 43},
                         {2, 268},
                         {2, 124},
                         {1, 17},
                         {1, 0},
                         {1, 21},
                         {1, 34},
                         {2, 227},
                         {2, -313},
                         {1, -6},
                         {1, 43},
                         {2, 1},
                         {2, -22},
                         {0, 162},
                         {2, 161},
                         {2, -339},
                         {1, -12},
                         {0, 109},
                         {1, 21},
                         {2, -149},
                         {0, -128},
                         {0, 199},
                         {2, -327},
                         {0, 165},
                         {1, 19},
                         {2, -302},
                         {1, 26},
                         {0, 67},
                         {2, -52},
                         {0, -353},
                         {1, -4},
                         {2, -200},
                         {2, 245},
                         {1, 38},
                         {1, 3},
                         {2, -232},
                         {1, 36},
                         {2, 1},
                         {1, 20},
                         {2, -157},
                         {1, -14},
                         {2, -114},
                         {2, -66},
                         {0, -59},
                         {1, 44},
                         {2, -42},
                         {1, 40},
                         {0, -90},
                         {2, -306},
                         {1, -7},
                         {0, -24},
                         {1, -17},
                         {2, -226},
                         {1, 8},
                         {1, 39},
                         {2, 106},
                         {2, 1},
                         {1, 27},
                         {2, -60},
                         {1, -10},
                         {2, 1},
                         {2, -366},
                         {1, 29},
                         {2, -325},
                         {2, -28},
                         {1, 34},
                         {1, 35},
                         {2, -3},
                         {1, 30},
                         {1, -9},
                         {1, 33},
                         {1, -5},
                         {2, 62},
                         {2, 147},
                         {1, 43},
                         {1, 37},
                         {0, 120},
                         {1, 21},
                         {2, 172},
                         {1, 22},
                         {1, 36},
                         {2, -105},
                         {0, 37},
                         {1, 40},
                         {0, 26},
                         {2, -288},
                         {1, 6},
                         {2, 98},
                         {0, -278},
                         {1, 17},
                         {1, -11},
                         {2, -99},
                         {0, -416},
                         {2, -364},
                         {2, 145},
                         {1, 23},
                         {1, -18},
                         {1, -13},
                         {1, 8},
                         {2, 112},
                         {1, 34},
                         {2, -411},
                         {2, -255},
                         {1, 23},
                         {1, 1},
                         {1, 30},
                         {2, 152},
                         {0, -225},
                         {1, 3},
                         {2, -217},
                         {1, 37},
                         {1, -10},
                         {1, -1},
                         {0, -81},
                         {2, 12},
                         {1, -3},
                         {1, 41},
                         {1, 12},
                         {2, 151},
                         {1, 20},
                         {1, 10},
                         {2, -229},
                         {1, 0},
                         {1, 12},
                         {1, 0},
                         {2, 24},
                         {1, 35},
                         {1, 21},
                         {1, -13},
                         {2, 40},
                         {1, 48},
                         {1, -9},
                         {1, 4},
                         {2, -30},
                         {1, 1},
                         {0, -440},
                         {1, 36},
                         {2, -241},
                         {2, 15},
                         {1, 5},
                         {0, 147},
                         {1, 37},
                         {1, 12},
                         {2, -457},
                         {2, 85},
                         {2, -308},
                         {2, 1},
                         {1, 33},
                         {2, -221},
                         {2, 114},
                         {1, 29},
                         {0, -142},
                         {2, -42},
                         {2, -415},
                         {2, -328},
                         {2, -345},
                         {1, 23},
                         {1, 3},
                         {1, 13},
                         {2, 1},
                         {2, -233},
                         {1, 9},
                         {1, -9},
                         {2, 59},
                         {0, -15},
                         {1, 17},
                         {1, 32},
                         {1, 39},
                         {2, -251},
                         {1, 24},
                         {1, 26},
                         {1, 0},
                         {1, 27},
                         {2, -319},
                         {2, 46},
                         {1, 35},
                         {0, -134},
                         {1, 37},
                         {2, -104},
                         {1, 5},
                         {1, 21},
                         {2, 48},
                         {1, -2},
                         {2, -83},
                         {2, -415},
                         {1, 0},
                         {2, -154},
                         {2, -285},
                         {1, 5},
                         {1, -2},
                         {1, 27},
                         {2, -519},
                         {1, -16},
                         {1, 31},
                         {1, 20},
                         {2, -34},
                         {1, 3},
                         {1, 20},
                         {2, -344},
                         {1, 0},
                         {1, -19},
                         {1, -5},
                         {2, -310},
                         {1, 17},
                         {1, 42},
                         {1, 11},
                         {2, -490},
                         {1, 47},
                         {1, 44},
                         {1, -1},
                         {2, 12},
                         {1, 34},
                         {0, -512},
                         {1, 33},
                         {2, -61},
                         {1, 43},
                         {1, -2},
                         {1, -16},
                         {1, 10},
                         {2, -327},
                         {2, -45},
                         {2, -147},
                         {1, 33},
                         {2, -203},
                         {1, 17},
                         {1, -8},
                         {0, 19},
                         {1, 20},
                         {2, -164},
                         {1, 11},
                         {1, 18},
                         {1, 50},
                         {2, -330},
                         {2, -326},
                         {1, 43},
                         {1, 42},
                         {1, 22},
                         {2, -310},
                         {2, -248},
                         {0, -219},
                         {1, -7},
                         {1, 21},
                         {2, -183},
                         {1, 0},
                         {2, 6},
                         {1, 13},
                         {2, -339},
                         {1, -17},
                         {1, -7},
                         {2, -471},
                         {2, -387},
                         {1, -4},
                         {1, 50},
                         {2, -250},
                         {2, -407},
                         {0, -1},
                         {2, 1},
                         {2, -157},
                         {1, 45},
                         {0, -456},
                         {1, 28},
                         {2, -41},
                         {2, -370},
                         {2, -482},
                         {1, -17},
                         {1, 11},
                         {1, 18},
                         {1, 15},
                         {2, -29},
                         {1, 31},
                         {1, 48},
                         {2, -564},
                         {1, 47},
                         {2, 1},
                         {1, 8},
                         {1, 27},
                         {2, -26},
                         {1, 23},
                         {1, 0},
                         {1, 12},
                         {1, 17},
                         {2, -364},
                         {1, -4},
                         {1, 50},
                         {1, -10},
                         {0, -393},
                         {2, -531},
                         {0, -118},
                         {0, -256},
                         {0, -551},
                         {1, 36},
                         {2, -536},
                         {1, -6},
                         {1, 44},
                         {2, -530},
                         {1, -5},
                         {1, 16},
                         {1, 19},
                         {2, 1},
                         {2, 1}};

/*
 * nop 0
 * acc 1
 * jmp 2
 */

int y2020::day8part1() {
    std::vector<int> executed;
    for (int i = 0; i < 638; i++) {
        if (std::find(executed.begin(), executed.end(), i) != executed.end()) {
            return accumulator;
        } else {
            switch (in[i][0]) {
                case 1:
                    accumulator += in[i][1];
                    executed.push_back(i);
                    break;
                case 2:
                    executed.push_back(i);
                    i += in[i][1] - 1;
                    break;
                default:
                    executed.push_back(i);
            }
        }
    }
    return -1;
}

int y2020::day8part2() {
    std::vector<int> executed;

    for (auto &x : in) {
        executed.clear();
        accumulator = 0;

        if (x[0] == 1) {
            continue;
        }
        x[0] = x[0] == 0 ? 2 : 0;

        for (int i = 0; i < 638; i++) {
            if (std::find(executed.begin(), executed.end(), i) != executed.end()) {
                break;
            } else {
                switch (in[i][0]) {
                    case 1:
                        accumulator += in[i][1];
                        if (i == 637) {
                            return accumulator;
                        }
                        executed.push_back(i);
                        break;
                    case 2:
                        if (in[i][1] > 0 && i == 637) {
                            return accumulator;
                        }
                        executed.push_back(i);
                        i += in[i][1] - 1;
                        break;
                    default:
                        if (i == 637) {
                            return accumulator;
                        }
                        executed.push_back(i);
                }
            }
        }

        x[0] = x[0] == 0 ? 2 : 0;
    }
    return -1;
}