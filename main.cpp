#include "network.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    // The user first creates a network with 5 options
    Network network;
    std::string user_input = "";
    while (user_input != "exit" || user_input != "create")
    {
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (user_input == "create")
        {
            // dont allow create empty network
            if (!network.enoughDevices())
            {
                std::cout << "You must add at least 2 devices to the network." << std::endl;
                continue;
            }

            // dont allow create network without connections
            if (!network.enoughConnections())
            {
                std::cout << "You must add at least 1 connection to the network." << std::endl;
                continue;
            }

            // Create the network
            network.create();
            std::cout << "Network created." << std::endl;
            break;
        }

        if (user_input == "add_device")
        {
            // Add a node to the network
            network.addDevice();
            continue;
        }

        if (user_input == "remove_device")
        {
            int device_id = -1;
            while (!network.deviceExists(device_id))
            {
                std::cout << "Enter the device id to remove: ";
                std::cin >> user_input;

                if (!network.deviceExists(device_id))
                    std::cout << "Device id does not exist, try again." << std::endl;
            }

            // Remove a node from the network
            network.removeDevice(device_id);
            continue;
        }

        if (user_input == "add_connection")
        {
            // Add a connection between two nodes
            int device_id1 = -1, device_id2 = -1;
            while (!network.deviceExists(device_id1) || !network.deviceExists(device_id2) || network.connectionExists(device_id1, device_id2))
            {
                std::cout << "Enter the device ids to connect: ";
                std::cin >> device_id1 >> device_id2;

                if (!network.deviceExists(device_id1) || !network.deviceExists(device_id2))
                    std::cout << "Device id does not exist, try again." << std::endl;

                if (network.connectionExists(device_id1, device_id2))
                    std::cout << "Connection already exists, try again." << std::endl;
            }

            network.addConnection(device_id1, device_id2);
            continue;
        }

        if (user_input == "remove_connection")
        {
            // Remove a connection between two nodes
            int device_id1 = -1, device_id2 = -1;
            while (!network.deviceExists(device_id1) || !network.deviceExists(device_id2) || !network.connectionExists(device_id1, device_id2))
            {
                std::cout << "Enter the device ids to disconnect: ";
                std::cin >> device_id1 >> device_id2;

                if (!network.deviceExists(device_id1) || !network.deviceExists(device_id2))
                    std::cout << "Device id does not exist, try again." << std::endl;

                if (!network.connectionExists(device_id1, device_id2))
                    std::cout << "Connection does not exist, try again." << std::endl;
            }
            continue;
        }

        if (user_input == "show")
            // Show the network topology
            std::cout << network.showNetwork() << std::endl;
    }

    // Then user can interact with the network
    while (user_input != "exit")
    {
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (user_input == "show")
        {
            // Show the network topology
            continue;
        }

        if (user_input == "send")
        {
            // Send a data packet
            continue;
        }

        if (user_input == "trace")
        {
            // Trace 1 or all packets
            continue;
        }
    }

    std::cout << "Exiting the program..." << std::endl;
    return 0;
}