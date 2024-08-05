#ifndef CPP_MAIN_HPP
#define CPP_MAIN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <iomanip>
#include <cmath>

void printGraph(const uint16_t nb_of_vertices, const std::vector<std::vector<long long int>> &graph);

constexpr long long int INF = std::numeric_limits<long long int>::max();

#endif /* CPP_MAIN_HPP */