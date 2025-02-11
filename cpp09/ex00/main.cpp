#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Invalid number of arguments." << std::endl;
    return 1;
  }

  try {
    BitcoinExchange btc("bitcoin_prices.csv"); // Pass the database file
    btc.processInput(argv[1]);                 // Pass the input file
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}

// The main function reads the input file from the command line and creates a
// BitcoinExchange object with the database file "bitcoin_prices.csv". It then
// calls the processInput method to process the input file and print the
// results. If an exception is caught, it prints the error message and
// returns 1. Otherwise, it returns 0 to indicate successful execution