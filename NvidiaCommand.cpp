#include "NvidiaCommand.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>

void NvidiaCommand::displayNvidiaSmi() {
    // Display Nvidia SMI output
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "Fri " << 1900 + ltm->tm_year << "-"
              << std::setw(2) << std::setfill('0') << (1 + ltm->tm_mon) << "-"
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << " "
              << std::setw(2) << std::setfill('0') << ltm->tm_hour << ":"
              << std::setw(2) << std::setfill('0') << ltm->tm_min << ":"
              << std::setw(2) << std::setfill('0') << ltm->tm_sec << "\n";
    std::cout << "+-----------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 461.79       Driver Version: 461.79       CUDA Version: 11.2     |\n";
    std::cout << "|-------------------------------+----------------------+----------------------|\n";
    std::cout << "| GPU  Name            TCC/WDDM | Bus-Id        Disp.A | Volatile Uncorr. ECC |\n";
    std::cout << "| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |\n";
    std::cout << "|                               |                      |               MIG M. |\n";
    std::cout << "|===============================+======================+======================|\n";
    std::cout << "|   0  GeForce RTX 3070    WDDM | 00000000:01:00.0 Off |                  N/A |\n";
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

    // Wait for user to press Enter
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Wait for Enter
}
