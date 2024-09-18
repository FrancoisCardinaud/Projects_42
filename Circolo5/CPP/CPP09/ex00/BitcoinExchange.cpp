/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:38 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 19:01:30 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

// Utility functions for string to number conversion
static unsigned int ft_stou(const std::string& str) {
    unsigned int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

float ft_stof(const std::string& str) {
    float num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

// Constructors and destructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->dataBase = other.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Database access
float BitcoinExchange::getRateFromDataBase(const std::string& date) const { // Ensure it matches the header
    std::map<std::string, float>::const_iterator it = this->dataBase.find(date);
    if (it != this->dataBase.end()) {
        return it->second;
    }
    return (--this->dataBase.lower_bound(date))->second;
}

// File reading
void BitcoinExchange::readInternalDataBase(std::ifstream& internal_db) {
    std::string line;
    std::getline(internal_db, line); // Skip first line (header)
    while (std::getline(internal_db, line)) {
        size_t delim = line.find(',');
        std::string date = line.substr(0, delim);
        std::string rate_str = line.substr(delim + 1);
        this->dataBase[date] = ft_stof(rate_str);  // Populate the database
    }
    internal_db.close();
}

// Validation functions
bool BitcoinExchange::isDateInCorrectFormat(const std::string& date) const { // Mark as 'const'
    size_t first_hyphen = date.find('-');
    size_t second_hyphen = date.find('-', first_hyphen + 1);
    if (first_hyphen == std::string::npos || second_hyphen == std::string::npos) {
        std::cerr << "Error: Invalid date format in \"" << date << "\"\n";
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const { // Mark as 'const'
    int year, month, day;
    std::istringstream ss(date);
    std::string token;
    int i = 0;

    while (std::getline(ss, token, '-')) {
        if (i == 0) {
            year = ft_stou(token);
            if (year < 2009 || year > 2022) {
                std::cerr << "Error: Year not in database range in \"" << date << "\"\n";
                return false;
            }
        } else if (i == 1) {
            month = ft_stou(token);
            if (month < 1 || month > 12) {
                std::cerr << "Error: Invalid month in \"" << date << "\"\n";
                return false;
            }
        } else if (i == 2) {
            day = ft_stou(token);
            if (day < 1 || day > 31 || (month == 2 && day > 28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
                std::cerr << "Error: Invalid day in \"" << date << "\"\n";
                return false;
            }
        }
        ++i;
    }
    if (i != 3) {
        std::cerr << "Error: Incorrect date structure in \"" << date << "\"\n";
        return false;
    }
    return true;
}

bool BitcoinExchange::isRateInCorrectFormat(const std::string& rate) const { // Mark as 'const'
    if (rate.empty() || rate.find_first_not_of("0123456789.-") != std::string::npos) {
        std::cerr << "Error: Invalid rate format in \"" << rate << "\"\n";
        return false;
    }
    if (rate[0] == '-') {
        std::cerr << "Error: Rate cannot be negative.\n";
        return false;
    }
    return true;
}
