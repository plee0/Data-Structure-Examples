#include "graph.h"
#include <fstream>
#include <iostream>
#include <queue>;
// number of edges established as a global variable
int numEdges;

// Return sum of vector array
int returnSum(std::vector<int> &vec){
    return std::accumulate(vec.begin(), vec.end(), 0);
}

// Returns a vector containing the position and minimum value of the vector
// vector[0] = position
// vector[1] = minimum value
std::vector<int> returnVillage(std::vector<int> &vec, std::vector<int> &vecVisited, int val){
    
    std::vector<int> min(2, val);
    for (int i = 0; i < vec.size(); i++)
    {
        // Condition 1: update minimum condition
        // Condition 2: Ignore vectors already visited
        if (vec[i] < min[1] && vecVisited[i] != true) {
            min[1] = vec[i];
            min[0] = i;
        }
    }
    return min;
}

// comparator for priority queue to sort by LOWEST weight
// priority queue is structured using a vector<int> with the below indexes:
// index 0: from village
// index 1: to village
// index 2: weight <-- sort criteria
struct sortByWeight {
    bool operator()(std::vector<int> const& a, std::vector<int> const& b) const {
        return a[2] > b[2];
    }
};

// Load the graph from a file
bool Graph::loadGraphFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return false;
    }

    infile >> numNodes >> numEdges;
    
    // u = village 1
    // v = village 2
    // w = weight
    int u, v, w;

    // Implement the adjacency matrix setup
    // Resize to a 5x5 with all INFS
    adjMatrix.resize(numNodes);
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        adjMatrix[i].resize(numNodes,INF);
    }
    
    // Change all diagonals to 0
    for (int i = 0; i < numNodes; i++)
    {
        adjMatrix[i][i] = 0;
    }

    // Continue to read from file "input.txt" and feed those weights into the respective locations in the array
    bool lineRead = false;
    for (int i = 0; i < numEdges; i++)
    {

        infile >> u;
        infile >> v;
        infile >> w;
        /*
        try
        {
            infile >> u >> v >> w;

        }
        catch (const std::exception&)
        {
            std::cout << "A disconnected Village: " << u << " has been detected." << std::endl;

        }
        // if (lineRead == true) {
            adjMatrix[u - 1][v - 1] = w;
            adjMatrix[v - 1][u - 1] = w;
        // }
        // lineRead = false;
        */
        adjMatrix[u - 1][v - 1] = w;
        adjMatrix[v - 1][u - 1] = w;
    }

    
    // Comment this line before submission
    // Graph::printMatrix();
    // std::cout << "TODO: Adjaceny Matrix Complete. Implement adjacency matrix handling edge cases.\n";

    infile.close();
    return true;
}

// Prim's algorithm to find the MST
int Graph::primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd) {

    // Steps:
    // 1. Initialize visited array and minWeight array
    std::vector<int> visitedArray, minWeight;
    //std::vector<int> mstWeight;

    // visitedArray keeps track of which elements are part of the MST tree
    visitedArray.resize(numNodes, false);
    
    // minWeight used to keep track corresponding weights to villages
    minWeight.resize(numNodes, INF);

    // initialize a priority_queue
    std::priority_queue< std::vector<int>, std::vector<std::vector<int>>, sortByWeight> myQueue;
    
    /*
    * For debugging purposes only
    myQueue.push({ 1, 2, 4 }); // from village 1 to village 2 with weight 4
    myQueue.push({ 1, 3, 3 }); // from village 1 to village 3 with weight 3
    myQueue.push({ 1, 5, 1 }); // from village 1 to village 3 with weight 3

    std::cout << "Elements of the items in the top of the priority queue." << std::endl;
    std::cout << "From Village: " << myQueue.top()[0] << std::endl;
    std::cout << "To Village: " << myQueue.top()[1] << std::endl;
    std::cout << "Weight: " << myQueue.top()[2] << std::endl;
    */


    // 2. Start from Village 1
    int startingVillage = 3;
    int villageIndex = startingVillage - 1;
    visitedArray[villageIndex] = true;
    minWeight[villageIndex] = 0;

    // 3. Use a loop to find the minimum weight edge at each step
    // Property of mst algorithm is that # edges is always 1 less than numNodes
    while (mstStart.size() < numNodes - 1) {
        // loop through all Nodes to update weights
        for (int i = 0; i < numNodes; i++)
        {
            // Condition: do not search the weight of any villages that have already
            // been checked
            if (visitedArray[i] != true) {
                // if current weight is greater than weight of some other village, update the minimum
                // and store push into queue
                if (minWeight[i] > adjMatrix[villageIndex][i]) {
                    minWeight[i] = adjMatrix[villageIndex][i];
                    myQueue.push({ villageIndex, i, minWeight[i] });
                }
            }
        }
        // 4. Update MST edges (mstStart and mstEnd vectors)
        int fromVillage = myQueue.top()[0];
        int toVillage = myQueue.top()[1];
        //int weight = myQueue.top()[2];

        // do not push any items where MST already connnected
        // instead, just jump directly to pop() to remove item from priority queue
        if (visitedArray[toVillage] != true) {
            mstStart.push_back(fromVillage + 1);
            mstEnd.push_back(toVillage + 1);
            //mstWeight.push_back(weight);
            villageIndex = toVillage; // next village
            visitedArray[villageIndex] = true;
        }
        
        myQueue.pop();
    }
        // 5. Return the total cost of the MST
        return returnSum(minWeight); // TODO: Return the actual total cost of the MST
    }