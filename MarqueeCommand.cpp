#include "MarqueeCommand.h"
#include <iostream>
#include <conio.h>  // For _kbhit and _getch

#ifdef _WIN32
    #include <windows.h>  // For Sleep
#else
    #include <unistd.h>   // For usleep
#endif
#include <string>

void MarqueeCommand::startMarquee() {
    // Marquee text
    std::string marqueeText = "CSOPESY";
    int consoleWidth = 120;
    int consoleHeight = 20;
    int x = 2, y = 2, dx = 2, dy = 1;
    
    std::string inputBuffer;  // Buffer to collect user input

    clearScreen();  // Ensure screen is cleared before starting

    while (true) {
        clearScreen();

        // Top border
        std::cout << "+" << std::string(consoleWidth - 2, '-') << "+\n";

        // Draw the console screen with the marquee text
        for (int i = 0; i < consoleHeight - 2; i++) {
            std::cout << "|";  // Left border
            for (int j = 0; j < consoleWidth - 2; j++) {
                if (i == y && j == x) {
                    std::cout << marqueeText;
                    j += marqueeText.size() - 1;  // Move cursor forward to avoid overwriting text
                } else {
                    std::cout << " ";
                }
            }
            std::cout << "|\n";  // Right border
        }

        // Bottom border
        std::cout << "+" << std::string(consoleWidth - 2, '-') << "+\n";

        // Move the marquee text
        x += dx;
        y += dy;

        // Boundary checking for the marquee text
        if (x <= 1 || x >= consoleWidth - marqueeText.size() - 3) dx = -dx;
        if (y <= 1 || y >= consoleHeight - 3) dy = -dy;

#ifdef _WIN32
        Sleep(15);  // Delay for Windows
#else
        usleep(15000);  // Delay for Unix-based systems
#endif

        // Check for input without waiting for Enter
        if (_kbhit()) {  // If a key is pressed
            char ch = _getch();  // Get the character

            // Handle input: append the character to inputBuffer and check for "back"
            if (ch == '\r') {  // If Enter is pressed, ignore it
                continue;
            } else if (ch == '\b') {  // Handle backspace
                if (!inputBuffer.empty()) {
                    inputBuffer.pop_back();
                }
            } else {
                inputBuffer += ch;  // Add the character to the buffer
            }

            // Check if the user has entered "back"
            if (inputBuffer == "back") {
                clearScreen();  // Clear the screen
                return;  // Exit and go back to the main menu
            }

            // Reset the buffer if the input exceeds the size of "back" and doesn't match
            if (inputBuffer.size() > 4) {
                inputBuffer.clear();  // Clear buffer if incorrect command is entered
            }
        }
    }
}

void MarqueeCommand::clearScreen() {
#ifdef _WIN32
    system("cls");  // Clear screen for Windows
#else
    system("clear");  // Clear screen for Unix-based systems
#endif
}
