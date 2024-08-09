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
    Input_Handler(void);

    uint16_t getVerticesNum(void) const;
    std::vector<std::vector<long long int>> getGraph(void) const;

private:
    uint16_t ipVerticesNum(int min, int max);
    uint16_t ipInputType(void);
    std::vector<std::vector<long long int>> ipGraph(void);

    void initializeGraph(void);

    bool verifyGraph(const std::string &str) const;
    void devideGraph(const std::string &str, const uint16_t &vertex1, uint16_t &vertex2, long long int &weight) const;
    bool verifyString(const std::string &str) const;
    void divideString(const std::string &str, uint16_t &vertex1, uint16_t &vertex2, long long int &weight) const;
};

#endif /* CPP_INPUT_HANDLER_HPP */