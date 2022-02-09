#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP
#include <string>

//! Essa classe é responsável pela exibição dos resultados para o usuário.
class IOManager {
    public:
        /*! Imprime as possíveis saídas de erro do sistema.
            @param code Um número interno indicando um erro.
            @return Código de erro do sistema.
        */
        int error(int error_code);

        /*! Envia para a saída padrão o resultado do processamento, ou um
          "No match" caso a sequência não coincida com a de alguém na base de dados.
            @param result O resultado da análise.
        */
        void print_result(std::string result);
};

#endif //IOMANAGER_HPP
