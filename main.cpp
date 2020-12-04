#include <iostream>

#include "2019_01/2019_01.hpp"
#include "2019_02/2019_02.hpp"
#include "2020_01/2020_01.hpp"
#include "2020_02/2020_02.hpp"
#include "2020_03/2020_03.hpp"
#include "2020_04/2020_04.hpp"


int main() {
    std::cout << "2019  1st December Part 1: " << y2019::day1part1() << std::endl;
    std::cout << "2019  1st December Part 2: " << y2019::day1part2() << std::endl;
    std::cout << "2019  2nd December Part 1: " << y2019::day2part1() << std::endl;
    std::cout << "2019  2nd December Part 2: " << y2019::day2part2() << std::endl;

    std::cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- --" << std::endl;

    std::cout << "2020  1st December Part 1: " << y2020::day1part1() << std::endl;
    std::cout << "2020  1st December Part 2: " << y2020::day1part2() << std::endl;
    std::cout << "2020  2nd December Part 1: " << y2020::day2part1() << std::endl;
    std::cout << "2020  2nd December Part 2: " << y2020::day2part2() << std::endl;
    std::cout << "2020  3rd December Part 1: " << y2020::day3part1() << std::endl;
    std::cout << "2020  3rd December Part 2: " << y2020::day3part2() << std::endl;
    std::cout << "2020  4th December Part 1: " << y2020::day4part1() << std::endl;
    std::cout << "2020  4th December Part 2: " << y2020::day4part2() << std::endl;

    return 0;
}
