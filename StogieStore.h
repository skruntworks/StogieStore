#ifndef STOGIESTORE_H_
#define STOGIESTORE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "Cigar.h"

class StogieStore // Should contain no actual console implementation
{
private:
	std::vector<Cigar*> humidor;
	std::string path;
public:
	StogieStore(std::string path);
	// Humidor controls
	void addCigar(Cigar* c);
	void removeCigar(int index);
	void updateIndices();
	// Humidor I/O
	std::string getHumidor();
	void saveHumidor();
	size_t getHumidorSize() { return humidor.size(); };
};

#endif
