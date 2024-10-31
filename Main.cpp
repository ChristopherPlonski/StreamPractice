#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

/// <summary>
/// Count the number of games where the name starts with the letter "C" (case insensitive).
/// </summary>
void problem_1() {
    ifstream tsvFile;
    tsvFile.open("data/video_games.tsv");

    int numberOfGamesNamesWithCAsFirstLetter = 0;

    if (tsvFile.is_open())
    {
        string line;
        while (getline(tsvFile, line))
        {
            char firstCharOfGameName = line[0];
            if (firstCharOfGameName == 'c' || firstCharOfGameName == 'C') {
                numberOfGamesNamesWithCAsFirstLetter++;
            }
        }
    }
    else
    {
        cout << "Sorry, the file could not be openend." << endl;
    }

    tsvFile.close();

    cout << "Number of games which names start with 'C' : " << numberOfGamesNamesWithCAsFirstLetter << endl;
}

/// <summary>
/// Count the number of games which were published in the year 2017
/// </summary>
void problem_3() {
    ifstream tsvFile;
    tsvFile.open("data/video_games.tsv");

    int numberOfGamesPublishedIn2017 = 0;

    if (tsvFile.is_open())
    {
        string line;
        while (getline(tsvFile, line))
        {
            int indexOfFirstTab = line.find_first_of("\t");
            //cout << "index of first tab: " << indexOfFirstTab << endl;

            int indexOfSecondTab = line.find_first_of("\t", indexOfFirstTab + 1);
            //cout << "index of second tab: " << indexOfSecondTab << endl;

            int year = stoi(line.substr(indexOfFirstTab, indexOfSecondTab - indexOfFirstTab));
            //cout << "Year: '" << year << "' \n";

            if (year == 2017) {
                numberOfGamesPublishedIn2017++;
            }
        }
    }
    else
    {
        cout << "Sorry, the file could not be openend." << endl;
    }

    cout << "Number of games published in 2017: " << numberOfGamesPublishedIn2017 << endl;
}

/// <summary>
/// Count the number of games which contain the word "dragon" in their title (case insensitive).
/// </summary>
void problem_4() {
    ifstream tsvFile;
    tsvFile.open("data/video_games.tsv");

    int numberOfGamesWithDragonInName = 0;

    if (tsvFile.is_open())
    {
        string line;
        while (getline(tsvFile, line))
        {
            int indexOfFirstTab = line.find_first_of("\t");
            //cout << "index of first tab: " << indexOfFirstTab << endl;

            string gameFullName = line.substr(0, indexOfFirstTab);

            // .tsv file is already in lower-case, but just incase if any .tsv were to be used that isn't lower case...
            for (char& c : gameFullName) {
                c = std::tolower(c);
            }

            if (gameFullName.find("dragon") != string::npos) {
                numberOfGamesWithDragonInName++;
            }
        }
    }
    else
    {
        cout << "Sorry, the file could not be openend." << endl;
    }

    cout << "# of games with 'dragon' in name: " << numberOfGamesWithDragonInName << endl;
}

int main()
{
    problem_1();

    problem_3();

    problem_4();

    return 0;
}