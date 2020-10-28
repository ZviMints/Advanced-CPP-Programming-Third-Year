/** Created by Zvi Mints on 11/04/2020. */

#include "Editor.h"

void Editor::loop() {
    Editor::Operation op = start;
    do {
        std::string current_line;
        std::cin >> current_line;
        op = parseLine(current_line);
        switch (op) {
            case n:
                document.n_command(std::stoi((current_line.substr(0, current_line.find("n")))));
                break;
            case p:
                document.p_command();
                break;
            case a:
                document.a_command(getTextUntilDot(current_line));
                break;
            case i:
                document.i_command(getTextUntilDot(current_line));
                break;
            case c:
                document.c_command(getTextUntilDot(current_line));
                break;
            case d:
                document.d_command(std::stoi((current_line.substr(0, current_line.find("d")))));
                break;
            case s:
                document.s_command(current_line);
                break;
            case j:
                document.j_command(
                        std::stoi(current_line.substr(0, current_line.find(","))),
                        std::stoi(current_line.substr( current_line.find(",") + 1, current_line.length() - 2)));
                break;
            case f_t:
                document.forward_text_command(current_line.substr(1));
                break;
            case b_t:
                document.backwards_text_command(current_line.substr(1));
                break;
            default:
                if (op != quit)
                    throw "Runtime Exception";
        }
    } while (op != quit);
}

Editor::Operation Editor::parseLine(std::string line) {

    const std::regex jumpRegex("\\d*n"); // Regex for 3n form for example when 3 can be any number
    const std::regex deleteRegex("\\d*d"); // Regex 3d 3n form for example when 3 can be any number
    const std::regex oldNewRegex("s\\/(\\w)*\\/(\\w)*\\/"); // Regex for s/old/new/ when old and new are strings
    const std::regex forwardTextRegex("\\/(\\w)*"); // Regex for forward text look-ahead
    const std::regex beforeTextRegex("\\?(\\w)*"); // Regex for before text look-ahead
    const std::regex concatLines("\\d*,\\d*j"); // Regex for 3,4j when 3,4 can be any number

    if (std::regex_match(line, jumpRegex)) return n;
    else if (line == "%p") return p;
    else if (line == "a") return a;
    else if (line == ".") return dot;
    else if (line == "i") return i;
    else if (line == "c") return c;

    else if (std::regex_match(line, deleteRegex)) return d;
    else if (std::regex_match(line, oldNewRegex)) return s;
    else if (std::regex_match(line, concatLines)) return j;
    else if (std::regex_match(line, forwardTextRegex)) return f_t;
    else if (std::regex_match(line, beforeTextRegex)) return b_t;

    else if (line == "Q") return quit;
    else return text;
}

std::vector <std::string> Editor::getTextUntilDot(std::string startLine) {
    std::vector <std::string> vec;
    std::string currentLine;
    std::cin.ignore();
    std::getline(std::cin, currentLine); // Remove the first blank line and start from text
    while (parseLine(currentLine) != dot) {
        if (parseLine(currentLine) == text) {
            vec.push_back(currentLine);
        }
        std::getline(std::cin, currentLine);
    }
    return vec;
}

