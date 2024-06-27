#include "StringCalculator.h"

int StringCalculator::add(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int sum = 0;
    
        // Split by comma and calculate sum
        while (getline(ss, token, ',')) {
            int num = std::stoi(token); // Convert string to integer
            if (num < 0) {
                throw std::runtime_error("Negatives not allowed");
            }
            sum += num; // Add to sum
        }
    
    return sum;
}
