#pragma once

#include <fstream>
#include <string>
#include <functional>

#include "parser.h"

struct Reader {
    static size_t reader(const std::string& rowFile) {
        std::ifstream stream;
        try {
            stream.open(rowFile, std::ios::in);
        } catch (std::exception& ex) {
            std::cout << ex.what();
            return 0;
        }
        std::string row;
        getline(stream, row);
        auto response = Parser::validCheckParser(row);
        if (!response.first) {
            return 0;
        }
        return response.second;
    }
};