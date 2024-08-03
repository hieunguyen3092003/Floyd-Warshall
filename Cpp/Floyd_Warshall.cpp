#include "Floyd_Warshall.hpp"

Floyd_Warshall::Floyd_Warshall(const uint8_t &nb_of_vertices)
    : nb_of_vertices(nb_of_vertices),
      shortest_path_mt(nb_of_vertices, std::vector<long long int>(nb_of_vertices, this->INF))
{
    for (size_t i = 0; i < this->nb_of_vertices; ++i)
    {
        this->shortest_path_mt[i][i] == 0;
    }
}
// O(V)

