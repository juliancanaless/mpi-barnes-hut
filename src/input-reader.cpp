#include "input-reader.h"

std::vector<Particle>* readData(const std::string& filepath) {
    std::ifstream input(filepath);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return nullptr;
    }
    int num_pts;
    input >> num_pts;

    std::vector<Particle>* vec = new std::vector<Particle>();
    vec->reserve(num_pts);

    for (int i = 0; i < num_pts; i++) {
        std::string line;
        if (!std::getline(input, line)){
            std::cerr << "Error: ran out of lines." << std::endl;
            return nullptr;
        }
        std::stringstream ss(line);
        Particle part;
        ss >> part.index >> part.mass >> part.x_pos >> part.x_vel >> part.y_pos >> part.y_vel;
        vec->push_back(part);
    }
    return vec;
}