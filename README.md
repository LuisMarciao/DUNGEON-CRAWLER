# 🕹️ Brazil Dungeon

**Brazil Dungeon** é um jogo de terminal escrito em C onde você controla **Zé do Crime**, um prisioneiro tentando escapar do presídio de Carandiru. Passe por três níveis com desafios crescentes, evitando guardas, coletando chaves e interagindo com o ambiente para alcançar a liberdade.

## 📋 Requisitos

- Compilador C (ex: `gcc`)
- Sistema compatível com Windows (uso de `system("cls")`, `getch()`, `sleep()` da `windows.h`)

> ❗ Em Linux/macOS, será necessário adaptar algumas funções (limpeza de tela e entrada de teclas).

---

## 🧱 Compilação

### Windows (com MinGW)

bash

`gcc -o brazil_dungeon.exe brazil_dungeon.c
brazil_dungeon.exe`

## 🎮 Como Jogar

Você deve passar por 3 níveis, cada um com um objetivo:

Nível 1: Pegue a chave (@) e abra a porta (D)

Nível 2: Pressione o botão (O) para desativar o arame farpado (#)

Nível 3: Use túneis de ventilação (>) para escapar do guarda e alcançar a saída

### Controles

| Tecla | Ação                           |
| ----- | ------------------------------ |
| `W`   | Mover para cima                |
| `A`   | Mover para a esquerda          |
| `S`   | Mover para baixo               |
| `D`   | Mover para a direita           |
| `I`   | Interagir (pegar chave, botão) |
| `Q`   | Voltar ao menu principal       |

## 🔠 Legenda dos Elementos

| Símbolo | Significado               |
| ------- | ------------------------- |
| `&`     | Jogador (Zé do Crime)     |
| `@`     | Chave                     |
| `D`     | Porta fechada             |
| `=`     | Porta aberta              |
| `X`     | Guarda nível 1            |
| `V`     | Guarda nível 2            |
| `#`     | Arame farpado (Game Over) |
| `O`     | Botão                     |
| `>`     | Túneis de ventilação      |
| `*`     | Paredes do mapa           |

## Créditos

Desenvolvido por Luis Arthur


