# SimpleFormations
This project was to test different formations for entities

By: Angus Poole

## COMPILING/RUNNING:
Compile/Run in x86/Release

NOTE: although the entities are placed in 2 rows at the start, this is NOT the Two Rows formation that is bound to 5

## CONTROLS:
1 = Circle Formation
2 = V Formation
3 = Square Formation
4 = Line Formation
5 = Two Rows Formation

6 = Break formation
7 = Regroup to last designated formation

8 = Start following path
9 = Reverse path following
0 = Stop following path


## ABOUT THE PATHING: 
I made it so that you can only follow the path once in a given direction. Thus, if you press 8 to follow the path forwards, you will need to press 9 and go through the reversed path before you can press 8 to follow it forwards again. 
If you press 0, the pathing movement "pauses" at the current position and time within the path. So if you press 8 and wait for 6 seconds, then press 0, the next time you press 8 it will continue from where you paused it. If you pressed 9, it would still continue, but it would run through the path in reverse
from where you paused.

## ABOUT THE FORMATIONS IN THE PATH:
The formations should strive to maintain their current shape AFTER rotating to follow the path.
So, if the path turns 90 degrees to the left, the entire formation will rotate with it.
This means not only are the ships themselves rotating, but the formation as a whole.


CODE:
Most of the relevant code can be found in AIFlocking.cpp, which also contains the code for formations and pathing.
UserIO.cpp contains the keyboard presses.