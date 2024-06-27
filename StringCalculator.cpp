#include "StringCalculator.h"

#include <stdexcept>

// Strategy interface for different parsing strategies
class InputParserStrategy {
public:
    virtual int parseAndCalculate(const std::string& input) = 0;
};

// Concrete strategy for comma-separated input
class CommaSeparatedParser : public InputParserStrategy {
public:
    int parseAndCalculate(const std::string& input) override;
};

// Concrete strategy for newline-separated input
class NewlineSeparatedParser : public InputParserStrategy {
public:
    int parseAndCalculate(const std::string& input) override;
};

// Context class that uses the strategy
class StringCalculator {
private:
    InputParserStrategy* parserStrategy;

public:
    StringCalculator(InputParserStrategy* strategy) : parserStrategy(strategy) {}

    // Method to add integers based on current strategy
    int add(const std::string& input);

    // Utility function to check for negative numbers
    void checkForNegatives(const std::string& token);
};
