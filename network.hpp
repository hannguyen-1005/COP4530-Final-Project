#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <climits>
#include "data.hpp"

// TODO (optional) Create function to randomly generate a network given a number of nodes.

class Network
{
public:
    Network();
    bool enoughDevices() const;                                     // check if there are at least 2 devices in the network 
    bool enoughConnections() const;                                 // check if there are at least 1 connection in the network
    bool deviceExists(int device_id) const;                         // check if a device exists in the network
    bool connectionExists(int device_id1, int device_id2) const;    // check if a connection exists in the network
    bool packetExists(int packet_id) const;                         // check if a packet exists in the network
    bool pathExists(int source_id, int destination_id) const;      // check if a path exists between source and destination
    // TODO: Implement the pathExists function to check if a path exists between source and destination
    void addDevice();
    void removeDevice(int device_id);                               // remove all connections to this device and the device itself
    void addConnection(int device_id1, int device_id2);
    void removeConnection(int device_id1, int device_id2);
    void create();                                                  // create routing table when user finalize input devices & connections, then init random latency


    void sendPacket(int source_id, int destination_id);             // send a packet from source to destination using optimal path
    std::vector<int> getShortestPath(int source_id, int destination_id) const; // return the shortest path between source and destination with Dijkstra's algorithm
    std::string tracePacket(int packet_id);                                // show the path of the packet after it was sent
    std::string traceAllPackets();                                         // show all packets already sent and their paths
    std::string showNetwork() const;                                      // return a string with the network topology

private:
    // The network is bidirectional weighted graph (different latencies between 2 directions are possible)
    // graph properties
    int device_id_counter = 0;
    std::vector<int> devices;                                            // or nodes
    std::vector<std::pair<int, int>> connections;                        // or edges, each pair is a connection between two nodes
    std::unordered_map<int, std::unordered_map<int, int>> routing_table; // or adjacency matrix, each pair is a connection between two nodes, and the value is the latency

    // data packets properties
    int packet_id_counter = 0;
    std::unordered_map<int, DataPacket*> packets;       // packet_id, DataPacket pointer
    std::unordered_map<int, int> packet_sources;      // packet_id, source_id
    std::unordered_map<int, int> packet_destinations; // packet_id, destination_id
};

#endif // NETWORK_HPP