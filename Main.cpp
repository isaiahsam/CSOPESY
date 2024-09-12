#include <iostream>
#include <string>
#include <cstdlib> 


void headerDisplay() {
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
    std::cout << "                              Command Line Emulator\n";
    std::cout << "____________________________________________________________________________________________________________\n\n";

    // Display the list of available commands
    std::cout << "Available Commands:\n";
    std::cout << "  initialize     - Initialize something\n";
    std::cout << "  screen         - Manage screen operations\n";
    std::cout << "  scheduler-test - Test the scheduler\n";
    std::cout << "  scheduler-stop - Stop the scheduler\n";
    std::cout << "  report-util    - Run report utility\n";
    std::cout << "  clear          - Clear the screen\n";
    std::cout << "  exit           - Exit the application\n";
    std::cout << "____________________________________________________________________________________________________________\n\n";
}


void clearScreen() {
#ifdef _WIN32
    system("cls"); 
#endif
    headerDisplay();
}

int main() {
    std::string command;
    headerDisplay();

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "initialize") {
            std::cout << "initialize command recognized. Doing something.\n";
        } else if (command == "screen") {
            std::cout << "screen command recognized. Doing something.\n";
        } else if (command == "scheduler-test") {
            std::cout << "scheduler-test command recognized. Doing something.\n";
        } else if (command == "scheduler-stop") {
            std::cout << "scheduler-stop command recognized. Doing something.\n";
        } else if (command == "report-util") {
            std::cout << "report-util command recognized. Doing something.\n";
        } else if (command == "clear") {
            clearScreen();
        } else if (command == "exit") {
            std::cout << "Exiting the application.\n";
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }

    return 0;
}
