# Scanner3D_Arduino
Inspired by this device: https://youtu.be/zAPWRaifZII?t=61 I decided to build something similar using Arduino and the open-source app Blender 3D. 

First I had to build electronics. The base of this project is Arduino and ultrasonic sensor mounted on servos.

The numbers of vertical and horizontal measurements can be controlled by int variables defined on top of the code.

When measurements are taken, the phyton program creates a map of cubes representing obstacles in a 3D Blender environment. 

Because I use 180-degree range servos, a 3D map is only half the sphere.
