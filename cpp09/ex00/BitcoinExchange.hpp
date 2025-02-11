#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> prices;

  void parseDatabase(const std::string &dbFile);
  void processLine(const std::string &line);
  bool isValidDate(const std::string &date);
  bool isLeapYear(int year);
  std::string trim(const std::string &str);

public:
  BitcoinExchange();
  BitcoinExchange(const std::string &dbFile);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void processInput(const std::string &inputFile);
};

#endif
