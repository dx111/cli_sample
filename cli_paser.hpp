#include <iostream>
#include "CLI11.hpp"

#include <complex>
#include <cstdint>
#include <regex>
#include <string>
#include <vector>

CLI::Option *
add_option(CLI::App &app, std::string name, std::vector<std::vector<int>> &dims, std::string description = "", bool defaulted = false) {
    CLI::callback_t fun = [&dims](std::vector<std::string> strs) {
        std::regex delim{','};
        for(auto str: strs){
            std::vector<int> dim;
            std::sregex_token_iterator end;
            std::sregex_token_iterator it(str.begin(), str.end(), delim,-1);
            for(; it != end; it++) {
                if(*it=="")continue;
                dim.push_back(std::stoi(*it));
            }
            dims.push_back(dim);
        }
        return true;
    };

    CLI::Option *opt = app.add_option(name, fun, description, defaulted);
    opt->type_name("DIMS")->type_size(1,10);
    return opt;
}
