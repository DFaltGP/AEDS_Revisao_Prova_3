## Revisão em C

### `<string.h>`

- **`strlen(string)`**  
    Retorna o comprimento de uma string (não inclui o caractere nulo `\0`).

- **`strcpy(destino, origem)`**  
    Copia o conteúdo da string `origem` para a string `destino`.

- **`strcspn(string, "texto")`**  
    Retorna o índice do primeiro caractere da string que coincide com algum do conjunto `"texto"`.

- **`strcat(destino, origem)`**  
    Concatena a string `origem` ao final da string `destino`.

- **`strtok(string, delimitadores)`**  
    Divide a string em partes (tokens), separadas pelos delimitadores especificados.

---

### `<stdlib.h>`

- **`malloc(tamanho)`**  
    Aloca dinamicamente um bloco de memória do tamanho especificado (em bytes).

- **`free(ponteiro)`**  
    Libera a memória alocada dinamicamente que foi apontada por `ponteiro`.

- **`atoi(string)`**  
    Converte uma string para inteiro.

---

### `<stdio.h>`

- **`fopen(nome_arquivo, modo)`**  
    Abre um arquivo com o nome e modo especificados (`"r"`, `"w"`, `"rb"`, `"wb"`, etc.).

- **`fclose(arquivo)`**  
    Fecha o arquivo aberto.

- **`fread(ptr, tamanho_elemento, quantidade, arquivo)`**  
    Lê dados binários de um arquivo para a memória apontada por `ptr`.

- **`fwrite(ptr, tamanho_elemento, quantidade, arquivo)`**  
    Grava dados binários da memória no arquivo.

- **`fprintf(arquivo, formato, ...)`**  
    Escreve dados formatados em um arquivo texto.

- **`fscanf(arquivo, formato, ...)`**  
    Lê dados formatados de um arquivo texto.

- **`fgets(buffer, tamanho, stdin)`**  
    Lê uma linha (incluindo espaços) da entrada padrão, com no máximo `tamanho - 1` caracteres.

- **`fputs("texto", arquivo)`**  
    Escreve uma linha em um arquivo (não inclui automaticamente o `\n`, este deve ser inserido manualmente em caso de necessidade).

- **`getchar()`**  
    Lê um único caractere da entrada padrão (geralmente usado para consumir o `\n` deixado pelo `scanf`).
