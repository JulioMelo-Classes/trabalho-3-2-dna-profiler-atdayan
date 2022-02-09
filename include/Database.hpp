#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <vector>

/*! Essa classe engloba a base de dados que detém as informações dos indivíduos, os STR's
    a serem analisados e suas respectivas quantidades presente no DNA de cada pessoa.
    Ela é responsável por processar o arquivo CSV, extrair esses dados e exportar esse conteúdo.
*/
class Database {
    public:
        /*! Processa o arquivo que contém a base de dados.
            @param filename O caminho para o arquivo.
            @return Um booleano informando se o processamento foi possível.
        */
        bool read_database(std::string filename);

        /*! Retorna uma coleção de STR's que serão buscadas na amostra de DNA.
            @return Um contêiner de strings com os STR's.
        */
        std::vector<std::string> str_list();
};

#endif //DATABASE_HPP
