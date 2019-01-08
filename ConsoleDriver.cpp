#include "ConsoleDriver.h"

ConsoleDriver::ConsoleDriver()
{
  char ch = '\0';

  while (ch != 'n')
  {
    std::cout << "Create new humidor?" << std::endl;
    ch = _getch();
    if (ch == 'y')
    {
      std::cout << "Enter humidor filename: ";
      std::string filename;
      getline(std::cin, filename);
      std::fstream file;
      file.open(filename, std::fstream::out);
      break;
    }
  }
}

ConsoleDriver::ConsoleDriver(std::string path)
{
  ss = new StogieStore(path);
  changesFlag = false;
  char ch = '0';
  while (ch != '5')
  {
    ch = '0';
    std::cout << "Current database: " << path << std::endl;
  	printMenu();
    ch = _getch();

    switch (ch)
    {
      case '1':
      std::cout << ss->getHumidor();
      break;
      case '2':
      changesFlag = true;
      ss->addCigar(inputCigarPrompt(ss->getHumidorSize()));
      break;
      case '3':
      changesFlag = true;
      ss->removeCigar(removeCigarPrompt());
      ss->updateIndices();
      break;
      case '4':
      changesFlag = false;
      ss->saveHumidor();
      break;
      case '5':
      if (changesFlag)
        saveChangesPrompt();
      break;
      default:
      break;
    }
  }
  delete ss;
}
void ConsoleDriver::printMenu()
{
  std::cout << std::endl;
  std::cout << "1. Print cigar database" << std::endl;
	std::cout << "2. Add entry" << std::endl;
	std::cout << "3. Delete entry" << std::endl;
	std::cout << "4. Save changes" << std::endl;
	std::cout << "5. Quit" << std::endl;
}

Cigar* ConsoleDriver::inputCigarPrompt(size_t index)
{
  std::string brand, name;
  int quantity, ring;
  double length;
  std::cout << "Cigar Input" << std::endl;
  std::cout << "Enter brand: ";
  getline(std::cin, brand);
  std::cout << "Enter name: ";
  getline(std::cin, name);
  std::cout << "Enter length: ";
  std::cin >> length; std::cin.ignore();
  std::cout << "Enter ring: ";
  std::cin >> ring; std::cin.ignore();
  std::cout << "Enter quantity: ";
  std::cin >> quantity; std::cin.ignore();

  Cigar* in = new Cigar(index, quantity, brand, name, length, ring);

  return in;
}

int ConsoleDriver::removeCigarPrompt()
{
  int i;
  printMenu();
  std::cout << "Enter index to delete: ";
  std::cin >> i; std::cin.ignore();
  return i;
}

void ConsoleDriver::saveChangesPrompt()
{
  char ch = '0';
  std::cout << "Warning, unsaved changes." << std::endl;
  while(ch != 'y' || ch != 'n')
  {
    std::cout << "Save changes? y/n" << std::endl;
    ch = _getch();
    switch(ch)
    {
      case 'y':
      ss->saveHumidor();
      case 'n':
      exit(EXIT_SUCCESS);
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    ConsoleDriver* cd = new ConsoleDriver;
    delete cd;
    return 0;
  }
  ConsoleDriver* cd = new ConsoleDriver(argv[1]);
  delete cd;
  return 0;
}
