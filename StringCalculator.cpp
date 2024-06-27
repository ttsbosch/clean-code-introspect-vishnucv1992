#include "StringCalculator.h"

// Implementation of comma-separated parsing strategy
int CommaSeparatedParser::parseAndCalculate(const std::string& input) const {
    std::stringstream ss(input);
    std::string token;
    int sum = 0;

    while (getline(ss, token, ',')) {
        std::stringstream ss_token(token);
        std::string subtoken;

        while (getline(ss_token, subtoken, '\n')) {
            int num = std::stoi(subtoken);
            sum += num;
        }
    }

    return sum;
}

// Implementation of newline-separated parsing strategy
int NewlineSeparatedParser::parseAndCalculate(const std::string& input) const {
    std::stringstream ss(input);
    std::string token;
    int sum = 0;

    while (getline(ss, token, '\n')) {
        int num = std::stoi(token);
        sum += num;
    }

    return sum;
}

// Constructor with default strategy (comma-separated)
StringCalculator::StringCalculator() : parserStrategy(CommaSeparatedParser()) {}

// Method to add integers based on current strategy
int StringCalculator::add(const std::string& input) const {
    int sum = parserStrategy.parseAndCalculate(input);
    return sum;
}

// Utility function to check for negative numbers
void StringCalculator::checkForNegatives(const std::string& token) const {
    int num = std::stoi(token);
    if (num < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
}
