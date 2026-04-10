
# 🏭 Manufacturing Workflow Optimization using Topological Sorting

---

## 📌 Problem Statement

Modern manufacturing systems involve multiple interdependent processes such as assembly, painting, wiring, testing, and packaging. These processes must follow a strict order due to dependencies, forming a **Directed Acyclic Graph (DAG)**.

The goal of this project is to:

* Determine a valid sequence of execution
* Identify tasks that can run in parallel
* Improve overall production efficiency

---

## 🎯 Objectives

* Model a manufacturing workflow as a graph
* Apply topological sorting to find a valid process order
* Identify levels of parallel execution
* Analyze algorithm efficiency
* Evaluate improvements in production throughput

---

## 🧠 Conceptual Background

### 🔹 Directed Acyclic Graph (DAG)

A DAG is a graph with:

* Directed edges (u → v means u must be done before v)
* No cycles (no circular dependencies)

### 🔹 Topological Sorting

Topological sorting is a linear ordering of nodes such that:
For every directed edge (u → v), node `u` comes before `v`.

### 🔹 Why Topological Sorting?

* Ensures correct execution order
* Helps detect invalid workflows (cycles)
* Enables scheduling and optimization

---

## 🏗️ System Design

### 🔸 Graph Representation

* Nodes → Manufacturing processes
* Edges → Dependencies between processes

### 🔸 Example Workflow

| Process   | ID | Dependencies     |
| --------- | -- | ---------------- |
| Assembly  | 0  | None             |
| Painting  | 1  | Assembly         |
| Wiring    | 2  | Assembly         |
| Testing   | 3  | Painting, Wiring |
| Packaging | 4  | Testing          |

### 🔸 Graph Structure

Assembly → Painting → Testing → Packaging  
      ↘ Wiring ↗  

---

## ⚙️ Algorithm Used

### ✅ Kahn’s Algorithm (BFS-based Topological Sort)

### Steps:

1. Compute in-degree of each node  
2. Add all nodes with in-degree = 0 to queue  
3. Repeat until queue is empty:
   * Remove a node  
   * Add it to result  
   * Reduce in-degree of its neighbors  
   * If in-degree becomes 0, add to queue  

---

## 🔄 Parallel Execution Strategy

To identify parallel tasks:

* Process nodes **level by level**
* All nodes available at the same step can execute simultaneously

### Example:

| Step | Processes        | Execution Type |
| ---- | ---------------- | -------------- |
| 1    | Assembly         | Sequential     |
| 2    | Painting, Wiring | Parallel       |
| 3    | Testing          | Sequential     |
| 4    | Packaging        | Sequential     |

---

## 💻 Implementation Details

### 🔧 Language Used

* C++

### 🔧 Data Structures

* Adjacency List (vector<vector<int>>)
* Queue (for BFS)
* Array (for in-degree tracking)

### 🔧 Key Functions

* `addDependency(u, v)` → adds edge u → v  
* `topologicalSortWithLevels()` → computes execution order + parallel levels  

---

## ▶️ How to Run

### 1. Compile

```bash
g++ workflow.cpp -o workflow
````

### 2. Run

```bash
./workflow
```

---

## 📊 Sample Output

```
Topological Order (Levels):
Step 1: 0
Step 2: 1 2
Step 3: 3
Step 4: 4
```

---

## 📈 Time Complexity Analysis

| Operation                | Complexity |
| ------------------------ | ---------- |
| Graph Construction       | O(V + E)   |
| Topological Sorting      | O(V + E)   |
| Parallel Level Detection | O(V + E)   |

### ✅ Overall Complexity:

**O(V + E)**

Where:

* V = Number of processes
* E = Number of dependencies

---

## 📉 Space Complexity

* Adjacency List: O(V + E)
* In-degree array: O(V)
* Queue: O(V)

### ✅ Total Space:

**O(V + E)**

---

## 🧪 Real-World Evaluation

### 🔸 Scenario 1: Sequential Execution

Assembly → Painting → Wiring → Testing → Packaging
**Total Time = 5 units**

### 🔸 Scenario 2: Parallel Execution

Assembly → (Painting + Wiring) → Testing → Packaging
**Total Time = 4 units**

### ✅ Improvement:

* **20% reduction in execution time**
* Better resource utilization

---

## 🚀 Performance Insights

### ✅ Advantages

* Identifies parallelizable tasks
* Reduces idle machine time
* Improves production speed

### ⚠️ Limitations

* Assumes no cycles (DAG required)
* Does not account for task duration differences

---

## 🔧 Future Enhancements

1. ⏱️ **Task Duration Integration**

   * Assign time to each process
   * Compute minimum completion time

2. 📍 **Critical Path Method (CPM)**

   * Identify bottleneck tasks

3. 🤖 **Dynamic Scheduling**

   * Adjust workflow based on delays

4. 🏭 **Resource Allocation Optimization**

   * Assign machines/workers efficiently

5. 📊 **Visualization**

   * Use Graphviz for graphical workflow representation

---

## 📚 Applications

* Manufacturing systems
* Build systems (compilers)
* Task scheduling in operating systems
* Project management tools
* Data pipeline execution

---

## 👩‍💻 Author

**Navya S**

---

## 📌 Conclusion

This project demonstrates how topological sorting can be used to:

* Ensure correct execution order
* Identify parallel execution opportunities
* Improve overall system efficiency

By modeling workflows as DAGs and applying graph algorithms, complex manufacturing systems can be optimized effectively.

---

```
```
