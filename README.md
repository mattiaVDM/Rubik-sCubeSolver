# Rubik-sCubeSolverInC++

![Immagine](https://user-images.githubusercontent.com/56454542/176896577-96192091-1e7f-4408-af98-892f6b2f211a.png)

Hello everyone!
I'm a computer engineering student and I had my first programming exam a few months ago. 
As a project I presented a Rubik cube solver (programmed in C ++ Object oriented) and I wanted to share it to get some opinions about it.
It may seem a bit confusing but I am a beginner with programming.

The solver is based on a method called "layer by layer", it is the simplest method to solve Rubik's Cube but also the one that requires the most moves.
It is divided into five phases described in detail in this video:

https://www.youtube.com/watch?v=1t1OL2zN0LQ

The program works using two main classes:

Cube class

The class contains 6 vectors that correspond to the 6 faces of the cube, each vector has 9 elements that correspond to the 9 cubes of the face. 
Each element is a char that indicates the color of the cube that is in that particular position.
The class also contains the input and output operators, copy constructor and all the functions that allow you to make the moves (from the rotations of the entire cube to those of the individual faces).

Solver class
The solver class contains a vector of cube objects in which copies of the cubes are saved after the completion of each phase.
It also contains the function that automatically resolves the cube.

The main is an interactive menu that allows you to:

- Insert a cube manually or generate it automatically.

- Simulate the resolution of x cubes to print the statistics (minimum and maximum moves used, average moves). The solver on my laptot solves up to 6000 cubes per second.

- Solve the cube generated manually: a list of the moves applicable to the cube is printed, I added this feature only for fun since the 2D printing of the cube does not allow easy resolution.

- Solve the automatically generated cube: A copy of the cube is printed after each phase, furthermore, once solved, a "Step by Step" solution is proposed which displays all the moves applied starting from the original cube.

I implemented a basic GUI to visualize the cube in 2D.
