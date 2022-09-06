// char ocupa 1 byte
// float int ocupa 4 byte
//%s só lê uma palavra (até o espaço)
// scanf(" %[^\n]", nome) vai ler tudo até encontrar o \n(enter), bom por espaço por conta do buffer
//<stdlib.h> trabalhar com ponteiro e <string.h> trabalhar com string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[100][100];
    char email[100][100];
    int ddd[100];
    int tel[100];
    int escolha, escolhaEditar, contUser = 0;
    char nomeAux[100];
    int i;
    int indiceCadastro = -1;

    do
    {
        printf("======================== MENU ========================\n");
        printf("| 0 ........................................... SAIR |\n");
        printf("| 1 ...................................... ADICIONAR |\n");
        printf("| 2 ...................................... PESQUISAR |\n");
        printf("| 3 ......................................... EDITAR |\n");
        printf("| 4 ........................................ EXCLUIR |\n");
        printf("| 5 .......................................... SOBRE |\n");
        printf("======================================================\n");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha)
        {
        case 0:
            printf("Obrigado por utilizar o Sistendi!\n");
            break;
        case 1:
            printf("===================== NOVO CADASTRO ====================\n");
            printf("Entre com as informacoes do novo usuario: \n");
            printf("NOME: ");
            scanf(" %[^\n]", nome[contUser]);

            printf("DDD: ");
            scanf("%d", &ddd[contUser]);

            printf("TELEFONE: ");
            scanf("%d", &tel[contUser]);

            printf("E-MAIL: ");
            scanf(" %[^\n]", email[contUser]);

            printf("Usuario cadastrado!\n\n");
            contUser++;
            break;
        case 2:
            indiceCadastro = -1;
            printf("===================== PESQUISAR CADASTRO ===================\n");
            printf("Entre com o nome a ser verificado: ");
            scanf(" %[^\n]", nomeAux);
            for (i = 0; i < contUser; i++)
            {
                if (strcmp(nome[i], nomeAux) == 0)
                {
                    indiceCadastro = i;
                    break;
                }
            }

            if (indiceCadastro != -1)
            {
                printf("===================== USUARIO %d ======================\n", i + 1);
                printf("| NOME: %s\n", nome[indiceCadastro]);
                printf("| TELEFONE: (%d) %d-%.4d\n", ddd[indiceCadastro], tel[indiceCadastro] / 10000, tel[indiceCadastro] % 10000);
                printf("| E-MAIL: %s\n", email[indiceCadastro]);
                printf("======================================================\n\n");
            }
            else
            {
                printf("Usuario inexistente!\n");
            }
            break;
        case 3:
            indiceCadastro = -1;
            printf("===================== EDITAR CADASTRO ===================\n");
            printf("Entre com o nome a ser verificado: ");
            scanf(" %[^\n]", nomeAux);
            for (i = 0; i < contUser; i++)
            {
                if (strcmp(nome[i], nomeAux) == 0)
                {
                    indiceCadastro = i;
                    break;
                }
            }

            if (indiceCadastro != -1)
            {
                do
                {
                    printf("================ MENU DE ATUALIZACAO ==== ============\n");
                    printf("| 0 ....................... VOLTAR AO MENU PRINCIPAL |\n");
                    printf("| 1 .................................... EDITAR NOME |\n");
                    printf("| 2 ..................................... EDITAR DDD |\n");
                    printf("| 3 ................................ EDITAR TELEFONE |\n");
                    printf("| 4 .................................. EDITAR E-MAIL |\n");
                    printf("======================================================\n");
                    scanf("%d", &escolhaEditar);
                    system("cls");
                    switch (escolhaEditar)
                    {
                    case 0:
                        break;
                    case 1:
                        printf("| NOME ATUAL: %s\n", nome[indiceCadastro]);
                        printf("| NOME: ");
                        scanf(" %[^\n]", nome[indiceCadastro]);
                        break;
                    case 2:
                        printf("| TELEFONE ATUAL: (%d) %d-%.4d\n", ddd[indiceCadastro], tel[indiceCadastro] / 10000, tel[indiceCadastro] % 10000);
                        printf("| DDD: ");
                        scanf("%d", &ddd[indiceCadastro]);
                        break;
                    case 3:
                        printf("| TELEFONE ATUAL: (%d) %d-%.4d\n", ddd[indiceCadastro], tel[indiceCadastro] / 10000, tel[indiceCadastro] % 10000);
                        printf("| TELEFONE: ");
                        scanf("%d", &tel[indiceCadastro]);
                        break;
                    case 4:
                        printf("| E-MAIL ATUAL: %s\n", email[indiceCadastro]);
                        printf("| E-MAIL: ");
                        scanf(" %[^\n]", email[indiceCadastro]);
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
                    }
                } while (escolhaEditar != 0);
            }
            else
            {
                printf("Usuario inexistente!\n");
            }
            break;
        case 4:
            printf("===================== EXCLUIR CADASTRO ===================\n");
            printf("Entre com o nome a ser verificado: ");
            scanf(" %[^\n]", nomeAux);
            for (i = 0; i < contUser; i++)
            {
                if (strcmp(nome[i], nomeAux) == 0)
                {
                    indiceCadastro = i;
                    break;
                }
            }
            if (indiceCadastro != -1)
            {
                printf("===================== USUARIO %d ======================\n", i + 1);
                printf("| NOME: %s\n", nome[i]);
                printf("| TELEFONE: (%d) %d-%.4d\n", ddd[i], tel[i] / 10000, tel[i] % 10000);
                printf("| E-MAIL: %s\n", email[i]);
                printf("======================================================\n\n");
                printf("Certeza que deseja excluir o usuario? ");
            }
            else
            {
                printf("Usuario inexistente!");
            }
            break;
        case 5:
            printf("======================== SOBRE =======================\n");
            printf("| Este software foi desenvolvido para fins didaticos.|\n");
            printf("| AUTOR: Wendi Ramos                                 |\n");
            printf("| DATA: 02/09/2022                                   |\n");
            printf("======================================================\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}
