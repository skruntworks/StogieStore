#include "StogieStore.h"

StogieStore::StogieStore(std::string path)
{
  this->path = path;
  int index = 0;
  std::fstream file(path);
  while (file)
  {
    int quantity, ring;
    double length;
    std::string brand, name;
    file >> quantity; file.ignore();
    getline(file, brand, ',');
    getline(file, name, ',');
    file >> length; file.ignore();
    file >> ring; file.ignore();

    Cigar* currentCigar = new Cigar(index, quantity, brand, name, length, ring);
    ++index;

    humidor.push_back(currentCigar);
    delete currentCigar;
  }
}

void StogieStore::addCigar(Cigar* c)
{
  humidor.push_back(c);
  delete c;
}

void StogieStore::removeCigar(int index)
{
  humidor.erase(humidor.begin() + (index - 1));
}

void StogieStore::updateIndices()
{
  int newIndex = 0;
  for (auto i : humidor)
  {
    i->setIndex(newIndex);
    ++newIndex;
  }
}

std::string StogieStore::getHumidor()
{
  std::string ret;
  ret += std::string("Index") + "   " + "Quantity" + "   " + "Brand" + "   " + "Name" + "   " + "Length"  + "   " + "Ring\n";
  for (auto i : humidor)
  {
    std::string tmpCigar = (i->getSimpleString() + '\n');
    ret += tmpCigar;
  }
  ret += "\n";
  return ret;
}

void StogieStore::saveHumidor()
{
  std::ofstream outFile;
  outFile.open(path);

  std::string outStr;

  for (auto i : humidor)
  {
    outStr += i->getCSVString() + '\n';
  }

  outStr.pop_back(); // Remove trailing newline
  outFile << outStr;
  outFile.close();
}
