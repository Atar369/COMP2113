#ifndef KEYBOARD_H
#define KEYBOARD_H

// Function declarations or class definitions go here
struct Player {
    int x;
    int y;
    int hrz;
    int vtcl;
    char symbol[4];
};

Player player;

void moveUp();

void moveDown();

void moveLeft();

void moveRight();

void stopMovement();
#endif // KEYBOARD_H
