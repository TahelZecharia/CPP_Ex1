/**
 * 
 * AUTHORS: Tahel Zecharia
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

// check the func with input of single row or colsum.

TEST_CASE("Good input: single row or colsum") {

    CHECK(nospaces(mat(1, 1, '~', '-')) == nospaces("~\n"));

    CHECK(nospaces(mat(7, 1, '@', '-')) == nospaces("@@@@@@@\n"));

    CHECK(nospaces(mat(1, 5, '&', '@')) == nospaces("&\n"
													"&\n"
                                                    "&\n"
                                                    "&\n"
                                                    "&\n"));

}

// check the func with input of small mat.

TEST_CASE("Good input: small mat") {
	
    CHECK(nospaces(mat(3, 3, '~', '~')) == nospaces("~~~\n"
								                    "~~~\n"
								                    "~~~\n"));

    CHECK(nospaces(mat(5, 3, '$', '-')) == nospaces("$$$$$\n"
								                    "$---$\n"
								                    "$$$$$\n"));

    
    CHECK(nospaces(mat(3, 7, '.', ',')) == nospaces("...\n"
								                    ".,.\n"
                                                    ".,.\n"
                                                    ".,.\n"
                                                    ".,.\n"
                                                    ".,.\n"
                                                    "...\n"));

    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

}

// check the func with input of large mat.

TEST_CASE("Good input: large mat") {
	
    CHECK(nospaces(mat(11, 11, '^', '^')) == nospaces("^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"
                                                      "^^^^^^^^^^^\n"));

    CHECK(nospaces(mat(11, 13, '#', '*')) == nospaces("#############\n"
                                                      "#***********#\n"
                                                      "#*#########*#\n"
                                                      "#*#*******#*#\n"
                                                      "#*#*#####*#*#\n"
                                                      "#*#*#***#*#*#\n"
                                                      "#*#*#***#*#*#\n"
                                                      "#*#*#####*#*#\n"
                                                      "#*#*******#*#\n"
                                                      "#***********#\n"
                                                      "#############\n"));

    CHECK(nospaces(mat(21, 21, '+', '-')) == nospaces("+++++++++++++++++++++\n"
                                                      "+-------------------+\n"
                                                      "+-+++++++++++++++++-+\n"
                                                      "+-+---------------+-+\n"
                                                      "+-+-+++++++++++++-+-+\n"
                                                      "+-+-+-----------+-+-+\n"
                                                      "+-+-+-+++++++++-+-+-+\n"
                                                      "+-+-+-+-------+-+-+-+\n"
                                                      "+-+-+-+-+++++-+-+-+-+\n"
                                                      "+-+-+-+-+---+-+-+-+-+\n"
                                                      "+-+-+-+-+-+-+-+-+-+-+\n"
                                                      "+-+-+-+-+---+-+-+-+-+\n"
                                                      "+-+-+-+-+++++-+-+-+-+\n"
                                                      "+-+-+-+-------+-+-+-+\n"
                                                      "+-+-+-+++++++++-+-+-+\n"
                                                      "+-+-+-----------+-+-+\n"
                                                      "+-+-+++++++++++++-+-+\n"
                                                      "+-+---------------+-+\n"
                                                      "+-+++++++++++++++++-+\n"
                                                      "+-------------------+\n"
                                                      "+++++++++++++++++++++\n"));

    CHECK(nospaces(mat(41, 17, '1', '0')) == nospaces("11111111111111111111111111111111111111111\n"
                                                      "10000000000000000000000000000000000000001\n"
                                                      "10111111111111111111111111111111111111101\n"
                                                      "10100000000000000000000000000000000000101\n"
                                                      "10101111111111111111111111111111111110101\n"
                                                      "10101000000000000000000000000000000010101\n"
                                                      "10101011111111111111111111111111111010101\n"
                                                      "10101010000000000000000000000000001010101\n"
                                                      "10101010111111111111111111111111101010101\n"
                                                      "10101010000000000000000000000000001010101\n"
                                                      "10101011111111111111111111111111111010101\n"
                                                      "10101000000000000000000000000000000010101\n"
                                                      "10101111111111111111111111111111111110101\n"
                                                      "10100000000000000000000000000000000000101\n"
                                                      "10111111111111111111111111111111111111101\n"
                                                      "10000000000000000000000000000000000000001\n"
                                                      "11111111111111111111111111111111111111111\n"));

}

// this TEST_CASE is the main tester of good inputs:
// The test passes over fifty good inputs and checks
// that the output of the function is indeed a polindrom.

TEST_CASE("Good input: is a polindrom") {

    bool flag;
    int size;
    string palindrom;
    
    for (int col = 1, row = 5; col <= 51 && row <= 55 ; col += 2, row += 2){
        
        flag = true;
        palindrom = nospaces(mat(col, row, '-', '~'));
        size = palindrom.length();
        
        for (int i = 0, j = size-1 ; i < j ; i++, j--){
            
            if (palindrom[i] != palindrom[j]){
                flag = false;
            }
        }
        CHECK(true == flag);
    }
}


// check that exception is thrown if the input of the row or colsum is an even num.

TEST_CASE("Bad input: even  input") {

    CHECK_THROWS(mat(0, 0, '!', '-'));

    CHECK_THROWS(mat(2, 2, '^', '$'));
    
    CHECK_THROWS(mat(7, 0, '*', '@'));
    
    CHECK_THROWS(mat(10, 5, '|', '!'));

    CHECK_THROWS(mat(2, 99, '$', '%'));
    
}

// check that exception is thrown if the input of the row or colsum is a negative num.

TEST_CASE("Bad input: negative  input") {

    CHECK_THROWS(mat(-1, -1, '^', '-'));
    
    CHECK_THROWS(mat(-1, 3, '^', '-'));
    
    CHECK_THROWS(mat(77, -13, '|', '!'));

    CHECK_THROWS(mat(-4, 11, '$', '%'));
    
}

// check that exception is thrown if the input of the row or colsum is not an integer.

TEST_CASE("Bad input: the input is not an integer") {

    CHECK_THROWS(mat('*', '#', '^', '-'));
    
    CHECK_THROWS(mat('#', 3, '^', '-'));
    
    CHECK_THROWS(mat(7, '%', '|', '!'));
    
}

// check that a specific exception type is thrown if the input of the row or colsum is an even num.

TEST_CASE("Bad input: negative  input") {

    CHECK_THROWS_AS(mat(-1, -1, '^', '-'), std::invalid_argument);
    
    CHECK_THROWS_AS(mat(-1, 3, '^', '-'), std::invalid_argument);
    
    CHECK_THROWS_AS(mat(77, -13, '|', '!'), std::invalid_argument);

    CHECK_THROWS_AS(mat(-4, 11, '$', '%'), std::invalid_argument);
    
}


