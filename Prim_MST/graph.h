#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <limits>
#include <iostream>
#include <numeric>
class Graph {

// Get Adjacency Matrix
std::vector<std::vector<int>> getMatrix(){
    return adjMatrix;
}

// Print Adjacency Matrix
void printMatrix(){
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < adjMatrix[i].size(); j++)
        {
            std::cout << adjMatrix[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
        
    }
    
}

public:
    // Load the graph from a file
    bool loadGraphFromFile(const std::string& filename);

    // Prim's algorithm to find MST
    int primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd);

private:
    int numNodes; // Number of nodes
    std::vector<std::vector<int>> adjMatrix; // Adjacency matrix
    const int INF = std::numeric_limits<int>::max(); // Infinity for no connection
};

#endif // GRAPH_H