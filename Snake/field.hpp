#ifndef FIELD_H
#define FIELD_H

class Field {
    int rows;
    int cols;
    int** F;
public:
    Field(int _rows, int _cols);
    void setval(int row, int col, int val);
    void output();
    int check(int headrow, int headcol);
};

#endif // FIELD_H