#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define Item int
#define chave(x) (x)
#define menor(a, b) (a > b)
#define trocar(a, b)  \
    {                 \
        Item t = a;   \
        a = b;        \
        b = t;        \
    }
#define compararTrocar(a, b) \
    if (menor(b, a))         \
    trocar(a, b)

Item ITEM_NULO = -1;

typedef struct
{
    Item *heap;
    size_t tamanho, capacidade;
} FilaPrioridade;

void HEAP_ajustarCima(Item *heap, int i)
{
    for (; i > 1 && menor(heap[i / 2], heap[i]); i /= 2)
        trocar(heap[i], heap[i / 2]);
}

void HEAP_ajustarBaixo(Item *heap, size_t tamanho, int i)
{
    for (int maior = i * 2; i * 2 <= tamanho; i = maior, maior = i * 2)
    {
        if (maior < tamanho && menor(heap[maior], heap[maior + 1]))
            maior++;

        if (!menor(heap[i], heap[maior]))
            break;

        trocar(heap[i], heap[maior]);
    }
}

FilaPrioridade FP_inicializar(size_t capacidade)
{
    FilaPrioridade fp = {.capacidade = capacidade, .tamanho = 0};
    fp.heap = malloc((capacidade + 1) * sizeof(Item));
    return fp;
}

void FP_liberar(FilaPrioridade fp)
{
    free(fp.heap);
}

int FP_estaVazia(FilaPrioridade fp)
{
    return fp.tamanho == 0;
}

void FP_garantirCapacidade(FilaPrioridade *fp, size_t novaCapacidade)
{
    if (novaCapacidade <= fp->capacidade)
        return;

    fp->capacidade *= 4;
    fp->heap = realloc(fp->heap, (fp->capacidade + 1) * sizeof(Item));
}

void FP_inserir(FilaPrioridade *fp, Item x)
{
    FP_garantirCapacidade(fp, fp->tamanho + 1);
    fp->heap[++fp->tamanho] = x;
    HEAP_ajustarCima(fp->heap, fp->tamanho);
}

Item FP_obterTopo(FilaPrioridade fp)
{
    return fp.heap[1];
}

Item FP_extrairTopo(FilaPrioridade *fp)
{
    if (FP_estaVazia(*fp))
        return ITEM_NULO;

    Item topo = FP_obterTopo(*fp);
    fp->heap[1] = fp->heap[fp->tamanho--];
    HEAP_ajustarBaixo(fp->heap, fp->tamanho, 1);
    return topo;
}

int main()
{
    FilaPrioridade fp = FP_inicializar(16);
    int t, p, v[100];

    while (scanf(" %d %d", &t, &p) == 2)
    {
        if (t == 1)
            FP_inserir(&fp, p);
        else
        {
            int n;
            for (n = 0; n < p; n++)
            {
                int topo = FP_extrairTopo(&fp);
                if (topo == ITEM_NULO)
                    break;
                v[n] = topo;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d%c", v[i], " \n"[i == n - 1]);
                FP_inserir(&fp, v[i]);
            }
        }
    }

    FP_liberar(fp);

    return 0;
}
