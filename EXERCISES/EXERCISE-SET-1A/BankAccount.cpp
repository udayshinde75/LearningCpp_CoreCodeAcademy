#include <iostream>

#define SUCCESS 1;
#define FAIL 0;
#define LOWBALANCE 2;

class BankAccount
{
    private:
        double balance;
    private:
        bool isAmountValid(double _amount); 

    public:
        BankAccount();
        double getBalance();

        // Operations
        int deposit(double _amount);
        int withdraw(double _amount);
};

BankAccount::BankAccount() : balance(0) {}

// getters
double BankAccount::getBalance()
{
    return this->balance;
}

// Operations
int BankAccount::deposit(double _amount)
{
    if (isAmountValid(_amount))
    {
        this->balance += _amount;
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}

int BankAccount::withdraw(double _amount)
{
    if (isAmountValid(_amount))
    {
        if (balance > _amount)
        {
            balance -= _amount;
            return SUCCESS
        }
        else
        {
            return LOWBALANCE;
        }
    }
    else
    {
        return FAIL;
    }
}

// Private helper
bool BankAccount::isAmountValid(double _amount)
{
    return _amount >= 1.0;
}

int main(void)
{
    BankAccount Account;

    std::cout << "Account opened successfully : Current balance : " << Account.getBalance() << std::endl;
    int choice, result;
    double amount;
    while (true)
    {
        std::cout << "Please choose action : retrive balance(1), deposit(2), withdraw(3), Exit(4) : ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 1)
        {
            std::cout << "Current account balance is as follows : " << Account.getBalance() << std::endl;
        }
        else if (choice == 2)
        {
            std::cout << "Enter amount to deposit : ";
            std::cin >> amount;
            std::cout << "Current account balance is : " << Account.getBalance() << std::endl;
            std::cout << "Depositing : " << amount << std::endl;
            result = Account.deposit(amount);
            if (result == 1)
            {
                std::cout << "Transaction successfull. Current account balance : " << Account.getBalance() << std::endl;
            }
            else
            {
                std::cout << "Transaction failed. Enter a valid amount. Current account balance : " << Account.getBalance() << std::endl;    
            }
        }
        else if (choice == 3)
        {
            std::cout << "Enter amount to withdraw : ";
            std::cin >> amount;
            std::cout << "Current account balance is : " << Account.getBalance() << std::endl;
            std::cout << "withdrawing : " << amount << std::endl;
            result = Account.withdraw(amount);
            if (result == 1)
            {
                std::cout << "Transaction successfull. Current account balance : " << Account.getBalance() << std::endl;
            }
            else if (result == 2)
            {
                std::cout << "Transaction failed. Account balance is low. Current account balance : " << Account.getBalance() << std::endl;
            }
            else
            {
                std::cout << "Transaction failed. Enter a valid amount. Current account balance : " << Account.getBalance() << std::endl;    
            }
        }
        else if (choice == 4)
        {
            break;
        }
    }
}