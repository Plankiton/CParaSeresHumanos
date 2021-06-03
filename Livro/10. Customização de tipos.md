## Estruturas

Até agora você só viu estruturas padrões do próprio C, e como usá-las, mas agora você vai aprender a criar as suas próprias...

### Structs e unions

`struct` é o tipo de dado que cria uma estrutura própria, e é muito útil para criar "objetos" ou seja, criar variáveis com várias características...

> E a galera que já conhece um pouco mais deve estar se perguntando "Mas o C é orientado a objetos?" e desde já, não, o máximo que você pode fazer no C é criar um tipo com espaços para armazenar dados, mas não é possível criar objetos ou classes.

```c

struct pessoa {
   char * nome;
   int idade;
   char sexo;
   float peso;
   float altura;
}

```

Como podem ver no exemplo acima, nós criamos uma estrutura `pessoa` que pode receber um `nome`, uma `idade`, um `peso`, um `sexo` e uma `altura`, assim melhorando e muito nosso armazenamento de dados, _"Mas como eu posso acessá-los?"_, muito simples:

```c
struct pessoa joao;        // aqui nós criamos uma pessoa "joao".
joao.nome = "Joao";        // aqui nós atribuímos "Joao" ao nome da pessoa.
```

E como você pôde notar agora existe um tipo `struct pessoa`, _"Mas, eu quero criar um tipo `pessoa`, é possível?"_, sim, é, e para isso você vai usar o `typedef`, e ele serve para apelidar um tipo.

```c
typedef int MyInt;

MyInt inteiro;
```

Mas como nós queremos usá-lo com a nossa `struct`, temos 3 formas de usar:

Criando o `struct` antes:

```c
struct p { char * name };
typedef struct p pessoa;
```

Criando ao mesmo tempo:

```c
typedef struct p { char * name } pessoa;
```

Criando ao mesmo tempo com uma `struct` anônima:

```c
typedef struct { char * name } pessoa;
```

E o resultado das sentenças anteriores é:

```c
pessoa joao;
joao.name = "Joao";
```

> E para evitar erros de escopo, sempre declare structs fora do `main`.

Outra estrutura muito interessante é a `union`, ela é semelhante a `struct`, mas a `union` assume apenas uma variável... _"Como assim?"_ ...observe:

```c
// struct
{
   struct p {
      char * nome;
      int idade;
   };

   // Uso

   struct p joao;
   joao.nome = "Joao";
   joao.idade = 12;
}

// union
{
   union p {
      char * nome;
      int idade;
   };

   // Uso

   union p joao;
   joao.nome = "Joao";       // aqui você escolheu usar a variável nome
   puts(joao.idade);         /* aqui aqui será imprimido "Joao", já que
                                joao.idade está unido com joao.nome
                             */
    // Ou
    union p coisa;
    coisa.idade = 14;
    printf("%i\n", coisa.idade);
}
```

Um macete legal na atribuíção de uma `struct` é usar um array para isso, é só colocar os valores na ordem de declaração da struct, _"Quê?"_:

```c
typedef struct {
    char * nome;
    int idade;
    float peso;
    float altura;
} pessoa;

//                      .nome, .idade, .peso, .altura
pessoa joao = (pessoa){"joao",     13,  40.3,    1.60};
```

Ou caso você não queira colocar na ordem é só específicar o atributo:

```C
pessoa maria = (pessoa){
    .altura = 1.5
    .idade = 12,
    .nome = "maria",
    .peso = 39.4,
};
```

E o mesmo vale para arrays de `struct`:

```c
pessoa * pessoas = (pessoa []){
    (pessoa){ "vanderlei", 25, 90, 1.80 },
    joao,
    (pessoa){
        .peso = 70,
        .altura = 1.90,
        .idade = 42,
        .nome = "rita"
    },
    maria
};
```

### Enum

O `enum` vem enumeração e nesse você deseje designar valores constantes para as suas estruturas.

```c
typedef enum {
   true = 1,
   false = 0,
} bool;

bool falso = false;
```

> Só pode colocar inteiros em enums.

E acima acabamos de criar o tipo booleano no C.

Como só é possível colocar inteiros em enums, e por isso existe um macete legal para atribuir esses números:

```c
typedef enum {

   zero = 0,        // zero é 0
   um,              // um é zero + 1
   dois,            // dois é um + 1
   tres,            // tres é dois + 1

   sete = 7,        // sete é 7
   oito,            // oito é sete + 1
   nove,            // nove é oito + 1

   quatro = 4,      // quatro é 4
   cinco,           // cinco é quatro + 1
   seis             // seis é seis + 1

} por_extenso;
```

```c
por_extenso numero = dois;

printf("%i\n", numero)
printf("%i\n", dois)
```

> Saída:

```c
2
2
```

