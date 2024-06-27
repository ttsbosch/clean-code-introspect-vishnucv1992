#include "StringCalculator.h"

int StringCalculator::add(string input)
{
    std::stringstream ss(input);
    std::string token;
    int sum = 0;
    
    // Split by comma and calculate sum
    while (getline(ss, token, ',')) {
        sum += std::stoi(token); // Convert string to integer and sum
    }
    
    return sum;
}
