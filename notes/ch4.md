# Combinatorial Games

## Simple game

* Settings: There are n stones in a pile. Two players take turns and remove 1 or 3 stones at a time. The one who takes the last stone wins. Find out the winner if both players play perfectly
* State space: Each state can be represented by the number of remaining stones in the pile
* Valid moves from state : $x \rightarrow (x-1)$ or $x \rightarrow (x-3)$, as long as the resulting stones in the pile
* State 0 is the losing state

DP table for small values of n:

| n    | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| W/L  | L    | W    | L    | W    | L    | W    | L    | W    |

* Conjecture : If $n$ is odd, the first player wins. If $n$ is even, the second player wins.
* Holds true for the base case n = 0
* In general,
  * If n is odd, we can remove one stone and give the opponent an even number of stones
  * If n is even, no matter what we choose, we have to give an odd number of stones to the opponent

## Minimax Algorithm

* Zero-sum: if the first player’s score is $x$, then the other player gets $-x$
* Each player tries to maximize his/her own score
* Both players play perfectly

Minimax Algorithm:

* Recursive algorithm that decides the best move for the current player at a given state
* Define $f(S)$ as the optimal score of the current player who starts at state S
* Let $T_1,T_2,\dots,T_m$ be states can be reached from $S$ using a single move
* Let $T$ be the state that minimizes $f(T_i)$
* Then, $f(S) = −f(T)$
  * Intuition: minimizing the opponent’s score maximizes my score

Minimax Algorithm Pseudocode:

* Given state $S$ , want to compute $f(S$)
* If we know $f(S)$ already, return it
* Set return value $x \leftarrow -\infty $
* For each valid next State $T$:
  * Update return value $x \leftarrow  \max\{x,-f(T)\}$
* Write a memo $f(S) = x$ and return $x$

## Nim Game

* Settings: There are n piles of stones. Two players take turns. Each player chooses a pile, and removes any number of stones from the pile. The one who takes the last stone wins. Find out the winner if both players play perfectly
* Can’t really use DP if there are many piles, because the state space is huge

**Nim Game Example**

* Starts with heaps of 3, 4, 5 stones
  * We will call them heap A, heap B, and heap C
* Alice takes 2 stones from A: (1, 4, 5)
* Bob takes 4 from C: (1, 4, 1)
* Alice takes 4 from B: (1, 0, 1)
* Bob takes 1 from A: (0, 0, 1)
* Alice takes 1 from C and wins: (0, 0, 0)

**Solution to Nim**

* Given heaps of size $n_1,n_2,\dots,n_m$
* The first player wins if and only if the nim-sum $n_1 \oplus  n_2 \oplus \dots \oplus n_m$ is nonzero

## Grundy Numbers (Nimbers)

* If the state space is small, use memoization
* If not, print out the result of the game for small test data and look for a pattern
  * This actually works really well!
* Try to convert the game into some nim-variant
* If multiple games are played at once, use Grundy numbers