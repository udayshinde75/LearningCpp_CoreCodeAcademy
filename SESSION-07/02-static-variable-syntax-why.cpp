struct Test
{
    int num1;
    int num2;

    // Qualifiers are not allowed in c language
    // static int x; in C tis not accepted
};

// C++ style struct,  Qualifiers allowed.
struct Date
{
    private:
        int Day, Month, year;
    public:
        Date(int dd, int mm, int yy);
};
