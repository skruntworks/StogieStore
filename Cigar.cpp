#include "Cigar.h"

Cigar::Cigar(int index, int quantity, std::string brand, std::string name, double length, int ring)
{
  this->index = index;
  this->quantity = quantity;
  this->brand = brand;
  this->name = name;
  this->length = length;
  this->ring = ring;
}

std::string Cigar::getSimpleString()
{
  std::string ret;

  ret =
  std::to_string(index + 1) +
  "   " +
  std::to_string(quantity) +
  "   " +
  brand +
  "   " +
  name +
  "   " +
  std::to_string(length).substr(0,3) +
  "   " +
  std::to_string(ring);

  return ret;
}

std::string Cigar::getCSVString()
{
  std::string ret;

  ret =
  std::to_string(quantity) +
  "," +
  brand +
  "," +
  name +
  "," +
  std::to_string(length).substr(0,3) +
  "," +
  std::to_string(ring);

  return ret;
}

std::string Cigar::getFormattedString()
{
  std::string ret;

  ret =
  "Quantity: " +
  std::to_string(quantity) +
  '\n' +
  "Brand: " +
  brand +
  '\n' +
  "Name: " +
  name +
  '\n' +
  "Length: " +
  std::to_string(length).substr(0,3) +
  '\n' +
  "Ring: " +
  std::to_string(ring) +
  '\n';

  return ret;
}

void Cigar::setIndex(int index)
{
  this->index = index;
}
