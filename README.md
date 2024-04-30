COMP2113 Group Project: Life Theatre (Group 15)

Group Members
Cheung Yat Ching (3036066438)
Chow Lok King (3036216643)
Chung Ka Yi (3036058247)
Kwok Yuen Wang (3036060329)
Lam Wui Yan (3036002420)

INTRODUCTION:
Life Theatre is a text-based minigame which tells the story of a Hero and a Girl. The player is able to choose between the Hero or the Girl. During the journey, they will encounter multiple decisions, and each will lead to a different ending. Player can learn about the full story and the characters by playing through various storylines.
Boy : A young male living in the village, determined to become a hero and save the lives of those around him. 
Girl : A young female living in the village, although not wielding the power of a hero, has her own special adventure in the story.

FEATURE:
This game is a story-based game. Player can explore around the designed maps to trigger different interactions with the NPCs in the game. The decision making dring scenarios of the player will me the core of the entire gameplay. Each choice will lead to a different ending. The Player can unlock 6 achievements by attaining to all the endings.

Generation of random game sets or events: Some chats are designed to be random so characters may chat to you with various dialogues.

Data structure for storing game status: Player can store their game status so that they can continue the gameplay at the same position.

Dynamic memory management: Dynamic memory is used to reduce the memory storage during gamplay and saving.

File input/output: The story, dialouges, endings, player's choices, saved game status, input and output data are in their respective files.

Program codes in multiple files: Our codes are in multiple files so that the codes can be organized and maintained in a better way.

Proper indentation and naming styles: The indentation and naming works were done properly.

In-code documentation: There are comments and documentation included in our codes for other developers to understander and modify the codes.

HOW TO COMPILE AND RUN:
1. Open a terminal in the group project folder.
2. Compile the game using the provided Makefile by the command "make".
3. Run the game by selecting "NEW GAME".

HOW TO PLAY:
W - Move Upwards
A - Move Leftwards
S - Move Rightwards
D - Move Downwards
E - Action
Q - Exit

To play the game, simply create a new game, choose to play the boy or the girl, and then follow the instructions shown on the bottom of the screen. Note that you have to click on an option when a decision needs to be made. Upon completion of the story for the first time, you can then return to the early stages of the game to change your decisions, ultimately altering the storyline. 

LIST OF NON-STANDARD C/C++ LIBRARIES:
<unordered_map>: Provides an unordered associative container implementation of a hash map.
<random>:  Provides facilities for generating random numbers.
<cstdlib>:  Provides general-purpose functions in C, including memory allocation, random number generation, and string conversion.
<ctime>:  Provides functions for manipulating time and date.
<thread>:  Provides classes and functions for managing and synchronizing concurrent execution threads.
<chrono>: Provides classes and functions for working with time durations and time points.
<unistd.h>: Provides access to various POSIX operating system APIs, including system calls and constants.
<sys/ioctl.h>: Provides access to I/O control operations on file descriptors.
<termios.h>: Provides terminal I/O functionality, including terminal modes and control settings.

