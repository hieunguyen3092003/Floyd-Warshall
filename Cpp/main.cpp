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
    system("clear");

    uint16_t nb_of_vertices = 0;
    uint16_t input_type = 0;

    std::cout << "Enter the number of vertices: ";
    std::cin >> nb_of_vertices;
    while (nb_of_vertices <= 0 || nb_of_vertices > 100)
    {
        std::cout << "Invalid number! Please enter number of vertices between 1 and 100 \n";
        std::cin >> nb_of_vertices;
    }

    Floyd_Warshall floyd_warshall(nb_of_vertices);

    system("clear");
    std::cout << "Number of Vertices: " << floyd_warshall.nbOfVertices() << "\n\n";

    std::cout << "1. Input as grapth" << "                " << "2. Input as single path weight \n";
    std::cout << "Please select input type: ";
    std::cin >> input_type;
    while (input_type != 1 && input_type != 2)
    {
        std::cout << "Invalid! Enter 1 for input as grapth and 2 for input as single path weight \n";
        std::cout << "Please select input type: ";
        std::cin >> input_type;
    }

    switch (input_type)
    {
    case 1:
    {

        break;
    }
    case 2:
    {
        std::string input_line = "";

        while (input_line != "quit" && input_line != "Quit")
        {
            system("clear");

            std::cout << "Number of Vertices: " << floyd_warshall.nbOfVertices() << "\n";
            floyd_warshall.printMatrix();
            std::cout << "\n";

            std::cout << "Enter the path and weight in the following format: <vertex1> <vertex2> <weight>. \n";
            std::cout << "For example, 'A B 3' means a path from vertex A to vertex B with a cost of 3. \n";

            std::getline(std::cin, input_line);
        }

        break;
    }
    }

    return 0;
}