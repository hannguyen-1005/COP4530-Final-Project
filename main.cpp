#include "network.hpp"
#include <iostream>
#include <string>

int main() {
    // The user first creates a network with 5 options
    // Network network;
    std::string user_input = "";
    while (user_input != "exit" || user_input != "create") {
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (user_input == "create") {
            // Create a network
            // network = Network();
            std::cout << "Network created." << std::endl;
            break;
        }

        if (user_input == "add_device") {
            // Add a node to the network
            continue;
        }

        if (user_input == "remove_device") {
            // Remove a node from the network
            continue;
        }

        if (user_input == "add_connection") {
            // Add a connection between two nodes
            continue;
        }

        if (user_input == "remove_connection") {
            // Remove a connection between two nodes
            continue;
        }

        if (user_input == "show") {
            // Show the network topology
            continue;
        }
    }

    // Then user can interact with the network
    while (user_input != "exit") {
        std::cout << "Enter a command: ";
        std::cin >> user_input;

        if (user_input == "show") {
            // Show the network topology
            continue;
        }

        if (user_input == "send") {
            // Send a data packet
            continue;
        }

        if (user_input == "trace") {
            // Trace 1 or all packets
            continue;
        }
    }

    std::cout << "Exiting the program..." << std::endl;
    return 0;
}