// Singleton pattern basics

#include <iostream>
class DatabaseConnection
{
    private:
        bool connected;
        static DatabaseConnection* instance;
        DatabaseConnection();
        ~DatabaseConnection();
        DatabaseConnection(const DatabaseConnection& other) = delete;
        DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    public:
        static DatabaseConnection* getInstance();
        static void destroyInstance();
        bool connect();
        bool isConnected();
};

DatabaseConnection* DatabaseConnection::instance = nullptr;

DatabaseConnection::DatabaseConnection() : connected(false) {}

DatabaseConnection* DatabaseConnection::getInstance()
{
    if (instance == nullptr)
    {
        instance = new DatabaseConnection();
    }
    return instance;
}

void DatabaseConnection::destroyInstance()
{
    delete instance;
    instance = nullptr;
}

bool DatabaseConnection::connect()
{
    connected = true;
    return connected;
}

bool DatabaseConnection::isConnected()
{
    return connected;
}

int main()
{
    DatabaseConnection* DBInstance = DatabaseConnection::getInstance();

    std::cout << "Created DBInstance : Address : " << DBInstance << std::endl;

    std::cout << "trying to create another instance" << std::endl;

    DatabaseConnection* DBInstance2 = DatabaseConnection::getInstance();

    std::cout << "Created DBInstance2 : Address : " << DBInstance2 << std::endl;
}


/*
Superior example 
class DatabaseConnection
{
private:
    bool connected;

    DatabaseConnection() : connected(false) {}

    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

public:
    static DatabaseConnection& getInstance()
    {
        static DatabaseConnection instance;
        return instance;
    }

    bool connect()
    {
        connected = true;
        return connected;
    }

    bool isConnected()
    {
        return connected;
    }
};
*/