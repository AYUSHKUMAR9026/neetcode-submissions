class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, int> m;

        // Row check
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                int x = board[i][j] - '0';

                if (m[x]) {
                    return false;
                }

                m[x]++;
            }

            m.clear();

            // Column check
            for (int j = 0; j < 9; j++) {

                if (board[j][i] == '.')
                    continue;

                int x = board[j][i] - '0';

                if (m[x]) {
                    return false;
                }

                m[x]++;
            }

            m.clear();
        }

        // 3 x 3 box check
        for (int row = 0; row < 9; row += 3) {

            for (int col = 0; col < 9; col += 3) {

                m.clear();

                // Check one 3 x 3 box
                for (int i = row; i < row + 3; i++) {

                    for (int j = col; j < col + 3; j++) {

                        if (board[i][j] == '.')
                            continue;

                        int x = board[i][j] - '0';

                        if (m[x]) {
                            return false;
                        }

                        m[x]++;
                    }
                }
            }
        }

        return true;
    }
};