cmake_minimum_required(VERSION 3.20)
project(SDIZO_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDIZO_2 main.cpp Structures/IncidenceMatrix/IncidenceMatrix.cpp Structures/IncidenceMatrix/IncidenceMatrix.h main.h Structures/NeighboursList/NeighboursList.cpp Structures/NeighboursList/NeighboursList.h Algorithms/Prim/Prim.cpp Algorithms/Prim/Prim.h Structures/EdgeHeap/Heap.cpp Structures/EdgeHeap/Heap.h Utility/FileManager/FileManager.cpp Utility/FileManager/FileManager.h Algorithms/Dijsktra/Dijkstra.cpp Algorithms/Dijsktra/Dijkstra.h Utility/GraphGenerator/GraphGenerator.cpp Utility/GraphGenerator/GraphGenerator.h Algorithms/Kruskal/Kruskal.cpp Algorithms/Kruskal/Kruskal.h Algorithms/BellmanFord/BellmanFord.cpp Algorithms/BellmanFord/BellmanFord.h Structures/Path/Path.cpp Structures/Path/Path.h Utility/Timer/Timer.cpp Utility/Timer/Timer.h Utility/Menu/Menu.cpp Utility/Menu/Menu.h Utility/Tests/Tests.cpp Utility/Tests/Tests.h Structures/Graph.cpp Structures/Graph.h)
