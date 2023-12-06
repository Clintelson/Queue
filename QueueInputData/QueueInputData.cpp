#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <thread>
#include <chrono>

int main() {

    //Array
    std::string songsInput[1000];

    int songSize;

    std::cout << "How many songs do you want to input? : ";

    while (true) {
        if (!(std::cin >> songSize)) {
            std::cout << "Invalid! Please input numbers only!" << std::endl;
            std::cout << std::endl;
                std::cout << "How many songs do you want to input? : ";
                    std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
        }

        break;

    }

     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "" << std::endl;
    std::cout << "Input songs: " << std::endl;
        for (int i = 0; i < songSize; i++) {
            std::cout << "Song " << i + 1 << ": ";
                std::getline(std::cin, songsInput[i]);
        }

        std::cout << std::endl;
            std::cout << "Processing....";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                    std::cout << std::endl;

                std::cout << std::endl;
            std::cout << "Entered songs: " << std::endl;
        for (int i = 0; i < songSize; i++) {
            std::cout << std::setw(10) << "Song " << i + 1 << ": " << songsInput[i] << std::endl;
        }

    int chc;

        std::cout << "" << std::endl;
            std::cout << "Delete one song[1]; Delete all songs[2]; Add more songs[3]; Skip[4];" << std::endl;
                std::cout << "> ";
                while (true) {
                    if (!(std::cin >> chc)) {
                        std::cout << "Invalid! Enter the choices only 1, 2, 3, and 4" << std::endl;
                            std::cout << "> ";
                                std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                continue;
                    }
                    break;
                }
        std::cout << std::endl;

    if (chc == 1) {

        int indexToDelete;
            std::cout << "Enter the number of the song to delete (1 to " << songSize << "): ";
            while (true) {
                if (!(std::cin >> indexToDelete)) {
                    std::cout << "Invalid!" << std::endl;
                  std::cout << "Enter the number of the song to delete (1 to " << songSize << "): ";
                        std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                }
                break;
            }

        if (indexToDelete >= 1 && indexToDelete <= songSize) {
            for (int i = indexToDelete - 1; i < songSize - 1; ++i) {
                songsInput[i] = songsInput[i + 1];
            }

            --songSize;

            std::cout << "Deleted the song at index " << indexToDelete << std::endl;

            std::cout << "Updated songs list:" << std::endl;
            for (int i = 0; i < songSize; ++i) {
                std::cout << std::setw(10) << "Song " << i + 1 << ": " << songsInput[i] << std::endl;
            }
        }
        else {
            std::cout << "Invalid index!" << std::endl;
        }
    }

    if (chc == 2) {
        char deleteAll;
        std::cout << "Do you want to delete all songs? (y/n): ";
        std::cin >> deleteAll;

        if (deleteAll == 'y' || deleteAll == 'Y') {
            songSize = 0;
            std::cout << "All songs deleted." << std::endl;
        }
    }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
        std::cout << "Enter additional songs (press Enter to skip):" << std::endl;
            for (int i = songSize; i < 1000; i++) {
                std::cout << "Song " << i + 1 << ": ";
                    std::getline(std::cin, songsInput[i]);
                if (songsInput[i].empty()) {
                    break;
                }
                ++songSize;
            }

    if (chc == 3) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter additional songs (press Enter to skip):" << std::endl;
        for (int i = songSize; i < 1000; i++) {
            std::cout << "Song " << i + 1 << ": ";
                std::getline(std::cin, songsInput[i]);
            if (songsInput[i].empty()) {
                break;
            }
            ++songSize;
        }

    }

        std::cout << std::endl;
            std::cout << "Final songs list:" << std::endl;
        for (int i = 0; i < songSize; i++) {

            std::cout << std::setw(10) << "Song " << i + 1 << ": " << songsInput[i] << std::endl;
        }

        //Queue
    std::queue<std::string> songsQueue;

    int songNum;

    std::string songTitle;

        std::cout << std::endl;
            std::cout << "Enter non-integer to stop. (e.g., 1 2 r)" << std::endl;
        std::cout << "Enter the number of songs you like: ";

        while (true) {
            if (!(std::cin >> songNum)) {
                std::cout << "Invalid! Enter the number of songs only:" << std::endl;
                exit(0);
            }

            if (songNum < 1 || songNum > songSize) {
                std::cout << "Song number not found! " << std::endl;
                continue;
            }

            break;
        }

        songTitle = songsInput[songNum - 1];
        songsQueue.push(songTitle);

        std::cout << std::endl;
            std::cout << "QUEUE" << std::endl;
        std::cout << std::endl;

        std::cout << "Now Playing" << std::endl;
            std::cout << "  - " << songsQueue.front() << std::endl;
        songsQueue.pop();

        std::this_thread::sleep_for(std::chrono::seconds(4));

        std::cout << std::endl;

        while (std::cin >> songNum) {
            if (songNum >= 1 && songNum <= songSize) {
                songTitle = songsInput[songNum - 1];
                    songsQueue.push(songTitle);
            }
            else {
                std::cout << "Invalid song number." << std::endl;
            }
        }

        while (!songsQueue.empty()) {
            std::cout << std::endl;
                std::cout << "Now playing: " << songsQueue.front() << std::endl;
                    std::cout << std::endl;
                std::cout << "Songs added to Queue: " << songsQueue.size() << std::endl;
            songsQueue.pop();
                std::cout << std::endl;
                    std::cout << "Next Song " << std::endl;
                std::cout << std::endl;

            std::queue<std::string> tempQueue = songsQueue;

            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << std::endl;
                tempQueue.pop();
            }

            std::this_thread::sleep_for(std::chrono::seconds(4));
        }

        std::cout << std::endl;
        std::cout << "Queue cleared: " << songsQueue.size() << std::endl;

    return 0;
}
