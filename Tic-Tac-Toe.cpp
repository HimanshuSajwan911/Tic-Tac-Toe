#include<iostream>
#include<string>
using namespace std;

void showGrid(char grid[3][3]){ // Function to print grid.

    cout<<"\n";
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            cout << grid[i][j] << " ";
        }
        cout<<"\n";
    }

}

int checkGameStatus(char grid[3][3], int CurrentPlayer){ // Function to check for winner.

    for(int i = 0; i < 3; i++){

        if( ( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '.' ) || // Checking in row.
            ( grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '.' ) ){ // Checking in column.

            return CurrentPlayer; // Winner is current player.

        }
    }

    // Diagonal checking.
    if( ( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '.' ) || // Checking in major diagonal.
        ( grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != '.' ) ){ // Checking in minor diagonal

        return CurrentPlayer; // Winner is current player.

    }

    return 0; // no current winner.

}

int main(){

    //Main Loop.
    while(1){

        string playerX = "", playerO = "", FirstPlayer = "";
        int CurrentPlayer = 0, winner = 0;
        int row = 0, col = 0, GameStaus = 1, Play = 0;
        char grid[3][3]={'.','.','.','.','.','.','.','.','.'}; //2D char array to make grid.

        cout << "Enter a name for the X player: \n";
        cin >> playerX;

        cout << "Enter a name for the O player: \n";
        cin >> playerO;

        //First_Turn Loop.
        /*
            this loop will continue to run until a valid first player is named.
        */
        while(1){

            cout << "Who plays first, " << playerX << " or " << playerO << "?\n";
            cin >> FirstPlayer;
            if( FirstPlayer == playerX ){
                CurrentPlayer = 1;
                break; // First player selected.
            }
            else if( FirstPlayer == playerO ){
                CurrentPlayer = 2;
                break; // First player selected.
            }
            else{
                cout << FirstPlayer << " is not a registered player.\n";
                // Retrying to select first player.
            }

        }//End of First_Turn Loop.

        //Game Loop.
        /*
            this loop will continue to run until a player wins or
            all the cells are filled(tie).
        */
        while(1){

            showGrid(grid); // Printing current grid status.
            if(CurrentPlayer == 1){
                cout << "Player of current turn: " << playerX << "\n";
            }
            else{
                cout << "Player of current turn: " << playerO << "\n";
            }

            //Valid_Cell Loop.
            /*
                this loop will continue to run until valid cell(valid row and valid column) is selected.
            */
            while(1){

                cout << "Choose a row number (0 to 2):\n";
                cin >> row;
                if(row < 0 || row > 2){
                    cout << row << " is not a valid row.\n";
                    continue; // Invalid row position.
                }

                cout << "Choose a column number (0 to 2):\n";
                cin >> col;

                if(col < 0 || col > 2){
                    cout << col << " is not a valid column.\n";
                    continue; // Invalid column position.
                }

                if( grid[row][col] == '.' ){ // checking if cell is empty.

                    if( CurrentPlayer == 1 ){
                        grid[row][col] = 'X';
                        CurrentPlayer = 2;
                    }
                    else{
                        grid[row][col] = 'O';
                        CurrentPlayer = 1;
                    }
                    break;

                }
                else{
                    cout << "Slot is already taken.\n";
                    continue; // this cell position is already taken.
                }

            }//End of Valid_Cell Loop.

            winner = checkGameStatus(grid, CurrentPlayer);

            if( winner == 1 ){ // Player 1 wins.

                cout << "\nGame is over: \n" << playerO << " wins!\n";
                break;
            }
            else if( winner == 2 ){ // Player 2 wins.

                cout << "\nGame is over: \n" << playerX << " wins!\n";
                break;
            }
            if( GameStaus++ >= 9 ){ // All the cells are filled and there is no winner.

                cout<<"Game is over: \nit is a tie!";
                break;
            }

        }//End of Game Loop.

        showGrid(grid); // Printing final grid status.

        //Replay Loop.
        while(1){

            string again = "";
            cout << "\nWould you like to play again? (Y/N)\n";
            cin >> again;
            if( again == "y" || again == "Y" ){
                Play = 1;
                break;
            }
            else if( again == "n" || again == "N" ){
                cout << "Bye!";
                Play = 0;
                break;
            }
            else{
                cout << again << " is not a valid answer.";
            }

        }//End of Replay Loop.

        if( ! Play ){ //exit.
            break;
        }

    }//End of Main Loop.

    return 0; //End of main function.
}
