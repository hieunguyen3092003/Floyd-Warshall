#ifndef CPP_FLOYD_WARSHALL_HPP
#define CPP_FLOYD_WARSHALL_HPP

#include "main.hpp"

class Floyd_Warshall
{
private:
    uint8_t nb_of_vertices;
    std::vector<std::vector<long long int>> shortest_path_mt;

    const long long int INF = std::numeric_limits<long long int>::max();

public:
    Floyd_Warshall(const uint8_t &nb_of_vertices);

    
};

#endif /* CPP_FLOYD_WARSHALL_HPP */