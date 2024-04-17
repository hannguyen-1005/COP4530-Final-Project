#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "data.hpp"

// TODO (optional) In a Network there is a function to randomly generate a network given a number of nodes.

class Network
{
public:
    Network(std::vector<int> devices, std::vector<std::vector<int>> connections, std::vector<std::vector<int>> routing_table);
    Network(); // default constructor

    void addDevice(int device_id);
    void removeDevice(int device_id); // remove all connections to this device and the device itself
    void addConnection(int device_id1, int device_id2, int latency);
    void removeConnection(int device_id1, int device_id2);

    void sendPacket(int source_id, int destination_id);             // send a packet from source to destination using optimal path
    void tracePacket(int packet_id);                                // show the path of the packet after it was sent
    void traceAllPackets();                                         // show all packets already sent and their paths
    std::string showNetwork() const;                                      // return a string with the network topology
    std::string getShortestPath(int source_id, int destination_id) const; // return the shortest path between source and destination with Dijkstra's algorithm

private:
    // The network is bidirectional weighted graph (different latencies between 2 directions are possible)
    // graph properties
    std::vector<int> devices;                                            // or nodes
    std::vector<std::pair<int, int>> connections;                        // or edges, each pair is a connection between two nodes
    std::unordered_map<int, std::unordered_map<int, int>> routing_table; // or adjacency matrix, each pair is a connection between two nodes, and the value is the latency

    // data packets properties
    int packet_id_counter = 0;
    std::unordered_map<int, DataPacket> packets;       // packet_id, DataPacket
    std::unordered_map<int, int> packet_sources;      // packet_id, source_id
    std::unordered_map<int, int> packet_destinations; // packet_id, destination_id
};

#endif // NETWORK_HPP