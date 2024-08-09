#include "Floyd_Warshall.hpp"

Floyd_Warshall::Floyd_Warshall(const uint16_t nb_of_vertices,
                               const std::vector<std::vector<long long int>> graph)
    : nb_of_vertices(nb_of_vertices),
      shortest_path_mt(graph)
{
    if (this->nb_of_vertices != this->shortest_path_mt.size())
    {
        throw std::invalid_argument("The number of vertices does not match the size of the graph matrix");
    }

    for (const auto &row : graph)
    {
        if (row.size() != this->nb_of_vertices)
        {
            throw std::invalid_argument("Graph matrix is not square");
        }
    }
}

// O(V)

uint16_t Floyd_Warshall::getVerticesNum() const
{
    return this->nb_of_vertices;
}

std::vector<std::vector<long long int>> Floyd_Warshall::getShortestPathMT() const
{
    return this->shortest_path_mt;
}

void Floyd_Warshall::runAlgorithm()
{
    system("clear");

    std::cout << "Input Graph \n";
    printGraph(this->nb_of_vertices, this->shortest_path_mt);

    std::cout << "\nStep 1: Assign 0 to Distance[i][j] if i == j (distance to itself is zero). \n";
    for (size_t i = 0; i < this->nb_of_vertices; ++i)
    {
        this->shortest_path_mt[i][i] = 0;
    }
    printGraph(this->nb_of_vertices, this->shortest_path_mt);

    for (size_t k = 0; k < this->nb_of_vertices; ++k)
    {
        std::cout << '\n'
                  << "Step " << k + 2 << " Treat node " << static_cast<char>('A' + k) << " as an intermediate node and calculate the Distance[][] for every {i,j} node pair using the formula: \n";
        std::cout << "Distance[i][j] = minimum(Distance[i][j], (Distance from i to " << static_cast<char>('A' + k) << ") + (Distance from " << static_cast<char>('A' + k) << " to j)) \n";

        for (size_t i = 0; i < this->nb_of_vertices; ++i)
        {
            for (size_t j = 0; j < this->nb_of_vertices; ++j)
            {
                if (shortest_path_mt[i][k] != INF && shortest_path_mt[k][j] != INF)
                {
                    shortest_path_mt[i][j] = std::min(shortest_path_mt[i][j], shortest_path_mt[i][k] + shortest_path_mt[k][j]);
                }
            }
        }
        printGraph(this->nb_of_vertices, this->shortest_path_mt);
    }
}
