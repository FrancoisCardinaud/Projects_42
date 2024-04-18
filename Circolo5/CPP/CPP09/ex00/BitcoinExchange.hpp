/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:30:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:30:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& to_copy);
        BitcoinExchange& operator=(const BitcoinExchange& to_copy);
        ~BitcoinExchange(void);

        void readInternalDataBase(std::ifstream& internal_db);

        float getRateFromDataBase(const std::string& date);

        bool isDateInCorrectFormat(const std::string &date);
        bool isValidDate(const std::string& date);
        bool isRateInCorrectFormat(const std::string& rate);

    private:
        std::map<std::string, float> dataBase;
};

#endif // BITCOINEXCHANGE_HPP