#ifndef CPP_INPUT_HANDLER_HPP
#define CPP_INPUT_HANDLER_HPP

#include "main.hpp"

class Input_Handler
{
private:
    uint16_t nb_of_vertices;
    uint16_t input_type;
    std::vector<std::vector<long long int>> graph;

public:
    Input_Handler(uint16_t nb_of_vertices = 0, uint16_t input_type = 0);

    int getValidatedVertices(int min, int max);
    void initializeGraph(void);
    uint16_t getInputType(void);

    bool verifyString(const std::string &str) const;
    void divideString(const std::string &str, uint16_t &vertex1, uint16_t &vertex2, long long int &weight) const;
    std::vector<std::vector<long long int>> getGraph(void);

    void printGraph(void) const;
};

#endif /* CPP_INPUT_HANDLER_HPP */