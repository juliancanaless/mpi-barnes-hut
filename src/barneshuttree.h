
#include <vector>
#include "particle.h"

struct Node {
    bool emptySpace;
    float xCenter;
    float yCenter;
    float length;
    Particle* p;
    float xCenterMass;
    float yCenterMass;
    Node* children[4];
};

Node* createNode(float xCenter, float yCenter, float length, Particle* p);

// add point to tree
void addParticle(Particle* p);

// redistributes points helper

// 
Node* constructBarnesHutTree(std::vector<Particle>* data);