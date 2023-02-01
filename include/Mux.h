#ifndef MUX_H
#define MUX_H

#include <Logic.h>

class Mux : public Logic
{
    public:
        Mux();
        virtual ~Mux();

        int calculate();

        void add_select_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL);
    protected:

    private:
        bool isEntriesCorrect();
        MutliplexerSelect *selectEntries;

        int binaryToInt();
};

class MutliplexerSelect : public Logic
{
private:
    /* data */
public:
    MutliplexerSelect();
    virtual ~MutliplexerSelect();
};

#endif // MUX_H
