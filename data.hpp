#ifndef DATA_HPP
#define DATA_HPP

#include <stack>
#include <string>

class DataPacket
{
public:
    DataPacket(int id);
    int getId() const;                  // get the packet id
    std::string getRoutingPath() const; // get the routing path as a string
    void addNodeToPath(int node_id);    // add a node to the routing path
    void removeNodeFromPath();          // remove the last node from the routing path

private:
    int id;
    std::stack<int> routing_path;
};

#endif // DATA_HPP