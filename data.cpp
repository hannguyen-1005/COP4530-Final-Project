#include "data.hpp"

// This file is the implementation of the DataPacket class,
// defining properties and methods of a data packet sending in a network

// Constructor
DataPacket::DataPacket(int id) : id(id) {}


int DataPacket::getId() const
{
    return id;
}

void DataPacket::addNodeToPath(int node_id)
{
    routing_path.push(node_id);
}

void DataPacket::removeNodeFromPath() {
    routing_path.pop();
}

std::string DataPacket::getRoutingPath() const
{
    std::stack<int> routing_path_copy = routing_path;
    std::string out_path;
    while (!routing_path_copy.empty())
    {
        out_path += std::to_string(routing_path_copy.top());
        routing_path_copy.pop();
        if (!routing_path_copy.empty())
            out_path += " <- ";
    }
    return out_path;
}