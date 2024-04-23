# Data Routing Optimization

This project presents an innovative system for optimizing data routing in computer networks, developed as a final project for the COP 4530 class.

## Features

- As data packets travel from one node to another, each node they pass through can be pushed onto the stack. This allows for easy tracking of the route taken by each packet and facilitates efficient error handling or rerouting if needed.

- When an end device sends a data packet to another device, the sysadmin need to keep track of the starting and ending point of the packet. This can be done using hash table, which can store the starting and ending point of the packet. This allows the sysadmin to quickly identify the source and destination of each packet, facilitating efficient error handling and route optimization.

- Each connection might have network latency, which we can turn into graph's weight. The weight can be used to calculate the shortest path between network nodes, ensuring efficient data packet travel from source to destination. By treating the network as a graph, with nodes representing network devices and edges representing connections between them, you can use Dijkstra's algorithm to calculate the shortest path for data packets to travel from a source node to a destination node.

## Installation

1. Clone the repository
2. Compile the program using the following command:

```bash
make
```

3. Run the compiled program using the following command:

```bash
./main
```

## Usage

1. User creates a network based on their configuration (number of devices, connections, etc.)

| Command           | Arguments                 | Description                                           |
| ----------------- | ------------------------- | ----------------------------------------------------- |
| add_device        | device_id                 | Add a device to the network                           |
| remove_device     | device_id                 | Remove a device from the network                      |
| add_connection    | source_id, destination_id | Add a connection between two devices                  |
| remove_connection | source_id, destination_id | Remove a connection between two devices               |
| show              |                           | Display the current network configuration             |
| create            |                           | Create the network based on the current configuration |
| exit              |                           | Exit the program                                      |

2. The system will auto generate network latency for each connection

3. User can access the command interface to interact with the system

| Command | Arguments                 | Description                                                                              |
| ------- | ------------------------- | ---------------------------------------------------------------------------------------- |
| send    | source_id, destination_id | Send a data packet from the source device to the destination device                      |
| show    |                           | Display the network configuration, including devices, connections, and network latency   |
| trace   | packet_id                 | Trace the route taken by a data packet with the specified ID, or -2 to trace all packets |
| exit    |                           | Exit the program                                                                         |

Check for example usage in the `test.txt` file. Enter each line in the file as a command in the command interface.

## Authors

- Tam Nguyen
- Nhi Bui
- Han Nguyen
