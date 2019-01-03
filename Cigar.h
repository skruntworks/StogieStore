#ifndef CIGAR_H_
#define CIGAR_H_

#include <string>

class Cigar
{
private:
  int index;
  int quantity;
  std::string brand;
  std::string name;
  double length;
  int ring;
public:
  Cigar(int index, int quantity, std::string brand, std::string name, double length, int ring);
  std::string getSimpleString();
  std::string getCSVString();
  std::string getFormattedString();
  void setIndex(int index);
};

#endif
