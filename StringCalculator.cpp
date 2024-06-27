#include "StringCalculator.h"

int StringCalculator::add(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int sum = 0;
    
        // Split by comma or newline and calculate sum
        while (getline(ss, token, ',')) {
            std::stringstream ss_token(token);
            std::string subtoken;
            
            while (getline(ss_token, subtoken, '\n')) {
                int num = std::stoi(subtoken); // Convert string to integer
                if (num < 0) {
                    throw std::runtime_error("Negatives not allowed");
                }
                sum += num; // Add to sum
            }
        }
    
    return sum;
}
