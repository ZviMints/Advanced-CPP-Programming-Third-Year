/** Created by Zvi Mints on 11/04/2020. */

#include "Document.h"

void Document::n_command(int newPos) {
    _pos = newPos - 1;
    std::cout << newPos << "\t" << _lines[_pos] << std::endl;
}

void Document::p_command() { // [V]
    for (int i = 0; i < _lines.size(); i++)
        std::cout << _lines[i] << std::endl;
    _pos = _lines.size();
}

void Document::a_command(std::vector <std::string> newLines) {
    for (int i = 0; i < newLines.size(); i++) {
        _lines.insert(_lines.begin() + _pos + 1, newLines[i]);
        _pos++;
    }
}


void Document::i_command(std::vector <std::string> newLines) {
    for (int i = 0; i < newLines.size(); i++) {
        _lines.insert(_lines.begin() + _pos, newLines[i]);
        _pos++;
    }
}

void Document::c_command(std::vector <std::string> newLines) {
    _lines.erase(_lines.begin() + _pos);
    _pos--;
    a_command(newLines);
}


void Document::d_command(int deletePos) {
    _lines.erase(_lines.begin() + deletePos - 1);
    _pos = deletePos - 1;
}

void Document::forward_text_command(std::string key) {
    for (int i = _pos; i < _lines.size(); i++) {
        if (_lines[i].find(key) != std::string::npos) {
            std::cout << _lines[i] << std::endl;  // There Error In The Task!
            _pos = i;
            return;
        }
    }
    _pos = _lines.size() - 1;
}

void Document::backwards_text_command(std::string key) {
    // log("----- In b_t");
    for (int i = _pos; i >= 0; i--) {
        if (_lines[i].find(key) != std::string::npos) {
            std::cout << _lines[i] << std::endl;  // There Error In The Task!
            _pos = i;
            return;
        }
    }
    _pos = -1;
}


void Document::j_command(int i, int j) {
    _lines[i - 1] += _lines[j - 1];
    _pos = i - 1;
    _lines.erase(_lines.begin() + (j - 1));
}


//  Method for Split with delimiter
std::vector <std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector <std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void Document::s_command(std::string command_line) {
    std::string delimiter = "/";
    std::vector <std::string> splitted = split(command_line, delimiter);
    _lines[_pos].replace(_lines[_pos].find(splitted[1]), sizeof(splitted[1]) - 1, splitted[2]);

}