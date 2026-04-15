# Travelling Salesman Problem (Brute Force)

## 📌 Problem Overview

The Travelling Salesman Problem (TSP) focuses on finding the shortest possible route for a delivery vehicle that:

- Starts from a central warehouse
- Visits each location exactly once
- Returns to the starting point
- Minimizes total travel distance

This solution uses a **brute-force approach**, evaluating all possible routes.

---

## 🧠 Problem Modeling

The problem is modeled as a **complete weighted graph**:

- **Vertices (V):** Delivery locations (including warehouse)
- **Edges (E):** Paths between locations
- **Weights:** Distance or travel cost between locations

### Representation

- Typically stored using an **adjacency matrix**
- Each entry `graph[i][j]` represents distance from node `i` to node `j`

---

## ⚙️ Brute Force Algorithm Design

### Core Idea

- Fix the starting node (warehouse)
- Generate all permutations of remaining locations
- Compute total distance for each possible route
- Select the route with minimum cost

---

### Steps

1. Start from node `0` (warehouse)
2. Create a list of remaining nodes `{1, 2, ..., n-1}`
3. Generate all possible permutations of these nodes
4. For each permutation:
   - Calculate total travel distance:
     - From start node to first node
     - Between intermediate nodes
     - From last node back to start
5. Keep track of the minimum cost route

---
## ⏱️ Time Complexity Analysis (Brute Force TSP)

The brute-force approach evaluates all possible routes (permutations of cities).

---

### 🔢 Number of Possible Routes

- Starting city is fixed
- Remaining cities = `n - 1`

Number of permutations:

\[
(n - 1)!
\]

---

### 🔁 Cost Computation per Route

For each route, the algorithm computes total travel cost by traversing all cities:

\[
O(n)
\]

---

### 📊 Total Time Complexity

\[
\text{Total Time} = (n - 1)! \times O(n)
\]

\[
= O(n \cdot (n - 1)!)
\]

\[
= O(n!)
\]

---

### 📈 Growth Illustration

| n  | Number of Routes |
|----|------------------|
| 4  | 6                |
| 5  | 24               |
| 10 | 362,880          |
| 15 | ~87 billion      |

---

### ⚠️ Conclusion

- Time complexity grows **factorially**
- Becomes infeasible for large `n`
- Practical only for small inputs (typically `n ≤ 10–12`)
## ⚠️ Limitations of Brute Force

- Explores **all possible permutations**
- Number of routes grows extremely fast
- Becomes impractical even for moderate input sizes
- High computational cost and execution time

---

## 🚀 More Efficient Approaches

### 1. Dynamic Programming (Held-Karp Algorithm)

- Uses **bitmasking + memoization**
- Reduces redundant computations

**Pros:**
- Guarantees optimal solution  
- Much faster than brute force  

**Cons:**
- Still exponential in nature  
- Memory intensive  

---

### 2. Approximation Algorithms

Examples:
- Greedy Approach
- Christofides Algorithm

**Pros:**
- Runs in polynomial time  
- Scales to large datasets  

**Cons:**
- Does not always give optimal solution  

---

### 3. Heuristic / Metaheuristic Methods

Examples:
- Genetic Algorithm  
- Simulated Annealing  
- Ant Colony Optimization  

**Pros:**
- Suitable for real-world large-scale problems  
- Produces near-optimal solutions  

**Cons:**
- No guarantee of optimality  
- Requires parameter tuning  

---

## 📊 Summary

- Brute force guarantees the **optimal solution**
- Not suitable for large inputs due to rapid growth in possibilities
- Best used for:
  - Small datasets  
  - Educational purposes  
  - Understanding permutations and exhaustive search  

For practical applications, **dynamic programming or heuristic methods** are preferred.
