#include <iostream>

class Book
{
private:
    std::string title;
    std::string author;
    int pages;
public:
    Book(const std::string& _title, const std::string& _author, int pages);
    ~Book() = default;

    void setTitle(const std::string& _title);
    std::string getTitle() const;
    void setAuthor(const std::string& _author);
    std::string getAuthor() const;
    void setPages(int _pages);
    int getPages() const;
};

Book::Book(const std::string& _title, const std::string& _author, int _pages)
    : title(_title), author(_author), pages(_pages)
{
}

void Book::setTitle(const std::string& _title)
{
    this->title = _title;
}
std::string Book::getTitle() const
{
    return this->title;
}
void Book::setAuthor(const std::string& _author)
{
    this->author = _author;
}
std::string Book::getAuthor() const
{
    return this->author;
}
void Book::setPages(int _pages)
{
    this->pages = _pages;
}
int Book::getPages() const
{
    return this->pages;
}