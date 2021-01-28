# Shortest Path Algorithms

## Shortest Path Problem

* Input : a weighted graph $G=(V,E)$
  * The edges can be directed or not
  * Sometimes, we allow negative edge weights
  * Note : use BFS for unweighted graph
* Output : the path between  two nodes $u$ and $v$ that minimizes the total weight

## Floyd-Warshall Algorithm

* Given a directed weighted graph $G$
* Outputs a matrix $D$ where $d_{ij}$ is the shortest distance from node $i$ to $j$
* Can detect a negative-weight cycle
* Runt in $\Theta(n^3)$ time

code :

* Initialize $D$ as the given cost matrix
* For $k=1,\dots,n:$
  * For all $i$ and $j$ :
    * $d_{ij}:=\min(d_{ij},d_{ik}+d_{kj})$
* If $d_{ij}+d_{ji}<0$ for some $i$ and $j$ , then the graph has a negative weight cycle

Proof :

* Define $f(i,j,k)$ as the shortest distance from $i$ to $j$ , using nodes $1,\dots,k$ as intermediate nodes
  * $f(i,j,n)$ is the shortest distance from $i$ to $j$
  * $f(i,j,0)=\text{cost}(i,j)$
* The optimal path for $f(i,j,k)$ may or may not have $k$ as an intermediate node
  * If it does, $f(i,j,k)=f(i,k,k-1)+f(k,j,k-1)$
  * Otherwise, $f(i,j,k)=f(i,j,k-1)$
* Therefore, $f(i,j,k)$ is the minimum of the two quantities above
* We have the following recurrences and base cases
  * $f(i,j,0)=\text{cost}(i,j)$
  * $f(i,j,k)=\min(f(i,k,k-1)+f(k,j,k-1),f(i,j,k-1))$
* From the value of $f(.,.,k-1)$, we can calculate $f(.,.,k)$

## Dijkstra’s Algorithm

* Given a directed weighted graph $G$ and a source $s$
  * Important: The edge weights have to be nonnegative!
* Outputs a vector $d$ where $d_i$ is the shortest distance from $s$ to node $i$
* Time complexity depends on the implementation:
  * Can be $O(n^2+m),O(m\log n),o(m+n\log n)$



code :

* Inititally, $S:=\{s\}$, and $d_v := \text{cost}(s,v)$
* Repeat until $S=V$ :
  * Find $v\notin S$ with the smallest $d_v$, and add it to $S$
  * For each edge $v\rightarrow u$ of cost $c$:
    * $d_u := \min(d_u,d_v+c)$

## Bellman-Ford Algorithm

* Given a directed weighted graph $G$ and a source $s$
  * Important: The edge weights have to be nonnegative!
* Outputs a vector $d$ where $d_i$ is the shortest distance from $s$ to node $i$
* Can detect a negative-weight cycle
* Runs in $\Theta(nm)$ time

code :

* Initialize $d_s:=0$ and $d_v:=\infty$ for all $v\neq s$
* For $k=1,\dots,n-1$
  * For each edge $u\rightarrow v$ of cost $c$ :
    * $d_v := \min(d_v,d_u+c)$
* For each edge $u \rightarrow v$ of cost $c$ :
  * If $d_v>d_u + c$:
    * Then the graph contains a negative-weight cycle

Proof :

* A shortest path can have at most $n-1$ edges
* At the $k_{th}$ iteration, all shortest paths using $k$ or less edges are computed
* After $n − 1$ iterations, all distances must be final; for every edge $u \rightarrow v$ of cost $c$, $d_v \leq d_u + c$ holds
  * Unless there is a negative-weight cycle
  * This is how the negative-weight cycle detection works

