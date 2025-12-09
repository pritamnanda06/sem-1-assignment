                                        DONUT.c

This is a famous C program that prints a spinning ASCII donut in our terminal.Instead of graphics,it uses math+text characters to simulate 3D rotation.

                                Ideas behind the program

1. 	Torus (donut shape):
A donut in 3D can be described using two angles:
 	goes around the tube (small circle).
 	goes around the donut itself (big circle).
2. 	Rotation:
Two variables  and  represent rotation angles. They change slightly each frame to make the donut spin.
3. 	Projection:
The program takes 3D points on the donut and projects them into 2D coordinates (, ) on your terminal screen.
4. 	Shading:
Depending on how each point faces the “light,” it chooses a character from .
Darker characters = shadow, brighter characters = highlight.
5. 	Buffers:
    stores characters for the current frame.
 	stores depth (how close each point is) so nearer points overwrite farther ones.
6. 	Animation loop:
The program runs forever (), updating angles and redrawing the donut each time.



NOTE:This readme file is only for Donut.c question.