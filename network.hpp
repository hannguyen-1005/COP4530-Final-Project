#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>
#include <vector>

// This file define some classes that are used in the routing system.
// This include the NetworkNode class that represents a node in the network.
// And Network class that represents the network itself.
// TODO (optional) In a Network there is a function to randomly generate a network given a number of nodes.

class NetworkNode {
public:
    NetworkNode(std::string id) : id(id) {}

    std::string getId() const {
        return id;
    }

private:
    std::string id;
    std::vector<NetworkNode*> parentNodes; // The devices that this device is connected to
    std::vector<NetworkNode*> childNodes; // The devices that are connected to this device
};

class Network {
    public:
        Network() {}

        void addNode(NetworkNode* node);

        void generateRandomNetwork(int numNodes); // Generate a random network with numNodes nodes, only works if the network is empty
    
        std::vector<std::string> printNetwork(); 
        // Output the whole network in 2d format, each connect to other with triple star 
        // horizontally and vertically, not diagonally
        
        std::string shortestPath(std::string start, std::string end); // Return the shortest path between two nodes
    
    private:
        std::vector<NetworkNode*> nodes;
};

#endif // NETWORK_HPP