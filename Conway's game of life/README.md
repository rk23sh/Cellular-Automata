# Conway's Game of Life
```
The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970.
It's basically a simulation, that describes the evolution of an organism under a certain set of rules.
```
```
The playground hosting evolution looks kinda this:

.........................
.........................
.........................
.........................
.........X..........X....
....................X....
.........................
.........................
.........................

'.' refers to an empty land, while
'X' refers to land occupied by a living organism
```
```
The rules that describe next generation of organisms :-

Birth Rule: 
Any empty land with exactly three live neighbours gets occupied by a newly born organism, as if by reproduction.
   
Survival Rule:
Any living organism with two or three live neighbours lives on to the next generation.

Death Rule:
Any living organism with fewer than two live neighbours dies, as if by underpopulation.
Any living organism with more than three live neighbours dies, as if by overpopulation. 
If the organism dies, the land it occupied gets empty.
```

### What this repo holds?
```
Implementation of Conway's game of life in C++ and python.
A major drawback of this implementation is the size of the playground that hosts the evolution.
These implementations cannot withstand a rectangular playground, they work only on square playgrounds.
```


### Is this simulation of any use?
```
The Game of Life motivated the use of cellular automata in the rich field of complexity science, 
with simulations modeling everything from ants to traffic, clouds to galaxies. 
More trivially, the game attracted a cult of “Lifenthusiasts,” programmers who spent a lot of time hacking Life i.e.,
constructing patterns in hopes of spotting new Life-forms.
```

### What's more to it
```
It's observed that Conway's simulation can give rise to some fascinating stuffs like spaceships and guns.
Changing the rules can give bring some interesting changes in behaviour of organisms, subsequently, deviating their path of evolution.
```
For more info, please refer to the link: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
