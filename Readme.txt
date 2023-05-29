1. Use ./box <7 variables >
2.I have used Leaks instead of Valgrind as i am using an arm based processor (MBP M1Pro) 
3.The code has been tested in the lab ENV



Leaks Output 


----------------------------------------------------------------------------------------------------------------
*********
*       *
*       *
*       *
*       *
*   P   *
*   G   *
*       *
*********
Move the box to the goal to win the game!
Press W to move Up 
Press A to move left
Press S to move down 
Press D to move right
Congratulations You have won The Game 
Process:         box [11075]
Path:            /Users/USER/Desktop/*/box
Load Address:    0x102ee4000
Identifier:      box
Version:         0
Code Type:       ARM64
Platform:        macOS
Parent Process:  leaks [11074]

Date/Time:       2023-04-26 23:13:41.289 +0800
Launch Time:     2023-04-26 23:13:37.210 +0800
OS Version:      macOS 13.0.1 (22A400)
Report Version:  7
Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
Analysis Tool Version:  Xcode 14.1 (14B47b)

Physical footprint:         3009K
Physical footprint (peak):  3009K
Idle exit: untracked
----

leaks Report Version: 3.0
Process 11075: 221 nodes malloced for 22 KB
Process 11075: 0 leaks for 0 total leaked bytes.
----------------------------------------------------------------------------------------------------


VALGRIND OUTPUT
----------------------------------------------------------------------------------------------------
==41966== 
==41966== HEAP SUMMARY:
==41966==     in use at exit: 0 bytes in 0 blocks
==41966==   total heap usage: 12 allocs, 12 frees, 2,201 bytes allocated
==41966== 
==41966== All heap blocks were freed -- no leaks are possible
==41966== 
==41966== Use --track-origins=yes to see where uninitialised values come from
==41966== For lists of detected and suppressed errors, rerun with: -s
---------------------------------------------------------------------------------------------------------------