#ifndef INPUT_HEADER
#define INPUT_HEADER

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "particle.h"

/*
Reads the input file.
Returns vector of particles if successful or null if not.
*/
std::vector<Particle>* readData(const std::string& filepath);

#endif