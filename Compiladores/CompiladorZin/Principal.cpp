//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal.h"

using namespace std;

/*****************************************************************************/
/*****************************************************************************/

#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrincipal *FormPrincipal;

fstream             file_1;

/**************************** -- Analise Lexica -- ***************************/

bool   Ini(string nomeArq);
bool   Insere_Lista_Encadeada(char *pal);
void   Comentario_Tipo_1();
void   Comentario_Tipo_2();
void   Tipo_String();
char*  Separa_String();
void   Apaga_Lista();
int    Leitura_token_1(int Tam_Pal,int i);
int    Leitura_token_2(int Tam_Pal,int i);
char*  Procura_Token();
char*  Mostrar_Buffer();
int    Carrega_Buffer_1();
int    Carrega_Buffer_2();
void   Inicializa_Tabela_Simbolo(void);
int    Insere_Token_Tabela_Simbolo(char palavra[MAX]);
Abb    Insere_Arvore_ABB(char Info[MAX],Abb Arvore,int tipo);
int    procura_ABB(char palavra[MAX]);
void   Inserir_Com_Hash(char palavra[MAX],int tipo);
int    Hash_Com_Posicao(char palavra[MAX]);

/*********************************Analise Sintática**************************/
int repeticaofor(fstream &);
int comandoif(fstream &);
int expressaoA(fstream &);
int expressaoB(fstream &);
int expressaoC(fstream &);
int atribuicao(fstream &);
int declaracao(fstream &);
int geral(fstream &);
int comandos(fstream &);
int programa(fstream &);
int primeiralinha(fstream &);
int beginendpadrao(fstream &);
int beginendprograma(fstream &);
int beginendif(fstream &);

void mensagens(char tipo[],char frase[]);

int cmdread(fstream &);
int cmdwrite(fstream &);
int desespero(fstream &);

/****************************************************************************/
/****************************************************************************/
/*********************** ---  ANÁLISE LÉXICA --- ****************************/
/****************************************************************************/
/****************************************************************************/

/*****************************************************************************/

bool Ini(string nomeArq)
{ int i;
 file_1.open(nomeArq.c_str(), ios::in);
 if(file_1)
 {
   Inicializa_Tabela_Simbolo();
   FormPrincipal->AtualizarTabela->Enabled = true;
   buffer_1 = new char[2*TAM_BLOCO+1];
   for(i=0;i<2*TAM_BLOCO+1;i++)
   buffer_1[i]=EOF;
   buffer_2 = new char[2*TAM_BLOCO+1];
   lin_1 = 0;
   lin_2 = 0;
   file_1.seekg(0,ios::end);
   tamArq = file_1.tellg();
   file_1.seekg(0,ios::beg);
   atual =0;
   bufferpos=0;
   Carrega_Buffer_1();
   return true;
 }
 return false;
}

/*****************************************************************************/

char* Mostrar_Buffer()
{
 char *temp;
 int i=0;
 if(troca==1)
  {
   while(buffer_1[i] != EOF)
      i++;
   temp = new char[i+1];
   strncpy(temp,buffer_1,i);
   temp[i]='\0';
  }
 else
  {
   i = TAM_BLOCO;
   while(buffer_1[i] != EOF)
      i++;
   temp = new char[i-TAM_BLOCO+1];
   strncpy(temp,buffer_1+TAM_BLOCO,i-TAM_BLOCO);
   temp[i-TAM_BLOCO]='\0';
  }
 return temp;
}

/*****************************************************************************/

int Carrega_Buffer_2()
{
 int    sobra, posArq;
 char    *temp;

  posArq = file_1.tellg();
  lin_1 = 0;
  if(!file_1.eof() )
   {
     sobra = tamArq -  TAM_BLOCO - posArq;
     temp = new char[TAM_BLOCO];
     strncpy(buffer_1,temp,TAM_BLOCO);
     file_1.read(buffer_1,TAM_BLOCO);
     if(sobra>0)
        buffer_1[TAM_BLOCO]=EOF;
     else
        buffer_1[file_1.gcount()-posArq+1]=EOF;
    return 0;
  }
 else  return -1;
}

/*****************************************************************************/

int Carrega_Buffer_1()
{
 int    sobra,posArq;
 char    *temp;
 troca=troca*(-1);
 posArq = file_1.tellg();
 if(!file_1.eof() )
  {
     sobra = tamArq -  TAM_BLOCO - posArq;
     if(troca==1)
      {
       lin_1 = 0;
       file_1.read(buffer_1,TAM_BLOCO);
       if(sobra < 0)
          buffer_1[TAM_BLOCO+sobra-2]=EOF;
       else buffer_1[TAM_BLOCO]=EOF;
          return 0;
      }
     else
      {
       lin_2 = 0;
       file_1.read(buffer_1+TAM_BLOCO,TAM_BLOCO);
        if(sobra < 0)
	   buffer_1[(TAM_BLOCO)+(tamArq-posArq)-5]=EOF;
	else buffer_1[2*TAM_BLOCO]=EOF;
	   return(bufferpos);
      }
  }
 else  return -1;
}

/*****************************************************************************/

int Hash_Com_Posicao(char palavra[MAX])
{
 int soma=0;
 unsigned int i;
 for (i=0;i<strlen(palavra); i++)
  soma+=((int)palavra[i]) * (i+1);
 soma%=300;
 return(soma);
}

/*****************************************************************************/

void Inicializa_Tabela_Simbolo(void)
{
 int x = 1;

strcpy(tokens[1].tipo,"begin");
strcpy(tokens[2].tipo,"do");
strcpy(tokens[3].tipo,"else");
strcpy(tokens[4].tipo,"end");
strcpy(tokens[5].tipo,"for");
strcpy(tokens[6].tipo,"if");
strcpy(tokens[7].tipo,"program");
strcpy(tokens[8].tipo,"read");
strcpy(tokens[9].tipo,"then");
strcpy(tokens[10].tipo,"to");
strcpy(tokens[11].tipo,"var");
strcpy(tokens[12].tipo,"write");

strcpy(tokens[13].tipo,"abre_parentese");
strcpy(tokens[14].tipo,"abre_colchetes");
strcpy(tokens[15].tipo,"abre_chave");
strcpy(tokens[16].tipo,"atribuicao");
strcpy(tokens[17].tipo,"dois_pontos");
strcpy(tokens[18].tipo,"fecha_chave");
strcpy(tokens[19].tipo,"fecha_colchetes");
strcpy(tokens[20].tipo,"fecha_parentese");
strcpy(tokens[21].tipo,"igual");
strcpy(tokens[22].tipo,"maior");
strcpy(tokens[23].tipo,"maior_ou_igual");
strcpy(tokens[24].tipo,"mais");
strcpy(tokens[25].tipo,"menor");
strcpy(tokens[26].tipo,"menor_ou_igual");
strcpy(tokens[27].tipo,"menos");
strcpy(tokens[28].tipo,"diferente");
strcpy(tokens[29].tipo,"ponto_e_virgula");
strcpy(tokens[30].tipo,"virgula");
strcpy(tokens[31].tipo,"vezes");
strcpy(tokens[32].tipo,"identificador");
strcpy(tokens[33].tipo,"numerico");
strcpy(tokens[34].tipo,"literal");

strcpy(tokens[33].tipo,"formato");

Inserir_Com_Hash("(",13);
Inserir_Com_Hash("[",14);
Inserir_Com_Hash("{",15);
Inserir_Com_Hash(":=",16);
Inserir_Com_Hash(":",17);
Inserir_Com_Hash("}",18);
Inserir_Com_Hash("]",19);
Inserir_Com_Hash(")",20);
Inserir_Com_Hash("=",21);
Inserir_Com_Hash(">",22);
Inserir_Com_Hash(">=",23);
Inserir_Com_Hash("+",24);
Inserir_Com_Hash("<",25);
Inserir_Com_Hash("<=",26);
Inserir_Com_Hash("-",27);
Inserir_Com_Hash("<>",28);
Inserir_Com_Hash(";",29);
Inserir_Com_Hash(",",30);
Inserir_Com_Hash("*",31);

Inserir_Com_Hash("integer",33);

for(x=1;x<13;x++)
  Inserir_Com_Hash(tokens[x].tipo,x);
}

/*****************************************************************************/

int Insere_Token_Tabela_Simbolo(char palavra[MAX])
{
 int x;
 for(x=1;x<300;x++)
   if(tokens[x].tipo==NULL)
    {
      strcpy(tokens[x].tipo,palavra);
     return(x);
    }
 return(0);
}

/*****************************************************************************/

Abb Insere_Arvore_ABB(char Info[MAX],Abb Arvore,int tipo)
{
 if ( Arvore == NULL )
   {
    Arvore = (Abb)malloc(sizeof(ABB));
    if ( Arvore != NULL)
     {
      strcpy(Arvore->palavra,Info);
      Arvore->tipo=tipo;
      Arvore->esq = Arvore->dir = NULL;
     }
    else
     {
      printf("Memoria Esgotada");
      return(NULL);
     }
   }
 else
    if (stricmp(Info,Arvore->palavra)<0)
      Arvore->esq = Insere_Arvore_ABB(Info,Arvore->esq,tipo);
    else  Arvore->dir = Insere_Arvore_ABB(Info,Arvore->dir,tipo);

 return(Arvore);
}

/*****************************************************************************/

int procura_ABB(char palavra[MAX])
{
  Abb p;
  int cont=1,VALORDOHASH;
  VALORDOHASH=Hash_Com_Posicao(palavra);
  p=vetor[VALORDOHASH].arvore;
  if(p!=NULL)
   do
    {
     if(stricmp(p->palavra,palavra)>0)
      {
       p=p->esq;
       cont++;
      }
     else
       if(stricmp(p->palavra,palavra)<0)
        {
         p=p->dir;
         cont++;
        }
      else
        return(p->tipo);
        }
  while(p!=NULL);
 return(-1);
}

/*****************************************************************************/

void Inserir_Com_Hash(char palavra[MAX],int tipo)
{
int Num;
Num = Hash_Com_Posicao(palavra);
vetor[Num].arvore=Insere_Arvore_ABB(palavra,vetor[Num].arvore,tipo);
}

/*****************************************************************************/

bool Insere_Lista_Encadeada(char *pal)
{
 No p = NULL;

 p = (No)malloc(sizeof(NO));
 if (p==NULL) return(false);
 else
  {
   p->prox = NULL;
   p->ante = NULL;
   p->palavra=(char*)malloc((strlen(palavra)+1)*sizeof(char));
   strcpy(p->palavra,pal);
   if (ini==NULL)
        ini = p;
   else
      {
        ult->prox = p;
        p->ante=ult;
      }
   ult = p;
  }
   return(true);
}

/*****************************************************************************/

void Comentario_Tipo_1()
{
while(buffer_1[bufferpos]!='}')
{
 if(buffer_1[bufferpos]!=EOF)
  {
   if(buffer_1[bufferpos]=='\n')
    {
     if(troca==1)
      lin_1++;
     else
      lin_2++;
     linhageral++;
     posgeral=1;
    }
   bufferpos++;
   posgeral++;
  }
  else
   {
    bufferpos=Carrega_Buffer_1();
    if(bufferpos<0)
     return;
   }
 }
}

/*****************************************************************************/

void Comentario_Tipo_2()
{
do
{
 if(buffer_1[bufferpos]=='\n')
  {
   if(troca==1)
    lin_1++;
   else
    lin_2++;
   linhageral++;
   posgeral=1;
  }
  bufferpos++;
  posgeral++;
  if(buffer_1[bufferpos]=='*')
   {
    bufferpos++;
    posgeral++;
    if(buffer_1[bufferpos]==')')
      break;
   }
  if(buffer_1[bufferpos]==EOF)
   {
    bufferpos=Carrega_Buffer_1();
    if(bufferpos<0)
     return;
   }
}
while (bufferpos!=-1);
}

/*****************************************************************************/

void Tipo_String()
{
int x=0;
bufferpos++;
       posgeral++;
while(buffer_1[bufferpos]!=39)
{
 if(buffer_1[bufferpos]!=EOF)
  {
   if(letra=='\n')
    {
     if(troca==1)
      lin_1++;
     else
      lin_2++;
     linhageral++;
     posgeral=1;
    }
     palavra[x]=buffer_1[bufferpos];
     bufferpos++;
     posgeral++;
  }
  else
  {
    bufferpos=Carrega_Buffer_1();
    palavra[x]=buffer_1[bufferpos];
    bufferpos++;
    posgeral++;
  }
  x++;
 }
palavra[x]='\0';
auxiliarstring=1;
bufferpos++;
posgeral++;
}

/*****************************************************************************/

char* Separa_String()
{
No p;
auxiliarstring=0;
strcpy(palavra,"");
palavra[1]='\0';
  while(bufferpos!=-1)
    {
     letra = buffer_1[bufferpos];
     if(letra!=EOF)
     {
        if((isalpha(letra))||(isdigit(letra))||(letra=='.'))
        {
           palavra[strlen(palavra)]=tolower(letra);
           palavra[strlen(palavra)+1]='\0';
        }
        else
	{
           if(strlen(palavra)!=0)
              {
	      palavra[strlen(palavra)]='\0';
 	      Insere_Lista_Encadeada(palavra);
              return(palavra);
              }
           strcpy(palavra,"");
 	   palavra[0]=tolower(letra);
 	   palavra[1]='\0';
           if (letra=='(')
           {
              bufferpos++;
              posgeral++;
              letra = buffer_1[bufferpos];
              if (letra=='*')
              {
                 strcpy(palavra,"");
                 Comentario_Tipo_2();
              }
              else
              {
                 Insere_Lista_Encadeada(palavra);
                 return(palavra);
              }
           }
           else if (letra=='{')
                   Comentario_Tipo_1();

           else if(((letra=='<')&&(buffer_1[bufferpos+1]=='='))||((letra=='>')&&(buffer_1[bufferpos+1]=='='))||((letra=='<')&&(buffer_1[bufferpos+1]=='>'))||((letra==':')&&(buffer_1[bufferpos+1]=='=')))
                {
                  bufferpos++;
                  posgeral++;
                  palavra[0]=letra;
                  palavra[1]=buffer_1[bufferpos];
                  palavra[2]='\0';
                  bufferpos++;
                  posgeral++;
                  Insere_Lista_Encadeada(palavra);
                  return(palavra);
                }

           else if(letra=='\n')
                {
                if(troca==1)
                lin_1++;
                else
                lin_2++;
                linhageral++;
                posgeral=1;
                }
           else if(letra==39)
                {
                 Tipo_String();
                 Insere_Lista_Encadeada(palavra);
                 return(palavra);
                }
           else if(letra!=32)
                {
                 Insere_Lista_Encadeada(palavra);
                 bufferpos++;
                 posgeral++;
                 return(palavra);
                }

          strcpy(palavra,"");
          palavra[1]='\0';
          }
           bufferpos++;
           posgeral++;
       }
       else
         bufferpos=Carrega_Buffer_1();

    }
if(palavra[0])
        Insere_Lista_Encadeada(palavra);

return("EOF");
}

/*****************************************************************************/

void Apaga_Lista()
{
 if(ult!=NULL)
 {
  while(ult->ante!=NULL)
   {
    ult=ult->ante;
    delete ult->prox;
   }
 ult->token=NULL;
 ult->palavra=NULL;
 }
}

/*****************************************************************************/

int Leitura_token_1(int Tam_Pal,int i)
{
 while(i < Tam_Pal && isdigit(palavra[i]) > 0)
        i++;
 if(i == Tam_Pal && isdigit(palavra[i-1]) )
 {
  Inserir_Com_Hash(palavra,num);
  Pos_Tabela_de_Simbolo = Hash_Com_Posicao(palavra);
  return (1);
 }
 if(i == Tam_Pal && isdigit(palavra[i-1]) == 0)
  return (0);
 return(-1);
}

/*****************************************************************************/

int Leitura_token_2(int Tam_Pal,int i)
{
for(i;i<Tam_Pal;i++)
  if(isdigit(palavra[i]) == 0)
     return (0);

Inserir_Com_Hash(palavra,num);
Pos_Tabela_de_Simbolo = Hash_Com_Posicao(palavra);
return (1);
}

/*****************************************************************************/

char* Procura_Token()
{
 int i =0,aux, Tam_Pal;
 No p=ult;
 char tipo[MAX];
 if(strcmp(palavra,"EOF")==0)
        return ("EOF");

 Tam_Pal = strlen(palavra);
 aux = procura_ABB(palavra);

 if(aux != -1)
  {
   p->token=(char*)malloc((strlen(tokens[aux].tipo)+1)*sizeof(char));
   strcpy(p->token,tokens[aux].tipo);
   return(tokens[aux].tipo);
  }
 else
 {

   if(isalpha(palavra[i]) > 0 || palavra[i] == '_')
    {
      for(i=1;i<Tam_Pal;i++)
       if(isalnum(palavra[i]) == 0)
          if(palavra[i] != '_')
           {
            p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
            strcpy(p->token,"desconhecido");
            return ("desconhecido");
           }
          Inserir_Com_Hash(palavra,id);
          Pos_Tabela_de_Simbolo = Hash_Com_Posicao(palavra);
          p->token=(char*)malloc((strlen("identificador")+1)*sizeof(char));
          strcpy(p->token,"identificador");
          return ("identificador");
    }
   else
     if(isdigit(palavra[i]) > 0)
      {
        if(Leitura_token_1(Tam_Pal,i)==1)
         {
          p->token=(char*)malloc((strlen("numerico")+1)*sizeof(char));
          strcpy(p->token,"numerico");
          return ("numerico");
         }
        if(Leitura_token_1(Tam_Pal,i)==0)
         {
          p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
          strcpy(p->token,"desconhecido");
          return ("desconhecido");
         }

        if(palavra[i] == '.')
         {
          i++;
          if(isdigit(palavra[i]) > 0 && i < Tam_Pal)
          {
           if(Leitura_token_1(Tam_Pal,i)==1)
           {
             p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
             strcpy(p->token,"desconhecido");
             return ("desconhecido");
           }
         if(Leitura_token_1(Tam_Pal,i)==0)
          {
           p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
           strcpy(p->token,"desconhecido");
           return ("desconhecido");
          }
         if(palavra[i] == 'e')
          {
           i++;
           if(i >= Tam_Pal)
            {
             p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
             strcpy(p->token,"desconhecido");
             return ("desconhecido");
            }
           if(palavra[i] == '+' || palavra [i] == '-' || isdigit(palavra[i]) > 0)
            {
             i++;
             if(Leitura_token_2(Tam_Pal,i)==1)
              {
               p->token=(char*)malloc((strlen("numerico")+1)*sizeof(char));
               strcpy(p->token,"numerico");
               return ("numerico");
              }
             if(Leitura_token_2(Tam_Pal,i)==0)
              {
               p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
               strcpy(p->token,"desconhecido");
               return ("desconhecido");
              }
            }
           }
        }
           p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
           strcpy(p->token,"desconhecido");
           return ("desconhecido");
      }
      else
       {
        p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
        strcpy(p->token,"desconhecido");
        return ("desconhecido");
       }
    }
   else
    if (palavra[0] == '\'' && palavra[strlen(palavra)-1] == '\'')
      {
       Inserir_Com_Hash(palavra,literal);
       Pos_Tabela_de_Simbolo = Hash_Com_Posicao(palavra);
        {
          p->token=(char*)malloc((strlen("literal")+1)*sizeof(char));
          strcpy(p->token,"literal");
          return ("literal");
        }
      }
    else
     {
      p->token=(char*)malloc((strlen("desconhecido")+1)*sizeof(char));
      strcpy(p->token,"desconhecido");
      return ("desconhecido");
     }
 }

}

/*****************************************************************************/

int parser(fstream &arq)
{
if(stricmp(Separa_String(),"EOF")==0)
{
 Procura_Token();
 return(0);
}
else
{
 Procura_Token();
 return(1);
}
}

/*****************************************************************************/
/*****************************************************************************/
/********************* ---  ANÁLISE SINTÁTICA --- ****************************/
/*****************************************************************************/
/*****************************************************************************/
/*-----------------------------------------------------------
 EXPA =  { AB* }
 SINAL={+,-,*,/}
 A={ID,NUM}
 B={SINAL,A}
-----------------------------------------------------------*/

int expressaoA(fstream &arq)
{
if((strcmp(ult->token,"identificador")==0)||(strcmp(ult->token,"numerico")==0))
{
        parser(arq);
        if((strcmp(ult->token,"mais")==0)||(strcmp(ult->token,"vezes")==0)||(strcmp(ult->token,"dividir")==0)||(strcmp(ult->token,"menos")==0))
        {
                parser(arq);
                if(expressaoB(arq))
                        return(1);
                else
                {
                        if(!errolog[linhageral])
                        mensagens("ERRO","Expressão mal formada");
                        errolog[linhageral]=1;
                        erros++;
                        return(0);
                }
        }
        else
                return(1);
}
else
{
        if(!errolog[linhageral])
        mensagens("ERRO","Ausencia de Expressão");
        errolog[linhageral]=1;
        erros++;
        return(0);
}
}

/*-----------------------------------------------------------
 EXPB =  { '(' EXPA ')'     ,     EXPA (SINAL EXPB)* }
 SINAL={+,-,*,/}
-----------------------------------------------------------*/

int expressaoB(fstream &arq)
{

 if(strcmp(ult->token,"abre_parentese")==0)
 {
        parser(arq);
        if(expressaoA(arq))
                if(strcmp(ult->token,"fecha_parentese")==0)
                {
                        parser(arq);
                        return(1);
                }
                else
                {
                        if(!errolog[linhageral])
                        mensagens("ERRO","Faltou um  )");
                        errolog[linhageral]=1;
                        erros++;
                        return(0);
                }
        else
        {
                return(0);
        }

 }
 else
 {
 if(expressaoA(arq))
        if((strcmp(ult->token,"mais")==0)||(strcmp(ult->token,"vezes")==0)||(strcmp(ult->token,"dividir")==0)||(strcmp(ult->token,"menos")==0))
        {
                expressaoB(arq);
                return(1);
        }
        else
                return(1);
 else
 {
        return(0);
 }
 }
}

/*-----------------------------------------------------------
 EXPC =  { '(' EXPB COMP EXPB (CONC EXPC)* ')'  }
 SINAL= {+,-,*,/}
 COMP = {<,>,<=,>=,=,<>}
 CONC = {AND,OR}
-----------------------------------------------------------*/

int expressaoC(fstream &arq)
{
if(strcmp(ult->token,"abre_parentese")==0)
{
        parser(arq);
        if(expressaoB(arq))
                if((strcmp(ult->token,"menor_ou_igual")==0)||(strcmp(ult->token,"maior_ou_igual")==0)||(strcmp(ult->token,"igual")==0)||(strcmp(ult->token,"menor")==0)||(strcmp(ult->token,"maior")==0)||(strcmp(ult->token,"diferente")==0))
                {
                        parser(arq);
                        if(expressaoB(arq))
                        {
                                if(strcmp(ult->token,"fecha_parentese")==0)
                                {
                                        parser(arq);
                                        return(1);
                                }
                                else
                                if((strcmp(ult->token,"or")==0)||(strcmp(ult->token,"and")==0))
                                {
                                        parser(arq);
                                        return(expressaoC(arq));
                                }
                                else
                                {
                                        if(!errolog[linhageral])
                                        mensagens("ERRO","Expressão terminada incorretamente");
                                        errolog[linhageral]=1;
                                        erros++;
                                        return(0);
                                }
                        }
                        else
                        {
                                return(0);
                        }
                }
                else
                {
                        if(!errolog[linhageral])
                        mensagens("ERRO","Ausencia de um comparador");
                        errolog[linhageral]=1;
                        erros++;
                        return(0);
                }
        else
        {
                return(0);
        }
}
else
{
        if(!errolog[linhageral])
        mensagens("ERRO","Expressão iniciada incorretamente");
        errolog[linhageral]=1;
        erros++;
        return(0);
}

}

/*-----------------------------------------------------------
 ATRIBUICAO =  { ID := EXPB }
-----------------------------------------------------------*/

int atribuicao(fstream &arq)
{
        parser(arq);
        if(strcmp(ult->token,"atribuicao")==0)
        {
                parser(arq);
                if(expressaoB(arq))
                        if(strcmp(ult->token,"ponto_e_virgula")==0)
                        {
                                return(1);
                        }
                        else
                        {
                                mensagens("ERRO","Faltou o ;");
                                erros++;
                                return(0);
                        }
                else
                {
                        mensagens("ERRO","A atribuição está incorreta");
                        erros++;
                        return(0);
                }
        }
        else   return(0);


}

/*-----------------------------------------------------------
 DECLARACAO =  { var id (,id)* : formato }
-----------------------------------------------------------*/

int declaracao(fstream &arq)
{
 if(strcmp(ult->token,"var")==0)
 {
        parser(arq);
        if(strcmp(ult->token,"identificador")==0)
        for(;;)
        {
       parser(arq);
       if(strcmp(ult->token,"dois_pontos")==0)
       {
		parser(arq);
		if(strcmp(ult->token,"formato")==0)
                {
                        parser(arq);
                        if(strcmp(ult->token,"ponto_e_virgula")==0)
                                return(1);
                        else
                        {
                                mensagens("ERRO","Faltou o ; ");
                                erros++;
                                return(0);
                        }
                }
                else
                {
                        mensagens("ERRO","Faltou o tipo de dado após os dois pontos\n Ou existe alguma sujeira entre eles");
                        erros++;
                        return(0);
                }
       }
       else
       if(strcmp(ult->token,"virgula")==0)
       {
                parser(arq);
                if(strcmp(ult->token,"identificador")!=0)
                {
                        mensagens("ERRO","Faltou um identificador, ou uma virgula está sobrando");
                        erros++;
                        return(0);
                }
       }
       else
       {
                mensagens("ERRO","Faltou uma virgula ou dois pontos");
                erros++;
                return(0);
       }
  }
  else
  {
        mensagens("ERRO","Faltou um identificador para a declaração");
        erros++;
        return(0);
  }
  }
  else
        return(0);
}

/*-----------------------------------------------------------
 SELECAO =  { EXPC THEN INTFUN }
-----------------------------------------------------------*/

int comandoif(fstream &arq)
{
 parser(arq);
 if(expressaoC(arq))
        if(strcmp(ult->token,"then")==0)
        {

		            if(beginendif(arq))
                        if(strcmp(ult->token,"else")==0)
                                return(beginendif(arq));
                        else return(1);

        }
        else
        {
                mensagens("ERRO","Faltou o 'then'");
                erros++;
                return(0);
        }
 return(0);
}

/*-----------------------------------------------------------
 REPETICAO FOR =  { atribuicao to/downto identificador/numerico do intfun }
-----------------------------------------------------------*/

int repeticaofor(fstream &arq)
{
 parser(arq);
 if(atribuicao(arq))
 {
        parser(arq);
        if((strcmp(ult->token,"to")==0))
        {
                parser(arq);
                if((strcmp(ult->token,"identificador")==0)||(strcmp(ult->token,"numerico")==0))
                {
                        parser(arq);
                        if(strcmp(ult->token,"do")==0)
                        {
                                return(beginendpadrao(arq));
                        }
                        else
                                mensagens("ERRO","Faltou o do");
                }
                else
                        mensagens("ERRO","Faltou um identificador ou numero");
        }
        else
                mensagens("ERRO","Faltou o downto ou to");
 }
 else
        mensagens("ERRO","Faltou uma atribuição");
 erros++;
 return(0);
}

/*-----------------------------------------------------------
 READ entrada de dados
-----------------------------------------------------------*/
int cmdread(fstream &arq)
{
 parser(arq);
 if(strcmp(ult->token,"abre_parentese")==0)
  {
    parser(arq);
    if(strcmp(ult->token,"identificador")==0)
      {
        parser(arq);
        while(strcmp(ult->token,"virgula")==0)
         {
          parser(arq);
          if(strcmp(ult->token,"identificador")==0)
            parser(arq);
          else{ mensagens("ERRO","READ há sujeira entre a virgula e o identificador ou uma virgula a mais"); erros++; return(0);}

         }
        if(strcmp(ult->token,"fecha_parentese")==0)
         {
           parser(arq);
           if(strcmp(ult->token,"ponto_e_virgula")==0)
            {
              return(1);
            }
           else
               mensagens("ERRO","READ Faltou o ;");
         }
        else { mensagens("ERRO","READ Faltou o )");}

       erros++;
      }
     else { mensagens("ERRO","READ há sujeira entre o ( e o primeiro identificador"); erros++; return(0); }
   }
  else { mensagens("ERRO","READ Faltou o ("); erros++; return(0);}
return(0);
}

/*-----------------------------------------------------------
 Write modo de output
-----------------------------------------------------------*/
int cmdwrite(fstream &arq)
{
 parser(arq);
 if(strcmp(ult->token,"abre_parentese")==0)
  {
    parser(arq);
    if(strcmp(ult->token,"identificador")==0)
      {
        parser(arq);
        while(strcmp(ult->token,"virgula")==0)
         {
          parser(arq);
          if(strcmp(ult->token,"identificador")==0)
            parser(arq);
          else{ mensagens("ERRO","WRITE há sujeira entre a virgula e o identificador ou uma virgula a mais"); erros++; return(0);}

         }
        if(strcmp(ult->token,"fecha_parentese")==0)
         {
           parser(arq);
           if(strcmp(ult->token,"ponto_e_virgula")==0)
            {
              return(1);
            }
           else
               mensagens("ERRO","WRITE Faltou o ;");
         }
        else { mensagens("ERRO","WRITE Faltou o )");}

       erros++;
      }
   }
  else { mensagens("ERRO","WRITE Faltou o ("); erros++; return(0);}
return(0);
}

/*-----------------------------------------------------------
 DESESPERO = tratamento de erros modo desespero
-----------------------------------------------------------*/

int desespero(fstream &arq)
{
while(parser(arq))
{
if(stricmp(ult->token,"end")==0)
return(0);
else
if(stricmp(ult->token,"ponto_e_virgula")==0)
return(1);
}
return(0);
}

/*-----------------------------------------------------------
 GERAL = comandos*
-----------------------------------------------------------*/

int geral(fstream &arq)
{
if(comandos(arq))
        geral(arq);
return(1);
}

/*-----------------------------------------------------------
 comandos = {SELECAO,REPETICAOWHILE,REPETICAOFOR,REPETICAOREPEAT,ATRIBUICAO}
-----------------------------------------------------------*/

int comandos(fstream &arq)
{
          parser(arq);
          if(strcmp(ult->token,"write")==0)
          {
                if(cmdwrite(arq)) return(1);
                else return(desespero(arq));
          }
          else
          if(strcmp(ult->token,"read")==0)
          {
                if(cmdread(arq))  return(1);
                else return(desespero(arq));
          }
          else
          if(strcmp(ult->token,"identificador")==0)
          {
                if(atribuicao(arq)) return(1);
                else  return(desespero(arq));
          }
          else
          if(strcmp(ult->token,"if")==0)
          {
                if(comandoif(arq)) return(1);
                else  return(desespero(arq));
          }
          else
          if(strcmp(ult->token,"for")==0)
          {
                if(repeticaofor(arq)) return(1);
                else  return(desespero(arq));
          }
          else return(0);
}

/*-----------------------------------------------------------
 BEGINENDPADRAO = BEGIN GERAL END;
-----------------------------------------------------------*/

int beginendpadrao(fstream &arq)
{
parser(arq);
if(strcmp(ult->token,"begin")==0)
{
        geral(arq);
        if(strcmp(ult->token,"end")==0)
        {
                parser(arq);
                if(strcmp(ult->token,"ponto_e_virgula")==0)
                        return(1);
                else
                {
                        mensagens("ERRO","Faltou um ; após o end");
                        erros++;
                        return(0);
                }
        }
        else
        {
                mensagens("ERRO","Faltou um end");
                erros++;
                return(0);
        }
}
else
{
        mensagens("ERRO","Faltou um begin");
        erros++;
        return(0);
}

}

/*-----------------------------------------------------------
 BEGINENDPROGRAMA = BEGIN GERAL END.
-----------------------------------------------------------*/

int beginendprograma(fstream &arq)
{
if(strcmp(ult->token,"begin")==0)
{
        geral(arq);
        if(strcmp(ult->palavra,"end.")==0)
                return(1);
        else
        {
                mensagens("ERRO","Faltou o end.");
                erros++;
                return(0);
        }
}
else
{
        mensagens("ERRO","Faltou um begin");
        erros++;
        return(0);
}

}

/*-----------------------------------------------------------
 BEGINENDIF = BEGIN GERAL END; | COMANDOS
-----------------------------------------------------------*/

int beginendif(fstream &arq)
{
parser(arq);
if(strcmp(ult->token,"begin")==0)
{
        geral(arq);
        if(strcmp(ult->token,"end")==0)
        {
                parser(arq);
                if(strcmp(ult->token,"ponto_e_virgula")==0)
                        return(1);
                else
                {
                        mensagens("ERRO","Faltou um ; após o end");
                        erros++;
                        return(0);
                }
        }
        else
        {
                mensagens("ERRO","Faltou o end");
                erros++;
                return(0);
        }
}
else
{
        if(comandos)
                return(1);
        else
        {
                mensagens("ERRO","Erro dentro do IF");
                erros++;
                return(0);
        }
 }

}



/*-----------------------------------------------------------
 PRIMEIRALINHA()
-----------------------------------------------------------*/

int primeiralinha(fstream &arq)
{
        parser(arq);
        if(strcmp(ult->token,"program")==0)
        {
                parser(arq);
                if(strcmp(ult->token,"identificador")==0)
                {
                        parser(arq);
                        if(strcmp(ult->token,"ponto_e_virgula")==0)
                                return(1);
                        else
                        {
                                mensagens("ERRO","Faltou o ;");
                                erros++;
                                return(0);
                        }
                }
                else
                {
                        mensagens("ERRO","Faltou o nome do programa");
                        erros++;
                        return(0);
                }
        }
        else
        {
                mensagens("ERRO","Faltou o program");
                erros++;
                return(0);
        }
}

/*-----------------------------------------------------------
 PROGRAMA - primeiralinha declaracao beginendprograma
-----------------------------------------------------------*/

int programa(fstream &arq)
{
        if(primeiralinha(arq))
        {
                parser(arq);
                if(declaracao(arq))
                {
                 do
                 { parser(arq); }
                  while(declaracao(arq));
                  if(beginendprograma(arq))
                       return(1);
                  else
                       return(0);
                }
                else
                        return(0);
        }
        else
                return(0);
}

/*-----------------------------------------------------------
 SINTATICA - FAZ A ANALISE SINTATICA
-----------------------------------------------------------*/

int sintatica(fstream &arq)
{
 erros=0;
 linhageral=0;
 posgeral=1;
 return(programa(arq));
}

/*-----------------------------------------------------------
 MENSAGENS - acumula as mensagens de verificação
-----------------------------------------------------------*/

void mensagens(char tipo[],char frase[])
{
//msgs.cat_sprintf("Linha :%d Pos :%d %s - %s\n",linhageral,posgeral,tipo,frase);
 FormPrincipal->Mensagens->Cells[0][LinhaMsg] = linhageral;
 FormPrincipal->Mensagens->Cells[1][LinhaMsg] = posgeral;
 FormPrincipal->Mensagens->Cells[2][LinhaMsg] = frase;
 LinhaMsg++;
 FormPrincipal->Mensagens->RowCount++;
}

/*-----------------------------------------------------------
 MENSAGENS - limpa o array que acumula os erros por linha
-----------------------------------------------------------*/

void limpaarrayerros()
{
int i=0;
for(i=0;i<5000;i++)
errolog[i]=0;
}

/*-----------------------------------------------------------
LIMPAMENSAGEM: Limpa Grid que contém as mensagens de ERRO
-----------------------------------------------------------*/
void limpaMensagem()
{
 for(int i = 1; i<5000; i++)
  {
   FormPrincipal->Mensagens->Cells[0][i] = "";
   FormPrincipal->Mensagens->Cells[1][i] = "";
   FormPrincipal->Mensagens->Cells[2][i] = "";
  }
}


//---------------------------------------------------------------------------
__fastcall TFormPrincipal::TFormPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::Abrir1Click(TObject *Sender)
{
 if( OpenDialog->Execute())
  {
   if(!Ini(OpenDialog->FileName.c_str())) 
     ShowMessage("ERRO AO ABRIR O ARQUIVO");
   Texto->Paragraph->Numbering = 2;                     // arabic style
   Texto->Lines->LoadFromFile(OpenDialog->FileName);
   Rich_buffer1->Lines->SetText(Mostrar_Buffer());
   Rich_buffer1->SelStart=0;
   edt_Diretorio->Text = OpenDialog->FileName;
   if(Lexica1->Checked == true) NextToken1->Enabled=true;
   else AnaliseSintatica->Enabled = true;
   pnl_Propriedades->Enabled=true;
   tabela_de_simbolo();
   Fechar1->Enabled=true;
 }

}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Fechar1Click(TObject *Sender)
{
   lbledt_Token->Text = "";
   lbledt_Lexema->Text = "";
   lbledt_Pos_Tabela->Text = "";
   edt_Diretorio->Text = "";
   Rich_Tabela_Simbolo->Lines->Clear();
   limpaMensagem();
   Texto->Lines->Clear();
   Rich_buffer1->Lines->Clear();
   Rich_buffer2->Lines->Clear();
   strgrd_Lista_Gerada->Cols[0]->Clear();
   strgrd_Lista_Gerada->Cols[1]->Clear();
   strgrd_Lista_Gerada->RowCount = 1;
   Mensagens->Cols[0]->Clear();
   Mensagens->Cols[1]->Clear();
   Mensagens->Cols[2]->Clear();
   Mensagens->RowCount = 5;
   Mensagens->Cells[0][0] = "Linha";
   Mensagens->Cells[1][0] = "Posição";
   Mensagens->Cells[2][0] = "Mensagem";
   bufferpos=0;
   lin_1=0;
   Apaga_Lista();
   file_1.close();
   file_1.clear();
   OpenDialog->Options.Clear();
   OpenDialog->Files->Clear();
   troca=-1;
   Fechar1->Enabled=false;
   NextToken1->Enabled=false;
   AnaliseSintatica->Enabled = false;
   AtualizarTabela ->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::tabela_de_simbolo()
{
 stringstream s;
 Rich_Tabela_Simbolo->Lines->Clear();
 for(int i=1;i<300;i++)
 {
   s << i << " - ";
   if(vetor[i].arvore)
   s << vetor[i].arvore->palavra;
   Rich_Tabela_Simbolo->Lines->Add(s.str().c_str());
   s.str("");
 }
}

//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Sair1Click(TObject *Sender)
{
 FormPrincipal->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::AtualizarTabelaClick(
      TObject *Sender)
{
 tabela_de_simbolo();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::NextToken1Click(TObject *Sender)
{
  int pos;
  lbledt_Lexema->Text=(Separa_String());
  if(lbledt_Lexema->Text=="EOF")
        lbledt_Lexema->Text=(Separa_String());

  lbledt_Token->Text=Procura_Token();

  if(lbledt_Lexema->Text=="EOF")
  {
   Application->MessageBox("Analise Léxica Concluida !", "Final de Arquivo! " , MB_OK);;
   NextToken1->Enabled=false;
   //btn_Analise_Sintatica->Enabled = true;
  }
  else {
    pos = Hash_Com_Posicao(lbledt_Lexema->Text.c_str());
    lbledt_Pos_Tabela->Text = pos;
    tabela_de_simbolo();
    if(troca==1)
     {
      if(bufferpos-lbledt_Lexema->Text.Length()<0)
       {
        Rich_buffer1->Lines->SetText(Mostrar_Buffer());
        Rich_buffer1->SelStart = lin_1;
        Rich_buffer1->SelLength= bufferpos-auxiliarstring;
        Rich_buffer1->SelAttributes->Style << fsBold;
        Rich_buffer1->SelAttributes->Color = clRed;

        Rich_buffer2->SelStart = TAM_BLOCO - (lbledt_Lexema->Text.Length()-bufferpos) + lin_2 - auxiliarstring;
        Rich_buffer2->SelLength= abs(lbledt_Lexema->Text.Length()- bufferpos + auxiliarstring);
        Rich_buffer2->SelAttributes->Style << fsBold;
        Rich_buffer2->SelAttributes->Color = clRed;
       }
      else
       {
        Rich_buffer2->SelLength= 0;
        Rich_buffer2->Lines->Clear();

        Rich_buffer1->Lines->SetText(Mostrar_Buffer());
        Rich_buffer1->SelStart = bufferpos - lbledt_Lexema->Text.Length() + lin_1 - auxiliarstring;
        Rich_buffer1->SelLength= lbledt_Lexema->Text.Length();
        Rich_buffer1->SelAttributes->Style << fsBold;
        Rich_buffer1->SelAttributes->Color = clRed;
       }
      }
     else
      {
       if(bufferpos-lbledt_Lexema->Text.Length()<TAM_BLOCO)
        {
         Rich_buffer2->Lines->SetText(Mostrar_Buffer());
         Rich_buffer2->SelStart = lin_2;
         Rich_buffer2->SelLength= bufferpos - TAM_BLOCO - auxiliarstring;
         Rich_buffer2->SelAttributes->Style << fsBold;
         Rich_buffer2->SelAttributes->Color = clRed;

         Rich_buffer1->SelStart = bufferpos - lbledt_Lexema->Text.Length() + lin_1 - auxiliarstring;
         Rich_buffer1->SelLength= abs(TAM_BLOCO -(bufferpos-lbledt_Lexema->Text.Length())+ auxiliarstring);
         Rich_buffer1->SelAttributes->Style << fsBold;
         Rich_buffer1->SelAttributes->Color = clRed;
        }
       else
        {
         Rich_buffer1->SelLength= 0;
         Rich_buffer1->Lines->Clear();

         Rich_buffer2->Lines->SetText(Mostrar_Buffer());
         Rich_buffer2->SelStart = bufferpos - lbledt_Lexema->Text.Length() + lin_2 -TAM_BLOCO - auxiliarstring;
         Rich_buffer2->SelLength= lbledt_Lexema->Text.Length();
         Rich_buffer2->SelAttributes->Style << fsBold;
         Rich_buffer2->SelAttributes->Color = clRed;
        }
       }
    strgrd_Lista_Gerada->Cells[0][strgrd_Lista_Gerada->RowCount-1] = lbledt_Lexema->Text.c_str();
    strgrd_Lista_Gerada->Cells[1][strgrd_Lista_Gerada->RowCount-1] = pos;
    strgrd_Lista_Gerada->RowCount++;
  }    
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::FormCreate(TObject *Sender)
{
  Mensagens->Cells[0][0] = "Linha";
  Mensagens->Cells[1][0] = "Posição";
  Mensagens->Cells[2][0] = "Mensagem";
}
//---------------------------------------------------------------------------



void __fastcall TFormPrincipal::AnaliseSintaticaClick(TObject *Sender)
{
 limpaMensagem();

 //Mensagens->Paragraph->Numbering=nsBullet;
 sintatica(file_1);
            if(erros==0)   ShowMessage("Analise Sintatica concluida sem erros :)");
            else if(erros==1)  ShowMessage("1 erro foi encontrado.");
                 else ShowMessage("Foram encontrados " + String(erros) + " erros.");
/* Mensagens->Lines->SetText(msgs.c_str());
 msgs="";*/
 AnaliseSintatica->Enabled = false;
 limpaarrayerros();
 LinhaMsg = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Lexica1Click(TObject *Sender)
{
 Lexica1->Checked = true;
 Sintatica1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Sintatica1Click(TObject *Sender)
{
 Lexica1->Checked = false;
 Sintatica1->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::GuiaParaExecutarumarquivoPascal1Click(
      TObject *Sender)
{
 ShowMessage("    Para Executar as operações primeiramente escolha o tipo de análise \n que deseja executar em Análise->Lexica ou Análise->Sintatica e então \n Abra um Arquivo em Arquivo->Abrir e execute em Executar->Next Token \n ou Executar->Analise Sintatica \n\n\n para executar as respectivas análises deve-se fechar e abrir o arquivo \n novamente, é feita somente um tipo de análise por vez");
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::SobreCompiladorZin1Click(TObject *Sender)
{
 ShowMessage("           Trabalho de Compiladores : CompiladorZin          \n\n\nAnderson Gregório da Silva\nRicardo Yukio Fugifara");
}
//---------------------------------------------------------------------------

