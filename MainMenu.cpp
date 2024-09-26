#include <iostream>
#include <sstream>

#include "MainMenu.h"
#include "ScreenLayout.h"

void MainMenu::displayMainMenu()
{

    std::cout << "          _____                    _____                   _______                   _____                    _____                    _____                _____          \n";
    std::cout << "         /\\    \\                  /\\    \\                 /::\\    \\                 /\\    \\                  /\\    \\                  /\\    \\              |\\    \\         \n";
    std::cout << "        /::\\    \\                /::\\    \\               /::::\\    \\               /::\\    \\                /::\\    \\                /::\\    \\             |:\\____\\        \n";
    std::cout << "       /::::\\    \\              /::::\\    \\             /::::::\\    \\             /::::\\    \\              /::::\\    \\              /::::\\    \\            |::|   |        \n";
    std::cout << "      /::::::\\    \\            /::::::\\    \\           /::::::::\\    \\           /::::::\\    \\            /::::::\\    \\            /::::::\\    \\           |::|   |        \n";
    std::cout << "     /:::/\\:::\\    \\          /:::/\\:::\\    \\         /:::/~~\\:::\\    \\         /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          |::|   |        \n";
    std::cout << "    /:::/  \\:::\\    \\        /:::/__\\:::\\    \\       /:::/    \\:::\\    \\       /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\         |::|   |        \n";
    std::cout << "   /:::/    \\:::\\    \\       \\:::\\   \\:::\\    \\     /:::/    / \\:::\\    \\     /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\        |::|   |        \n";
    std::cout << "  /:::/    / \\:::\\    \\    ___\\:::\\   \\:::\\    \\   /:::/____/   \\:::\\____\\   /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\       |::|___|______  \n";
    std::cout << " /:::/    /   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\ |:::|    |     |:::|    | /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\      /::::::::\\    \\ \n";
    std::cout << "/:::/____/     \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\|:::|____|     |:::|    |/:::/  \\:::\\   \\:::|    |/:::/__\\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\    /::::::::::\\____\\\n";
    std::cout << "\\:::\\    \\      \\::/    /\\:::\\   \\:::\\   \\::/    / \\:::\\    \\   /:::/    / \\::/    \\:::\\  /:::|____|\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /   /:::/~~~~/~~      \n";
    std::cout << " \\:::\\    \\      \\/____/  \\:::\\   \\:::\\   \\/____/   \\:::\\    \\ /:::/    /   \\/_____\\/:::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/   /:::/    /         \n";
    std::cout << "  \\:::\\    \\               \\:::\\   \\:::\\    \\        \\:::\\    /:::/    /             \\::::::/    /    \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\      /:::/    /          \n";
    std::cout << "   \\:::\\    \\               \\:::\\   \\:::\\____\\        \\:::\\__/:::/    /               \\::::/    /      \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\    /:::/    /           \n";
    std::cout << "    \\:::\\    \\               \\:::\\  /:::/    /         \\::::::::/    /                 \\::/____/        \\:::\\   \\::/    /        \\:::\\  /:::/    /    \\::/    /            \n";
    std::cout << "     \\:::\\    \\               \\:::\\/:::/    /           \\::::::/    /                   ~~               \\:::\\   \\/____/          \\:::\\/:::/    /      \\/____/             \n";
    std::cout << "      \\:::\\    \\               \\::::::/    /             \\::::/    /                                      \\:::\\    \\               \\::::::/    /                            \n";
    std::cout << "       \\:::\\____\\               \\::::/    /               \\::/____/                                        \\:::\\____\\               \\::::/    /                             \n";
    std::cout << "        \\::/    /                \\::/    /                 ~~                                               \\::/    /                \\::/    /                              \n";
    std::cout << "         \\/____/                  \\/____/                                                                    \\/____/                  \\/____/                               \n";
    std::cout << "____________________________________________________________________________________________________________\n\n";
    std::cout << "                                          Command Line Emulator\n";
    std::cout << "\n____________________________________________________________________________________________________________\n\n";

    std::cout << "\033[32mHello, Welcome to CSOPESY command line interface!\n\n"
              << "\033[0m";

    // Display the list of available commands
    std::cout << "List of Available Commands:\n\n";
    std::cout << "  'initialize'     - Initialize something\n";
    std::cout << "  'screen'         - Manage screen operations\n";
    std::cout << "  'scheduler-test' - Test the scheduler\n";
    std::cout << "  'scheduler-stop' - Stop the scheduler\n";
    std::cout << "  'report-util'    - Run report utility\n";
    std::cout << "  'clear'          - Clear the screen\n";
    std::cout << "  'exit'           - Exit the application\n";
    std::cout << "__________________________________________\n\n";
}

// Function to clear output in the screen
void MainMenu::clearScreen()
{
/* Modified so that it would be cross-platform */
#ifdef _WIN32
    system("cls"); // Clear screen for Windows
#else
    system("clear"); // Clear screen for Linux/Unix/MacOS
#endif
}

// Check if a screen with a given name exists
bool MainMenu::screenExists(const std::string &name)
{
    for (const std::string &screen : screens)
    {
        if (screen == name)
            return true;
    }
    return false;
}

void MainMenu::processCommand(const std::string &command)
{
    ScreenLayout screenLayout;
    static bool isScreenLayoutActive = false; // Track if the screen layout is active

    std::stringstream ss(command);

    std::string cmd, option, screenName;
    ss >> cmd >> option >> screenName;

    // Different conditions for command actions

    if (command == "initialize")
    {
        std::cout << "initialize command recognized. Doing something.\n";
    }

    else if (cmd == "screen" && option.empty())
    {
        std::cout << "screen command recognized. Doing something.\n";
    }

    // screen -s: creating and loading a screen
    else if (cmd == "screen" && option == "-s")
    {
        if (screenName.empty())
        {
            std::cout << "Please provide a screen name.\n";
        }
        else
        {
            if (screenExists(screenName))
            {
                std::cout << "The screen '" << screenName << "' already exists.\n";
            }
            else
            {
                screens.push_back(screenName);                // Add the new screen
                clearScreen();                                // Clear the main menu console
                screenLayout.displayScreenLayout(screenName); // Display the new screen
                isScreenLayoutActive = true;

                // Handle input for the screen layout
                std::string screenCommand;
                while (isScreenLayoutActive)
                {
                    std::cout << "root:\\> "; // Change prompt for screen layout
                    std::getline(std::cin, screenCommand);

                    if (screenCommand == "exit")
                    {
                        isScreenLayoutActive = false; // Return to main menu
                        clearScreen();                // Clear the screen for the main menu
                        displayMainMenu();            // Display the main menu again
                    }
                    else
                    {
                        std::cout << "\nUnknown command input. Try again.\n\n";
                    }
                }
            }
        }
    }
    else if (cmd == "screen" && option == "-r")
    {
        if (screenName.empty())
        {
            std::cout << "Please provide a screen name.\n";
        }
        else if (!screenExists(screenName))
        {
            std::cout << "The screen does not exist yet. Try again!\n";
        }
        else
        {
            clearScreen();                                // Clear the main menu console
            screenLayout.displayScreenLayout(screenName); // Re-draw the screen that was created

            isScreenLayoutActive = true;

            // Handle input for the screen layout
            std::string screenCommand;
            while (isScreenLayoutActive)
            {
                std::cout << "root:\\> "; // Change prompt for screen layout
                std::getline(std::cin, screenCommand);

                if (screenCommand == "exit")
                {
                    isScreenLayoutActive = false; // Return to main menu
                    clearScreen();                // Clear the screen for the main menu
                    displayMainMenu();            // Display the main menu again
                }
                else
                {
                    std::cout << "\nUnknown command input. Try again.\n\n";
                }
            }
        }
    }

    else if (command == "scheduler-test")
    {
        std::cout << "scheduler-test command recognized. Doing something.\n";
    }
    else if (command == "scheduler-stop")
    {
        std::cout << "scheduler-stop command recognized. Doing something.\n";
    }
    else if (command == "report-util")
    {
        std::cout << "report-util command recognized. Doing something.\n";
    }
    else if (command == "clear")
    {
        clearScreen();     // Clear the screen
        displayMainMenu(); // Display the main menu again after clearing
    }
    else if (command == "exit")
    {
        std::cout << "Exiting the application.\n";
        exit(0);
    }
    else
    {
        std::cout << "Unknown command. Try again.\n";
    }
}