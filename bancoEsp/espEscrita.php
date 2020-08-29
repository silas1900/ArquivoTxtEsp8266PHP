<!DOCTYPE html>
<html lang="pt-br">
<head>
	<title>Trabalhando com arquivos </title>
	<meta charset="utf-8">
	
</head>
<body>
<?php
	 // manipulando arquivos php
	// r = abrir p/leitura, ponteiro no inicio ezera apaga
	// r+= abrir p/leitura e escrita
	// w = abre p/escrita ponteiro no inicio se arquivo não existir ele criar
	// w+= abre p/leitura e escrita
	// a = abre pra escrita
	// a+= abre pra escrita
	
	
	$dia = date("d");
	$mes = date("m");
	$ano = date("Y");
	
	$hor =  date("H");
	$min =  date("i");
	$sec =  date("s");
	
	$data = $dia."/".$mes."/".$ano;
	$hora = $hor.":".$min.":".$sec;
	
	$temperatura = $_GET['temperatura'];
	$umidade = $_GET['umidade'];
	
	$conteudo ="Temperatura " .$temperatura."°C".".\r\n"."Umidade ".$umidade."\r\n".$data." ".$hora."\r\n"."........................................................................."."\r\n";
	
	$arquivo = fopen("th.txt","a"); // cria uma arquivo do tipo txt
	
	fwrite($arquivo,$conteudo);
	
	echo "Mensagem gravada: $conteudo";
	
	fclose($arquivo );
	
	

?>

	
	
</body>
</html>
