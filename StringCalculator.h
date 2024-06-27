#include <string>
#include <stdexcept>
#include <sstream>

// Strategy interface for different parsing strategies
class InputParserStrategy {
public:
    virtual int parseAndCalculate(const std::string& input) const = 0;
    virtual ~InputParserStrategy() = default;
};

// Concrete strategy for comma-separated input
class CommaSeparatedParser : public InputParserStrategy {
public:
    int parseAndCalculate(const std::string& input) const override;
};

// Concrete strategy for newline-separated input
class NewlineSeparatedParser : public InputParserStrategy {
public:
    int parseAndCalculate(const std::string& input) const override;
};

// Context class that uses the strategy
class StringCalculator {
private:
    const InputParserStrategy& parserStrategy;

public:
    // Constructor with default strategy (comma-separated)
    StringCalculator();

    // Method to add integers based on current strategy
    int add(const std::string& input) const;

    // Utility function to check for negative numbers
    void checkForNegatives(const std::string& token) const;
};
