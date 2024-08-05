#include "main.hpp"
#include "Floyd_Warshall.hpp"
#include "Input_Handle.hpp"

/*
                /\/\
               /'^.^)
       _.-^^^-/  /
     _/         /7
    <__.|_|--|_|
*/

void tc(void);

int main()
{
    Input_Handler input_handler(0, 0);

    (void)input_handler.ipVerticesNum(1, 8);
    (void)input_handler.ipGraph();

    Floyd_Warshall floyd_warshall(input_handler.getVerticesNum(),
                                  input_handler.getGraph());

    floyd_warshall.runAlgorithm();

    // tc();

    return 0;
}

void tc()
{
    std::vector<std::vector<long long int>> graph = {{INF, 5, INF, 10},
                                                     {INF, 0, 3, INF},
                                                     {3, INF, 0, 1},
                                                     {INF, INF, INF, 0}};

    Floyd_Warshall floyd_warshall(4, graph);

    floyd_warshall.runAlgorithm();

    return;
}

void printGraph(const uint16_t nb_of_vertices, const std::vector<std::vector<long long int>> &graph)
{
    for (size_t i = 0; i < nb_of_vertices; ++i)
    {
        std::cout << std::setw(14) << static_cast<char>('A' + i);
    }

    std::cout << '\n';

    for (size_t i = 0; i < nb_of_vertices; ++i)
    {
        std::cout << std::setw(2) << static_cast<char>('A' + i);

        for (const auto &elem : graph[i])
        {
            if (elem == INF)
            {
                std::cout << std::setw(12) << "INF" << std::setw(2) << '|';
            }
            else
            {
                std::cout << std::setw(12) << elem << std::setw(2) << '|';
            }
        }
        std::cout << '\n';
    }
}