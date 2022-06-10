#include "Menu.h"

Menu::Menu()
{
    fm = new FileManager();
}

void Menu::mainMenu()
{
    int choice = -1;

    while(choice != 3)
    {

        std::cout << "Choose problem:\n1. MST\n2. Shortest Path\n3. Quit" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                MST();
                break;
            case 2:
                shortestPath();
                break;
            case 3:
                break;
        }
    }

}

void Menu::MST()
{
    int choice = -1;
    size_t nodes, density, from;

    while(choice != 6)
    {
        std::cout << "1. Write graph from file.\n2. Generate random graph.\n3. "
                  << "Display graph.\n4. Prim.\n5. Kruskal.\n6. Return\n";

        std::cin >> choice;


        switch(choice)
        {
            case 1:
                fm->readFromFile();

                if(matrix != nullptr || list != nullptr)
                {
                    delete matrix;
                    delete list;
                }

                matrix = new IncidenceMatrix(fm->getNodesNumber(), fm->getEdgesNumber(), fm->getData());
                list = new NeighboursList(fm->getNodesNumber(), fm->getEdgesNumber(), fm->getData());
                break;
            case 2:
                std::cout << "Type nodes number and density:" << std::endl;
                std::cin >> nodes >> density;
                gg = new GraphGenerator(nodes, density);

                if(matrix != nullptr || list != nullptr)
                {
                    delete matrix;
                    delete list;
                }

                matrix = new IncidenceMatrix(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());
                list = new NeighboursList(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());
                break;
            case 3:
                matrix->displayGraph();
                list->displayGraph();
                break;
            case 4:
                std::cout << "Type first node: " << std::endl;
                std::cin >> from;
                if(matrixResult != nullptr || listResult != nullptr)
                {
                    delete matrixResult;
                    delete listResult;
                }

                matrixResult = Prim::generateMST(matrix, from);
                matrixResult->displayGraph();

                listResult = Prim::generateMST(list, from);
                listResult->displayGraph();
                break;
            case 5:
                if(matrixResult != nullptr || listResult != nullptr)
                {
                    delete matrixResult;
                    delete listResult;
                }

                matrixResult = Kruskal::generateMST(matrix);
                matrixResult->displayGraph();

                listResult = Kruskal::generateMST(list);
                listResult->displayGraph();
                break;
            case 6:
                break;
        }
    }

}
void Menu::shortestPath()
{
    int choice = -1;
    size_t nodes, density, from, to;

    while(choice != 6)
    {
        std::cout << "1. Write graph from file.\n2. Generate random graph.\n3. "
                  << "Display graph.\n4. Dijkstra\n5. Bellman - Ford.\n6. Return\n";

        std::cin >> choice;


        switch(choice)
        {
            case 1:

                fm->readFromFile();

                if(matrix != nullptr || list != nullptr)
                {
                    delete matrix;
                    delete list;
                }

                matrix = new IncidenceMatrix(fm->getNodesNumber(), fm->getEdgesNumber(), fm->getData());
                list = new NeighboursList(fm->getNodesNumber(), fm->getEdgesNumber(), fm->getData());

                break;

            case 2:

                std::cout << "Type nodes number and density:" << std::endl;
                std::cin >> nodes >> density;
                gg = new GraphGenerator(nodes, density);

                if(matrix != nullptr || list != nullptr)
                {
                    delete matrix;
                    delete list;
                }

                matrix = new IncidenceMatrix(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());
                list = new NeighboursList(gg->getNodesNumber(), gg->getEdgesNumber(), gg->getData());
                break;

            case 3:

                matrix->displayGraph();
                list->displayGraph();

                break;

            case 4:
                std::cout << "Type first node and last node: " << std::endl;
                std::cin >> from >> to;

                if(path != nullptr)
                    delete path;

                std::cout << "Matrix" << std::endl;

                path = Dijkstra::findShortestPath(matrix, from, to);
                path->displayPath();

                if(path != nullptr)
                    delete path;

                std::cout << "List" << std::endl;

                path = Dijkstra::findShortestPath(list, from, to);
                path->displayPath();

                break;

            case 5:

                std::cout << "Type first node and last node: " << std::endl;
                std::cin >> from >> to;

                if(path != nullptr)
                    delete path;

                std::cout << "Matrix" << std::endl;

                path = BellmanFord::findShortestPath(matrix, from, to);
                path->displayPath();

                if(path != nullptr)
                    delete path;

                std::cout << "List" << std::endl;

                path = BellmanFord::findShortestPath(list, from, to);
                path->displayPath();

                break;

            case 6:

                break;
        }
    }

}