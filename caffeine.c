#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


/*
          Caffeine
-------------------------------
Keep your Windows screen awake!
*/


// Function to move the mouse cursor to the specified coordinates
void moveMouse(int x, int y) {
    SetCursorPos(x, y);
}

// Function to simulate a key press
void pressKey(char key) {
    keybd_event(key, 0, 0, 0);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}


int main() {
    int x = 0;
    int y = 0;
    time_t start = time(NULL);  // Start time

    while (1) {
        // Get the current time
        time_t current = time(NULL);

        // If 5 minutes have passed since the start time
        if ((current - start) >= 5 * 10) {
            // Move the mouse cursor to a random location on the screen
            x = rand() % 100;
            y = rand() % 100;
            moveMouse(x, y);
            pressKey('c');
            // Update the start time
            start = time(NULL);
        }
    }

    return 0;
}