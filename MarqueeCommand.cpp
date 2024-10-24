#include "MarqueeCommand.h"
#include <iostream>
#include <string>
#include <thread>  // Required for std::this_thread
#include <chrono>  // Required for std::chrono
#include <conio.h> // For _kbhit() and _getch()

void MarqueeCommand::startMarquee() {
    std::string marqueeText = "CSOPESY";
    int consoleWidth = 80;  // Adjust as necessary for your console
    int x = consoleWidth;    // Start position (off-screen on the right)
    int speed = 100;         // Speed of the marquee (lower is faster)

    clearScreen();  // Clear the screen initially

    while (true) {
        clearScreen();  // Clear the screen for the next frame

        // Print the marquee text at the current position
        std::cout << std::string(x, ' ') << marqueeText << std::endl;

        // Move the text to the left
        x--;
        
        // Reset position if it moves off the left side
        if (x < -static_cast<int>(marqueeText.length())) {
            x = consoleWidth;  // Reset to the right
        }

        // Check for user input to exit
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '\r') {  // If Enter is pressed
                break;  // Exit the loop
            }
        }

        // Control the speed of the marquee
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }

    clearScreen();  // Final clear before returning to the main menu
}

void MarqueeCommand::clearScreen() {
#ifdef _WIN32
    system("cls");  // Clear screen for Windows
#else
    system("clear");  // Clear screen for Unix-based systems
#endif
}
