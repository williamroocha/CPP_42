/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:52:37 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/20 20:00:01 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <fstream>
#include <iostream>
#include <string>

class FileReplacer {

private:
  const std::string _fileName;
  const std::string _s1;
  const std::string _s2;

  const std::string _fileNameReplace;

  std::ifstream _inFile;
  std::ofstream _outFile;

public:
  FileReplacer(const std::string &fileName, const std::string &s1,
               const std::string &s2);
  ~FileReplacer();

  const std::string &getFileName() const;
  const std::string &getFileNameRep() const;
  const std::string &getS1() const;
  const std::string &getS2() const;

  void openFiles();
  void replace();
};

std::string ft_replace(const std::string &str, const std::string &from,
                       const std::string &to);

#endif