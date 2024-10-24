#include "MarqueeCommand.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>   // For usleep
#include <string>

bool running = true; // Control flag for the marquee loop

void* marqueeTask(void*) {
    // Marquee text
    std::string marqueeText = "CSOPESY";
    int consoleWidth = 120;
    int consoleHeight = 20;
    int x = 2;

    while (running) {
        // Clear screen
        system("clear"); // For Unix-based systems

        // Top border
        std::cout << "+" << std::string(consoleWidth - 2, '-') << "+\n";

        // Draw the console screen with the marquee text
        for (int i = 0; i < consoleHeight - 2; i++) {
            std::cout << "|";  // Left border
            for (int j = 0; j < consoleWidth - 2; j++) {
                if (i == 2 && j == x) {
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
        std::cout << "Press Enter to go back to the main screen\n";

        // Move the marquee text
        x++;
        if (x >= consoleWidth - marqueeText.size() - 2) {
            x = 2; // Reset position
        }

        usleep(150000); // Delay for Unix-based systems
    }
    return nullptr;
}

void* inputTask(void*) {
    std::string inputBuffer;

    while (running) {
        char ch = std::cin.get();
        
        if (ch == '\n') {
            running = false; // Stop the marquee when Enter is pressed
        } else if (ch == '\b') {  // Handle backspace
            if (!inputBuffer.empty()) {
                inputBuffer.pop_back();
            }
        } else {
            inputBuffer += ch;  // Add the character to the buffer
        }

        // Check if the user has entered "back"
        if (inputBuffer == "back") {
            running = false; // Stop the marquee if "back" is entered
        }
    }
    return nullptr;
}

void MarqueeCommand::startMarquee() {
    pthread_t marqueeThread, inputThread;

    // Create threads for marquee and input handling
    pthread_create(&marqueeThread, nullptr, marqueeTask, nullptr);
    pthread_create(&inputThread, nullptr, inputTask, nullptr);

    // Wait for both threads to finish
    pthread_join(inputThread, nullptr);
    pthread_join(marqueeThread, nullptr);

    clearScreen(); // Clear the screen before returning to the main menu
}

void MarqueeCommand::clearScreen() {
    system("clear");  // Clear screen for Unix-based systems
}
