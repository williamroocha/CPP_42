/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:01:02 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/20 20:06:43 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string &fileName, const std::string &s1,
                           const std::string &s2)
    : _fileName(fileName), _s1(s1), _s2(s2),
      _fileNameReplace(fileName + ".replace") {
  openFiles();
}

FileReplacer::~FileReplacer() {

  if (_inFile.is_open())
    _inFile.close();
  if (_outFile.is_open())
    _outFile.close();

  std::cout << "✅ 🗑️ Destructor Called!" << std::endl;
}

const std::string &FileReplacer::getFileName() const { return _fileName; }

const std::string &FileReplacer::getS1() const { return _s1; }

const std::string &FileReplacer::getS2() const { return _s2; }

const std::string &FileReplacer::getFileNameRep() const {
  return _fileNameReplace;
}

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
