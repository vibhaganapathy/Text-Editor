#include "TextBuffer.hpp"


// Empty text buffer
TextBuffer::TextBuffer()
    : cursor(data.end()), row(1), column(0), index(0)
{}

// Forward
bool TextBuffer::forward(){
    if (is_at_end()){
        return false;
    }

    // Check line
    if (*cursor == '\n'){
        column = 0;
        row++;
    }
    column++;
    index++;
    cursor++;

    return true;
}

// Backward
bool TextBuffer::backward(){
    if (cursor == data.begin()){
        return false;
    }

    index--;
    cursor--;

    // Check line
    if (*cursor == '\n'){
        column = compute_column();
        row--;
    }
    else{
        column--;
    }

    return true;
}

// Insert
void TextBuffer::insert(char c){
    data.insert(cursor, c);
    index++;

    // Check line
    if (c == '\n'){
        row++;
        column = 0;
    }
    else{
        column++;
    }
}

// Remove
bool TextBuffer::remove(){
    if (is_at_end()){
        return false;
    }

    cursor = data.erase(cursor);
    return true;
}

// Move to row start
void TextBuffer::move_to_row_start(){
    while (column > 0){
        backward();
    }
}

// Move to row end
void TextBuffer::move_to_row_end(){
    while ((!is_at_end()) && (*cursor != '\n')){
        forward();
    }
}

// Move to column
void TextBuffer::move_to_column(int new_column){
    if (new_column < column){
        while (column > new_column){
            backward();
        }
    }            
    while ((!is_at_end())&& (*cursor != '\n') && (column < new_column)){
        forward();
    }
}

// Up
bool TextBuffer::up(){
    if (row == 1){
        return false;
    }

    int prevCol = column;
    move_to_row_start();
    move_to_row_end();
    move_to_column(prevCol);

    return true;
}

// Down
bool TextBuffer::down(){
    int prevCol = column;
    move_to_row_end();

    if (is_at_end()){
        move_to_column(prevCol);
        return false;
    }

    forward();
    move_to_column(prevCol); 
    return true;
}

// Is at end
bool TextBuffer::is_at_end() const{
    return (cursor == data.end());
}

// Data at cursor
char TextBuffer::data_at_cursor() const{
    return *cursor;
}

// Get row
int TextBuffer::get_row() const{
    return row;
}

// Get col
int TextBuffer::get_column() const{
    return column;
}

// Get index
int TextBuffer::get_index() const{
    return index;
}

// Get size
int TextBuffer::size() const{
    return int(data.size());
}

// Stringify
std::string TextBuffer::stringify() const{
    return std::string(data.begin(), data.end());
}

// Compute column