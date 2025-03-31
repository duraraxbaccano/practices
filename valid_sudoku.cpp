class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++)
        {
            std::map<char, bool> existed;
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.')
                    continue;
                else if (!existed[board[row][col]])
                    existed[board[row][col]] = true;
                else
                    return false;
            }
        }

            for (int col = 0; col < board[0].size(); col++)
            {
                std::map<char, bool> existed;
                for (int row = 0; row < board.size(); row++)
                {
                    if (board[row][col] == '.')
                        continue;
                    else if (!existed[board[row][col]])
                        existed[board[row][col]] = true;
                    else
                        return false;
                }
            }
        
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                std::map<char, bool> existed;
                for (int rIndex = 0; rIndex < 3; rIndex++)
                {
                    for (int cIndex = 0; cIndex < 3; cIndex++)
                    {
                        if (board[row * 3 + rIndex][col * 3 + cIndex] == '.')
                            continue;
                        else if (!existed[board[row * 3 + rIndex][col * 3 + cIndex]])
                            existed[board[row * 3 + rIndex][col * 3 + cIndex]] = true;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};