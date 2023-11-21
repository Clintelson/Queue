#include <iostream>
#include <iomanip>  
#include <queue>
#include <thread>
#include <chrono> 

void SongsTable() {

    std::cout << std::setw(5) << "SPOTIFY" << std::endl;
    std::cout << std::setw(15) << "" << std::setw(10) << "SONGS" << std::setw(20) << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << std::left << std::setw(25) << "1.Totoy Bibo" << std::setw(25) << std::setw(25) << "10.Balay ni Mayang" << std::endl;
    std::cout << std::left << std::setw(25) << "2.Ge Finger" << std::setw(25) << "11.Bahay Kubo" << std::endl;
    std::cout << std::left << std::setw(25) << "3.Igo na day" << std::setw(25) << "12.Ikaw ra Gang" << std::endl;
    std::cout << std::left << std::setw(25) << "4.Mamayotay" << std::setw(25) << "13.Englishera" << std::endl;
    std::cout << std::left << std::setw(25) << "5.Walay Forever" << std::setw(25) << "14.Istambay" << std::endl;
    std::cout << std::left << std::setw(25) << "6.Irong Gipatol" << std::setw(25) << "15.Suroy-Suroy" << std::endl;
    std::cout << std::left << std::setw(25) << "7.Otso-Otso" << std::setw(25) << "16.Quit" << std::endl;
    std::cout << std::left << std::setw(25) << "8.Ukay-Ukay Condom \n" << std::endl;
    std::cout << std::left << std::setw(25) << "9.Mahimo ba Inday" << std::endl;

}

void SongData(std::string& songTitle, int songnum) {

    switch (songnum) {

    case 1:
        songTitle = "   Totoy bibo";
        break;
    case 2:
        songTitle = "   Ge Finger";
        break;
    case 3:
        songTitle = "   Igo na day";
        break;
    case 4:
        songTitle = "   Mamayotay";
        break;
    case 5:
        songTitle = "   Walay Forever";
        break;
    case 6:
        songTitle = "   Irong Gipatol";
        break;
    case 7:
        songTitle = "   Otso-Otso";
        break;
    case 8:
        songTitle = "   Ukay-Ukay Condom";
        break;
    case 9:
        songTitle = "   Mahimo ba Inday";
        break;
    case 10:
        songTitle = "   Balay ni Mayang";
        break;
    case 11:
        songTitle = "   Bahay Kubo";
        break;
    case 12:
        songTitle = "   Ikaw ra Gang";
        break;
    case 13:
        songTitle = "   Englishera";
        break;
    case 14:
        songTitle = "   Istambay";
        break;
    case 15:
        songTitle = "   Suroy-Suroy";
        break;
    default:
        songTitle = "   Unknown Song";
        break;
    }

}

int main() {
    SongsTable();

    std::queue<std::string> songsq;

    int songnum;

    std::string songTitle;

    std::cout << "" << std::endl;

    std::cout << "Enter non-integer to stop.(e.g 1 2 r)" << std::endl;
        std::cout << "Enter the number of songs you like: ";

    while (true) {

        if (!(std::cin >> songnum)) {
            std::cout << "Invalid! Enter the number of songs only:" << std::endl;
                std::cout << "Enter non-integer to stop." << std::endl;
                    std::cout << "Enter the number of songs you like: ";
                std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;;
        }

        if (songnum == 16) {

            std::cout << "BYE!!!";
                exit(0);
        }

        if (songnum < 1 || songnum > 15) {
            std::cout << "Song number not found! " << std::endl;
                continue;
        }

        break;
    }

    SongData(songTitle, songnum);
    songsq.push(songTitle);

    std::cout << "" << std::endl;
        std::cout << "QUEUE" << std::endl;
            std::cout << "" << std::endl;

            std::cout << "Now Playing" << std::endl;
        std::cout << "  -" << songsq.front() << std::endl;
    songsq.pop();

        std::this_thread::sleep_for(std::chrono::seconds(4));

            std::cout << "" << std::endl;

        while (std::cin >> songnum) {
            if (songnum > 1 && songnum <= 15) {
                SongData(songTitle, songnum);
                songsq.push(songTitle);
            }
        }

    while (!songsq.empty()) {

        std::cout << "" << std::endl;
            std::cout << "Now playing: " << songsq.front() << std::endl;
                std::cout << "" << std::endl;
                    std::cout << "Songs added to Queue: " << songsq.size() << std::endl;
                        songsq.pop();
                    std::cout << "" << std::endl;
                std::cout << "Next Song " << std::endl;
            std::cout << "" << std::endl;

        std::queue<std::string> temp_queue = songsq;

        while (!temp_queue.empty()) {

            std::cout << temp_queue.front() << std::endl;
            temp_queue.pop();

        }

        std::this_thread::sleep_for(std::chrono::seconds(4));

    }

        std::cout << "" << std::endl;
            std::cout << "Queue cleared: " << songsq.size() << std::endl;

    return 0;
}