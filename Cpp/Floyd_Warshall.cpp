#include "Floyd_Warshall.hpp"

Floyd_Warshall::Floyd_Warshall(const uint16_t nb_of_vertices,
                               const std::vector<std::vector<long long int>> graph)
    : nb_of_vertices(nb_of_vertices),
      shortest_path_mt(graph)
{
    for (size_t i = 0; i < this->nb_of_vertices; ++i)
    {
        this->shortest_path_mt[i][i] = 0;
    }
}
// O(V)

uint16_t Floyd_Warshall::nbOfVertices() const
{
    return this->nb_of_vertices;
}

void Floyd_Warshall::printMatrix() const
{
    return;
}
