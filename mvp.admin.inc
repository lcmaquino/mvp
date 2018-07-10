<?php
/**
* @file Callbacks da página de administração do módulo.
*/

/**
 * Formulário para configurar as opções do módulo.
 *
 * @param array $form
 *   Contém os items do formulário.
 *
 * @param array $form_state
 *   Contém o estado do formulário.
 *
 * @return array.
 *   Retorna uma array contendo os itens do formulário.
 */
function mvp_admin_configuracoes($form, &$form_state) {
  $file_path_mvp = variable_get('file_public_path', conf_path() . '/files') . '/mvp';
  $form['limpar-cache'] = array(
      '#type' => 'fieldset',
      '#title' => t('Limpar cache'),
  );
  $form['limpar-cache']['aviso'] = array(
    '#type' => 'item',
    '#markup' => '<p>' . t('Limpar o cache de gráficos gerados pelo MVP. Isso exclui 
os arquivos ".png" criados dentro do diretório <strong>@file_path</strong>.', array('@file_path' => $file_path_mvp)) . '</p>',
  );
  $form['limpar-cache']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Limpar'),
  );
  return $form;
}

/**
 * Controla a submissão do formulário mvp_admin_configuracoes().
 *
 * @param array $form
 *   Uma array com os elementos do formulário.
 *
 * @param array $form_state
 *   Uma array com os elementos do formulário após submissão.
 *
 * @return array.
 *   Retorna uma array contendo os itens do formulário.
 *
 * @see mvp_admin_configuracoes()
 */
function mvp_admin_configuracoes_submit($form, &$form_state) {
  $erros = _mvp_limpar_cache();
  if (empty($erros)) {
    drupal_set_message(t('O cache foi limpo com sucesso!'));
  }
  else {
    $mensagem = '';
    $qtd_max = 10;
    $n = 0;
    foreach ($erros as $erro) {
      $mensagem .= '<li>' . $erro . '</li>' . PHP_EOL;
      $n++;
      if ($n >= $qtd_max) {
        $mensagem .= '<li>' . t('outro(s) @n arquivo(s)...', array('@n' => count($erros) - $qtd_max)) . '</li>';
        break;
      }
    }
    drupal_set_message(t('Ops! Ocorreu um erro ao limpar o cache. Não foi 
possível remover os arquivos:') . '<ul>' . $mensagem . '</ul>', 'error');
  }
}

/**
 * Remove todos os arquivos ".png" gerados pelo módulo.
 *
 * @return array
 *   Retorna uma array contendo a uri dos arquivos que geraram erro na remoção.
 * Ou retorna NULL caso não ocorra erros.
 */
function _mvp_limpar_cache() {
  $file_path_mvp = variable_get('file_public_path', conf_path() . '/files') . '/mvp';
  $arquivos = file_scan_directory($file_path_mvp, '/.*\.png$/');
  foreach ($arquivos as $arquivo) {
    if (!drupal_unlink($arquivo->uri)) {
      $erros[] = $arquivo->uri;
    }
  }
  return isset($erros) ? $erros : NULL;
}
