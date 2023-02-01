#ifndef DEMUX_H
#define DEMUX_H

#include <Logic.h>

class Demux : public Logic
{
    public:
        Demux();
        virtual ~Demux();

        void add_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL);

        int calculate();

        void add_select_outputs(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL);
    protected:

    private:
        bool isOutputsCorrect();
        DemutliplexerSelect *selectOutputs;

        int binaryToInt();
};

class DemutliplexerSelect : public Logic
{
private:
    /* data */
public:
    DemutliplexerSelect();
    virtual ~DemutliplexerSelect();
};

#endif // DEMUX_H
