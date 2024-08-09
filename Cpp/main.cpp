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
void tc1(void);
void tc2(void);

int main()
{
    // tc();

    Input_Handler input_handler;

    Floyd_Warshall floyd_warshall(input_handler.getVerticesNum(),
                                  input_handler.getGraph());

    floyd_warshall.runAlgorithm();

    return 0;
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

void tc()
{
    std::vector<std::vector<long long int>> graph = {{0, 4, INF, 5, INF},
                                                     {INF, 0, 1, INF, 6},
                                                     {2, INF, 0, 3, INF},
                                                     {INF, INF, 1, 0, 2},
                                                     {1, INF, INF, 4, 0}};
    Floyd_Warshall floyd_warshall(5, graph);

    floyd_warshall.runAlgorithm();
    return;
}

void tc1()
{
    std::vector<std::vector<long long int>> graph = {{INF, 5, INF, 10},
                                                     {INF, 0, 3, INF},
                                                     {3, INF, INF, 1},
                                                     {INF, INF, INF, 0}};
    Floyd_Warshall floyd_warshall(4, graph);

    floyd_warshall.runAlgorithm();

    return;
}

void tc2()
{
    std::vector<std::vector<long long int>> graph = {{0, 2, INF, 8, INF},
                                                     {INF, 1, 4, INF, 5},
                                                     {7, INF, INF, 2, INF},
                                                     {INF, 3, INF, 0, 6},
                                                     {INF, INF, 9, INF, 4}};
    Floyd_Warshall floyd_warshall(5, graph);

    floyd_warshall.runAlgorithm();

    return;
}