# csh — Mini Shell em C

Uma implementação minimalista de um **shell estilo POSIX** em C, com foco **didático** e **extensível**.  
A ideia é dominar o ciclo: **prompt → leitura da linha → tokenização → (builtins ou `execvp`) → aguardar término** — e, a partir daí, evoluir para pipes, redirecionamento, histórico e *job control*.

## Objetivos

- **Aprender por fazer**: entender na prática como um shell conversa com o SO (`fork`/`exec`/`wait`).
- **Base sólida**: evoluir em etapas sem “bola de neve”.
- **Portável**: C padrão + chamadas POSIX comuns (Linux/macOS).

## Compilar e executar

```bash
make         # compila
./csh       # executa o binário (ajuste o nome conforme o Makefile)
# ou:
make run
```

## Limpar Artefatos
```bash
make clean
```
