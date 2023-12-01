/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:57:01 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/01 16:48:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

class Contact
{
private:
    std::string name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;

public:
    // Getters
    std::string getName() const { return name; }
    std::string getLastName() const { return last_name; }
    std::string getNickname() const { return nickname; }
    std::string getNumber() const { return number; }
    std::string getSecret() const { return secret; }

    // Setters
    void setName(const std::string &newName) { name = newName; }
    void setLastName(const std::string &newLastName) { last_name = newLastName; }
    void setNickname(const std::string &newNickname) { nickname = newNickname; }
    void setNumber(const std::string &newNumber) { number = newNumber; }
    void setSecret(const std::string &newSecret) { secret = newSecret; }
};

class PhoneBook {
private:
    Contact Cont[8];
    int num;
    int oldestIndex; // Index of the oldest contact

public:
    PhoneBook() : num(0), oldestIndex(0) {}

    // Accessor for Contact objects
    Contact& getContact(int index) {
        return Cont[index];
    }

    // Getters and Setters for num and oldestIndex
    int getNum() const { return num; }
    void setNum(int newNum) { num = newNum; }

    int getOldestIndex() const { return oldestIndex; }
    void setOldestIndex(int newIndex) { oldestIndex = newIndex; }
};

#endif