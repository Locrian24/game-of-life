# Game of Life in C++ and SFML 2.5.+

For my first program with C++, I decided to do the age old classic Conway's Game of Life.

Conway's Game of Life is a cellular automata devised in 1970 by the John Horton Conway.
It's population follows 4 specific and very simple rules:
  1. Any live cell with less than two neighbours dies, as if by underpopulation
  2. Any live cell with either 2 or 3 neighbours survives the current generation
  3. Any live cell with more than 3 neighbours dies, as if by overpopulation
  4. Any dead cell with exactly 3 neighbours is born, coming alive for the next generation
  
In the simple model I created, bounds are dealth with by only dealing with cells not on the edge. I might end up updating it to have wrap around but that's not a priority. Future plans for this program also would be to implement classes and have an Object Oriented approach to the problem (may end up doing this with a different cellular automata).

Again, this was made as my first intro program to C++ so stuff like user defined parameters regarding the size of the cells and number of cells on the screen were ignored.
