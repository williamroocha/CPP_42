#include "Serializer.hpp"
#include <iostream>
#include <sstream> // For stringstream

bool isNumber(const std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i]) && !(i == 0 && str[i] == '-')) // Allow negative numbers
            return false;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac != 3) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./serializer <intValue> <stringValue>" << std::endl;
        return 1;
    }

    // Validate and parse the first argument as an integer
    if (!isNumber(av[1])) {
        std::cerr << "Error: First argument must be a valid integer." << std::endl;
        return 1;
    }
    int intValue;
    std::stringstream(av[1]) >> intValue;

    // The second argument is the string value
    std::string stringValue = av[2];

    // Create a Data object and assign the values
    Data data;
    data.intValue = intValue;
    data.stringValue = stringValue;

    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Original Data Content: " << data.intValue << ", " << data.stringValue << std::endl;

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data: " << raw << std::endl;

    // Deserialize the raw uintptr_t back to Data*
    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data Content: " << deserializedData->intValue << ", " << deserializedData->stringValue << std::endl;

    // Verify the equality
    if (deserializedData == &data) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}
