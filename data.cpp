#include "data.hpp"

DataPacket::DataPacket(std::string id) : id(id) {}

void DataPacket::addNodeToPath(std::string node_id)
{
    routingPath.push(node_id);
}

std::string DataPacket::getId() const
{
    return id;
}

std::string DataPacket::getRoutingPath() const
{
    std::stack<std::string> copy_path = routingPath;
    std::string out_path;
    while (!copy_path.empty())
    {
        out_path += copy_path.top();
        copy_path.pop();
        if (!copy_path.empty())
            out_path += " -> ";
    }
    return out_path;
}