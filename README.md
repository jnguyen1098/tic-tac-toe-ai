# Tic Tac Toe AI

It's been two years and I still hadn't done Kremer's Tic Tac Toe assignment. One very bored quarantine day I decided to finally do it, and fuck did it hurt my head still. I don't know how so many people managed to get this on their first try because I surely didn't.

From backpropagational machine learning to backtracking, people had many different theories on what kind of black magic fuckery Kremer put us through, but those are all wrong. What he did was make us implement a very simple decision-making AI known as the "minimax algorithm" (aka saddle point).

This algorithm is well-known in game theory (specifically in two-player zero-sum games). Its main goal is to minimize the worst-case scenario's maximum possible loss by means of the utility function. In a generalized scenario, we try to reach an extreme of this utility function given the many possible values, but in this assignment, there are only a few of these values: WINNING, TIE, and LEGAL. So, given a player P's move, the priority of the utility function would be WINNING > TIE > LEGAL. As in, prioritize making a winning move in the current game state, and if that isn't possible, try to tie the game. If that isn't possible, then make the next legal move knowing that you have exhausted all 9 possible next moves. Because of the few number of states we can reach in a given position, this implementation detail of the minimax algorithm was abstracted away in the assignment. Touché Stefan.

In another generalized sense, the Minimax algorithm recursively exhausts the game tree until it reaches end states (leaf nodes), then it assigns the utility value to these end states (`./a1p3 9`) before these utility values are _backed up_ through the tree as the recursion finally unwinds and backtracks to the beginning (`./a1p3 8` `./a1p3 7` `./a1p3 6` `./a1p3 5` `./a1p3 4` `./a1p3 3` `./a1p3 2` `./a1p3 1`).

_Below: an example game tree showing the Minimax Algorithm from Norvig's (in)famous AI book. Here you can see the player 'MAX' is trying to maximize the utility value whereas the opponent player 'MIN' is trying to minimize it in a back-and-forth tug-of-war._

![img](https://i.imgur.com/u6DWSac.png)
