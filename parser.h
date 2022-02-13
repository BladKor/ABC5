#pragma once

#include <string>
#include <utility>

struct Parser {
    static std::pair<bool, size_t> validCheckParser(const std::string &rowData) {
        if (rowData.empty() || rowData.size() > 2) {
            return std::make_pair(false, 0);
        }
        for (const char &item: rowData) {
            if (!('0' <= item && item <= '9')) {
                return std::make_pair(false, 0);
            }
        }
        return std::make_pair(true, std::stoul(rowData));
    }
};