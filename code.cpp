#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>
using namespace std;

int main() {
        time_t now = time(nullptr);
        
        setlocale(LC_ALL, "Portuguese");
        setlocale(LC_TIME, "pt_BR.UTF-8");

	int escolha = 0,  dificuldade  = 1;

        // Letras ainda tão quebrando o codigo todo
        while (escolha != 4){ // serve pra que todas as escolhas voltem pro menu 
		cout << "===================SENHA==================="  << endl;
		cout << "escolha uma opção :" << endl;
		cout << "1 - Jogar" << endl;
		cout << "2 - Dificuldade" << endl;
		cout << "3 - Sobre" << endl;
		cout << "4 - FIM" << endl;
		cin >> escolha;

		switch (escolha)
		{
		case 1:  // Tem Que começar a arrumar a parte do jogo
			cout << "aaa";
			break;

		case 2:// O codigo também ta motrando qual a dificuldade atual do jogador
			cout << "=============DIFICULDADE==========="<<  endl;
            cout << "Por favor escolha a dificuldade que quer desafiar:  " << endl;
			if (dificuldade == 1){
                cout << "  Dificuldade atual: fácil"<<  endl;
            }else if (dificuldade == 2) {
                cout << "  Dificuldade atual: médio"<<  endl;
            } else {
                cout << "  Dificuldade atual: difícil"<<  endl;
            }
            cout << "1 - Fácil" << endl;
            cout << "2 - médio" << endl;
            cout << "3 - Difícil" << endl;
            cin >> dificuldade;
            break;

		case 3: // Coloquem o nome completo de voces aqui
            cout << "==============SOBRE================" << endl;
			cout << "Equipe de Desenvolvimento==========" << endl;
            cout << "- João Gabriel M. T. dos Santos" << endl;
            cout << "- Thiago" << endl;
            cout << "- Juliano" << endl;
            cout << "- Yasmin" << endl;
            cout << "dia e data atuais :" << endl;
            
            //Tem que converter a data de ingles para protgues ele pega direto do sistema
            cout << "Data atual: " << ctime(&now); 

            cout << "===Professor e Disciplina=========="<< endl;
            cout << "Professor: Alex Rese" << endl;
            cout << "Disciplina : Algoritmo e Programação" << endl;
			break;


		case 4: // Finaliza o código
            escolha = 0;
			return 0;

		default:
			cout << "Digite uma escolha válida" << endl;
            break;

		}
       } 

       //protótipo  do  jogo  em si
       if (dificuldade == 1){
        srand(time(0));
        int num1, num2, num3, tentativas = 1, res1, res2, res3;
        bool resposta = false;
        do{
            num1  = rand()%6 + 1;
            num2  = rand()%6 + 1;
            num3  = rand()%6 + 1;
        }while (num1 == num2 or num1 == num3 or num2 == num3);
         
            while (tentativas < 8 or resposta != true){
       
             cout <<"============TENTATTIVA "<< tentativas << " ===================";
             
             cin >> res1, res2, res3;
             if (res1  ==  num1){
                cout <<" Primeiro número certo, local certo" << endl;
             } else if (res1 == num2 or  res1 == num3)
             {
               cout <<" Primeiro número certo, porém local errado!" << endl;
             } else {
                cout << "numero errado" << endl;
             }
             
             if (res2  ==  num2){
                cout <<" Segundo número certo, local certo" << endl;
             } else if (res2 == num1 or  res2 == num3){
               cout <<" Segundo número certo, porém local errado!" << endl;
             } else {
                cout << "numero errado" << endl;
             }
            
             if (res3  ==  num3){
                cout <<" Terceiro número certo, local certo" << endl;
             } else if (res3 == num2 or  res3 == num1)
             {
               cout <<" Terceiro número certo, porém local errado!" << endl;
             } else { 
                cout << "numero errado" << endl;
             }
             tentativas++;
             if (res1 == num1 && res2 == num2 && res3 == num3){
                cout << "Parabéns você conseguiu!!";
                resposta = true;
             }
    
             }
             if (tentativas == 8 and resposta ==  false){
                cout << "Você não conseguiu adivinhar. Que pena!";
             }
      
         }



     return 0;

       }