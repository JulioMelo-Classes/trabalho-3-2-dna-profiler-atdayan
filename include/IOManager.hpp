#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP
#include <string>

//! Essa classe é responsável pela exibição dos resultados para o usuário.
class IOManager {
    public:
        /*! Imprime o resultado do processamento, ou um "No match"
          caso a sequência não coincida com a de alguém na base de dados.
            @param result O resultado da análise.
        */
        void print_result(std::string result);

        /*! Imprime as possíveis saídas de erro do sistema.
            @param code Um número interno indicando um erro.
        */
        void error(int error_code);

        //! Imprime um texto informando como utilizar o programa.
        void show_usage();
};

#endif //IOMANAGER_HPP
