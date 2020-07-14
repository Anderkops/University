
//NOME DO ARQUIVO: MATRIZ.CPP

#include<iostream>
#include "matriz.h"

using namespace std;




//---------------------------------------------------------------------
//---------------------------------------------------------------------
//CLASSES::::::::::::::CLASSES::::::::::::::::CLASSES:::::::::::::::::
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//Atribuição de valores
//--------------------------------------------------------------------
//--------------------------------------------------------------------

//construtor
Matriz4x4::Matriz4x4()
{
   int i, j;
   for(i=0;i<ORD;i++)
    for(j=0;j<ORD;j++)
     setMatriz(i, j,0.0);

}
//--------------------------------------------------------------------
//identidade
void Matriz4x4::identidade_ini()//SOH COLOCAMOS UM NA DIAGONAL PRINCIPAL
{                               //PORQUE A MATRIZ JAH EH INICIALIZADA
   int i(0),UM(1);             //COM ZERO EM TODAS AS CASA(PELO CONSTRUTOR)
   Matriz4x4 temp;
   (*this)=temp;
   for(i=0;i<ORD;i++)
   {
   setMatriz(i,i,UM);
   }
   return;
}
//---------------------------------------------------------------------

//randomicamente
void Matriz4x4::rand_ini()
{
   int linha(0),coluna(0),num(0);
   //INICIALIZA RAND
   srand ( time(NULL) );

   for(linha=0;linha<ORD;linha++)//MUDANDO DE LINHA
   {   for(coluna=0;coluna<ORD;coluna++)//MUDANDO DE COLUNA
       {
               num=rand()%100;
               if(rand()%2)//PARA NUMEROS NEGATIVOS
               num*=-1;

               setMatriz(linha,coluna,num);
       }
   }
   return;
}

//----------------------------------------------------------------------

//manualmente
void Matriz4x4::teclado_ini()
{
   int linha(0),coluna(0),i(0),ponto(0),lixo(1);
   char num[10]={0,0,0,0,0,0,0,0,0,0};

   for(linha=0;linha<ORD;linha++)//MUDANDO DE LINHA
   {   for(coluna=0;coluna<ORD;coluna++)//MUDANDO DE COLUNA
       {
               /*while(lixo||ponto>1)
               {
                               lixo=0;
                               cin.getline(num,10);
                               for(i=0;i<10;i++)
                               {  if(!isdigit(num[i]))
                                  {
                                  if(ispunct(num[i])) ponto++;
                                  else lixo++;
                                  }
                               }
               }*/
               cout<<"["<<linha+1<<"]"<<"["<<coluna+1<<"]   ";
               fflush(stdin);
               cin.getline(num,10);
               setMatriz(linha,coluna,atof(num));

       }
       cout<<"\n";

   }
   return;
}

//---------------------------------------------------------------------

//saida
void Matriz4x4::impressao(void)const
{
   int i,j;
   for(i=0;i<ORD;i++)
   {
       for(j=0;j<ORD;j++)
       {
               cout<<"\t"<<getMatriz(i,j);
       }
       cout<<endl;
   }

   return;
}
//----------------------------------------------------------------------

//função de acesso
float Matriz4x4::getMatriz(int i, int j) const
{
   return(matriz[i][j]);
}

Matriz4x4 &Matriz4x4::getMatriz()
{
    return *this;
}
//-----------------------------------------------------------------------

//função de alteração
void  Matriz4x4::setMatriz(int i, int j,float valor)
{
   this->matriz[i][j]=valor;
   return;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//Operadores sobrecarregados
//-------------------------------------------------------------------
//-----------------------------------------------------------------

//igualdade de Matriz4x4es

//------------------------------------------------------------------

//soma duas matrizes
Matriz4x4 Matriz4x4::operator + (const Matriz4x4 &B)const
{
   int linha(0),coluna(0);
   float num(0.0);
   Matriz4x4 objeto2;
   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       objeto2.matriz[linha][coluna]=B.getMatriz(linha,coluna)+this->getMatriz(linha,coluna);

   }
   return(objeto2);

}

//-----------------------------------------------------------------
//OBSERVE QUE COM ESTE OPERADOR NAO PODEMOS ALTERAR A MATRIZ, SOMENTE
//SE MANDARMOS O RETURN PARA ELA MESMA
//soma uma constante a uma matriz
Matriz4x4 Matriz4x4::operator + (const float constante)const//SOMA UMA CONSTANTE NA MATRIZ
{
   int linha(0),coluna(0);
   float num(0.0);
   Matriz4x4 objeto2;
   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       objeto2.matriz[linha][coluna]=(getMatriz(linha,coluna)+constante);

   }
   return(objeto2);

}
//---------------------------------------------------------------------

//subtrai duas matrizes
Matriz4x4 Matriz4x4::operator - (const Matriz4x4 &B)const
{
   int linha(0),coluna(0);
   float num(0.0);
   Matriz4x4 objeto2;
   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       objeto2.matriz[linha][coluna]=B.getMatriz(linha,coluna)-this->getMatriz(linha,coluna);

   }
   return(objeto2);

}

//---------------------------------------------------------------------

//subitrai uma constante
Matriz4x4 Matriz4x4::operator - (const float constante)const
{
   int linha(0),coluna(0);
   float num(0.0);
   Matriz4x4 objeto2;
   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       objeto2.matriz[linha][coluna]=(getMatriz(linha,coluna)-constante);

   }
   return(objeto2);

}

//----------------------------------------------------------------------

//multiplica a matriz por uma constante
Matriz4x4 Matriz4x4::operator * (const float constante)const
{
   int linha(0),coluna(0);
   float num(0.0);
   Matriz4x4 objeto2;
   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       objeto2.matriz[linha][coluna]=(getMatriz(linha,coluna)*constante);

   }
   return(objeto2);

}

//-----------------------------------------------------------------------

//multiplica por outra matriz
Matriz4x4 Matriz4x4::operator * (const Matriz4x4 &B)const
{
   int i(0), linha(0), coluna(0);
   float soma(0);
   Matriz4x4 temp;

  for(linha=0;linha<ORD;linha++)
  {
     for(coluna=0;coluna<ORD;coluna++)
     {
         soma=0;
         for(i=0; i<ORD; i++)
         {
             soma+=this->matriz[linha][i]*B.matriz[i][coluna];
         }
         temp.matriz[linha][coluna]=soma;
     }
  }

  return(temp);
}
//----------------------------------------------------------------------
bool  Matriz4x4::operator ==(const  Matriz4x4 &B) const
{
   int linha(0),coluna(0);

   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       if(B.getMatriz(linha, coluna)!=this->getMatriz(linha,coluna))//repare pra prova
       return(false);
   }
   return(true);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//inversão de Matriz4x4
Matriz4x4 Matriz4x4::inverter()const //resposta será em outra Matriz4x4
{
   Matriz4x4 objeto2;
   int linha(0),coluna(0),sinal(0);
   float num(0),det(0);

   det=this->determinante4x4();

   if(det==0)
   {
       cout<<"\n\n A MATRIZ INSERIDA NAO EH INVERSIVEL n\n";
       return(objeto2);
   }

   for(linha=0;linha<ORD;linha++)
   {
       for(coluna=0;coluna<ORD;coluna++)
       {
       if((coluna+linha)%2==1)
       sinal=-1;
       else
       sinal=1;

       num=sinal*(this->determinante3x3(linha, coluna));//NOTE QUE EH UMA FUNCAO PRIVATE

       objeto2.setMatriz(coluna,linha,num);//TAH INVERTIDOS LINHA E COLUNA
       }                                    //PORQUE TEM QUE SER TRASPOSTA

   }

   objeto2=objeto2*(1/det);
   return(objeto2);

}

//----------------------------------------------------------------------

//transposta
Matriz4x4 Matriz4x4::transp() const //resposta será em outra Matriz4x4
{
   Matriz4x4 objeto2;
   int linha(0),coluna(0);
   float num(0.0);

   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       num= this->matriz[linha][coluna];//repare nessa sintaxe
       objeto2.setMatriz(coluna,linha,num);//importante para a prova
       //Esta usando a variavel privada matriz o objeto que chamou a funçao,
       //por intermedio this-> ;
       //Se não tivesse outra classe na função nem precisaria colocar this.
   }

   return(objeto2) ;//RETORNADO OBJETO---REPARE BEM IMPORTANTE PATRA A PROVA
}

//-----------------------------------------------------------------------
//determinante
float Matriz4x4::determinante4x4()const
{
   int coluna(0),sinal(0);
   float det(0);
   for(coluna=0;coluna<ORD;coluna++)
   {
       if((coluna%2)==1)sinal=1;
       else sinal=-1;
       det+=getMatriz(1,coluna)*determinante3x3(1,coluna)*sinal;//NOTE QUE EH UMA
   }                                                            //FUNCAO PRIVATE
   return(det);
}
//----------------------------------------------------------------------
float   Matriz4x4::determinante3x3(int NaoContaLinha, int NaoContaColuna)const
{
   int L1(0),L2(0),C1(0),C2(0);
   float M[ORD-1][ORD-1],resp(0);
   for(L1=0,L2=0;L1<ORD&&L2<ORD-1;L1++,L2++)
   {
       if(L1==NaoContaLinha)
       {
           L1++;
           if(L1>ORD-1)break;
       }
       for(C1=0,C2=0;C1<ORD&&C2<ORD-1;C1++,C2++)
       {
               if(C1==NaoContaColuna)
               {
                      C1++;
                      if(C1>ORD-1)break;
               }
               M[L2][C2]=this->getMatriz(L1,C1);//REPARAR NA CHAMADA
       }
   }
   resp+=M[0][0]*M[1][1]*M[2][2]  +  M[0][1]*M[1][2]*M[2][0]  +  M[0][2]*M[1][0]*M[2][1];
   resp-=M[0][2]*M[1][1]*M[2][0]  +  M[0][0]*M[1][2]*M[2][1]  +  M[0][1]*M[1][0]*M[2][2];
   return(resp);
}

//----------------------------------------------------------------------
//-----------------------------------------------------------------------
//funções de verificação
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

//triangular principal
bool Matriz4x4::triang_sup()const
{
   if(
   getMatriz(1,0)||
   getMatriz(2,0)||
   getMatriz(3,0)||
   getMatriz(2,1)||
   getMatriz(3,1)||
   getMatriz(3,2))
   {
   return(false);
   }
   else
   {
   return(true);
   }
}

//----------------------------------------------------------------------

//triangular secundaria
bool Matriz4x4::triang_inf()const
{

   if(
   getMatriz(0,1)||
   getMatriz(0,2)||
   getMatriz(0,3)||
   getMatriz(1,2)||
   getMatriz(1,3)||
   getMatriz(2,3))
   {
   return(false);
   }
   else
   {
   return(true);
   }

}

//-----------------------------------------------------------------------

//simétrica
bool Matriz4x4::simetric()const
{
   if(*this==transp())//REPARE NISTO PARA A PROVA
       return(true);        //CHAMADA DA FUNCAO PELA
   else                     //PELO O OBJETO QUE
       return(false);       //CHAMOU A FUNCAO
}
//---------------------------------------------------------------------------
