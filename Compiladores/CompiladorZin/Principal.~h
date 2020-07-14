//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
#include <fstream>
#include <sstream>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>


#define id                      32
#define num                     33
#define literal                 34

#define TAM_BLOCO               1024
#define TAM_TABELA_SIMBOLO      300
#define MAX                     30

//---------------------------------------------------------------------------
class TFormPrincipal : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *Menu1;
        TMenuItem *Arquivo;
        TMenuItem *Abrir1;
        TMenuItem *Fechar1;
        TMenuItem *Sair1;
        TMenuItem *Anlise1;
        TMenuItem *Lexica1;
        TMenuItem *Sintatica1;
        TGroupBox *pnl_Texto;
        TGroupBox *pnl_Buffer;
        TGroupBox *pnl_Tabela_Simbolo;
        TGroupBox *pnl_Propriedades;
        TGroupBox *pnl_Lista_Gerada;
        TRichEdit *Texto;
        TRichEdit *Rich_buffer1;
        TRichEdit *Rich_buffer2;
        TLabel *Label1;
        TLabel *Label2;
        TRichEdit *Rich_Tabela_Simbolo;
        TStringGrid *strgrd_Lista_Gerada;
        TStringGrid *Mensagens;
        TLabeledEdit *lbledt_Lexema;
        TLabeledEdit *lbledt_Pos_Tabela;
        TLabeledEdit *lbledt_Token;
        TOpenDialog *OpenDialog;
        TMenuItem *Executar1;
        TMenuItem *NextToken1;
        TMenuItem *AnaliseSintatica;
        TMenuItem *Ajuda1;
        TMenuItem *SobreCompiladorZin1;
        TMenuItem *GuiaParaExecutarumarquivoPascal1;
        TMenuItem *AtualizarTabela;
    TLabel *Label3;
    TEdit *edt_Diretorio;
    void __fastcall Abrir1Click(TObject *Sender);
    void __fastcall Fechar1Click(TObject *Sender);
    void __fastcall tabela_de_simbolo();
    void __fastcall Sair1Click(TObject *Sender);
    void __fastcall AtualizarTabelaClick(TObject *Sender);
    void __fastcall NextToken1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AnaliseSintaticaClick(TObject *Sender);
        void __fastcall Lexica1Click(TObject *Sender);
        void __fastcall Sintatica1Click(TObject *Sender);
        void __fastcall GuiaParaExecutarumarquivoPascal1Click(
          TObject *Sender);
        void __fastcall SobreCompiladorZin1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------

/*****************************************************************************/

typedef struct no                *No;
typedef struct abb               *Abb;
typedef struct lista_token       *Lista_Token;
typedef struct registro_tab_simb *Registro_Tab_Simb;

/*****************************************************************************/


typedef struct no {
	char *palavra;
    char *token;
	No prox,ante;
	} NO;


typedef struct abb
	 {
      int  tipo;
	  char palavra[MAX];
	  Abb  esq, dir;
	 }ABB;


typedef struct lista_token
	 {
	  char tipo[MAX];
	 }LISTA_TOKEN;

typedef struct registro_tab_simb
 {
      Abb arvore;
 }REGISTRO_TAB_SIMB;

typedef struct listadevar *Listadevar;
typedef struct listadevar
	 {
	  char *ident;
          Listadevar prox,ante;
	 } LISTADEVAR;


No   ini = NULL,
     ult = NULL;

REGISTRO_TAB_SIMB   vetor[TAM_TABELA_SIMBOLO];
LISTA_TOKEN         tokens[300];
int                 auxiliarstring=0, Pos_Tabela_de_Simbolo, aux1;
int                 lin_1,lin_2,
                    tamArq, atual,
                    bufferpos=0,troca=-1;
char                letra,palavra[MAX];
char                *buffer_1,*buffer_2;
int                 posgeral=0,linhageral=0, LinhaMsg = 1;

AnsiString msgs = "";
char errolog[5000];
int  erros=0;


#endif
