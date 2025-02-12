#include "commandParser.hpp"
#include <sstream>
#include <algorithm>

Command CommandParser::parse(const std::string& message) {
    std::string mutableMessage = message;
    std::string prefix = extractPrefix(mutableMessage);
    std::string command = extractCommand(mutableMessage);
    std::vector<std::string> parameters = extractParameters(mutableMessage);

    return Command(prefix, command, parameters);
}

std::string CommandParser::extractPrefix(std::string& message) {
    std::string prefix;
    if (message[0] == ':') {
        size_t spacePos = message.find(' ');
        if (spacePos != std::string::npos) {
            prefix = message.substr(1, spacePos - 1);
            message = message.substr(spacePos + 1);
        }
    }
    return prefix;
}

std::string CommandParser::extractCommand(std::string& message) {
    std::string command;
    size_t spacePos = message.find(' ');
    if (spacePos != std::string::npos) {
        command = message.substr(0, spacePos);
        message = message.substr(spacePos + 1);
    } else {
        command = message;
        message.clear();
    }
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    return command;
}

std::vector<std::string> CommandParser::extractParameters(std::string& message) {
    std::vector<std::string> parameters;
    std::string param;
    std::istringstream iss(message);

    while (iss >> param) {
        if (param[0] == ':') {
            std::string trailing;
            std::getline(iss, trailing);
            parameters.push_back(param.substr(1) + trailing);
            break;
        }
        parameters.push_back(param);
    }

    return parameters;
}