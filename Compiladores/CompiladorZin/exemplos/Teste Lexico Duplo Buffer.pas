program testeAL;

var x:string;
    i:integer;

{ Isto estah ERRADO}
34t
14.r
34.4b
4e*5
10E-9l

BeGiN { O analisador NAO eh sensivel ao caso... }
   x:='Teste AL.'; (* O que estah entre as aspas serah ignorado. *)
   i:=0;
   
   { Testando uma estrutura de repeticao... }
   for i := 1 to 200 do
   begin
      { Testando uma estrutura de selecao }
      if(x<>'TESTE AL!') then
         i:=i+45
      else 
         i:=i+1;
      
      { Write Reservada }
      write( 'Teste do analisador lexico!' );
   end;
   
   (* Teste do repeat *)
   repeat
      write( 'jlojunion:' );
      i := i + 1;
      
      (* Teste do CASE *)
      case i of
         1: write( 'Isto faz nada...' );
         2: i := 0;
         0:
         begin
            i := 2000;
            writeln( 'O valor de i eh: ', i );
         end;
      end;
   until i > 1000;
   
   { Esse eh identificador }
   while ( i < 0 ) do
   begin
      x := 'LOL';
      write( const);
      i:=5000;
   end;   
{ Comentario de 1,
                2,
           	3 linhas com os delimitadores { e
}

(* Uma linha com varios espacos em branco *)
           identificador      :=  IDENTIFICADOR +	4 ;    

   x:='Teste AL.'; (* O que estah entre as aspas serah ignorado. *)
   i:=0;
   
   { Testando uma estrutura de repeticao... }
   for i := 1 to 200 do
   begin
      { Testando uma estrutura de selecao }
      if(x<>'TESTE AL!') then
         i:=i+45
      else 
         i:=i+1;
      
      { Write Reservada }
      write( 'Teste do analisador lexico!' );
   end;
   
   (* Teste do repeat *)
   repeat
      write( 'jlojunion:' );
      i := i + 1;
      
      (* Teste do CASE *)
      case i of
         1: write( 'Isto faz nada...' );
         2: i := 0;
         0:
         begin
            i := 2000;
            writeln( 'O valor de i eh: ', i );
         end;
      end;
   until i > 1000;
   
   { Esse eh identificador }
   while ( i < 0 ) do
   begin
      x := 'LOL';
      write( const);
      i:=5000;
   end;   

end. 
