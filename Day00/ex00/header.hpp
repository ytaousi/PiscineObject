#ifndef HEADER_HPP
#define HEADER_HPP
#include <vector>
#include <ostream>
#include <iostream>

class Bank
{
    private:
        double _liquidity;
        static int _counter;
        struct Account
        {
            int _id;
            double _value;
            double _loan;

            Account(int id) : _id(id), _value(0), _loan(0) {};
            Account &operator=(const Account &acc);
            Account(int id, const Account &acc) : _id(id), _value(acc._value), _loan(acc._loan) {};
            ~Account() {};

            // Getters
            int getId() const { return this->_id; }
            double getValue() const { return this->_value; }
            double getLoan() const { return this->_loan; }
        };
        std::vector<Account *> _clientAccounts;
        

    public:
        Bank() : _liquidity(0) {};
        Bank(double amount) : _liquidity(amount) {};
        Bank(const Account &acc)
        {
            this->_clientAccounts.push_back(new Account(this->_counter++, acc));
        }
        
        ~Bank()
        {
            for (size_t i = 0; i < this->_clientAccounts.size(); i++)
            {
                delete this->_clientAccounts[i];
            }
            this->_clientAccounts.clear();
        }

        Account* operator[](int id)
        {
            try
            {
                if ((size_t)id >= this->_clientAccounts.size())
                    throw std::string("Account not found");
                return this->_clientAccounts[id];
            }
            catch (std::string e)
            {
                std::cout << e << std::endl;
            }
            return NULL;
        }
        Account* operator[](int id) const
        {
            try {
                if ((size_t)id > this->_clientAccounts.size())
                    throw std::string("Account not found");
                return this->_clientAccounts[id];
            }
            catch (std::string e)
            {
                std::cout << e << std::endl;
            }
            return NULL;
        }
        Bank& operator=(const Bank &bank);

        double getLiquidity() const
        {
            return this->_liquidity;
        }
        double getLiquidity()
        {
            return this->_liquidity;
        }
        std::vector<Account *> getClientAccounts() const
        {
            return this->_clientAccounts;
        }
        std::vector<Account *> getClientAccounts()
        {
            return this->_clientAccounts;
        }

        void setLiquidity(double amount)
        {
            this->_liquidity = amount;
        }

        void createAccount()
        {
            Bank::Account *acc = new Bank::Account(this->_counter++);
            this->_clientAccounts.push_back(acc);
        }
        void delAccount(Account &acc)
        {
            Bank::Account *account = Bank::operator[](acc.getId());
            if (account == NULL) {
                return ;
            }
            this->_clientAccounts.erase(this->_clientAccounts.begin() + acc.getId());
            for (size_t i = acc.getId(); i < this->_clientAccounts.size(); i++) {
                this->_clientAccounts[i]->_id--;
            }
            Bank::_counter--;
        }
        void delAccount(int id)
        {
            Bank::Account *acc = Bank::operator[](id);
            if (acc == NULL) {
                return ;
            }
            delete acc;
            this->_clientAccounts.erase(this->_clientAccounts.begin() + id);
            for (size_t i = id; i < this->_clientAccounts.size(); i++) {
                this->_clientAccounts[i]->_id--;
            }
            Bank::_counter--;
        }
        void addMoney(double amount, Account &acc) {
            try {
                this->_clientAccounts[acc.getId()]->_value += amount;
                double inflow = (amount / 100) * 5;
                amount -= inflow;
                this->_liquidity += inflow;
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        void addMoney(double amount, int id) {
            try {
                this->_clientAccounts[id]->_value += amount;
                double inflow = (amount / 100) * 5;
                amount -= inflow;
                this->_liquidity += inflow;
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        void takeMoney(double amount, Account &acc)
        {
            try {
                Bank::Account *account = this->_clientAccounts[acc.getId()];
                if (account->_value >= amount) {
                    account->_value -= amount;
                    this->_liquidity += amount;
                } else {
                    throw std::string("Not enough money");
                }
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        void takeMoney(double amount, int id)
        {
            try {
                Bank::Account *account = this->_clientAccounts[id];
                if (account->_value >= amount) {
                    account->_value -= amount;
                    this->_liquidity += amount;
                } else {
                    throw std::string("Not enough money");
                }
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }

        void withdraw(double amount)
        {
            try {
                if (this->_liquidity < amount)
                    throw std::string("Not enough liquidity");
                this->_liquidity -= amount;
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        void deposit(double amount)
        {
            this->_liquidity += amount;
        }
        void giveLoan(double amount, Account &acc)
        {
            try {
                if (this->_liquidity >= amount) {
                    this->_liquidity -= amount;
                    this->_clientAccounts[acc.getId()]->_loan += amount;
                } else {
                    throw std::string("Not enough liquidity");
                }
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        void giveLoan(double amount, int id) {
            try {
                if (this->_liquidity >= amount) {
                    this->_liquidity -= amount;
                    this->_clientAccounts[id]->_loan += amount;
                } else {
                    throw std::string("Not enough liquidity");
                }
            } catch (std::string e) {
                std::cout << e << std::endl;
            }
        }
        
        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
        {
            p_os << "Bank informations : " << std::endl;
            p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
            std::vector<Bank::Account *> acc = p_bank.getClientAccounts();
            std::vector<Bank::Account *>::iterator it = acc.begin();
            for (; it != acc.end(); it++) {
                p_os << *it << std::endl;
            }
	        return (p_os);
        }
        friend std::ostream& operator << (std::ostream& p_os, const Account* p_account)
        {
            p_os << "Account Id : " << p_account->getId() << std::endl;
            p_os << "Value : " << p_account->getValue() << std::endl;
            p_os << "Loan : " << p_account->getLoan() << std::endl;
            return (p_os);
        }
};

#endif