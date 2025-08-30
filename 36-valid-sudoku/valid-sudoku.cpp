class Solution {
public:

    // Function to check that the number placed there is valid or not
    bool ifValid(vector<vector<char>>& board, int r, int c, char ch){
        // Check for the same row
        for(int i=0;i<9;i++){
            if(board[r][i]==ch){
                return false;
            }
        }
        
        // Check for the same coloumn
        for(int i=0;i<9;i++){
            if(board[i][c]==ch){
                return false;
            }
        }
        
        // Check in the same grid(3*3)
        int rr = r-(r%3);
        int cc = c-(c%3);
        for(int i=rr;i<(rr+3);i++){
            for(int j=cc;j<(cc+3);j++){
                if(board[i][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    
    // The recursive helper function
    bool isValidSudokuHelper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                // If the cell is filled
                if(board[i][j]!='.'){
                    
                    // Store the value in ch, and empty the cell
                    char ch = board[i][j];
                    board[i][j]='.';
                    
                    // Check if it is valid
                    if(!ifValid(board, i, j, ch)) return false;
                   
                   // If valid, store the value back
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidSudokuHelper(board);
    }
};