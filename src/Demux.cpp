#include "Demux.h"

Demux::Demux()
{
    //ctor
    //It is something like its component id
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(12);
    set_component_name("Demux");

    selectOutputs = new DemutliplexerSelect();
}

Demux::~Demux()
{
    //dtor
    delete selectOutputs;
}


void Demux::add_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL)
{
    if (get_size_src() == 0)
    {
        sources_t.push_back(src1);
        if (src2 != NULL && src3 != NULL && src4 != NULL) {
            #ifdef DEBUG
            std::cout << "Demux only accept one source" << std::endl;
            #endif
        }
    }
    else
    {
        #ifdef DEBUG
        std::cout << "Demux only accept one source" << std::endl;
        #endif
    }
}

int Demux::calculate()
{
    if (!isOutputsCorrect())
    {
        #ifdef DEBUG
        std::cout << "Erreur dans l'assignement des sorties" << std::endl;
        #endif
    }
    int _exit;

    _exit = sources_t.at(binaryToInt())->get_exit();

    set_exit(_exit);
    return _exit;
}

int Demux::binaryToInt()
{
    int res = 0;
    for (int i = 0; i < selectOutputs->get_size_src(); i++)
    {
        res += (selectOutputs->sources_t.at(i)->get_exit() ? 0 : pow(2,i));
    }
    return res;
}

void Demux::add_select_outputs(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL)
{
    selectOutputs->add_sources(src1);
    if (src2 != NULL) selectOutputs->add_sources(src2);
    if (src3 != NULL) selectOutputs->add_sources(src3);
    if (src4 != NULL) selectOutputs->add_sources(src4);
}

bool Demux::isOutputsCorrect()
{
    if (output_t.size() > (pow(2,selectOutputs->get_size_src()))) return false;
    else return true;
}


/* DemuxSelect section | to select the output */

DemutliplexerSelect::DemutliplexerSelect()
{
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(12);
    set_component_name("Demux");
}

DemutliplexerSelect::~DemutliplexerSelect()
{
}