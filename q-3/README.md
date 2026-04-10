#  Warshall’s Algorithm – Access Control System

---

## Problem Statement
This project models an access control system using a directed graph.

- **Nodes represent users / roles / resources**
- **Directed edges represent direct access permissions (i → j means i can directly access j)**

The goal is to compute **transitive closure** using Warshall’s Algorithm to determine both **direct and indirect access permissions**.

---

## Algorithm Used

###  Warshall’s Algorithm
Warshall’s Algorithm is used to compute the **transitive closure** of a directed graph.

###  Meaning of Transitive Closure:
It determines whether a path exists between every pair of nodes, either directly or through intermediate nodes.

###  Core Rule:
If  
i → k AND k → j  
Then  
i → j

---

##  How to Compile & Run

```bash
gcc warshall.c -o warshall
./warshall
```
## Input Format
Number of nodes (n)
n × n adjacency matrix

## Example Input
```
4
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1
```
##  Output
```
The output is the transitive closure matrix, which shows:

Direct access relationships
Indirect access relationships (via intermediate nodes)
Interpretation:

If A[i][j] = 1, then node i can access node j either directly or indirectly.
```
## Application
```
Role-based access control (RBAC)
Permission inheritance systems
Security auditing
Detecting hidden access paths
```
## Complexity
```
Time Complexity: O(n³)
Space Complexity: O(n²)

Why O(n³)?
Because the algorithm uses three nested loops to check all possible intermediate paths between every pair of nodes.
```
## Security Insight
```
This helps detect:

Indirect privilege escalation
Hidden access chains
Over-permissioned users
```
##  Conclusion

Warshall’s Algorithm efficiently computes the reachability between all nodes in a directed graph, making it useful in access control systems to identify both direct and indirect permissions.