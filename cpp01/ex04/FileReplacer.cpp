/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:01:02 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 08:50:44 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

// Constructor
FileReplacer::FileReplacer(std::string &fileName, std::string &s1,
                           std::string &s2) {
  this->_fileName = fileName;
  this->_s1 = s1;
  this->_s2 = s2;
  this->_fileNameReplace = fileName.append(".replace");
  openFiles();
}

// Destructor
FileReplacer::~FileReplacer() { closeFiles(); }

// Open files
void FileReplacer::openFiles() {
  _inFile.open(this->_fileName.c_str());
  if (!_inFile.is_open()) {
    std::cerr << "🚨 Error: Could not open input file " << this->_fileName
              << " or file does not exist! 🚨" << std::endl;
    return;
  }

  _outFile.open(this->_fileNameReplace.c_str());
  if (!_outFile.is_open()) {
    std::cerr << "🚨 Error: Could not open output file "
              << this->_fileNameReplace << "! 🚨" << std::endl;
    return;
  }
}

// Close files
void FileReplacer::closeFiles() {
  if (_inFile.is_open())
    _inFile.close();
  if (_outFile.is_open())
    _outFile.close();
}

// Replace
std::string ft_replace(const std::string &str, const std::string &from,
                       const std::string &to) {
  std::string result = str;
  size_t start_pos = 0;
  while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
    result.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
  return result;
}

void FileReplacer::replace() {
  std::string line;
  std::string replacedLine;

  while (std::getline(_inFile, line)) {
    replacedLine = ft_replace(line, _s1, _s2);
    _outFile << replacedLine << std::endl;
  }
  std::cout << "✅ 📝 File " << _fileName << " has been replaced successfully!"
            << std::endl;
}
