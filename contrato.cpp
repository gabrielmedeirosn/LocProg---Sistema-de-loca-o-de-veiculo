#include "Contrato.h"
#include "Cliente.h"
#include "Veiculo.h"

#include <iostream>
#include <fstream>
#include <filesystem>



Contrato::Contrato(const Cliente &c, Veiculo* v) : cliente(c), veiculo(v), diasAluguel(0), seguro(false), valorFinal(0.0) {}



void Contrato::preencherFormulario(){
    cout << endl << "--------FORMULARIO DE LOCACAO LOCPROG--------" << endl << endl;
    cout << "Data de retirada(DD/MM/AAAA): ";
    getline(cin, dataRetirada);

    cout << endl << "Quantos dias de aluguel: ";
    cin >> diasAluguel;

    cout << endl << "Aproveite: seguro para qualquer veiculo por R$19,99/dia! " << endl
    << "Inclui protecao completa contra danos a voce e a terceiros. Seguranca total por um preco unico." << endl <<
    "Gostaria de adicionar seguro ao pacote? (S/N)" << endl;
    string respSec;
    cin >> respSec;
    if(toupper(respSec[0]) == 'S'){
        seguro = true;
    }
    calcularValorFinal();
}


void Contrato::calcularValorFinal(){
    valorFinal = veiculo->getDiaria() * diasAluguel;
    if (seguro){
        valorFinal += diasAluguel * 19.99f;
    }

}

void Contrato::gerarArquivoTxt(const string& gerarContrato) const{

    string pastaContratos = "Contratos";
    if (!std::filesystem::exists(pastaContratos)) {
        std::filesystem::create_directory(pastaContratos);
    }
    std::string caminhoArq = pastaContratos + "/" + gerarContrato;


    ofstream contratoTxt (caminhoArq);
    if(!contratoTxt.is_open()){
        system("cls");
        cout << "Erro ao gerar contrato, reinicie o programa e tente novamente" << endl;
    }

    system("cls");
    contratoTxt << "==============================" << endl;
    contratoTxt << "      CONTRATO DE LOCPROG     " << endl;
    contratoTxt << "==============================" << endl << endl;

    contratoTxt << "NOME............: " << cliente.getNome() << endl;
    contratoTxt << "CPF.............: " << cliente.getCpf() << endl;
    contratoTxt << "VEICULO.........: " << veiculo->getMarca() << " " << veiculo->getModel() << endl;
    contratoTxt << "VALOR DA DIARIA.: " << "R$" << veiculo->getDiaria() << endl;

    contratoTxt << "DATA DE RETIRADA: " << dataRetirada << endl;
    contratoTxt << "DIAS DE LOCACAO.: " << diasAluguel << endl;
    contratoTxt << "SEGURO..........: " ; if(seguro){contratoTxt << "SIM";} else{contratoTxt << "NAO";} contratoTxt << endl;
    contratoTxt << "VALOR FINAL.....: R$ " << valorFinal << endl;

    contratoTxt.close();

    cout << endl << "CONTRATO GERADO COM SUCESSO EM: " << std::filesystem::absolute(caminhoArq) << endl;
    cout << "LOCPROG AGRADECE A SUA PREFERENCIA E DESEJA UMA OTIMA EXPECIENCIA" << endl;
    cout << "Precione Enter para encerrar o programa";

}
