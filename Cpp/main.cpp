#include "main.hpp"
#include "Floyd_Warshall.hpp"

/*
                /\/\
               /'^.^)
        .-^^^-/  /
     _/         /7
    <__.|_|--|_|
*/

int main()
{
    uint8_t nb_of_vertices = 0;

    std::cout << "Enter the number of vertices: " << std::endl;
    std::cin >> nb_of_vertices;

    while (nb_of_vertices <= 0 || nb_of_vertices > 100)
    {
        std::cout << "Invalid number! Please enter number of vertices between 1 and 100" << std::endl;
        std::cin >> nb_of_vertices;
    }

    Floyd_Warshall Fw(nb_of_vertices);

    return 0;
}