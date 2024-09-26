#include <string>
#include <vector>

class MainMenu
{

private:
    std::vector<std::string> screens; // this will be used to store screen names (processes)

public:
    void displayMainMenu();

    void clearScreen();

    void processCommand(const std::string &command);

    bool screenExists(const std::string &name);
};