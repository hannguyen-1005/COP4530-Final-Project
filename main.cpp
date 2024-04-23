#include "network.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    std::cout << "*** Network Simulator ***" << std::endl;
    std::cout << "Welcome to the network simulator!" << std::endl;
    std::cout << "You will go through 2 steps to create and interact with a network." << std::endl;
    std::cout << "Step 1: Create a network" << std::endl;
    std::cout << "Step 2: Interact with the network" << std::endl;
    std::cout << "Type 'exit' to exit the program." << std::endl;
    std::cout << "Remember to Read the instructions carefully and follow the commands." << std::endl;
    std::cout << "Good luck!"
              << std::endl
              << std::endl
              << std::endl;

    // The user first creates a network with 5 options
    Network network;
    std::string user_input = "";
    while (user_input != "exit" && user_input != "create")
    {
        std::cout << "Step 1: Create a network" << std::endl;
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << std::endl << "Invalid input, try again." << std::endl;
            continue;
        }

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
            std::cout << "Added a device to the network." << std::endl;
            continue;
        }

        if (user_input == "remove_device")
        {
            int device_id = -1;
            while (true)
            {
                std::cout << "Enter the device id to remove, or -1 to go back: ";
                std::cin >> device_id;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (device_id == -1)
                    break;

                if (!network.deviceExists(device_id))
                {
                    std::cout << "Device id does not exist, try again." << std::endl;
                    continue;
                }

                // Remove a node from the network
                network.removeDevice(device_id);
                std::cout << "Removed a device from the network." << std::endl;
                break;
            }

            continue;
        }

        if (user_input == "add_connection")
        {
            // Add a connection between two nodes
            int device_id1 = -1, device_id2 = -1;
            while (true)
            {
                std::cout << "Enter the device ids to connect, or double -1 to go back: ";
                std::cin >> device_id1 >> device_id2;

                // Validate input
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();

                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (device_id1 == -1 && device_id2 == -1)
                    break;

                if (device_id1 == device_id2)
                {
                    std::cout << "Cannot connect a device to itself, try again." << std::endl;
                    continue;
                }

                if (!network.deviceExists(device_id1) || !network.deviceExists(device_id2))
                {
                    std::cout << "Device id does not exist, try again." << std::endl;
                    continue;
                }

                if (network.connectionExists(device_id1, device_id2))
                {
                    std::cout << "Connection already exists, try again." << std::endl;
                    continue;
                }

                network.addConnection(device_id1, device_id2);
                std::cout << "Added a connection between two devices." << std::endl;
                break;
            }

            continue;
        }

        if (user_input == "remove_connection")
        {
            // Remove a connection between two nodes
            int device_id1 = -1, device_id2 = -1;
            while (true)
            {
                std::cout << "Enter the device ids to disconnect, or double -1 to go back: ";
                std::cin >> device_id1 >> device_id2;

                // Validate input
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (device_id1 == -1 && device_id2 == -1)
                    break;

                if (!network.deviceExists(device_id1) || !network.deviceExists(device_id2))
                {
                    std::cout << "Device id does not exist, try again." << std::endl;
                    continue;
                }
                if (!network.connectionExists(device_id1, device_id2))
                {
                    std::cout << "Connection does not exist, try again." << std::endl;
                    continue;
                }

                network.removeConnection(device_id1, device_id2);
                std::cout << "Removed a connection between two devices." << std::endl;
                break;
            }
            continue;
        }

        if (user_input == "show")
        {
            // Show the network topology
            std::cout << network.showNetwork() << std::endl;
            continue;
        }

        std::cout << "Invalid command, try again." << std::endl;
    }

    // Then user can interact with the network
    while (user_input != "exit")
    {
        std::cout << "Step 2: Interact with the network" << std::endl;
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << std::endl << "Invalid input, try again." << std::endl;
            continue;
        }

        if (user_input == "show")
        {
            // Show the network topology
            std::cout << network.showNetwork() << std::endl;
            continue;
        }

        if (user_input == "send")
        {
            // Send a data packet
            int source_id = -1, destination_id = -1;
            while (true)
            {
                std::cout << "Enter the source and destination device ids to send a packet, or double -1 to go back: ";
                std::cin >> source_id >> destination_id;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (source_id == -1 && destination_id == -1)
                    break;

                if (!network.deviceExists(source_id) || !network.deviceExists(destination_id))
                {
                    std::cout << "Device id does not exist, try again." << std::endl;
                    continue;
                }

                if (!network.pathExists(source_id, destination_id))
                {
                    std::cout << "No path between source and destination, try again." << std::endl;
                    continue;
                }

                if (source_id == destination_id)
                {
                    std::cout << "Source and destination are the same, try again." << std::endl;
                    continue;
                }

                network.sendPacket(source_id, destination_id);
                std::cout << "Sent a packet from source to destination." << std::endl;
                break;
            }
            continue;
        }

        if (user_input == "trace")
        {
            // Trace 1 or all packets
            int trace_id = -2;
            while (true)
            {
                std::cout << "Enter the packet id to trace, or -1 to go back, or -2 to trace all packets: ";
                std::cin >> trace_id;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << std::endl << "Invalid input, try again." << std::endl;
                    continue;
                }

                if (trace_id == -1)
                    break;

                if (trace_id == -2)
                {
                    std::cout << network.traceAllPackets() << std::endl;
                    break;
                }

                if (!network.packetExists(trace_id))
                {
                    std::cout << "Packet id does not exist, try again." << std::endl;
                    continue;
                }

                std::cout << network.tracePacket(trace_id) << std::endl;
                break;
            }
            continue;
        }
    }
    std::cout << "Exiting the program..." << std::endl;
    return 0;
}