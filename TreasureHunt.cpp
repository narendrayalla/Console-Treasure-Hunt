#include <iostream>
#include <vector>
#include <cstring> // For memcpy

using namespace std;

char map[18][32] = {
    "+#############################+",
    "|                             |",
    "|                             |",
    "|## ########### ##   #########|",
    "|   |                         |",
    "| | |### |  |           |     |",
    "| |      |  | |###  |   |  |  |",
    "| | #####|  | |      ## |     |",
    "| |           |###  |      |  |",
    "| |##### ###         ##       |",
    "|          ######  ####### ###|",
    "|                             |",
    "|# ### ####      ###   #######|",
    "|                             |",
    "|                             |",
    "|                             |",
    "|                             |",
    "+############################+#"};

void ShowMap(int playerX, int playerY)
{
    // Create a temporary map to display the player's position
    char displayMap[18][32];
    memcpy(displayMap, map, sizeof(displayMap)); // Copy the original map

    // Place the player 'H' on the temporary map
    displayMap[playerY][playerX] = 'P';
    // Mark the treasure location
    displayMap[1][10] = 'T';

    // Print the temporary map with the player's position
    for (int i = 0; i < 18; i++)
    {
        printf("%s\n", displayMap[i]);
    }
}

int main()
{
    bool running = true;
    int x = 15; // hero x
    int y = 16; // hero y

    // Show initial map with player position
    ShowMap(x, y);

    while (running)
    {
        char move;
        cout << "Enter your move (w/a/s/d for up/left/down/right): ";
        cin >> move;

        switch (move)
        {
            case 'w': // Up
                if (map[y - 1][x] == ' ')
                    y--;
                break;
            case 's': // Down
                if (map[y + 1][x] == ' ')
                    y++;
                break;
            case 'a': // Left
                if (map[y][x - 1] == ' ')
                    x--;
                break;
            case 'd': // Right
                if (map[y][x + 1] == ' ')
                    x++;
                break;
            default:
                cout << "Invalid move! Use w/a/s/d to move.\n";
                continue; // Skip showing position for invalid moves
        }

        // Clear the screen (basic way in console; won't work on all systems)
        system("clear"); // Use "cls" on Windows

        // Show the updated map with the new player position
        ShowMap(x, y);

        // Check if player has reached the treasure
        if (x == 10 && y == 1) {
            cout << "Congratulations! You've found the treasure! Game Over.\n";
            running = false; // End the game
        }
    }

    return 0;
}

