# Data Routing Optimization

This project presents an innovative system for optimizing data routing in computer networks, developed as a final project for the COP 4530 class.

## Features

- Utilizes a stack to trace the routing path of data packets across the network, allowing for efficient route tracking and robust error handling. As data packets travel from one node to another, each node they pass through can be pushed onto the stack. This allows for easy tracking of the route taken by each packet and facilitates efficient error handling or rerouting if needed. 

- Employs a binary search tree to manage network nodes and their connections, enabling rapid lookup and selection of optimal paths for data routing. Each node in the tree represents a network device (such as routers, switches, or servers), with the left child representing nodes that are closer in terms of network latency or cost, and the right child representing nodes that are farther away. This structure enables quick lookup and selection of optimal paths for data routing. (This sound like weighted graph and Dijkstra's algorithm) 
Suggested change: "Rephrased point 2: Implement a simple load balancing algorithm that distributes data packets evenly across network nodes, ensuring efficient use of network resources. This can be achieved with heap data structure."

- Applies Dijkstra's algorithm to identify the shortest path between network nodes, ensuring efficient data packet travel from source to destination. By treating the network as a graph, with nodes representing network devices and edges representing connections between them, you can use Dijkstra's algorithm to calculate the shortest path for data packets to travel from a source node to a destination node.

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

## Planning
- For user interface, we will use a simple command-line interface (CLI) that allows users to interact with the system by entering commands and viewing output.

- The displayed network would have about 3-4 layers, with 1st layer is end-device, 2-3 layers are network devices (routers, switches), and the last layer is the server. Technically, end-vice & server are the same, but we can separate them for better visualization.

