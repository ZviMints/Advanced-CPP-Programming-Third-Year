/** Created by Zvi Mints on 11/04/2020. */
#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"
#include <iostream>
#include <vector>
#include <regex>

class Editor {
private:
    enum Operation { start, n, p, a, dot, i, c, d, f_t, b_t, s, j, quit, text };
    Document document;
public:
    void loop();

    Operation parseLine(std::string line);

    std::vector <std::string> getTextUntilDot(std::string startLine);
};


#endif
