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

| Command | Arguments | Description |
| --- | --- | --- |
| add_device | device_id | Add a device to the network |
| remove_device | device_id | Remove a device from the network |
| add_connection | source_id, destination_id | Add a connection between two devices |
| remove_connection | source_id, destination_id | Remove a connection between two devices |
| show | | Display the current network configuration |
| create | | Create the network based on the current configuration |
| exit | | Exit the program |

2. The system will auto generate network latency for each connection
3. User can access the command interface to interact with the system, including ('send', 'show', 'trace', 'exit')

| Command | Arguments | Description |
| --- | --- | --- |
| send | source_id, destination_id | Send a data packet from the source device to the destination device |
| show | | Display the network configuration, including devices, connections, and network latency |
| trace | packet_id | Trace the route taken by a data packet with the specified ID, leave blank to trace all packets |
| exit | | Exit the program |

## Planning
- Feature 1: Create stacks built into each data packet to trace its route
- Feature 2: Implement 2 hash tables, 1st map packet_id to source_id, 2nd map packet_id to destination_id
- Feature 3: First treat the network as a graph, with each devices is a vertex and each connection is an edge. Randomly assign weight (latency) to each edge. Then use Dijkstra algorithm to find the shortest path between source and destination.

- Object Design (UML):
    - Network: Represent the network
      // Graph properties
      - devices: vector<int> (device id)
      - connections: vector<pair<int, int>> (adjacency list, link 2 devices ids)
      - routing_table: vector<vector<int>> (adjacency matrix, represented weight (latency) of each connection)
      
      // Hash table to store packet_id and source_id, destination_id
      - packet_sources: unordered_map<int, int> (packet_id, source_id)
      - packet_destinations: unordered_map<int, int> (packet_id, destination_id)
      - packets: unordered_map<int, DataPacket> (packet_id, DataPacket)

    ----------------------------
    // Methods
    - constructor(): Initialize the network and generate random latency for each connection
    - addDevice(int id): Add a node to the network
    - removeDevice(int id): Remove a node and its connections from the network
    - addConnection(int source_id, int destination_id): Add a connection between two nodes
    - removeConnection(int source_id, int destination_id): Remove a connection between two nodes

    - sendPacket(int source_id, int destination_id): Send a data packet from source to destination
    - showNetwork(): Display the network configuration, including devices, connections, and network latency
    - tracePacket(int packet_id): Trace the route taken by a data packet with the specified ID
    - traceAllPackets(): Trace the route taken by all data packets
    - getShortestPath(int source_id, int destination_id): Calculate the optimal latency path between source and destination

    - DataPacket: Represent the data packet
      - id: int
      - route: stack<int> (trace the route taken by the packet)
    ----------------------------
    // Methods
    - constructor(int id): Initialize the data packet with the specified ID
    - addNodeToPath(int id): Add a node to the route
    - removeNodefromPath(): Remove a node from the route
    - showRoute(): Display the route taken by the packet
