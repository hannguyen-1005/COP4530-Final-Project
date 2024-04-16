#include "data.hpp"
#include <iostream>

int main() {
    // Create a DataPacket object
    DataPacket packet("packet1");

    // Add nodes to the packet's path
    packet.addNodeToPath("A");
    packet.addNodeToPath("B");
    packet.addNodeToPath("C");

    // Get the packet's routing path
    std::string path = packet.getRoutingPath();
    std::cout << "Packet routing path: " << path << std::endl;
}