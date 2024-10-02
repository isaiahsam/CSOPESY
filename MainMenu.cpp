#include <iostream>
#include <sstream>
#include <conio.h> 
#ifdef _WIN32
    #include <windows.h> 
#else
    #include <unistd.h>  
#endif

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
    std::cout << "  'marquee'        - Start the marquee application\n";
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

void MainMenu::startMarquee() {
    clearScreen();

    std::string header = 
    R"(    ...     ..      ..                                                                               
  x*8888x.:*8888: -"888:                                                                             
 X   48888X `8888H  8888                  .u    .                  x.    .                           
X8x.  8888X  8888X  !888>        u      .d88B :@8c      .u@u     .@88k  z88u        .u         .u    
X8888 X8888  88888   "*8%-    us888u.  ="8888f8888r  .zWF8888bx ~"8888 ^8888     ud8888.    ud8888.  
'*888!X8888> X8888  xH8>   .@88 "8888"   4888>'88"  .888  9888    8888  888R   :888'8888. :888'8888. 
  `?8 `8888  X888X X888>   9888  9888    4888> '    I888  9888    8888  888R   d888 '88%" d888 '88%" 
  -^  '888"  X888  8888>   9888  9888    4888>      I888  9888    8888  888R   8888.+"    8888.+"    
   dx '88~x. !88~  8888>   9888  9888   .d888L .+   I888  9888    8888 ,888B . 8888L      8888L      
 .8888Xf.888x:!    X888X.: 9888  9888   ^"8888*"    `888Nx?888   "8888Y 8888"  '8888c. .+ '8888c. .+ 
:""888":~"888"     `888*"  "888*""888"     "Y"       "88" '888    `Y"   'YP     "88888%    "88888%   
    "~'    "~        ""     ^Y"   ^Y'                      88E                    "YP'       "YP'    
                                                           98>                                       
                                                           '8                                         
                                                            `)";

   std::string borderTopBottom = "+------------------------------------------------------------------------------------------------------------------------+";
    std::string borderSide = "|                                                                                                                            |";

    int consoleWidth = 120; 
    int consoleHeight = 20; 

    int x = 1, y = 2;  
    int dx = 2, dy = 1; 
    std::string marqueeText = "CSOPESY";
    int textLength = marqueeText.length();

    while (true) {
        clearScreen();

        std::cout << borderTopBottom << "\n";
        std::cout << borderSide << "\n";
        std::cout << header << "\n";
        std::cout << borderSide << "\n";
        

        for (int i = 1; i < consoleHeight - 2; ++i) {
            std::cout << "|"; 
            for (int j = 1; j < consoleWidth - 1; ++j) {
                if (i == y && j == x) {
                    std::cout << marqueeText;
                    j += textLength - 1; 
                } else {
                    std::cout << " "; 
                }
            }
            std::cout << "|" << std::endl; 
        }
        std::cout << borderTopBottom << "\n";

        std::cout << "Enter a command: ";

        x += dx;
        y += dy;

        if (x <= 1 || x >= consoleWidth - textLength - 2) dx = -dx;
        if (y <= 1 || y >= consoleHeight - 3) dy = -dy;


#ifdef _WIN32
        Sleep(15); // Decreased sleep duration for faster refresh rate
#else
        usleep(15000); // Decreased sleep duration for Unix-like systems
#endif

        if (_kbhit()) { 
            std::string input;
            std::getline(std::cin, input);
            if (input == "back") break;
        }
    }

    clearScreen();
    displayMainMenu();
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

    else if (command == "marquee") // New command to start marquee
    {
        clearScreen(); // Clear the screen
        startMarquee(); // Start the marquee
        clearScreen(); // Clear the screen after exiting marquee
        displayMainMenu(); // Display the main menu again
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