#ifndef CPP_FLOYD_WARSHALL_HPP
#define CPP_FLOYD_WARSHALL_HPP

#include "main.hpp"

class Floyd_Warshall
{
private:
    uint16_t nb_of_vertices;
    std::vector<std::vector<long long int>> shortest_path_mt;

public:
    Floyd_Warshall(const uint16_t nb_of_vertices, const std::vector<std::vector<long long int>> graph);

    uint16_t getVerticesNum(void) const;
    std::vector<std::vector<long long int>> getShortestPathMT(void) const;

    void runAlgorithm(void);
};

#endif /* CPP_FLOYD_WARSHALL_HPP */