#ifndef DATA_HPP
#define DATA_HPP

#include <stack>
#include <string>

class DataPacket {
public:
    DataPacket(int id);
    void addNodeToPath(int node_id);
    void removeNodeFromPath();
    int getId() const;
    std::string getRoutingPath() const;

private:
    int id;
    // std::stack<int> routing_path;
    //create mock data in stack
    std::stack<int> routing_path;
};

#endif // DATA_HPP