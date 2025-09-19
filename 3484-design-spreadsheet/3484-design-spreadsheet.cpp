#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    // Parse "A12" → {row, col}
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A';              // 'A'→0, 'Z'→25
        int row = stoi(cell.substr(1)) - 1;   // convert to 0-indexed
        return {row, col};
    }

    // Operand can be a number or a cell reference
    int getOperand(const string &op) {
        if (isdigit(op[0])) {
            return stoi(op);
        } else {
            auto [r, c] = parseCell(op);
            if (r < 0 || r >= rows || c < 0 || c >= 26) return 0;
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0)); // initialize with 0
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        // Format: "=X+Y"
        if (!formula.empty() && formula[0] == '=')
            formula = formula.substr(1);
        
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        return getOperand(left) + getOperand(right);
    }
};

/**
 * Example usage:
 * Spreadsheet* obj = new Spreadsheet(10);
 * obj->setCell("A1", 5);
 * obj->setCell("B2", 10);
 * cout << obj->getValue("=A1+B2"); // 15
 * obj->resetCell("A1");
 * cout << obj->getValue("=A1+B2"); // 10
 */