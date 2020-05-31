# Tic Tac Toe AI

It's been two whole years and having still not finished Kremer's Tic Tac Toe, I decided to finally liberate this first-year ghost of mine. I don't know how so many people managed to get this on their first try because I surely didn't (I also tried this assignment right after W19 and still couldn't do it. Until now!!!).

With theories ranging from simple backtracking all the way to backpropagational machine learning, my cohort had many different tinfoil hat explanations on what Kremer was making us do under the hood. But these are all misnomers; what he _actually_ did was make us implement a very simple decision-making AI known as the "minimax algorithm" (aka saddle point).

This algorithm is well-known in game theory (specifically in two-player zero-sum games). Its main goal is to minimize the worst-case scenario's maximum possible loss by means of the utility function (or the opposite in an opponent's case). In a generalized Minimax, we try to reach an extreme of this utility function given the many possible values, but in this assignment, there are only a few of these values: WINNING, TIE, and LEGAL. Given a player P's move, the priority of the utility function would be WINNING > TIE > LEGAL. In other words: prioritize making a winning move in the current game state, and if that isn't possible, try to tie the game. If that isn't possible, then make the next legal move knowing that you have exhausted all 9 possible next moves. Because of the few number of states we can reach in a given position, the utility function implementation detail of the minimax algorithm was abstracted away in the assignment. Touché Stefan.

In another generalized sense, the Minimax algorithm recursively exhausts the game tree until it reaches end states (leaf nodes), then it assigns the utility value to these end states (`./a1p3 9` and other prematurely finished boards) before these utility values are _backed up_ through the tree as the recursion finally unwinds and backtracks to the beginning (`./a1p3 8` `./a1p3 7` `./a1p3 6` `./a1p3 5` `./a1p3 4` `./a1p3 3` `./a1p3 2` `./a1p3 1`). \^ Just as a closure to those wondering what `a1p3` really was... 

_Below: an example game tree showing the Minimax Algorithm from Norvig's (in)famous AI book. Here you can see the player 'MAX' is trying to maximize the utility value whereas the opponent player 'MIN' is trying to minimize it in a back-and-forth tug-of-war._

![img](https://i.imgur.com/u6DWSac.png)
