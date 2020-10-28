/** Created by Zvi Mints on 11/04/2020. */

#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <vector>
#include <string>

class Document {
private:
    std::vector<std::string> _lines;
    int _pos;
public:
    Document(): _pos{-1} {}
    void n_command(int newPos); // goes to [[newPos]] line, prints [[newPos]], prints TAB and prints the [[newPos]] line
    void p_command(); // prints all lines until current position
    void a_command(std::vector<std::string> newLines); // insert newLines after the current line
    void i_command(std::vector<std::string> newLines); // insert newLines before the current line
    void c_command(std::vector<std::string> newLines); // change the current line with  newLine

    void d_command(int deletePos); // goes to [[deletePos]], delete the line and position _pos to next line
    void forward_text_command(std::string key); // search forward the first "key" string, and then goes to the "key" string position, otherwise, go to the last row
    void backwards_text_command(std::string key); // search backwards the first "key" string, and then goes to the "key" string position, otherwise, go to the first row
    void s_command(std::string command_line); // replace first _old string in _new string which appear in command_line, in the current position
    void j_command(int i, int j); // concat i and j lines to one line, and set the position to i and the total number of lines is dec by 1
};


#endif
