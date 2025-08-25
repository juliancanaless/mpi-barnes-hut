#include "cmdline-parser.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h> 

ArgOptions parseCommandLine(int argc, char* argv[]) {
    ArgOptions argopts;
    int opt;

    while ((opt = getopt(argc, argv, "i:o:s:t:d:V")) != -1) {
        switch (opt) {
            case 'i':
                argopts.input_file = optarg;
                break;
            case 'o':
                argopts.output_file = optarg;
                break;
            case 's':
                try {
                    argopts.steps = std::stoi(optarg);
                } catch (const std::exception& e) {
                    std::cerr << "Invalid value for -s: " << optarg << "\n";
                    std::exit(EXIT_FAILURE);
                }
                break;
            case 't':
                try {
                    argopts.theta = std::stof(optarg);
                } catch (const std::exception& e) {
                    std::cerr << "Invalid value for -t: " << optarg << "\n";
                    std::exit(EXIT_FAILURE);
                }
                break;
            case 'd':
                try {
                    argopts.timestep = std::stof(optarg);
                } catch (const std::exception& e) {
                    std::cerr << "Invalid value for -d: " << optarg << "\n";
                    std::exit(EXIT_FAILURE);
                }
                break;
            case 'V':
                argopts.viz = true;
            case '?':
                std::exit(EXIT_FAILURE);
            default:
                std::cerr << "Parsing failed.\n";
                std::exit(EXIT_FAILURE);
        }
    }

    return argopts;

}