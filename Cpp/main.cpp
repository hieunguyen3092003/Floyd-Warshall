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

    (void)input_handler.ipVerticesNum(1, 100);
    (void)input_handler.ipGraph();

    Floyd_Warshall floyd_warshall(input_handler.getVerticesNum(),
                                  input_handler.getGraph());

    floyd_warshall.runAlgorithm();

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