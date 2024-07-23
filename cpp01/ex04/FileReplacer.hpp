/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:52:37 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 08:47:06 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <fstream>
#include <iostream>
#include <string>

class FileReplacer {

private:
  std::string _fileName;
  std::string _s1;
  std::string _s2;

  std::string _fileNameReplace;

  std::ifstream _inFile;
  std::ofstream _outFile;

public:
  FileReplacer(std::string &fileName, std::string &s1, std::string &s2);
  ~FileReplacer();

  void openFiles();
  void closeFiles();
  void replace();
};

std::string ft_replace(const std::string &str, const std::string &from,
                       const std::string &to);

#endif