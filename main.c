#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    printf("*****SIMULADOR DE TARIFA DE ENERGIA IFBA*****\n");
    int cont = 0;                                                                                          //Contador
    float icms = 0.27;                                                                                     //Valor do imposto ICMS
    float pis = 0.0165;                                                                                    //Valor do impostos PIS
    float cofins = 0.0761;                                                                                 //Valor do imposto OCFINS
    float ctg, vgt,impostos, vti = 0;
    float kwh;
    ctg = 0;
    char aparelho [5][20]= {"AR-CONDICIONADO","COMPUTADOR","GELADEIRA","LAMPADA","TELEVISOR"};               //Matriz de atribuição dos aparelhos
    int escolha = 0;
    printf("Digite o valor da tarifa de energia: ");
    scanf("%f",&kwh );                                                                                       //Recebe valor da tarifa de energia do usuário
    getchar();
    do
    {
        int qhd, qdm, p, qa, consumokwh;
        float consumors;
        char setor[30];
        printf("Digite o setor: ");
        scanf("%s",setor);
        for (int i=0; i<5; i++)                                                                        //Inicia laço de repetição para os setores
        {
            printf("%s \n",aparelho[cont]);                                                            //Inicia contagem para os aparelhos
            printf("Digite a quantidade: ");
            scanf("%d",&qa );                                                                          //Recebe quantidade dos aparelhos solicitados
            printf("Digite a potência: ");
            scanf("%d",&p);                                                                            //Recebe valor da potência do aparelho
            printf("Digite a quantidade de horas de uso por dia: " );
            scanf("%d",&qhd);                                                                          //Recebe quantidade de horas de uso por dia do aparelho
            printf("Digite a quantidade de dias no mês de uso: " );
            scanf("%d",&qdm);                                                                          //Recebe quantidade de dias no mês de uso do aparelho
            system("clear");                                                                           //Limpa tela
            consumokwh = ((qhd*qdm)*p)*qa;                                                             //Calcula o consumo de KwH por aparelho
            consumors = (float)(consumokwh*kwh);                                                       //Calcula o valor em R$ do consumo
            ctg = ctg + consumokwh;                                                                    //Cálculo do Consumo Total do setor
            vgt = vgt + consumors;                                                                     //Cálculo do Valor em R$ do setor
            cont++;                                                                                    //Contador para matriz dos aparelhos
            printf("Valor do consumo em Kw/H foi: %d \n",consumokwh);                                  //Exibe quantidade de KWH gastos por setor
            printf("Valor do consumo em reais do setor %s foi: R$%.2f \n",setor, consumors);           //Exibe quantidade em R$ gastos por setor
        }
        printf("Deseja incluir outro setor?\n");
        printf("Digite 1 para Sim ou 0 para Nao!\n");
        scanf("%d",&escolha);                                                                      //Usuário decide se quer continuar
        system("clear");
        cont =0;
    }
    while(escolha !=0);
    impostos = vgt*(pis+cofins+icms);                                                                 //Cálculo do valor dos impostos
    vti = vgt+impostos;                                                                               //Cálculo da conta final com impostos
    printf("Consumo total do IFBA em KhW de todos os setores foi %.1f \n", ctg);                     //Exibe total de KwH gastos por todos os setores
    printf("Consumo total antes dos impostos foi de R$ %.2f \n", vgt);                               //Valor total do uso antes da aplicação dos impostos
    printf("Valor dos Impostos sobre consumo foi de %.2f \n",impostos);                              //Exibe valor final dos impostos sobre o uso
    printf("Valor total a ser pago R$ %.2f \n",vti);                                                 //Exibe valores finais do consumo em R$ dos setores somados
    return 0;
}
