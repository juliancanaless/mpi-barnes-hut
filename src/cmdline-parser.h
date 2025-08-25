#ifndef CMDLINE_PARSER
#define CMDLINE_PARSER

#include <string>

/*
Struct that contains command line arguments
*/
struct ArgOptions {
    std::string input_file;
    std::string output_file;
    int steps;
    double theta;
    double timestep;
    bool viz;
};

/*
Will parse command line arguments and populate the ArgOptions struct
*/
ArgOptions parseCommandLine(int argc, char* argv[]);

#endif