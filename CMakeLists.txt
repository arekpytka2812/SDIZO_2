cmake_minimum_required(VERSION 3.20)
project(SDIZO_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDIZO_2 main.cpp Structures/IncidenceMatrix/IncidenceMatrix.cpp Structures/IncidenceMatrix/IncidenceMatrix.h main.h Structures/NeighboursList/NeighboursList.cpp Structures/NeighboursList/NeighboursList.h Algorithms/Prim/PrimAlgorithm.cpp Algorithms/Prim/PrimAlgorithm.h Structures/EdgeHeap/Heap.cpp Structures/EdgeHeap/Heap.h Utility/FileManager/FileManager.cpp Utility/FileManager/FileManager.h Algorithms/Dijsktra/DijkstraAlgorithm.cpp Algorithms/Dijsktra/DijkstraAlgorithm.h Utility/GraphGenerator/GraphGenerator.cpp Utility/GraphGenerator/GraphGenerator.h)
