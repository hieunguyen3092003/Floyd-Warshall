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
    Input_Handler input_handler;

    Floyd_Warshall floyd_warshall(input_handler.getValidatedVertices(1, 100),
                                  input_handler.getGraph());

    return 0;
}

void tc()
{
    std::vector<std::vector<long long int>> graph = {{INF, 5, INF, 10},
                                                     {INF, 0, 3, INF},
                                                     {3, INF, 0, 1},
                                                     {INF, INF, INF, 0}};
    Floyd_Warshall floyd_warshall(4, graph);
    return;
}