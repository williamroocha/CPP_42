#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile) {
  parseDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    this->prices = other.prices;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Parse the database file and store the prices in a map
void BitcoinExchange::parseDatabase(const std::string &dbFile) {
  std::ifstream file(dbFile.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: Could not open database file.");
  }

  std::string line;
  bool isHeader = true;
  while (std::getline(file, line)) {
    if (isHeader) {
      isHeader = false;
      continue;
    }

    std::istringstream ss(line);
    std::string date;
    float price;

    if (std::getline(ss, date, ',') && ss >> price) {
      prices[date] = price;
    }
  }
  file.close();
}

// Check if the date is valid
bool BitcoinExchange::isValidDate(const std::string &date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year, month, day;
  std::istringstream(date.substr(0, 4)) >> year;
  std::istringstream(date.substr(5, 2)) >> month;
  std::istringstream(date.substr(8, 2)) >> day;

  if (month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2 && day > (isLeapYear(year) ? 29 : 28))
    return false;

  return true;
}

// Check if the year is a leap year
bool BitcoinExchange::isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Trim leading and trailing spaces from a string
std::string BitcoinExchange::trim(const std::string &str) {
  size_t first = str.find_first_not_of(" ");
  size_t last = str.find_last_not_of(" ");
  return str.substr(first, (last - first + 1));
}

// Process a single line of input and calculate the Bitcoin value
void BitcoinExchange::processLine(const std::string &line) {
  std::istringstream ss(line);
  std::string date, valueStr;
  float value;

  if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
    date = trim(date);
    std::istringstream(valueStr) >> value;

    if (!isValidDate(date)) {
      throw std::runtime_error("Error: Invalid date.");
    }
    if (value < 0 || value > 1000) {
      throw std::runtime_error("Error: Value out of range.");
    }

    std::map<std::string, float>::iterator it = prices.lower_bound(date);
    if (it == prices.begin() && it->first != date) {
      throw std::runtime_error("Error: No data for date " + date);
    }
    if (it == prices.end() || it->first != date)
      --it;

    float price = it->second;
    std::cout << date << " => " << value << " = " << (value * price)
              << std::endl;
  } else {
    throw std::runtime_error("Error: Bad input format.");
  }
}

// Process the input file and calculate the Bitcoin value for each entry
void BitcoinExchange::processInput(const std::string &inputFile) {
  std::ifstream file(inputFile.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: Could not open input file.");
  }

  std::string line;
  while (std::getline(file, line)) {
    try {
      processLine(line);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  file.close();
}