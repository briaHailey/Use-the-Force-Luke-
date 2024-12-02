/* Name: Bria Weisblat
Date: 12/02/2022
Section: 4
Assignment: Homework 7- Problem 1- Use the Force Luke!
Due Date: 12/02/2022
About this project: This program documents the path of a proton beam by backtracking from the exhaust port backwards
through a room to a spot on the wall that needs to be hit.
Assumptions: Assume that the user will only enter the proper type of data. Assume that The exhaust port will always
be on the west (left) or the north (top) wall, and NEVER at a corner. Assume that the mirrors will always be oriented
as a \or a /. Assume that The walls of the room are represented by the character ‘x’. The exhaust port is represented
by ‘*’. The empty spaces are represented by ‘.'.


All work below was performed by Bria Weisblat */


#include <iostream>
using namespace std;

// Function Declarations
void process (int numRows, int numCols);

int main() {

    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    process (numRows, numCols);

    return 0;
}

// Function Definitions
void process (int numRows, int numCols) {
    int xCoordinate = 0;
    int yCoordinate = 0;
    char direction;

    cout << "Enter the map: " << endl;

    // Creates a dynamic array of pointers
    char **mat = new char *[numRows];

    // Creates individual rows
    for (int i = 0; i < numRows; i++)
        mat[i] = new char[numCols];

    // Reads in the room from the user
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++)
            cin >> mat[i][j];
    }

    // Finds and marks the coordinates of the exhaust port (*)
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++)
            if (mat[i][j] == '*') {
                xCoordinate = i;
                yCoordinate = j;
            }
    }

    // Determine initial direction
    if (xCoordinate == 0)
        direction = 'd';
    else if (yCoordinate == 0)
        direction = 'r';

    // Loop until reaching an x
    while (mat[xCoordinate][yCoordinate] != 'X') {


        bool directionChanged = false;

        // Change direction for left bouncing mirror
        if (mat[xCoordinate][yCoordinate] == '/'){
            if (direction == 'd') {
                direction = 'l';
            }
            else if (direction == 'u') {
                direction = 'r';
            }
            else if (direction == 'r') {
                direction = 'u';
            }
            else if (direction == 'l') {
                direction = 'd';
            }
            directionChanged = true;
        }
        // Change direction for right bouncing mirror
        else if (mat[xCoordinate][yCoordinate] == '\\') {
            if (direction == 'd') {
                direction = 'r';
            } else if (direction == 'u') {
                direction = 'l';
            } else if (direction == 'r') {
                direction = 'd';
            } else if (direction == 'l') {
                direction = 'u';
            }
            directionChanged = true;
        }

        // Move accordingly based on direction
        switch (direction) {
            case 'd':
                xCoordinate++;
                break;
            case 'r':
                yCoordinate++;
                break;
            case 'u':
                xCoordinate--;
                break;
            case 'l':
                yCoordinate--;
                break;
        }


        // Overwrite new position
        if (mat[xCoordinate][yCoordinate] == '.')
            mat[xCoordinate][yCoordinate] = 'o';
    }

    // Overwrite the last X
    if (mat[xCoordinate][yCoordinate] == 'X')
        mat[xCoordinate][yCoordinate] = 'o';



    // Prints the matrix
    cout << "The traced path is: " << endl;
    for (int i=0; i < numRows; i++){
        for (int j=0; j < numCols; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }

    // Prints the entry point
    cout << "The entry point is (" << xCoordinate << "," << yCoordinate << ")";

}

// Room Map Examples
/*

XXXXXXXXXXX
X.........X
X.........X
*../......X
X.........X
XXXXXXXXXXX


XXXX*XXXXXX
X.........X
X.........X
X.........X
X...\...\.X
XXXXXXXXXXX


XXXXX
*...X
X...X
X...X
XXXXX


 */
