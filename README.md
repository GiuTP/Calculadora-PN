<a id="readme-top"></a>

[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<br />
<div align="center">
  <h3 align="center">🧮 Calculadora RPN</h3>

  <p align="center">
    Avaliador recursivo de expressões aritméticas em notação pré-fixa — trabalho da disciplina Algoritmos e Estrutura de Dados 2 (CI1056) na UFPR.
    <br />
    <a href="https://github.com/GiuTP/Calculadora-RPN/issues/new?labels=bug">Reportar Bug</a>
    &middot;
    <a href="https://github.com/GiuTP/Calculadora-RPN/issues/new?labels=enhancement">Sugerir Melhoria</a>
  </p>
</div>

---

<!-- SUMÁRIO -->
<details>
  <summary>Sumário</summary>
  <ol>
    <li><a href="#-sobre-o-projeto">Sobre o Projeto</a>
      <ul>
        <li><a href="#-construído-com">Construído com</a></li>
      </ul>
    </li>
    <li><a href="#-fundamentação--arquitetura">Fundamentação / Arquitetura</a></li>
    <li><a href="#-entidades--componentes">Entidades / Componentes</a></li>
    <li><a href="#-dinâmica-e-fluxo-de-execução">Dinâmica e Fluxo de Execução</a></li>
    <li><a href="#-estrutura-do-projeto">Estrutura do Projeto</a></li>
    <li>
      <a href="#-instalação">Instalação</a>
      <ul>
        <li><a href="#-pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#-compilação">Compilação</a></li>
        <li><a href="#-comandos-úteis">Comandos Úteis</a></li>
      </ul>
    </li>
    <li><a href="#-dificuldades-e-aprendizados">Dificuldades e Aprendizados</a></li>
    <li><a href="#-licença">Licença</a></li>
    <li><a href="#-contato">Contato</a></li>
  </ol>
</details>

---

## 📖 Sobre o Projeto

**Calculadora RPN** é um avaliador de expressões aritméticas em **notação pré-fixa** (também conhecida como notação polonesa ou prefix notation), desenvolvido em linguagem C para a disciplina **Algoritmos e Estrutura de Dados 2 (CI1056)** da **Universidade Federal do Paraná (UFPR)**.

O objetivo do trabalho é praticar **recursão**: em vez de usar pilhas explícitas para avaliar a expressão, o próprio mecanismo de chamadas recursivas assume esse papel. A expressão é lida token por token a partir da entrada padrão (stdin), e cada operador consome recursivamente seus dois operandos antes de retornar o resultado.

Suporta as quatro operações básicas: **soma** (`+`), **subtração** (`-`), **multiplicação** (`*`) e **divisão** (`/`).

Trabalho realizado em dupla.

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

### 🛠 Construído com

* [![C][C-badge]][C-url]
* [![Linux][Linux-badge]][Linux-url]

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## ⏱ Fundamentação / Arquitetura

A calculadora usa **notação pré-fixa**: o operador aparece *antes* dos seus operandos. Por exemplo, a expressão `(3 + 4) * 2` é representada como `* + 3 4 2`.

A avaliação é inteiramente **recursiva**. Ao encontrar um operador, a função `avalia()` chama a si mesma duas vezes para obter os operandos — e cada uma dessas chamadas pode, por sua vez, encontrar novos operadores e se aprofundar ainda mais na recursão.

```
Entrada (stdin): * + 3 4 2

avalia()                      → lê '*'
├── avalia()                  → lê '+'
│   ├── avalia()              → lê '3' → retorna 3.0
│   └── avalia()              → lê '4' → retorna 4.0
│   └── retorna 3.0 + 4.0 = 7.0
└── avalia()                  → lê '2' → retorna 2.0
└── retorna 7.0 * 2.0 = 14.0
```

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 👥 Componentes

| Módulo / Função | Descrição |
|-----------------|-----------|
| **`proximo_item()`** | Lê o próximo token da entrada via `scanf`. Aloca dinamicamente uma cópia da string lida e a retorna. Retorna `NULL` ao fim da entrada (EOF). |
| **`avalia()`** | Função recursiva central. Obtém um token: se for número, converte e retorna; se for operador, chama `avalia()` duas vezes e aplica a operação. |
| **`main()`** | Ponto de entrada. Chama `avalia()` uma vez e imprime o resultado final. |

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 🔄 Dinâmica e Fluxo de Execução

| Etapa | Comportamento e Ações Executadas |
|-------|----------------------------------|
| `Leitura do token` | `proximo_item()` lê uma palavra da stdin com `scanf("%s")`. Retorna `NULL` se EOF. |
| `Token é número` | `isdigit(item[0])` detecta número. `strtod()` converte a string para `double`. Memória liberada com `free()`. |
| `Token é operador` | A função identifica o símbolo (`+`, `-`, `*`, `/`) e chama `avalia()` recursivamente duas vezes, obtendo os dois operandos antes de calcular. |
| `Token inválido` | A string é liberada e a função retorna `0`. |
| `EOF / NULL` | `avalia()` retorna `NAN`, sinalizado para `main()` exibir mensagem de erro. |

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 📁 Estrutura do Projeto

```
Calculadora-RPN/
├── bin/          executável final gerado pelo make (avalia)
├── avalia.h      definições e protótipos (TAMANHO_MAXIMO_ITEM, avalia, proximo_item)
├── avalia.c      implementação do avaliador recursivo
├── main.c        ponto de entrada: chama avalia() e imprime o resultado
├── Makefile      automação de compilação e limpeza
└── README.md
```

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 🚀 Instalação

### 📦 Pré-requisitos

É necessário dispor de um compilador C com suporte a C99 e do GNU Make. No Ubuntu/Debian:

```sh
sudo apt update
sudo apt install build-essential valgrind -y
```

### 🔧 Compilação

1. Clone o repositório:
   ```sh
   git clone https://github.com/GiuTP/Calculadora-PN.git
   cd Calculadora-PN
   ```

2. Compile o projeto:
   ```sh
   make
   ```
   O executável será gerado em `bin/avalia`.

3. Execute passando uma expressão via stdin:
   ```sh
   echo "+ 3 4" | ./bin/avalia
   # Saída: 7
   ```

### ⚙ Comandos Úteis

| Comando | Descrição |
|---------|-----------|
| `make` | Compila os arquivos fonte e gera `bin/avalia` |
| `make valgrind` | Executa o programa sob o Valgrind para checagem de vazamentos de memória |
| `make clean` | Remove o executável e o diretório `bin/` |

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 📚 Dificuldades e Aprendizados

Principais desafios encontrados no desenvolvimento:

- **Lidar com strings em C** — Foi a primeira vez trabalhando ativamente com `char *`, alocação dinâmica de strings com `malloc`, cópia com `strcpy` e liberação com `free`. Entender o modelo de memória manual do C e evitar vazamentos foi o maior aprendizado do trabalho.

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 📄 Licença

O código-fonte deste projeto está distribuído sob a licença **MIT**. Consulte o arquivo `LICENSE` para mais informações.

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 📬 Contato

GiuTP — [github.com/GiuTP](https://github.com/GiuTP)

E-mail — giulianotpt@gmail.com

Link do projeto: [https://github.com/GiuTP/Calculadora-RPN](https://github.com/GiuTP/Calculadora-RPN)

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

## 🙏 Agradecimentos

* [Prof. Renato Carmo (DINF/UFPR)](https://www.inf.ufpr.br/renato/) — pela disciplina e pelo enunciado do trabalho
* [Best-README-Template](https://github.com/othneildrew/Best-README-Template) — template base deste README

<p align="right">(<a href="#readme-top">voltar ao topo</a>)</p>

---

<!-- MARKDOWN LINKS & IMAGES -->
[stars-shield]: https://img.shields.io/github/stars/GiuTP/Calculadora-RPN.svg?style=for-the-badge
[stars-url]: https://github.com/GiuTP/Calculadora-RPN/stargazers
[issues-shield]: https://img.shields.io/github/issues/GiuTP/Calculadora-RPN.svg?style=for-the-badge
[issues-url]: https://github.com/GiuTP/Calculadora-RPN/issues
[license-shield]: https://img.shields.io/github/license/GiuTP/Calculadora-RPN.svg?style=for-the-badge
[license-url]: https://github.com/GiuTP/Calculadora-RPN/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/giuliano-tavares/
[C-badge]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[Linux-badge]: https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black
[Linux-url]: https://www.kernel.org/
