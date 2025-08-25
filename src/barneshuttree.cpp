#include "barneshuttree.h"


Node* createNode(float xCenter, float yCenter, float length, Particle* p) {
    Node* node = new Node();
    node->xCenter = xCenter;
    node->yCenter = yCenter;
    node->length = length;
    node->p = p;
    if (p == nullptr) {
        node->emptySpace = true;
    } else {
        node->emptySpace = false;
    }
    node->xCenterMass = -1;
    node->yCenterMass = -1;
    for (int i = 0; i < 4; i++){
        node->children[i] = nullptr;
    }
}

void addParticle(Particle* p) {

}

Node* constructBarnesHutTree(std::vector<Particle>* data) {
    // pick particle

    // add particle to tree

    // 
}