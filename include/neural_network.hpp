#pragma once
#include <glad/glad.h>
#include <vector>

class NeuralNetwork {
public:
    NeuralNetwork();  // Constructor declaration
    ~NeuralNetwork() = default;  // Default destructor
    
    void forward();
    
private:
    // We'll add actual neural network components later
    // For now, just a placeholder
    std::vector<float> m_weights;
};