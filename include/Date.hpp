#ifndef DATE_H
#define DATE_H


class Date
{
public:

    Date ();
    Date (int d, int m, int y);

    bool
    Validate (int d, int m, int y);

    bool
    Validate ();

private:

    int day;
    int month;
    int year;
};


#endif        /* DATE_H */
