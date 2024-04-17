#include <algorithm>
#include "network.hpp"

// This file is the implementation of the Network class,
// which is a class that represents a network of devices

// Constructor
Network::Network(){};

//
// Check existance for devices, connections and packets
//

bool Network::enoughDevices() const
{
    return devices.size() >= 2;
}

bool Network::enoughConnections() const
{
    return connections.size() >= 1;
}

bool Network::deviceExists(int device_id) const
{
    return std::find(devices.begin(), devices.end(), device_id) != devices.end();
}

bool Network::connectionExists(int device_id1, int device_id2) const
{
    return std::find(connections.begin(), connections.end(), std::make_pair(device_id1, device_id2)) != connections.end() ||
           std::find(connections.begin(), connections.end(), std::make_pair(device_id2, device_id1)) != connections.end();
}

bool Network::packetExists(int packet_id) const
{
    return packets.find(packet_id) != packets.end();
}

//
// Add and remove devices and connections
//

void Network::addDevice()
{
    devices.push_back(device_id_counter++);
}

void Network::removeDevice(int device_id)
{
    // First remove all connections to this device
    for (auto it = connections.begin(); it != connections.end();)
    {
        if (it->first == device_id || it->second == device_id)
        {
            it = connections.erase(it);
            continue;
        }
        ++it;
    }

    // Then remove the device itself
    devices.erase(std::remove(devices.begin(), devices.end(), device_id), devices.end());
}

void Network::addConnection(int device_id1, int device_id2)
{
    connections.push_back(std::make_pair(device_id1, device_id2));
}

void Network::removeConnection(int device_id1, int device_id2)
{
    connections.erase(std::remove(connections.begin(), connections.end(), std::make_pair(device_id1, device_id2)), connections.end());
    connections.erase(std::remove(connections.begin(), connections.end(), std::make_pair(device_id2, device_id1)), connections.end());
}

void Network::create()
{
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(10, 100);

    // Create routing table with random latencies
    // 0 means the device itself
    // -1 means no connection
    // Other positive numbers are established connections with random latencies

    for (int i = 0; i < devices.size(); i++)
    {
        for (int j = 0; j < devices.size(); j++)
        {
            // a node reach itself with 0 latency
            if (i == j)
            {
                routing_table[devices[i]][devices[j]] = 0;
                continue;
            }

            // check if there is a connection between the two nodes
            if (connectionExists(devices[i], devices[j]))
            {
                routing_table[devices[i]][devices[j]] = dis(gen);
                continue;
            }

            // Otherwise set the latency to -1
            routing_table[devices[i]][devices[j]] = -1;
        }
    }
}

// Display network
std::string Network::showNetwork() const
{
    std::string network_str = "Network Topology:\n";
    // create a hashmap to map each device to its connections
    std::unordered_map<int, std::unordered_set<int>> device_connections;

    // Loop through the devices vector to get all vertices
    for (int i = 0; i < devices.size(); i++)
        device_connections[devices[i]] = std::unordered_set<int>();

    // Loop through the connections vector to get all edges
    for (int i = 0; i < connections.size(); i++)
    {
        device_connections[connections[i].first].insert(connections[i].second);
        device_connections[connections[i].second].insert(connections[i].first);
    }

    // Finally build the network output string
    for (auto it = device_connections.begin(); it != device_connections.end(); ++it)
    {
        network_str += "* Device " + std::to_string(it->first) + ":\n";
        // check if the device has no connections
        if (it->second.empty())
        {
            network_str += " -> No connections;\n\n";
            continue;
        }

        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            network_str += " -> Device " + std::to_string(*it2) + ";\n\n";
    }
    // TODO: Add packet information tables here

    return network_str;
}