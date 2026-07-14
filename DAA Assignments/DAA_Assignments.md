# Design and Analysis of Algorithms - Assignments

## 1. Binary Search using Divide and Conquer

### Idea
Binary search works on a sorted array by repeatedly dividing the search space into two halves. The middle element is compared with the target value. If the target is smaller, the left half is searched; otherwise, the right half is searched.

### Algorithm Steps
1. Sort the array if it is not already sorted.
2. Compare the target with the middle element.
3. If equal, return the position.
4. If target is smaller, search the left half.
5. If target is larger, search the right half.

### Time Complexity Analysis
The recurrence relation is:

$$T(n) = T(n/2) + O(1)$$

Solving this gives:

$$T(n) = O(\log n)$$

### Space Complexity
- Iterative version: $O(1)$
- Recursive version: $O(\log n)$ due to recursion stack

### Conclusion
Binary search is efficient for sorted data because each comparison eliminates half of the remaining elements.

---

## 2. Merge Sort and Quick Sort with Execution-Time Comparison

### Merge Sort
Merge sort uses divide and conquer. It splits the array into halves, sorts each half recursively, and merges the sorted halves.

### Time Complexity
- Best case: $O(n \log n)$
- Average case: $O(n \log n)$
- Worst case: $O(n \log n)$

### Space Complexity
- $O(n)$ extra space

### Quick Sort
Quick sort chooses a pivot and partitions the array so that elements smaller than the pivot go to the left and larger elements go to the right.

### Time Complexity
- Best case: $O(n \log n)$
- Average case: $O(n \log n)$
- Worst case: $O(n^2)$ when partitions are highly unbalanced

### Space Complexity
- Average: $O(\log n)$ for recursion
- Worst: $O(n)$

### Execution-Time Comparison
Execution time depends on input size, pivot selection, and data distribution. In general:
- For small arrays, both are fast.
- For large arrays, merge sort is more stable in performance.
- Quick sort is often faster in practice because of low constant overhead and in-place partitioning.

### Sample Observation Table

| Input Size | Merge Sort Time | Quick Sort Time |
|-----------:|----------------:|----------------:|
| 100        | lower constant  | usually very fast |
| 1000       | $O(n \log n)$   | usually faster on average |
| 10000      | predictable     | may degrade if pivot is poor |

### Conclusion
Merge sort is preferred when guaranteed performance is needed. Quick sort is preferred when practical speed and in-place sorting are important.

---

## 3. Maximum and Minimum Elements in an Array using Divide and Conquer

### Idea
The array is divided into two halves. The maximum and minimum of each half are found recursively, and then combined.

### Algorithm Steps
1. If the array has one element, it is both max and min.
2. If the array has two elements, compare once and assign max/min.
3. Otherwise divide the array into two halves.
4. Find max and min in each half.
5. Combine the results.

### Time Complexity
The recurrence is:

$$T(n) = 2T(n/2) + O(1)$$

So the complexity is:

$$T(n) = O(n)$$

### Comparison with Simple Method
- Simple scanning uses $2n - 2$ comparisons in the worst case.
- Divide and conquer reduces the number of comparisons.

### Conclusion
This approach is efficient and demonstrates a clean divide-and-conquer strategy for finding both maximum and minimum.

---

## 4. Dijkstra’s Algorithm and Bellman-Ford Algorithm

### Dijkstra’s Algorithm
Dijkstra’s algorithm finds shortest paths from a source vertex to all other vertices in a graph with non-negative edge weights.

### Time Complexity
- With array implementation: $O(V^2)$
- With min-priority queue: $O((V+E)\log V)$

### Bellman-Ford Algorithm
Bellman-Ford relaxes all edges repeatedly and works even when negative edge weights are present.

### Time Complexity
- $O(VE)$

### Comparison of Applications
- Dijkstra’s algorithm is used in road networks, routing, and navigation where weights are non-negative.
- Bellman-Ford is used when negative edges may exist, such as in financial models or graphs where edge weights can represent gains and losses.

### Key Difference
- Dijkstra does not handle negative-weight edges correctly.
- Bellman-Ford can detect negative cycles.

### Conclusion
Choose Dijkstra for speed and non-negative weights, and Bellman-Ford for graphs with negative weights or when cycle detection is required.

---

## 5. Breadth First Search (BFS) and Depth First Search (DFS)

### BFS
BFS visits vertices level by level starting from a source vertex. It uses a queue.

### DFS
DFS explores as far as possible along one path before backtracking. It uses recursion or a stack.

### Time Complexity
For both BFS and DFS:

$$O(V + E)$$

### Applications
- BFS: shortest path in unweighted graphs, level order traversal, connectivity
- DFS: cycle detection, topological sorting, path finding, connected components

### Conclusion
BFS is suitable for level-wise exploration, while DFS is suitable for deep traversal and structural analysis of graphs.

---

## 6. 0/1 Knapsack Problem using Greedy Method

### Note
The classic 0/1 Knapsack problem is not optimally solved by a greedy method. Greedy works perfectly for the fractional knapsack problem, but for 0/1 knapsack it gives only an approximate or heuristic solution.

### Greedy Idea
Items are selected based on a greedy rule such as:
- highest profit
- lowest weight
- highest profit/weight ratio

### Analysis of Obtained Solution
The solution may not be optimal because taking a locally best item may block a better combination of items later.

### Time Complexity
- Sorting items by ratio: $O(n \log n)$
- Selection: $O(n)$

Overall:

$$O(n \log n)$$

### Conclusion
Greedy is simple and fast, but it is not guaranteed to produce the optimal answer for 0/1 knapsack. Dynamic programming is the correct exact method.

---

## 7. Job Sequencing with Deadlines using Greedy Approach

### Idea
Each job has a deadline and a profit. The goal is to schedule jobs so that the total profit is maximized.

### Greedy Strategy
1. Sort jobs in decreasing order of profit.
2. Place each job in the latest available slot before its deadline.
3. Continue until all jobs are considered.

### Time Complexity
- Sorting: $O(n \log n)$
- Scheduling: $O(n^2)$ in simple implementation
- Can be improved with disjoint set data structure

### Conclusion
This greedy strategy is effective because choosing high-profit jobs first usually leaves room for profitable scheduling.

---

## 8. Prim’s Algorithm and Kruskal’s Algorithm

### Prim’s Algorithm
Prim’s algorithm grows a minimum spanning tree by starting from one vertex and repeatedly adding the minimum-weight edge that connects the tree to a new vertex.

### Time Complexity
- Using adjacency matrix: $O(V^2)$
- Using priority queue: $O(E \log V)$

### Kruskal’s Algorithm
Kruskal’s algorithm sorts all edges by weight and adds them one by one if they do not form a cycle.

### Time Complexity
- Sorting edges: $O(E \log E)$
- Union-Find operations are almost constant amortized time

### Comparison
- Prim is often better for dense graphs.
- Kruskal is often better for sparse graphs.
- Both generate a minimum spanning tree.

### Conclusion
Prim and Kruskal are classic greedy algorithms for MST construction, each preferred in different graph settings.

---

## 9. 8-Queen Problem and Graph Coloring Problem using Backtracking

### 8-Queen Problem
The task is to place 8 queens on an 8x8 chessboard so that no two queens attack each other.

### Backtracking Approach
- Place a queen row by row.
- Check whether the current placement is safe.
- If not safe, backtrack and try another position.

### Graph Coloring Problem
The goal is to assign colors to graph vertices so that no adjacent vertices share the same color.

### Backtracking Approach
- Assign a color to a vertex.
- Check validity against adjacent vertices.
- If a conflict arises, try the next color.

### Time Complexity
Both problems have exponential worst-case behavior.

### Conclusion
Backtracking is suitable for constraint satisfaction problems where brute force is too large but pruning can reduce the search space.

---

## 10. Floyd-Warshall Algorithm

### Idea
Floyd-Warshall finds shortest paths between all pairs of vertices using dynamic programming.

### Core Recurrence
If $dist[i][j]$ is the shortest path from $i$ to $j$, then considering an intermediate vertex $k$:

$$dist[i][j] = \min(dist[i][j], dist[i][k] + dist[k][j])$$

### Time Complexity

$$O(V^3)$$

### Space Complexity

$$O(V^2)$$

### Conclusion
Floyd-Warshall is simple and useful for dense graphs and all-pairs shortest path computation.

---

## 11. Matrix Chain Multiplication using Dynamic Programming

### Problem
Given a sequence of matrices, determine the order of multiplication that minimizes the number of scalar multiplications.

### Dynamic Programming Idea
Let $m[i][j]$ be the minimum cost to multiply matrices from $i$ to $j$.

### Recurrence

$$m[i][j] = \min_{i \le k < j} (m[i][k] + m[k+1][j] + p_{i-1}p_kp_j)$$

where the matrix dimensions are represented by array $p$.

### Time Complexity

$$O(n^3)$$

### Space Complexity

$$O(n^2)$$

### Conclusion
Dynamic programming gives the optimal parenthesization and significantly reduces unnecessary computation.

---

## 12. Travelling Salesman Problem (TSP) using Dynamic Programming / Branch and Bound

### Dynamic Programming Approach
TSP asks for the minimum-cost tour visiting every city exactly once and returning to the start.

A common DP method is the Held-Karp algorithm.

### Time Complexity
- Time: $O(n^2 2^n)$
- Space: $O(n 2^n)$

### Branch and Bound Approach
This method explores candidate tours while pruning paths that cannot beat the current best solution.

### Characteristics
- Exact method
- Often faster than brute force in practice for some instances
- Worst-case complexity is still exponential

### Conclusion
TSP is computationally expensive. DP is elegant for smaller instances, while Branch and Bound is effective when pruning is strong.

---

## Overall Summary
These problems demonstrate the main algorithm design paradigms in DAA:
- Divide and Conquer: Binary Search, Merge Sort, Max/Min
- Greedy Method: Job Sequencing, MST algorithms, Knapsack heuristic
- Graph Algorithms: Dijkstra, Bellman-Ford, BFS, DFS, Floyd-Warshall
- Backtracking: 8-Queen, Graph Coloring
- Dynamic Programming: Matrix Chain Multiplication, TSP

Each algorithm is chosen based on the structure of the problem, the need for optimality, and the expected input size.
