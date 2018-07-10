MVP módulo para o Drupal 7.x.
Este módulo determina a visão política do usuário através de um formulário.

# Minha Visão Política - MVP

[![Build Status](https://github.com/lcmaquino/mvp)](https://github.com/lcmaquino/mvp)


## Instalação

Para instalar esse módulo copie seus arquivos para o diretório 
sites/all/modules/mvp e habilite-o na 
página de módulos.


## Configuração

Após instalar e habilitar esse módulo, você precisa realizar os seguintes passos:

* criar um nó do tipo "afirmacao" (Estrutura -> Tipos de conteúdo -> Novo tipo 
de conteúdo);
* adicionar no nó "afirmacao" os campos "field_liberdade" e "field_intervencao",
ambos do tipo "Listagem (texto)";
* o campo "field_liberdade" deve ter como valores permitidos
"le|Liberdade econômica" e "lp|Liberdade pessoal". Já o campo "field_intervencao" 
deve ter "ni|Nenhuma intervenção" e "ti|Total intervenção";

## Como usar

Insira os nós do tipo "afirmacao" para compor o formulário que o usuário deverá 
responder. Apenas os nós "afirmacao" marcados com o status "publicado" serão 
adicionados no formulário.

Deve existir pelo menos uma afirmação publicada de cada tipo: 
"Nenhuma intervenção do Estado na liberdade econômica"; "Total intervenção do 
Estado na liberdade econômica"; "Nenhuma intervenção do Estado na liberdade pessoal"; 
"Total intervenção do 
Estado na liberdade pessoal";

## Crédito

O módulo MVP foi desenvolvido pelo Prof. Luiz C. M. de Aquino (www.lcmaquino.org).
