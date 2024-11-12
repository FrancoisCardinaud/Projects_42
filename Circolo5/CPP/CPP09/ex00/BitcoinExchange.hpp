/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:01:09 by fcardina          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <fstream>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void readInternalDataBase(std::ifstream& internal_db);
        float getRateFromDataBase(const std::string& date) const;
        bool isDateInCorrectFormat(const std::string& date) const;
        bool isValidDate(const std::string& date) const;
        bool isRateInCorrectFormat(const std::string& rate) const;

    private:
        std::map<std::string, float> dataBase;
};

#endif
