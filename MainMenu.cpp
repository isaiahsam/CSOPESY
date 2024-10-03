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
#include <ctime>

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
    std::cout << "  'nvidia-smi'     - Display Nvidia SMI\n";
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

void MainMenu::displayNvidiaSmi()
{
    // Get the current system time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Format and display the current date and time
    std::cout << "Fri " 
              << 1900 + ltm->tm_year << "-"  // Display the year (tm_year gives years since 1900)
              << 1 + ltm->tm_mon << "-"     // Display the month (tm_mon is 0-based, so add 1)
              << ltm->tm_mday << " "        // Display the day of the month
              << 1 + ltm->tm_hour << ":"    // Display the hour (tm_hour is 0-based)
              << 1 + ltm->tm_min << ":"     // Display the minute
              << 1 + ltm->tm_sec            // Display the second
              << "\n";

    std::cout << "+-----------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 461.79       Driver Version: 461.79       CUDA Version: 11.2     |\n";
    std::cout << "|-------------------------------+----------------------+----------------------|\n";
    std::cout << "| GPU  Name            TCC/WDDM | Bus-Id        Disp.A | Volatile Uncorr. ECC |\n";
    std::cout << "| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |\n";
    std::cout << "|                               |                      |               MIG M. |\n";
    std::cout << "|===============================+======================+======================|\n";
    std::cout << "|   0  GeForce RTX 307... WDDM  | 00000000:01:00.0 Off |                  N/A |\n";
    std::cout << "| N/A   67C    P0    22W /  N/A |    637MiB /  8192MiB |     16%      Default |\n";
    std::cout << "|                               |                      |                  N/A |\n";
    std::cout << "+-------------------------------+----------------------+----------------------+\n";
    std::cout << "\n";
    std::cout << "+-----------------------------------------------------------------------------+\n";
    std::cout << "| Processes:                                                                  |\n";
    std::cout << "|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |\n";
    std::cout << "|        ID   ID                                                   Usage      |\n";
    std::cout << "|=============================================================================|\n";
    std::cout << "|    0   N/A  N/A      2184    C+G   Insufficient Permissions        N/A      |\n";
    std::cout << "|    0   N/A  N/A      3232    C+G   ...icrosoft VS Code\\Code.exe    N/A      |\n";
    std::cout << "|    0   N/A  N/A      7264    C+G   ...2txyewy\\TextInputHost.exe    N/A      |\n";
    std::cout << "|    0   N/A  N/A      7336    C+G   ...Client\\v1.0.7\\rsAppUI.exe    N/A      |\n";
    std::cout << "|    0   N/A  N/A      8372    C+G   ...v1g1gvanyjgm\\WhatsApp.exe    N/A      |\n";
    std::cout << "+-----------------------------------------------------------------------------+\n";
    
    std::cout << "\nType 'back' to go back to the main menu: ";
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

    if (command == "initialize")
    {
        std::cout << "initialize command recognized. Doing something.\n";
    }
    else if (cmd == "screen" && option.empty())
    {
        std::cout << "screen command recognized. Doing something.\n";
    }
    else if (command == "nvidia-smi")
    {
        clearScreen();             // Clear the screen
        displayNvidiaSmi();         // Display the dummy NVIDIA SMI output

        std::string userInput;
        std::getline(std::cin, userInput); // Get user input

        if (userInput == "back") {
            clearScreen(); // Clear the screen
            displayMainMenu(); // Display the main menu
        }
    }
    else if (command == "marquee") 
    {
        clearScreen(); 
        startMarquee(); 
        clearScreen(); 
        displayMainMenu(); 
    }
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

                std::string screenCommand;
                while (isScreenLayoutActive)
                {
                    std::cout << "root:\\> "; 
                    std::getline(std::cin, screenCommand);

                    if (screenCommand == "exit")
                    {
                        isScreenLayoutActive = false; 
                        clearScreen();  
                        displayMainMenu(); 
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
            clearScreen();                                
            screenLayout.displayScreenLayout(screenName);

            isScreenLayoutActive = true;

            std::string screenCommand;
            while (isScreenLayoutActive)
            {
                std::cout << "root:\\> "; 
                std::getline(std::cin, screenCommand);

                if (screenCommand == "exit")
                {
                    isScreenLayoutActive = false; 
                    clearScreen();  
                    displayMainMenu(); 
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
        clearScreen(); 
        displayMainMenu(); 
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