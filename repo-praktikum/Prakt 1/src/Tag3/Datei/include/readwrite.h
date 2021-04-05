#ifndef READWRITE_H
#define READWRITE_H
#include <string>

class readwrite
{
    public:
        readwrite();
        virtual ~readwrite();
        bool read_file(std::string Dateiname);
        bool write_file(std::string Dateiname);

    protected:

    private:
};

#endif // READWRITE_H
