#include "Mux.h"

Mux::Mux()
{
    //ctor
    //It is something like its component id
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(11);
    set_component_name("Mux");

    selectEntries = new MutliplexerSelect();
}

Mux::~Mux()
{
    //dtor
    delete selectEntries;
}

int Mux::calculate()
{
    if (!isEntriesCorrect())
    {
        #ifdef DEBUG
        std::cout << "Erreur dans l'assignement des entrées" << std::endl;
        #endif
    }
    int _exit;

    _exit = sources_t.at(binaryToInt())->get_exit();

    set_exit(_exit);
    return _exit;
}

int Mux::binaryToInt()
{
    int res = 0;
    for (int i = 0; i < selectEntries->get_size_src(); i++)
    {
        res += (selectEntries->sources_t.at(i)->get_exit() ? 0 : pow(2,i));
    }
    return res;
}

void Mux::add_select_sources(Logic *src1, Logic *src2 = NULL, Logic *src3 = NULL, Logic *src4 = NULL)
{
    selectEntries->add_sources(src1);
    if (src2 != NULL) selectEntries->add_sources(src2);
    if (src3 != NULL) selectEntries->add_sources(src3);
    if (src4 != NULL) selectEntries->add_sources(src4);
}

bool Mux::isEntriesCorrect()
{
    if (sources_t.size() > (pow(2,selectEntries->get_size_src()))) return false;
    else return true;
}


/* MuxSelect section | to select the output */

MutliplexerSelect::MutliplexerSelect()
{
    set_logic_type(1);
    set_logic_type_name("Gate");
    set_component_id(11);
    set_component_name("Mux");
}

MutliplexerSelect::~MutliplexerSelect()
{
}