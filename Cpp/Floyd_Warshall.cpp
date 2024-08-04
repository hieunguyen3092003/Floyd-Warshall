#include "Floyd_Warshall.hpp"

Floyd_Warshall::Floyd_Warshall(const uint16_t nb_of_vertices)
    : nb_of_vertices(nb_of_vertices),
      shortest_path_mt(nb_of_vertices, std::vector<long long int>(nb_of_vertices, this->INF))
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

void Floyd_Warshall::addEdge(const uint8_t vertex1, const uint8_t vertex2, const long long int weight)
{
    return;
}

void Floyd_Warshall::printMatrix() const
{
    return;
}
