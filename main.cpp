#include "Test.h"
#include <iostream>
using namespace std;

void initialize_distances(int* path, int* distance, int size, int origin)
{
    for (int i = 0; i < size; ++i){
        path[i] = -1;
        distance[i] = 999999;
    }
    path[origin] = 0;
    distance[origin] = 0;
}

int* getShortestPath(int** graph, int size, int origin)
{
    int* path = new int[size];
    int* distance = new int[size];
    initialize_distances(path, distance, size, origin);
    
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j)
        {
            int weight = graph[i][j];
            if(weight!=-1 && (distance[i] + weight < distance[j])){
                distance[j] = distance[i] + weight;
                path[j] = i;
            }
        }
    }

    return path;
}

int main ()
{
    test();
    return 0;
}
