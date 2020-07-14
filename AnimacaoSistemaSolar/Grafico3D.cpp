#include "Grafico3D.h"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

_3D_Point::_3D_Point(float x, float y, float z)
{
    set_3D_Point(x,y,z);
}

void _3D_Point::set_3D_Point(float x, float y, float z)
{
    vetor[0] = x;
    vetor[1] = y;
    vetor[2] = z;
    vetor[3] = 1.0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Transformacao3D::translacao(float dx, float dy, float dz)
{
    Matrix_Ordem_4 translacao;
    translacao.identidade_ini();
    translacao.set_Matrix(0,3,dx);
    translacao.set_Matrix(1,3,dy);
    translacao.set_Matrix(2,3,dz);
    transformacao = transformacao * translacao;
}

//------------------------------------------------------------------------------

void Transformacao3D::rotacao(float angulo, float eixoX, float eixoY, float eixoZ)
{
    Matrix_Ordem_4 rotacao;
    float c, s, ang;

    ang = DegreesToRads(angulo);
    c = cos(ang);
    s = sin(ang);

    cout<<"\nValor do Coseno: "<<c<<endl;
    cout<<"\nPosicao [0][0] da matriz: "<<(c+(1-c)*pow(eixoX,2))<<endl<<endl;

    rotacao.identidade_ini();
    rotacao.set_Matrix(0,0,(c+(1-c)*pow(eixoX,2)));
    rotacao.set_Matrix(1,0,((1-c)*(eixoX*eixoY)+(s*eixoZ)));
    rotacao.set_Matrix(2,0,((1-c)*(eixoX*eixoZ)-(s*eixoY)));

    rotacao.set_Matrix(0,1,((1-c)*(eixoX*eixoY)-(s*eixoZ)));
    rotacao.set_Matrix(1,1,(c+(1-c)*pow(eixoY,2)));
    rotacao.set_Matrix(2,1,((1-c)*(eixoY*eixoZ)+(s*eixoX)));

    rotacao.set_Matrix(0,2,((1-c)*(eixoX*eixoZ)+(s*eixoY)));
    rotacao.set_Matrix(1,2,((1-c)*(eixoY*eixoZ)-(s*eixoX)));
    rotacao.set_Matrix(2,2,(c+(1-c)*pow(eixoZ,2)));

    transformacao = transformacao * rotacao;
}

//------------------------------------------------------------------------------

void Transformacao3D::escala(float sx, float sy, float sz)
{
    Matrix_Ordem_4 escala;

    escala.identidade_ini();

    escala.set_Matrix(0,0,sx);
    escala.set_Matrix(1,1,sy);
    escala.set_Matrix(2,2,sz);

    transformacao = transformacao * escala;
}

//------------------------------------------------------------------------------

void Transformacao3D::transformaPonto(_3D_Point &ponto)
{
    _3D_Point temp;
    for(int i=0;i<4;i++)
    {
     for(int j=0;j<4;j++)
     {
      temp.vetor[i]+= (transformacao.get_Matrix(i,j) * ponto.getPonto(j));
     }
 }
 ponto = temp;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Projecao3D::setOrtogonalParalela()
{

    projecao.set_Matrix(0,0,1.0);
    projecao.set_Matrix(1,0,0.0);
    projecao.set_Matrix(2,0,0.0);
    projecao.set_Matrix(3,0,0.0);

    projecao.set_Matrix(0,1,0.0);
    projecao.set_Matrix(1,1,1.0);
    projecao.set_Matrix(2,1,0.0);
    projecao.set_Matrix(3,1,0.0);

    projecao.set_Matrix(0,2,0.0);
    projecao.set_Matrix(1,2,0.0);
    projecao.set_Matrix(2,2,0.0);
    projecao.set_Matrix(3,2,0.0);

    projecao.set_Matrix(0,3,0.0);
    projecao.set_Matrix(1,3,0.0);
    projecao.set_Matrix(2,3,0.0);
    projecao.set_Matrix(3,3,1.0);
}

void Projecao3D::projetaPonto(_3D_Point &ponto)
{

    _3D_Point temp;
    for(int i=0;i<4;i++)
    {
     for(int j=0;j<4;j++)
      {
       temp.vetor[i]+= (projecao.get_Matrix(j,i) * ponto.getPonto(j));
      }
    }
  ponto = temp;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Z_Buffer::zera()
{
    for(int i(0); i < MAX_TAM_Y; i++)
     for(int j(0); j < MAX_TAM_X; j++)
     {
      buff[i][j] = 100000;
     }
}

//------------------------------------------------------------------------------

bool Z_Buffer::check_depth(float Z, int x, int y)
{
    if((Z-buff[y][x])<0)
    {
      buff[y][x] = Z;
      return true;
    }
    else
    {
      return false;
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Grafico3D::figura_DesenhaPonto(_3D_Point p)
{
    float largura = Principal->imgGrafico->Width/2;
    float altura = Principal->imgGrafico->Height/2;
    transforma_3D_Point(p);
    projeta_3D_Point(p);

    int x = (int)(p.getX()+largura);
    int y = (int)(altura-p.getY());

    if((x >=0) && (x<447) && (y>=0) && (y<463))
    if(z_buffer.check_depth(p.getZ(),x,y))
    {
     Principal->imgGrafico->Canvas->Pixels[(int)(p.getX()+largura)][(int)(altura-p.getY())] = this->cor;
    }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_DesenhaLinha(_3D_Point p1, _3D_Point p2)
{
    float largura = Principal->imgGrafico->Width/2;
    float altura = Principal->imgGrafico->Height/2;

    transforma_3D_Point(p1);
    transforma_3D_Point(p2);

    projeta_3D_Point(p1);
    projeta_3D_Point(p2);

    Principal->imgGrafico->Canvas->MoveTo((int)(p1.getX()+largura), (int)(altura-p1.getY()));
    Principal->imgGrafico->Canvas->LineTo((int)(p2.getX()+largura), (int)(altura-p2.getY()));
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Cubo(int fator)
{

   float incPonto = 0.7;

    for(float i = -fator; i< fator; i+=incPonto)
        for(float j = -fator; j< fator; j+=incPonto)
        {
          figura_DesenhaPonto(_3D_Point(i,j,-fator));
          figura_DesenhaPonto(_3D_Point(i,j,fator));

          figura_DesenhaPonto(_3D_Point(i,fator,j));
          figura_DesenhaPonto(_3D_Point(i,-fator,j));

          figura_DesenhaPonto(_3D_Point(fator,i,j));
          figura_DesenhaPonto(_3D_Point(-fator,i,j));
        }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Esfera(float raio)
{
    float fator = 2;
    float x, y, z;
    float alfa = 0.0, beta = 0.0;

    fator = DegreesToRads(fator);

    for(alfa = 0.0; alfa < _2PI; alfa+= fator)
    {
     for(beta = 0.0; beta < _2PI; beta+=fator)
      {
        x = raio*cos(alfa)*cos(beta);
        y = raio*cos(alfa)*sin(beta);
        z = raio*sin(alfa);

        figura_DesenhaPonto(_3D_Point(x,y,z));
        }
    }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Cilindro(float altura, float raio)
{
    float angIncremento = DegreesToRads(0.5);
    float incAltura = 0.1;
    float x, y, z;
    float alfa = 0.0;

    for(float i=-(altura/2); i<altura/2; i+=incAltura)
    {
     for(alfa=0.0; alfa < _2PI; alfa+=angIncremento)
      {
        x = raio*cos(alfa);
        y = raio*sin(alfa);
        z = i;
        figura_DesenhaPonto(_3D_Point(x,y,z));
      }
    }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Cone(float altura)
{
    float angIncremento = DegreesToRads(2);
    float incAltura = 0.1;
    float x, y, z;
    float alfa = 0.0;

    for(float i(0) ; i<altura ; i += incAltura)
    {
        for(alfa=0.0; alfa < _2PI; alfa+=angIncremento)
        {
            x = i*cos(alfa);
            y = i*sin(alfa);
            z = i;

            figura_DesenhaPonto(_3D_Point(x,y,z));
        }
    }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Plano(float xmin, float xmax, float ymin, float ymax)
{
    float x(0.0),y(0.0),z(0.0);
    float incX=0.3;
    float incY=0.3;

    for(x=xmin; x<xmax; x += incX)
    {
      for(y=ymin; y<ymax; y += incY)
      {
        z = ((3*x)-(2*y)+5);
        figura_DesenhaPonto(_3D_Point(x,y,z));
      }
    }
}

//------------------------------------------------------------------------------

void Grafico3D::figura_Superficie(float xmin, float xmax, float ymin, float ymax)
{
    float x(0.0),y(0.0),z(0.0);
    float incX=0.1;
    float incY=0.1;

    for(x=xmin;x<xmax;x+=incX)
    {
     for(y=ymin; y<ymax;y+=incY)
     {
       z = pow(x,2)+y;
       figura_DesenhaPonto(_3D_Point(x,y,z));
     }
    }
}

//------------------------------------------------------------------------------
//-----------------------------------------------------------------

Matrix_Ordem_4 Matrix_Ordem_4::operator * (const float cte)const
{
   int lin(0),col(0);
   Matrix_Ordem_4 objeto2;
   for(lin=0;lin<ORD;lin++)
   for(col=0;col<ORD;col++)
   {
    objeto2.matriz[lin][col]=(get_Matrix(lin,col)*cte);
   }
   return(objeto2);
}

//-----------------------------------------------------------------------

Matrix_Ordem_4 Matrix_Ordem_4::operator *(const Matrix_Ordem_4 &B)const
{
   int i(0), lin(0), col(0);
   float soma(0);
   Matrix_Ordem_4 temp;
   for(lin=0;lin<ORD;lin++)
   {
     for(col=0;col<ORD;col++)
     {
         soma=0;
         for(i=0; i<ORD; i++)
         {
             soma+=this->matriz[lin][i]*B.matriz[i][col];
         }
         temp.matriz[lin][col]=soma;
     }
   }

  return(temp);
}
//----------------------------------------------------------------------

bool  Matrix_Ordem_4::operator ==(const  Matrix_Ordem_4 &B) const
{
   int linha(0),coluna(0);

   for(linha=0;linha<ORD;linha++)
   for(coluna=0;coluna<ORD;coluna++)
   {
       if(B.get_Matrix(linha, coluna)!=this->get_Matrix(linha,coluna))//repare pra prova
       return(false);
   }
   return(true);
}

//---------------------------------------------------------------------------

float Matrix_Ordem_4::determinante4x4()const
{
   int coluna(0),sinal(0);
   float det(0);
   for(coluna=0;coluna<ORD;coluna++)
   {
       if((coluna%2)==1)sinal=1;
       else sinal=-1;
       det+=get_Matrix(1,coluna)*determinante3x3(1,coluna)*sinal;//NOTE QUE EH UMA
   }                                                            //FUNCAO PRIVATE
   return(det);
}

//----------------------------------------------------------------------

float   Matrix_Ordem_4::determinante3x3(int NaoContaLinha, int NaoContaColuna)const
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
               M[L2][C2]=this->get_Matrix(L1,C1);//REPARAR NA CHAMADA
       }
   }
   resp+=M[0][0]*M[1][1]*M[2][2]  +  M[0][1]*M[1][2]*M[2][0]  +  M[0][2]*M[1][0]*M[2][1];
   resp-=M[0][2]*M[1][1]*M[2][0]  +  M[0][0]*M[1][2]*M[2][1]  +  M[0][1]*M[1][0]*M[2][2];
   return(resp);
}

Matrix_Ordem_4::Matrix_Ordem_4()
{
   int i, j;
   for(i=0;i<ORD;i++)
    for(j=0;j<ORD;j++)
     set_Matrix(i, j,0.0);
}
//--------------------------------------------------------------------

void Matrix_Ordem_4::identidade_ini()
{
   int i(0),UM(1);
   Matrix_Ordem_4 temp;
   (*this)=temp;
   for(i=0;i<ORD;i++)
   {
   set_Matrix(i,i,UM);
   }
   return;
}
//---------------------------------------------------------------------

float Matrix_Ordem_4::get_Matrix(int i, int j) const
{
   return(matriz[i][j]);
}
//-----------------------------------------------------------------------

Matrix_Ordem_4 &Matrix_Ordem_4::get_Matrix()
{
    return *this;
}
//-----------------------------------------------------------------------

void  Matrix_Ordem_4::set_Matrix(int i, int j,float valor)
{
   this->matriz[i][j]=valor;
   return;
}

//------------------------------------------------------------------------------
