#ifndef ROUTING_HPP
#define ROUTING_HPP

#include <stack>
#include <string>

class DataPacket {
public:
    DataPacket(std::string id);

    void addNodeToPath(std::string node_id);

    std::string getId() const;

    std::string getRoutingPath() const;

private:
    std::string id;
    std::stack<std::string> routingPath;
};

#endif // ROUTING_HPP