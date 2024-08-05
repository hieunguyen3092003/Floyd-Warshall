#include "Input_Handle.hpp"

Input_Handler::Input_Handler(uint16_t nb_of_vertices, uint16_t input_type)
    : nb_of_vertices(nb_of_vertices), input_type(input_type) {}

uint16_t Input_Handler::ipVerticesNum(int min, int max)
{
    system("clear");

    std::cout << "Enter the number of vertices: ";
    std::cin >> this->nb_of_vertices;
    while (!(this->nb_of_vertices >= min && this->nb_of_vertices <= max))
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between " << min << " and " << max << '\n';
        }
        else
        {
            std::cout << "Invalid number! Please enter number of vertices between " << min << " and " << max << '\n';
        }
        std::cin >> this->nb_of_vertices;
    }

    initializeGraph();

    return this->nb_of_vertices;
}

uint16_t Input_Handler::getVerticesNum() const
{
    return this->nb_of_vertices;
}

void Input_Handler::initializeGraph()
{
    this->graph.resize(this->nb_of_vertices, std::vector<long long int>(this->nb_of_vertices, INF));
}

uint16_t Input_Handler::ipInputType()
{
    system("clear");

    std::cout << "Number of Vertices: " << this->nb_of_vertices << "\n\n";

    std::cout << "1. Input as grapth" << std::setw(50) << "2. Input as single path weight \n";
    std::cout << "Please select input type: ";
    std::cin >> this->input_type;
    while (this->input_type != 1 && this->input_type != 2)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter 1 for input as grapth and 2 for input as single path weight \n";
        }
        else
        {
            std::cout << "Invalid number! Enter 1 for input as grapth and 2 for input as single path weight \n";
        }
        std::cout << "Please select input type: ";
        std::cin >> this->input_type;
    }
    return this->input_type;
}

bool Input_Handler::verifyGraph(const std::string &str) const
{
    return true;
}

void Input_Handler::devideGraph(const std::string &str, const uint16_t &vertex1, uint16_t &vertex2, long long int &weight) const
{
}

bool Input_Handler::verifyString(const std::string &str) const
{
    if (str.empty())
    {
        return false;
    }

    size_t vertex1_pos = str.find_first_not_of(' ');
    size_t vertex2_pos = str.find_first_not_of(' ', vertex1_pos + 1);
    size_t weight_pos = str.find_first_not_of(' ', vertex2_pos + 1);

    if (vertex1_pos == std::string::npos || vertex2_pos == std::string::npos || weight_pos == std::string::npos)
    {
        return false;
    }

    if (str.find_first_of(' ', weight_pos) != std::string::npos)
    {
        if (str.find_first_not_of(' ', str.find_first_of(' ', weight_pos)) != std::string::npos)
        {
            return false;
        }
    }

    if (!(str[vertex1_pos] >= 'A' && str[vertex1_pos] <= 'Z') ||
        (str[vertex1_pos] - 'A') >= this->nb_of_vertices || str[vertex1_pos + 1] != ' ')
    {
        return false;
    }

    if (!(str[vertex2_pos] >= 'A' && str[vertex2_pos] <= 'Z') ||
        (str[vertex2_pos] - 'A') >= this->nb_of_vertices || str[vertex2_pos + 1] != ' ')
    {
        return false;
    }

    if (str[weight_pos] == '-')
    {
        if ((++weight_pos) >= str.size())
        {
            return false;
        }
    }
    while (weight_pos < str.size())
    {
        if (str[weight_pos] == ' ')
        {
            break;
        }
        if (!(str[weight_pos] >= '0' && str[weight_pos] <= '9'))
        {
            return false;
        }
        ++weight_pos;
    }

    return true;
}

void Input_Handler::divideString(const std::string &str, uint16_t &vertex1, uint16_t &vertex2, long long int &weight) const
{
    int pow = 1;
    weight = 0;

    vertex1 = str[str.find_first_not_of(' ')] - 'A';
    vertex2 = str[str.find_first_not_of(' ', str.find_first_not_of(' ') + 1)] - 'A';

    for (size_t i = str.find_last_not_of(' '); str[i] != ' '; --i)
    {
        if (str[i] == '-')
        {
            weight = -weight;

            break;
        }
        weight += (str[i] - '0') * pow;
        pow *= 10;
    }

    return;
}

std::vector<std::vector<long long int>> Input_Handler::ipGraph()
{
    uint16_t vertex1 = 0;
    uint16_t vertex2 = 0;
    long long int weight = 0;
    std::string input_line("");

    (void)ipInputType();
    system("clear");

    std::cin.ignore();

    switch (this->input_type)
    {
    case 1:
    {
        std::cout << "Number of Vertices: " << this->nb_of_vertices << '\n';

        printGraph(this->nb_of_vertices, this->graph);
        std::cout << '\n';

        std::cout << "Enter the graph in the following format: \n";
        std::cout << "Distance[0][0]> <Distance[0][1]> ... <Distance[0][V]>. \n";
        std::cout << ". \n. \n. \n";
        std::cout << "Distance[V][0]> <Distance[V][1]> ... <Distance[V][V]>. \n";
        std::cout << "Input \"quit\" or \"Quit\" to finish input \n";

        while (input_line != "quit" && input_line != "Quit")
        {
            while (vertex1)
            {
                std::cout << "Row " << vertex1 << ": ";
                std::getline(std::cin, input_line);

                if (verifyGraph(input_line))
                {
                }

                ++vertex1;
            }
        }
        break;
    }
    case 2:
    {
        while (input_line != "quit" && input_line != "Quit")
        {
            std::cout << "Number of Vertices: " << this->nb_of_vertices << '\n';

            printGraph(this->nb_of_vertices, this->graph);
            std::cout << '\n';

            std::cout << "Enter the path and weight in the following format: <vertex1> <vertex2> <weight>. \n";
            std::cout << "For example, 'A B 3' means a path from vertex A to vertex B with a cost of 3. \n";
            std::cout << "Input \"quit\" or \"Quit\" to finish input \n";

            std::getline(std::cin, input_line);

            system("clear");

            if (verifyString(input_line))
            {
                divideString(input_line, vertex1, vertex2, weight);
                this->graph[vertex1][vertex2] = weight;
            }
            else
            {
                std::cout << "Invalid input! \n";
            }
        }
        break;
    }
    }

    return this->graph;
}

std::vector<std::vector<long long int>> Input_Handler::getGraph(void) const
{
    return this->graph;
}