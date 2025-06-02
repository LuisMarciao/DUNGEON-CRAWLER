#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declarando as variaveis globais
char jogador_char = '&';
char chave_char = '@';
char guarda_char = 'X';
char guarda2_char = 'V';
char porta_fecha = 'D';
char porta_aber = '=';
char arame_char = '#';
char botao_char = 'O';
char ventilacao_char = '>';

char tecla_pressionada;
int jogadorX = 1, jogadorY = 1;
int guardaX, guardaY;
int guarda2X, guarda2Y;
int tem_chave;
int chaveX, chaveY;
int tela = 0;
int coord_X, coord_Y;
int vidas;
int botao_pressionado;

// funçao para movimentar o jogador
void movimento_jogador(char tecla_pressionada, int limite)
{
    if (tecla_pressionada == 'q')
    {
        tela = 0;
        main();
    }
    if (tecla_pressionada == 'w' && jogadorX - 1 != 0 && jogadorX - 1 != limite)
    {
        jogadorX--;
    }
    if (tecla_pressionada == 's' && jogadorX + 1 != 0 && jogadorX + 1 != limite)
    {
        jogadorX++;
    }
    if (tecla_pressionada == 'a' && jogadorY - 1 != 0 && jogadorY - 1 != limite)
    {
        jogadorY--;
    }
    if (tecla_pressionada == 'd' && jogadorY + 1 != 0 && jogadorY + 1 != limite)
    {
        jogadorY++;
    }
}
// funçao para criar as paredes do nivel
void paredes(int limiteX, int limiteY, char nivel[limiteX][limiteY])
{
    for (int x = 0; x < limiteX; x++)
    {
        for (int y = 0; y < limiteY; y++)
        {
            if (x == 0 || x == limiteX - 1 || y == 0 || y == limiteY - 1)
            {
                nivel[x][y] = '*';
            }
            else
            {
                nivel[x][y] = ' ';
            }
        }
    }
}
// funçao para imprimir o nivel
void printar_nivel(int limiteX, int limiteY, char nivel[limiteX][limiteY])
{
    for (coord_X = 0; coord_X < limiteX; coord_X++)
    {
        for (coord_Y = 0; coord_Y < limiteY; coord_Y++)
        {
            printf(" %c", nivel[coord_X][coord_Y]);
        }
        printf("\n");
    }
}
// funçao para verificar se o jogador foi pego pelo guarda ou se ele caiu no arame farpado
void gameover(char nivel[20][20]) 
{
    if (nivel[jogadorX][jogadorY] == arame_char || jogadorX == guardaX && jogadorY == guardaY) {
        system("cls");
        jogadorY = 1;
        jogadorX = 1;
        tem_chave = 0;
        vidas--;
        // Se o jogador perder todas as vidas, exibe uma mensagem de game over
        // e reinicia o jogo
        if (vidas == 0) {
            printf(
                "Voce foi pego 3 vezes tentando fugir e foi jogado na solitaria\n"
                "Talvez em outro momento voce consiga fugir...\n"
                "\n"
            );
            system("pause");
            
            tela = 0;
            main();
        }
        printf("Voce foi pego! Tentativas restantes: (%d)\n\n", vidas);

        system("pause");
        
    }
}
// funçao para verificar se o jogador foi pego pelo guarda ou se ele caiu no arame farpado no segundo nivel porem com mensagens diferentes
void gameover2(char nivel[40][40])
{
	if (nivel[jogadorX][jogadorY] == arame_char || jogadorX == guardaX && jogadorY == guardaY) {
        system("cls");
        jogadorY = 1;
        jogadorX = 1;
        tem_chave = 0;
        vidas--;
        // Se o jogador perder todas as vidas, exibe uma mensagem de game over
        if (vidas == 0) {
            printf(
                "Dessa vez foi quase, Ze do crime...\n"
                "Voce foi pego 3 vezes tentando fugir e foi jogado na solitaria\n"
                "Talvez em outro momento voce consiga fugir...\n"
                "\n"
            );
            system("pause");
            tela = 0;
            main();
        }
        printf("Voce foi pego! Tentativas restantes: (%d)\n\n", vidas);

        system("pause");
        
    }
}
// funçao principal que inicia o jogo
int main()
{
    vidas = 3;
    srand(time(NULL));

    int opcao;

    int guard_move;

    char nivel1[10][10];

    char nivel2[20][20];
    
    char nivel3[40][40];
    jogadorX = 1;
    jogadorY = 1;
    chaveX = 5;
    chaveY = 5;
    tem_chave = 0;
    
    paredes(10, 10, nivel1);
    paredes(20, 20, nivel2);
    paredes(40, 40, nivel3);
    // inicializa o menu do jogo
    while (tela == 0)
    {
        system("cls");
        printf("||||BRAZIL DUNGEON||||\n\n");
	    printf("   1- Jogar\n\n\n   2- Tutorial\n\n\n   3- Sair\n\n\n");
        opcao = getch();

        if (opcao == '1')
        {
            system("cls");

            printf("Ze do crime foi jogado no presidio de Carandiru para pagar pelo o que fez\n");
            sleep(1);
            printf("Em uma madrugada silenciosa, o Ze do crime tentou escapar de carandiru\n\n\n");

            system("pause");
            tela = 1;
            system("cls");
        }
        else if (opcao == '2')
        {
            system("cls");
            printf(
                "Passe por tres setores do presidio coletando 3 chaves e evitando os guardas para conseguir sua liberdade.\n\n"
                "Em cada nivel, voce precisa se mover para coletar uma chave e abrir uma porta fechada.\n\n"
                "Para completar sua fuga, veja esses comandos e elementos do cenario:\n\n\n"
                "W: Mova uma unidade para cima\n\n"
                "A: Mova uma unidade para esquerda\n\n"
                "S: Mova uma unidade para baixo\n\n"
                "D: Mova uma unidade para direita\n\n"
                "I: Interage com um objeto\n\n"
				"@: Chave da porta\n\n"
				"X: Guarda nivel 1\n\n"
				"V: Guarda nivel 2\n\n"
				"&: Ze do crime\n\n"
				"#: Arame farpado\n\n"
				">: Tubo de ventilacao\n\n"
				"O: Botao\n\n"
				"D: Porta fechada\n\n"
				"=: Porta aberta\n\n");
            system("pause");
        }
        else if (opcao == '3')
        {
            system("cls");
            printf("Voce nao tem a coragem necessaria para fugir ne?");
            return 0;
        }
        else
        {
            printf("Coloque uma opcao valida!\n");
            system("pause");
        }
    }

    // primeiro nivel do jogo
    while (tela == 1)
    {
        guardaX = 6;
        guardaY = 6;
        chaveX = 5;
        chaveY = 5;
        // movimenta o guarda aleatoriamente
        guard_move = rand() % 4;
        if (guard_move == 0 && guardaX - 1 != 0 && guardaX - 1 != 9)
        {
            guardaX--;
        }
        if (guard_move == 1 && guardaX + 1 != 0 && guardaX + 1 != 9)
        {
            guardaX++;
        }
        if (guard_move == 2 && guardaY - 1 != 0 && guardaY - 1 != 9)
        {
            guardaY--;
        }
        if (guard_move == 3 && guardaY + 1 != 0 && guardaY + 1 != 9)
        {
            guardaY++;
        }

        nivel1[guardaX][guardaY] = guarda_char;
        if (tem_chave == 0)
        {
            nivel1[9][5] = porta_fecha;
            nivel1[chaveX][chaveY] = chave_char;
        }
        if (tem_chave == 1)
        {
            nivel1[9][5] = porta_aber;
            nivel1[chaveX][chaveY] = ' ';
        }

        nivel1[jogadorX][jogadorY] = jogador_char;
        printar_nivel(10, 10, nivel1);

        nivel1[jogadorX][jogadorY] = ' ';
        nivel1[guardaX][guardaY] = ' ';

        tecla_pressionada = getch();
        movimento_jogador(tecla_pressionada, 9);

        if (jogadorX == chaveX && jogadorY == chaveY && tecla_pressionada == 'i')
        {
            tem_chave = 1;
        }

        gameover(nivel1);

        // se o jogador chegar na porta com a chave, ele avança para o segundo nivel
        if (jogadorX == 8 && jogadorY == 5 && tem_chave == 1 && tecla_pressionada == 's')
        {
            tela = 2;
            system("cls");
            printf(
                "Ze do crime conseguiu sair de dentro de sua cela\n"
                "Agora ele tem que sair do patio de carandiru\n"
                "Porem vai precisar liberar a chave que esta cheia de arame farpado\n"
                "\n"
                "\n"
            );
            system("pause");
            jogadorX = 1, jogadorY = 1;
            tem_chave = 0;
        }
        system("cls");
    }
		jogadorX = 1;
		jogadorY = 1;
        guarda2X = 10;
        guarda2Y = 17;
        botao_pressionado = 0;
        tem_chave = 0;
        chaveX = 2;
        chaveY = 8;
        
    // segundo nivel do jogo 
    while (tela == 2)
    {   
        
        if (botao_pressionado == 0)
        {
            nivel2[chaveX-1][chaveY] = arame_char;
            nivel2[chaveX+1][chaveY] = arame_char;
            nivel2[chaveX][chaveY-1] = arame_char;
            nivel2[chaveX][chaveY+1] = arame_char;
            nivel2[12][12] = botao_char;
        }
        else
        {
            nivel2[chaveX-1][chaveY] = ' ';
            nivel2[chaveX+1][chaveY] = ' ';
            nivel2[chaveX][chaveY-1] = ' ';
            nivel2[chaveX][chaveY+1] = ' ';
        }
        if (tem_chave == 0)
        {
            nivel2[19][5] = porta_fecha;
            nivel2[chaveX][chaveY] = chave_char;
        }
        else
        {
            nivel2[19][5] = porta_aber;
        }

        // movimenta o guarda de acordo com a posiçao do jogador
        guard_move = rand() % 2;    
        if (guard_move == 0) 
        {
            if (jogadorY < guardaY && guardaY - 1 != 0) {
                guardaY--;
            } else if (jogadorY > guardaY && guardaY + 1 != 19) {
                guardaY++;
            }
        } 
        else 
        {
            if (jogadorX < guardaX && guardaX - 1 != 0) {
                guardaX--;
            } else if (jogadorX > guardaX && guardaX + 1 != 19) {
                guardaX++;
            }
        }

        
        nivel2[jogadorX][jogadorY] = jogador_char;
        nivel2[guardaX][guardaY] = guarda2_char;

        printar_nivel(20, 20, nivel2);

        if (jogadorX == 12 && jogadorY == 12)
        {
            botao_pressionado = 1;
        }

        nivel2[jogadorX][jogadorY] = ' ';
        nivel2[guardaX][guardaY] = ' ';
        tecla_pressionada = getch();

        if (jogadorX == chaveX && jogadorY == chaveY && tecla_pressionada == 'i')
        {
            tem_chave = 1;
            nivel2[19][5] = porta_aber;
        }
        // se o jogador chegar na porta com a chave, ele avança para o terceiro nivel
        if (jogadorX == 18 && jogadorY == 5 && tem_chave == 1 && tecla_pressionada == 's'){
            system("cls");
            tela = 3;
            printf("Boa, Ze do crime ja esta vendo a luz da liberdade...\n");
            printf("Use as ventilacoes marcadas como '>' para driblar o guarda\n\n\n");
            system("pause");
        }
        movimento_jogador(tecla_pressionada, 19);
        gameover(nivel2);
        system("cls");

    }
    
	jogadorX = 1;
	jogadorY = 1;
	guarda2X = 10;
    guarda2Y = 17;
    botao_pressionado = 0;
    tem_chave = 0;
    chaveX = 22;
    chaveY = 28;
    
    // terceiro nivel do jogo
	while(tela == 3)
	{
		
        
        if (botao_pressionado == 0)
        {
            nivel3[chaveX-1][chaveY] = arame_char;
            nivel3[chaveX+1][chaveY] = arame_char;
            nivel3[chaveX][chaveY-1] = arame_char;
            nivel3[chaveX][chaveY+1] = arame_char;
            nivel3[32][17] = botao_char;
        }
        else
        {
            nivel3[chaveX-1][chaveY] = ' ';
            nivel3[chaveX+1][chaveY] = ' ';
            nivel3[chaveX][chaveY-1] = ' ';
            nivel3[chaveX][chaveY+1] = ' ';
        }
        if (tem_chave == 0)
        {
            nivel3[39][20] = porta_fecha;
            nivel3[chaveX][chaveY] = chave_char;
        }
        else
        {
            nivel3[39][20] = porta_aber;
        }

        // movimenta o guarda de acordo com a posiçao do jogador
        guard_move = rand() % 2;    
        if (guard_move == 0) 
        {
            if (jogadorY < guardaY && guardaY - 1 != 0) {
                guardaY--;
            } else if (jogadorY > guardaY && guardaY + 1 != 39) {
                guardaY++;
            }
        } 
        else 
        {
            if (jogadorX < guardaX && guardaX - 1 != 0) {
                guardaX--;
            } else if (jogadorX > guardaX && guardaX + 1 != 39) {
                guardaX++;
            }
        }

        
        nivel3[jogadorX][jogadorY] = jogador_char;
        nivel3[guardaX][guardaY] = guarda2_char;

        printar_nivel(40, 40, nivel3);

        if (jogadorX == 32 && jogadorY == 17)
        {
            botao_pressionado = 1;
        }
		
		nivel3[5][22] = ventilacao_char;
		nivel3[29][25] = ventilacao_char;
		
		if(jogadorX == 5 && jogadorY == 22)
		{
			jogadorX = 29;
			jogadorY = 25;
		}
		else if(jogadorX == 29 && jogadorY == 25)
		{
			jogadorX = 5;
			jogadorY = 22;
		}
		
        nivel3[jogadorX][jogadorY] = ' ';
        nivel3[guardaX][guardaY] = ' ';
        tecla_pressionada = getch();

        if (jogadorX == chaveX && jogadorY == chaveY && tecla_pressionada == 'i')
        {
            tem_chave = 1;
            nivel3[39][20] = porta_aber;
        }

        // se o jogador chegar na porta com a chave, ele avança para a tela de creditos
        // e finaliza o jogo
        if (jogadorX == 38 && jogadorY == 20 && tem_chave == 1 && tecla_pressionada == 's'){
            system("cls");
            tela = 4;
            printf("O sol nao eh mais quadrado!\n");
            printf("Voce conquistou sua liberdade (nao) honesta, mas cuidado pra nao vacilar e perder ela de novo...\n\n\n");
            system("pause");
        }
        movimento_jogador(tecla_pressionada, 39);
        gameover2(nivel3);
        system("cls");

	}
	// tela de creditos do jogo
	while(tela == 4){
		printf("Obrigado por jogar\n\nFeito por: Luis Arthur\n\n");
        // retorna ao menu principal
		tela = 0;
		system("pause");
		main();
        
	}
    
    return 0;
}
