//Diane Ngo
//ENPM809Y
//RWA 2
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define ROWS 6 ///< Number of Rows for the Maze
#define COLS 8 ///< Number of Columns for the Maze
/**
 * CheckWall Function:
 * Function to check if there is a wall in the desired direction
 * @param maze the 2D array of character for the maze
 * @param x integer of the x coordinate
 * @param y integer of the y coordinate
 * @return
 */
bool CheckWall(char maze[6][8], int& x, int& y){
    cout << "Checking wall" << endl;
    if (maze[y][x] == '#'){
        //cout << "->Position is at a wall." << endl;
        return true;
    }
    else {
        //cout << "->No wall." << endl;
        return false;
    }
};
/**
 * CheckOutside Function:
 * Function to check if the desired direction is outside of the maze
 * @param maze the 2D array of character for the maze
 * @param x integer of the x coordinate
 * @param y integer of the y coordinate
 * @return
 */
bool CheckOutside(int& x, int& y){
    cout << "Checking if outside the maze" << endl;
   if ((x > COLS || x < 0 ) || (y > ROWS || y < 0)){
       //cout << "->Point is outside. " << endl;
       return true;
   }
   else {
       //cout << "->Point is not outside. " << endl;
       return false;
    }
};
/**
 * Function to backtrack if the coordinate has been visited
 * and there is no path found
 * @param maze the 2D array of character for the maze
 * @param x integer of the x coordinate
 * @param y integer of the y coordinate
 * @return
 */
bool BackTrack(char maze[6][8], int& x, int& y){
    cout << "Backtrack if already visited and no path found" << endl;
    if (maze[y][x] == '+') {
        //cout << "->Need to backtrack" << endl;
        return true;
    }
    else {
        //cout << "->No need to backtrack" << endl;
        return false;
    }

};

/**
 * Function to display the maze
 * @param maze the 2d array of characters for the maze
 */
void display_maze(char maze[6][8]) {
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << " " << endl;
    }
};
/**
 * FindPath Function is a recursive function to iterate through the maze
 * by checking North, East, South, and West. It checks if there is a wall at the position or if
 * its outside of the maze, then proceeds by placing a + sign at the position and updates.
 * @param maze the 2D array of character for the maze
 * @param x integer of the x coordinate
 * @param y integer of the y coordinate
 * @return
 */
bool FindPath(char maze[6][8], int x, int y){
    if (maze[y][x] == 'G') { //! If the x, y is at the goal position
        cout << "Reached the goal!" << endl;
        return true;
    }
    //! If the coordinates is not at the goal position
    cout << "Not at goal." << endl;
    bool outside = CheckOutside(x, y); //! Declare outside variable
    bool wall = CheckWall(maze, x, y); //! Declare wall variable
    bool backtrack = BackTrack(maze, x, y); //! Declare backtrack variable
    //! If x, y is outside of the maze or is a wall
    if (outside || wall || backtrack) {
        return false;
    }
    maze[y][x] = '+'; //!Mark path

    //! Checking North
    cout << "---Checking north." << endl;
    if (FindPath(maze, x, y + 1) == true)
        return true;

    //! Checking East
    cout << "---Checking east."  << endl;
    if (FindPath(maze, x + 1, y) == true){
        return true;
    }

    //! Checking South
    cout << "---Checking south." << endl;
    if (FindPath(maze, x, y - 1) == true)
        return true;

    //! Checking West
    cout << "---Checking west." << endl;
    if( FindPath(maze, x - 1, y) == true)
        return true;

    cout << "No path found" << endl;

    display_maze(maze);
    //! Backtrack by setting the coordinate back to .
    maze[y][x] = '.';
    return false;
}

int main() {
    //!Maze array is reversed to print it out with respect to the coordinate system
    char maze[6][8] ={{'#' , '.', '.', '.', '#' , '#' , '.', '#' },
                      {'.', '.', '#' , '.', '.', '#' , '.', '.'},
                      {'#' , '.', '#' , '#', '.', '#' , '.', '#'},
                      {'#' , '.', '#' , '.' , '.', '#' , '.', '.' },
                      {'#' , '.',  '.', '#' , '.', '.', '.', '#' },
                      { '#' , '#', '#', '#', '#', '#', '#', '#'}};
    cout << "This is the maze." << endl;
    display_maze(maze);
    //! Initialize the variables for the starting position
    int s_x = 0;
    int s_y = 0;
    //!Initialize temporary variables s_x and s_y to save the new input
    int temp_s_x = 0;
    int temp_s_y = 0;
    cout << "Enter your desired starting position: " << endl;
    //! User Input
    cin >> s_x;
    cin >> s_y;
    /**
     * While Loop to determine if start and goal position
     * are inside of the maze and not a wall
     */
    while((maze[s_y][s_x] == '#') || (s_x > ROWS) || (s_y > COLS)){
        if (maze[s_y][s_x] == '#') {
            cout << "Invalid starting position - that is a wall." << endl;
            cout << "Please enter your desired starting position: " << endl;
            cin >> temp_s_x >> temp_s_y;
            s_x = temp_s_x;
            s_y = temp_s_y;
            maze[s_y][s_x] = maze[temp_s_y][temp_s_x];
        }
        /**
         * This if loop checks if the desired starting position
         * is outside of the maze.
         */
        if ((s_x > ROWS) ||(s_x < 0) || (s_y > COLS) || (s_y <0)){
            cout << "The starting position cannot be outside of the maze." << endl;
            cout << "Please enter your desired starting position: " << endl;
            cin >> temp_s_x;
            cin >> temp_s_y;
            s_x = temp_s_x;
            s_y = temp_s_y;
            maze[s_y][s_x] = maze[temp_s_y][temp_s_x];
        }
    }
         int s[] = {s_x, s_y}; //! set the s array to coordinates x, y
         cout << "Starting position is: {" << s[0] << ", " << s[1]  << "}." << endl;
         maze[s_y][s_x] = 'S'; // had to swap y and x position because how C++ reads columns first
         temp_s_x = temp_s_y = 0;

         // Initialize the variables for the goal position
         int g_x = 0;
         int g_y = 0;
         cout << "Enter your desired goal position: " << endl;
         cin >> g_x >> g_y;
         //!Initialize temporary variables g_x and g_y to save the new input
         int temp_g_x = 0;
         int temp_g_y = 0;
         while((maze[g_y][g_x] == '#')|| (g_x > ROWS) || (g_y > COLS)){
             if (maze[g_y][g_x]){
                 cout << "Coordinate contains: " << maze[g_y][g_x] << endl;
                 cout << "Invalid starting position - that is a wall." << endl;
                 cout << "Please enter your desired starting position: " << endl;
                 cin >> temp_g_x >> temp_g_y;
                 g_x = temp_g_x;
                 g_y = temp_g_y;
                 maze[g_y][g_x] = maze[temp_g_y][temp_g_x];
             }
             /**
              * This if loop checks if the desired goal position
              * is outside of the maze.
              */
             if ((g_x > ROWS) || (g_x <0) || (g_y > COLS || g_y < 0)){
                 cout << "The goal position cannot be outside of the maze." << endl;
                 cout << "Please enter your desired goal position: " << endl;
                 cin >> temp_g_x;
                 cin >> temp_g_y;
                 g_x = temp_g_x;
                 g_y = temp_g_y;
                 maze[g_y][g_x] = maze[temp_g_y][temp_g_x];
             }
        }
    int g[] = {g_x, g_y}; //! set the g array to coordinates x, y
    cout << "Goal position is: {" << g[0] << ", " << g[1]  << "}." << endl;
    temp_g_x = temp_g_y = 0;
    maze[g_y][g_x] = 'G'; // had to swap y and x position because how C++ reads columns first
    display_maze(maze);
    cout << "Start x: " << s_x << " Start y: " <<  s_y << endl;
    //maze[s_y][s_x] = '+';
    FindPath(maze, s_x, s_y);

    maze[s_y][s_x] = 'S';
    cout << "The Final Maze" << endl;
    display_maze(maze);
    return 0;
}
