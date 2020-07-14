//-------------------------------------------------------------------------//
// Trabalho de Complexidade de Algoritmos - Codigo de Huffman              //
// Compactador e descompactador de arquivos                                //
// Docente:     Erwin                                                      //
// Discente:    Anderson Gregorio da Silva                                 //
//              Fabio Feliciano de Oliveira                                //
//              Marcelo Satio Karakawa                                     //
//              Ricardo Yukio Fugifara                                     //
// Curso/turma: Ciencia da computacao - 4 ano - noturno                    //
// Faculdade:   Faculdade de Ciencias e Tecnologia de P. Prudente - Unesp  //
//-------------------------------------------------------------------------//
#include <vcl.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#pragma hdrstop

#include "main.h"
#include "sobre.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#define TAM_ARRAY 	256         //tamanho do array de frequencia
#define ch(p)  		p->ch
#define freq(p) 	p->freq
#define codigo(p) 	p->codigo
#define tam(p) 		p->tam
#define prox(p) 	p->prox
#define dir(p) 		p->dir
#define esq(p)		p->esq
#define MIL         1000        //identificador de noh q nao eh folha

using namespace std;

//E S T R U T U R A ---------------------------------------------------------

typedef struct no *No;
typedef struct no
	{
    char    ch;         //caracter
    int     freq,       //frequencia do caracter
            codigo,     //codificacao do caracter
            tam;        //tamanho do codigo
    No      prox,       //ponteiro p/ o proximo da lita
            dir,        //ponteiro p/ direita na arvore
            esq;        //ponteiro p/ esquerda na arvore
    }NO;

//V A R I A V E I S   G L O B A I S -----------------------------------------

char nome_entrada[80], nome_saida[80], nome_aux[80];
int tam_arq=0,          //qtde de caracteres no arquivo
    freq_caracter[TAM_ARRAY], //frequencia dos bytes (caracateres)
    cont_elem=0;        //qtde de elementos na lista =
                        //qtde de folhas na arvore =
                        //qtde de caracteres diferentes
FILE *arq_entrada, *arq_saida; //ponteiro para o arquivo de entrada e saida
No Tree;                //topo da arvore de codificacao


//P R O T O T I P O S -------------------------------------------------------

void Compactacao();                                                 //contem funcoes para compactcao
void Inicializar_array_zero(int *Array);                            //inicializa array com zeros
void Freq_caracteres(FILE* File_in, int *Array);                    //encontra as freq. dos caracteres num arquivo
void Cria_lista_ordenada(No *Lista, int *Array);                    //cria uma lista ordenada pelas freq. utilizando dados do array
void Criar_arvore_codificacao(No *Lista);                           //cria a arvore de codificacao atravez da lista
void Insere_lista_ordenada(No *Lista, No *Elem);                    //utilizada para inserir novo noh na lista ordenada
No Extrair_menor(No *Lista);                                        //devolve menor noh da lista em relac. a freq.
void Criar_codigo(No *Raiz, int Cod_parcial, int Tam);              //grava nas folhas da arvore o codigo do caracter
void Criar_cabecalho_arquivo(FILE * File_out, No *Raiz);            //grava nome do arquivo e qtde de caracteres no arquivo
void Salvar_arvore(FILE *File_out, No *Raiz);                       //salva parcialmente arvore de codif. no arquivo
void Compactar_arquivo(FILE *File_in, FILE *File_out, No *Raiz);    //funcao para compactar o arquivo
No Busca_arvore(No *Raiz, char Ch);                                 //busca um noh na arvore em relac. ao caracter passado

void Descompactacao();                                              //contem funcoes para descompactacao
No Ler_arvore_arquivo(FILE *File_in);                               //recupera arvore de codif. gravado no arquivo
void Descompactar_arquivo(FILE *File_in, FILE *File_out, No *Raiz); //funcao para descompactar o arquivo
No Criar_no_arvore(char Ch);                                        //aloca memoria para um noh da arvore

void Limpar_variaveis_globais();                                    //limpa os dados das variaveis globais
void Excluir_arvore_codificacao(No *Raiz);                          //exclui a arvore de codificacao

//---------------------------------------------------------------------------

void Compactacao()
{
strcpy(nome_entrada,Form1->odCompactar->FileName.c_str()); // entra com nome do arquivo pra compactar
if((arq_entrada=fopen(nome_entrada, "rb"))==NULL) //verifica erro na abertura do arquivo
    {
    ShowMessage("Erro na abertura de arquivo de entrada!");
    exit(1);
    }
Inicializar_array_zero(freq_caracter);
Freq_caracteres(arq_entrada, freq_caracter); //verifica frequencia de carac. no arquivo
Cria_lista_ordenada(&Tree, freq_caracter); //cria lista ordenada pela freq. usando o array de freq.
Criar_arvore_codificacao(&Tree); //cria arvore de codif. atravez da lista ordenada
Criar_codigo(&Tree, 0, 0); //gera e grava o codigo de codif. nas folhas da arvore
strcpy(nome_aux, nome_entrada);
strcat(nome_aux, ".huf");
strcpy(nome_saida,Form1->sdCompactar->FileName.c_str()); //entra com nome do arquivo compactado
strcat(nome_saida, ".huf");
if(!strcmp(nome_saida, ".huf")) // se nao entrar com nome, usar mesmo nome do arq. original + ".huf"
    strcpy(nome_saida, nome_aux);
if((arq_saida=fopen(nome_saida, "w+b"))==NULL) //verifica erro na abertura do arquivo
    {
    ShowMessage("Erro na abertura de arquivo de saida!");
    exit(1);
    }
Criar_cabecalho_arquivo(arq_saida, &Tree); //grava nome original mais qtde de caract. no arquivo
Compactar_arquivo(arq_entrada, arq_saida, &Tree); //funcao q compacta arquivo
fflush(arq_saida);
ShowMessage("Arquivo compactado com sucesso!!!");
}

//---------------------------------------------------------------------------

void Inicializar_array_zero(int *Array)
{
int i=0;
for(i; i<TAM_ARRAY; i++) //inicializa com zero em todas as posicoes no array
	Array[i]=0;
}

//---------------------------------------------------------------------------

void Freq_caracteres(FILE* File_in, int *Array)
{
char ch;
ch=getc(File_in); //le um caracter
while(ch!=EOF) //enquanto nao chegar no final do arquivo
	{
    tam_arq++; //incrementa o contador de caracteres
    Array[(int)ch]++; //acrescenta a freq. do caracter correspondente no array
    ch=getc(File_in); //le proximo caracter
    }
}

//---------------------------------------------------------------------------

void Cria_lista_ordenada(No *Lista, int *Array)
{
int i=0;
for(i; i<TAM_ARRAY; i++)
	if(Array[i]!=0) //verifica quais caracteres existentes no arquivo
    	{
        No p;
        p=(No)malloc(sizeof(NO)); //e cria um noh pro respectivo
        if(p==NULL)
        	{
            ShowMessage("Erro na alocacao!");
            exit(1);
        	}
        cont_elem++; //coloca as informacoes na no novo noh criado
        ch(p)=char(i);
        freq(p)=Array[i];
        prox(p)=dir(p)=esq(p)=NULL;
        Insere_lista_ordenada(Lista, &p); //e insere na lista ordenado pela freq.
        }
}

//---------------------------------------------------------------------------

void Criar_arvore_codificacao(No *Lista) //utilizar o metodo de Huffman
{
int i;
No z=NULL, x=NULL, y=NULL;
for(i=1; i<cont_elem; i++)
    {
    z=(No)malloc(sizeof(NO)); //criar novo noh na arvore
    if(z==NULL)
        {
        ShowMessage("Erro na alocacao!");
        exit(1);
        }
    x=Extrair_menor(&Tree); //devolve menor noh da lista
    y=Extrair_menor(&Tree); //devolve proximo menor da lista
    ch(z)=(char)MIL;              //MIL serve pra identif. q nao eh folha (noh auxiliar)
    freq(z)=freq(x)+freq(y);//freq. do noh criado eh a soma dos dois menores (filhos)
    esq(z)=x;               //esquerda do noh recebe menor elemento da lista
    dir(z)=y;               //direita do noh recebe o seg. menor da lista
    prox(z)=NULL;           //na arvore nao usa ponteiro pra proximo
    Insere_lista_ordenada(&Tree, &z);   //insere noh criado na lista ordenada pela freq.
    }
}

//---------------------------------------------------------------------------

No Extrair_menor(No *Lista)
{
No p=NULL;
p=*Lista;
if(p!=NULL) //se lista nao estiver vazia
    {
    *Lista=prox(p);
    prox(p)=NULL;
    }
else // lista vazia
    {
    ShowMessage("Erro na extracao da lista. Lista vazia!");
    exit(1);
    }
return(p); //retorna o ponteiro para o primeiro noh da lista, q eh o menor em freq.
}

//---------------------------------------------------------------------------

void Insere_lista_ordenada(No *Lista, No *Elem)
{
No q=NULL, r=NULL;
for(r=*Lista; r!=NULL && freq((*Elem))>freq(r); r=prox(r)) //no fim do
    q=r; //loop 'r' apontara para o proximo noh com freq. > q '*Elem' e 'q'
if(q==NULL) //aponta p/ o noh com freq. ligeiramente menor que '*Elem'
    { // se for inserir no começo
    if(*Lista==NULL) //se a lista estiver fazia
        *Lista=*Elem;
    else //se ja existir elementos
        {
        prox((*Elem))=*Lista;
        *Lista=*Elem;
        }
    }
else //se for inserir no meio ou no final da lista
    {
    prox((*Elem))=prox(q);
    prox(q)=*Elem;
    }
}

//---------------------------------------------------------------------------

void Criar_codigo(No *Raiz, int Cod_parcial, int Tam)
{
if( esq((*Raiz))==NULL && dir((*Raiz))==NULL ) // se for noh folha
    {
    codigo((*Raiz))=Cod_parcial; //gravar no noh folha o codigo
    tam((*Raiz))=Tam; //grava no noh folha tamanho do codigo
    }
else
    {
    Tam++;
    Criar_codigo(&esq((*Raiz)), Cod_parcial<<1, Tam);       //p/ esquerda o codigo recebe '0' no final
    Criar_codigo(&dir((*Raiz)), (Cod_parcial<<1)|1, Tam);   //p/ direita o codigo recebe '1' no final
    }
}

//---------------------------------------------------------------------------

void Criar_cabecalho_arquivo(FILE * File_out, No *Raiz)
{
if((*Raiz)==NULL) //se a arvore estiver vazia
    {
    ShowMessage("Arvore de codificacao inexistente!");
    exit(1);
    }
//fprintf(File_out, "%s", nome_entrada);     //grava nome do arquivo
fwrite(&tam_arq, sizeof(int), 1, File_out); //grava qtde de caracter do arquivo
Salvar_arvore(File_out, Raiz);              //grava parcialmente arvore em arquivo
}

//---------------------------------------------------------------------------

void Salvar_arvore(FILE *File_out, No *Raiz)
{
int int_ch;
if(esq((*Raiz))==NULL) //se eh folha da arvore... obs:dir((*Raiz)) tbm eh NULL
    {
    int_ch=(int)ch((*Raiz));
    fwrite(&int_ch, sizeof(int), 1, File_out); //salva o caracter no formato 'int'
    }
else
    {
    int_ch=MIL; //identifica no nao folha com numero 1000
    fwrite(&int_ch, sizeof(int), 1, File_out); //salva o caracter
    Salvar_arvore(File_out, &esq((*Raiz))); //recursao para a esquerda
    Salvar_arvore(File_out, &dir((*Raiz))); //recursao para a direita
    }
}

//---------------------------------------------------------------------------

void Compactar_arquivo(FILE *File_in, FILE *File_out, No *Raiz)
{
No p; //no auxiliar
char ch_entrada, ch_saida;
int i, tamanho_bit=0, cod=0, cod_aux=0;
fseek(File_in, 0, 0);
do
    {
    i=8;//inicia como tamanho do byte
    while(i>0 && (ch_entrada!=EOF)) //enquanto ainda cabe no byte e nao eh fim de arquivo
        {
        if(tamanho_bit==0)//naum tem mais bits para serem colocados
            {
            ch_entrada=getc(File_in);
            p=Busca_arvore(&Tree, ch_entrada);//o nome da função jah diz oq faz
            if(p)
                {
                tamanho_bit=tam(p);//tamanho_bit tamanho variavel do codigo
                cod=codigo(p);// codigo binario do caracter
                }
            }
        //colocando no arquivo........
        if(tamanho_bit<=i)// cabe inteiro- coloca tudo
            {
            ch_saida <<= tamanho_bit; //desloca ch_saida tamanho_bit vezes,
            ch_saida |= cod;   // ou lógico, na verdade eh o q coloca o cod em ch_saida
            i-=tamanho_bit; //descrementa o i, pois usou um bit
            tamanho_bit=0; //limpa tamanho_bit para o proximo
            }
        else  //senaum coloca oq cabe no byte
            {
            ch_saida <<= i;// desloca ch_saida I vezes, para colocar oq dah, ou seja limpa o byte
            // dah pra usar a função reset de C++
            cod_aux=(cod>>(tamanho_bit-i));//cod_aux recebe oq vai dar pra colocar no byte
            ch_saida |= cod_aux;//atribuindo cod_aux com OU
            cod_aux <<= (tamanho_bit-i);//desloca oq colocou
            cod ^= cod_aux; //coloca em cos oq sobrou em cod_aux
            tamanho_bit-=i; //decrementa oq colocou
            i=0;
            }
        }
    if(ch_entrada==EOF)
        for(; i>0; i--)
            ch_saida <<= 1;
    putc(ch_saida,File_out);
    }while(ch_entrada!=EOF);
}

//---------------------------------------------------------------------------

No Busca_arvore(No *Raiz, char Ch)
{
if(esq((*Raiz))==NULL) //se for noh folha
    if(ch((*Raiz))==Ch) //e se for o noh procurado
        return ((*Raiz)); //retorna o ponteiro pra ele
    else
        return NULL;
else
    {
    No p=NULL;
    if((p=Busca_arvore(&esq((*Raiz)), Ch))!=NULL) //recursao pra esquerda
        return p;
    else
        return (Busca_arvore(&dir((*Raiz)), Ch)); //recursao pra direita
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void Descompactacao()
{
strcpy(nome_entrada,Form1->odDescompactar->FileName.c_str()); //entra com nome do arquivo compactado
if((arq_entrada=fopen(nome_entrada, "rb"))==NULL) //verifica erro na abertura do arquivo
    {
    ShowMessage("Erro na abertura de arquivo de entrada!");
    exit(1);
    }
//fscanf(arq_entrada, "%s", nome_aux); //le nome do arquivo
fread(&tam_arq, sizeof(int), 1, arq_entrada); //le qtde de caracter salvo no arquivo
Tree=Ler_arvore_arquivo(arq_entrada); //gera arvore atravez dos dados salvo no arquivo
strcpy(nome_aux, nome_entrada); //escolhe nome para arquivo descompactado. se nao inserir, sera o original
strcat(nome_aux, ".txt");
strcpy(nome_saida,Form1->sdDescompactar->FileName.c_str());
strcat(nome_saida, ".txt");
if(!strcmp(nome_saida, ".txt")) //se nao inserir
    strcpy(nome_saida, nome_aux); //copia do nome original salvo no arquivo
if((arq_saida=fopen(nome_saida, "w+b"))==NULL) //verifica erro na abertura do arquivo
    {
    ShowMessage("Erro na abertura de arquivo de saida!");
    exit(1);
    }
Descompactar_arquivo(arq_entrada, arq_saida, &Tree); //funcao pra descompactar arquivo
fflush(arq_saida);
ShowMessage("Arquivo descompactado com sucesso!!!");
}

//---------------------------------------------------------------------------

No Criar_no_arvore(char Ch)
{
No p=NULL;
p=(No)malloc(sizeof(NO)); //aloca memoria para o novo noh
if(p==NULL) //verifica erro na locacao de memoria
    {
    ShowMessage("Erro na alocacao!");
    exit(1);
    }
ch(p)=Ch; //insere os dados no novo noh
freq(p)=1;
codigo(p)=-1;
esq(p)=dir(p)=prox(p)=NULL;
return p; //retorna o ponteiro para o novo noh
}

//---------------------------------------------------------------------------

No Ler_arvore_arquivo(FILE *File_in)
{
int int_ch;
No p;
fread(&int_ch, sizeof(int), 1, File_in); //leh caracter da arvore salvo no arquivo
if(int_ch!=MIL) //se nao eh noh folha
    p=Criar_no_arvore((char)int_ch); //cria noh somente
else //se for noh folha
    {
    p=Criar_no_arvore(MIL); //cria o noh respectivo
    esq(p)=Ler_arvore_arquivo(File_in); //chama func. recursivo pra esquerda
    dir(p)=Ler_arvore_arquivo(File_in); //chama func. recursivo pra direita
    }
return(p); //retorna ponteiro pro noh criado
}

//---------------------------------------------------------------------------

void Descompactar_arquivo(FILE *File_in, FILE *File_out, No *Raiz)
{
int i, tam=0, bit;
char ch_entrada, ch_saida;
No p=*Raiz;

for(i=0; i<tam_arq; i++)
    {
    while(dir(p)!=NULL && esq(p)!=NULL)// enquento não eh folha,
                                       //pois os caracteres estao nas folhas
        {
        if(!tam)//se ja leu tudo, leia outro
            {
            ch_entrada=getc(File_in);
            tam=8;
            }
        bit=(ch_entrada&128);//fazendo E logico com 128 ou 1000 0000, para colocar apenas o primeiro bit em bit
        ch_entrada <<= 1;// desloca ch_entrada em 1 bit para esquerda, pois jah colocou um bit em bit
        tam--; // decrementa pq jah leu um bit
        if(bit)
            p=dir(p); // se eh 1
        else
            p= esq(p); // se eh zero
        }  // no final vai achar o caracter correspondente n arvore q jah foi construida
    putc(ch(p), File_out);
    p=*Raiz;
    }
}

//---------------------------------------------------------------------------

void Limpar_variaveis_globais()
{
int i;
for(i=0; i<80; i++)
    {
    nome_entrada[i]=NULL;
    nome_saida[i]=NULL;
    nome_aux[i]=NULL;
    }
tam_arq=0;
cont_elem=0;
arq_entrada=NULL;
arq_saida=NULL;
Excluir_arvore_codificacao(&Tree);
}

//---------------------------------------------------------------------------

void Excluir_arvore_codificacao(No *Raiz)
{
if((*Raiz)==NULL)
    return;
else
    {
    Excluir_arvore_codificacao(&esq((*Raiz)));
    Excluir_arvore_codificacao(&dir((*Raiz)));
    free((*Raiz));
    }
}

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
Close();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
edtEntrada->Text = "";
edtSaida->Text ="";
if(rbCompactar->Checked == true) //compactar arquivo
    {
    if(odCompactar->Execute())
        edtEntrada->Text = odCompactar->FileName;
    if(MessageBox(Handle,"Compactar arquivo?","Confirmar arquivo", MB_YESNO) == IDYES)
        {
        if(sdCompactar->Execute())
            edtSaida->Text = sdCompactar->FileName;
        Compactacao(); //chama funcao de compacatacao
        Limpar_variaveis_globais();
        }
    }
if(rbDescompactar->Checked == true) //descompactar arquivo
    {
    if(odDescompactar->Execute())
        {
        edtEntrada->Text = odDescompactar->FileName;
        }
    if(MessageBox(Handle,"Descompactar arquivo?","Confirmar arquivo", MB_YESNO) == IDYES)
        {
        if(sdDescompactar->Execute())
            edtSaida->Text = sdDescompactar->FileName;
        Descompactacao(); //chama funcao de descompactacao
        Limpar_variaveis_globais();
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Program1Click(TObject *Sender)
{
Form2->Show();    
}
//---------------------------------------------------------------------------

