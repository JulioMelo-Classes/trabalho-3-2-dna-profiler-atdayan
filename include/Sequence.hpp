#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <string>
#include <vector>

/*! Classe responsável pela amostra de DNA, essa classe engloba o processo de manipulação
    do arquivo de amostra, armazenamento da sequência e procura dos STR's buscados.
*/
class Sequence {
    private:
        std::string m_sequence; //!< A sequência "ATCGTGAC" extraída do arquivo.

    public:
        /*! Processa o arquivo que contém a sequência de DNA a ser testada.
            @param filename O caminho para o arquivo.
            @return Um booleano informando se o processamento foi possível.
        */
        bool read_sequence(std::string filename);

        /*! Percorre a sequência de DNA e contabiliza a quantidade de cada STR informado.
            @param path A lista de STR's.
            @return Uma lista com a quantidade de cada STR.
        */
        std::vector<int> count_strs(std::vector<std::string> &str_list);

};

#endif //SEQUENCE_HPP
