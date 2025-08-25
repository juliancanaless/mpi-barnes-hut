#include "cmdline-parser.h"
#include "input-reader.h"

int main (int argc, char* argv[]) {
    // read command line 
    ArgOptions opts = parseCommandLine(argc, argv);

    // read input file
    std::vector<Particle>* data = readData(opts.input_file);

    // construct tree
    

}