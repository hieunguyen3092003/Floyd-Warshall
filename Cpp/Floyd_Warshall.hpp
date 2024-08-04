#ifndef CPP_FLOYD_WARSHALL_HPP
#define CPP_FLOYD_WARSHALL_HPP

#include "main.hpp"

class Floyd_Warshall
{
private:
    uint16_t nb_of_vertices;
    std::vector<std::vector<long long int>> shortest_path_mt;

    const long long int INF = std::numeric_limits<long long int>::max();

public:
    Floyd_Warshall(const uint16_t nb_of_vertices);

    uint16_t nbOfVertices(void) const;
    void addEdge(const uint8_t vertex1, const uint8_t vertex2, const long long int weight);
    void printMatrix(void) const;
};

#endif /* CPP_FLOYD_WARSHALL_HPP */