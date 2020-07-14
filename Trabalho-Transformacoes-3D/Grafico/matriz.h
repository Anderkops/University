
//NOME DO ARQUIVO: MATRIZ.H


#ifndef MATRIZ_H

#define MATRIZ_H


const int ORD(4);

class Matriz4x4
{
       public:

               //construtores
               Matriz4x4();//inicializa com zero*******************OK

               //destrutor
               //~Matriz4x4();
               //Ponto operator +(const Ponto &Ponto2);
               //soma
               Matriz4x4 Matriz4x4::operator + (const Matriz4x4 &B)const;//matrizes******************OK
               Matriz4x4 Matriz4x4::operator + (const float constante)const;  //uma constante***********OK
               //subtra��o
               Matriz4x4 Matriz4x4::operator - (const Matriz4x4 &B)const;//matrizes***************OK
               Matriz4x4 Matriz4x4::operator - (const float constante)const;  //uma constante***********OK
               //multiplica��o
               Matriz4x4 Matriz4x4::operator * (const float constante)const;//por constante*************OK
               Matriz4x4 Matriz4x4::operator * (const Matriz4x4 &B)const;  //por outra Matriz4x4***OK
               bool  Matriz4x4::operator ==(const  Matriz4x4 &B) const ;//igualdade de Matriz4x4es***OK

               //multiplicaMatriz4x4(const Matriz4x4 &B){(*this) = B * (*this);}

       //invers�o de Matriz4x4
               Matriz4x4 inverter()const;//resposta ser� em outra Matriz4x4***************OK
               //transposta
       Matriz4x4 transp() const; //resposta ser� em outra Matriz4x4****************OK
       //verifica��o
       bool triang_sup()const; //triangular superior*********************OK
       bool triang_inf()const; //triangular inferior*****************OK
       bool simetric()const;  //sim�trica****************************OK

       //determinante
       float determinante4x4()const;

         // atribui��o de valores
        void identidade_ini(); //identidade*************OK
        void rand_ini();  //randomicamente     *************OK
        void teclado_ini();  //manualmente *************OK
            //saida
            void impressao(void)const;//*************OK
            //fun��o de acesso
            float getMatriz(int i, int j) const;//************OK
            //fun��o de altera��o
            void  setMatriz(int i, int j,float valor);//*************OK
            //uso inutil
            Matriz4x4 &getMatriz();

   protected: //declara��o das variaveis usadas pelas fun��es publicas
       float matriz[ORD][ORD];
       float   Matriz4x4::determinante3x3(int NaoContaLinha, int NaoContaColuna)const;//******OK

};

#endif


