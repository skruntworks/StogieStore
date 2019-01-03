#ifndef CONSOLEDRIVER_H_
#define CONSOLEDRIVER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "StogieStore.h"
#include "Cigar.h"

class ConsoleDriver
{
private:
  bool changesFlag;
  StogieStore* ss;
public:
  ConsoleDriver();
  ConsoleDriver(std::string path);
  void printMenu();
  Cigar* inputCigarPrompt(int index);
  int removeCigarPrompt();
  void saveChangesPrompt();
};

int main(int argc, char *argv[]);

#endif