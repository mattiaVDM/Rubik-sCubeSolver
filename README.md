# Rubik-sCubeSolverInC++

![Immagine](https://user-images.githubusercontent.com/56454542/176896577-96192091-1e7f-4408-af98-892f6b2f211a.png)

The solver is based on a method called "layer by layer", it is the simplest method to solve a Rubik's Cube.
It is divided into five phases described in detail in this video:

https://www.youtube.com/watch?v=1t1OL2zN0LQ

The program works using two main classes:

## Cube class

The class contains 6 vectors that correspond to the 6 faces of the cube, each vector has 9 elements that correspond to the 9 cubes of the face. 
Each element is a char that indicates the color of the cube that is in that particular position.
The class also contains the input and output operators, copy constructor and all the functions that allow you to make the moves (from the rotations of the entire cube to those of the individual faces). I implemented a basic GUI to visualize the cube in 2D.

## Solver class
The solver class contains a vector of cube objects in which copies of the cubes are saved after the completion of each phase.
It also contains the function that automatically resolves the cube.

The main is an interactive menu that allows you to:

- Insert a cube manually or generate it automatically.

- Simulate the resolution of x cubes to print the statistics (minimum and maximum moves used, average moves). The solver on my laptot solves up to 6000 cubes per second.

![Immagine](https://user-images.githubusercontent.com/56454542/176928167-c27da01c-49e2-41f6-929f-2011c977dd8f.png)

- Solve the cube generated manually: a list of the moves applicable to the cube is printed, I added this feature only for fun since the 2D printing of the cube does not allow easy resolution.

![2](https://user-images.githubusercontent.com/56454542/176928509-951bf091-4f11-40ca-9de8-4801adfd35ee.png)


- Solve the automatically generated cube: A copy of the cube is printed after each phase, once solved a txt file is generated which displays all the moves made starting from the original cube.

![3](https://user-images.githubusercontent.com/56454542/176928767-a2770b74-ae9a-40ba-b226-92abbae50e4d.png)

