 // Crie uma instância da lista
 let minhaLista = new LinkedList();

//--------------------------------------------------------------------------------------------


 //limpa os campos após inserção

function limpaCampos() {
  const descricao = document.getElementById("txtnovaTarefa");
  const prioridade = document.getElementById("txtnovaPrioridade");

  descricao.value = "";
  prioridade.value = "";

  return;
}
//--------------------------------------------------------------------------------------------
 // Função para adicionar um elemento 
 function adicionarElemento() {
    const descricao = document.getElementById("txtnovaTarefa");
    const prioridade = document.getElementById("txtnovaPrioridade");
    const indice = document.getElementById("txtIndice");
    
    if (descricao.value === "" || prioridade.value === "") {
      alert("Preencha todos os campos antes de adicionar à fila!");
      return;
    }
      const novaTarefa =   
      new Tarefa(descricao.value,prioridade.value, obterDataAtual(),obterHoraAtual());  
      minhaLista.addAtIndex(indice.value,novaTarefa);
      mostrarLista(); 
      descricao.value = "";
      prioridade.value="";
      indice.value="";
      descricao.focus();           
 }
 //--------------------------------------------------------------------------------------------
  // Função para adicionar um elemento ordenado
  function adicionarOrdenado() {
    const descricao = document.getElementById("txtnovaTarefa").value.trim();
    const prioridade = document.getElementById("txtnovaPrioridade").value.trim();
    

    if(descricao === "" || prioridade === "") {
      alert("Todos os campos devem ser preenchidos!");
      return; 
  }

    const novaTarefa = new Tarefa(descricao, prioridade, obterDataAtual(), obterHoraAtual());
    let indice = 1;
    let retorno = false;
    let novaPrioridade = parseInt(novaTarefa.prioridade);

    if(minhaLista.isEmpty())
       retorno = minhaLista.addFirst(novaTarefa);

    else if(novaPrioridade >= minhaLista.getLast().prioridade)
       retorno = minhaLista.addLast(novaTarefa);

    else if(novaPrioridade < minhaLista.getFirst().prioridade)
       retorno = minhaLista.addFirst(novaTarefa);

    else{
      let inserido = false;
      minhaLista.forEach((item) => {
        if(item.prioridade > novaPrioridade && inserido === false){
            retorno = minhaLista.addAtIndex(indice, novaTarefa);
            inserido = true;
            return;
        }
        indice++;
      });
      
      if(!inserido){
        retorno = minhaLista.addLast();
      }
    }
    mostrarLista();
    limpaCampos();
    return;
  }
//--------------------------------------------------------------------------------------------
 // Função para remover o primeiro elemento da fila
 function removerPrimeiroElemento() {
    if(minhaLista.isEmpty()) 
      alert("Lista vazia!");
    else{  
      let del = minhaLista.deleteFirst();
        mostrarMensagemRemocao(del);
        mostrarLista();
    }
 }

 //--------------------------------------------------------------------------------------------


 function mostrarMaisAntiga() {
  let tarefa = minhaLista.getFirst();

  minhaLista.forEach((item) => {
      tarefa = comparaTarefasDataHora(tarefa, item);
  });

  mostrarMensagemPrimeiro(tarefa);
  return;
}

//---------------------------------------------------------------------------------------------

function mostraPrimeiro() {
  if(minhaLista.isEmpty()){
      alert("Lista vazia!");
  }
  else {  
      let del = minhaLista.deleteFirst();
      mostrarMensagemPrimeiro(del);
      minhaLista.addFirst(del);
  }
}

//--------------------------------------------------------------------------------------------
function mostrarMensagemRemocao(tarefaRealizada) {
    const mensagem = document.getElementById("mensagem-remocao");
    mensagem.innerHTML ="Tarefa "+ tarefaRealizada.descricao + ", realizada em "; // apresentar a mensagem de remoção com dias e horas
    mensagem.style.display = "block";

  }
//-------------------------------------------------------------------------------------------- 

function mostrarMensagemPrimeiro(tarefaRealizada) {
  const mensagem = document.getElementById("mensagem-remocao");
  mensagem.innerHTML = "Tarefa: "+ tarefaRealizada.descricao + ", criada há " + calcularDiferencaHoras(tarefaRealizada.hora, obterHoraAtual()); // apresentar a mensagem de remoção com dias e horas
  mensagem.style.display = "block";
}
//-------------------------------------------------------------------------------------------- 


// Função para atualizar a exibição da fila
 function mostrarLista() {
   const listaElemento = document.getElementById("list_listadeTarefas");
   const listaTarefa = document.getElementById("lblmostraTarefas");
   if (minhaLista.isEmpty()) {
      listaTarefa.innerHTML = "Lista vazia!";
      listaElemento.innerHTML = "";
   } else {
       listaTarefa.innerHTML = "Tarefas Pendentes:";
        listaElemento.innerHTML = "";
        minhaLista.forEach((item) => {
          const li = document.createElement("li");
          li.innerText = item.toString();
          listaElemento.appendChild(li);
        }); // for each percorre cada elemento da lista encadeada
   }
 }
//--------------------------------------------------------------------------------------------
 // funcao data
 function obterDataAtual() {
    let dataAtual = new Date();
    let dia = dataAtual.getDate();
    let mes = dataAtual.getMonth() + 1; // Adiciona 1 porque o mês inicia do zero
    let ano = dataAtual.getFullYear();
    // Formata a data como "dd/mm/aaaa"
    let dataFormatada = `${dia.toString().padStart(2, '0')}/${mes.toString().padStart(2, '0')}/${ano}`;
    return dataFormatada;
}
//--------------------------------------------------------------------------------------------
function obterHoraAtual() {
  const data = new Date();
  const hora = data.getHours().toString().padStart(2, '0');
  const minuto = data.getMinutes().toString().padStart(2, '0');
  const segundo = data.getSeconds().toString().padStart(2, '0');
  return `${hora}:${minuto}:${segundo}`;
}
//--------------------------------------------------------------------------------------------
function calcularDiferencaHoras(hora1, hora2) {
  const [h1, m1, s1] = hora1.split(':').map(Number);
  const [h2, m2, s2] = hora2.split(':').map(Number);
  
  const diferencaSegundos = (h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);
  
  const horas = Math.floor(diferencaSegundos / 3600);
  const minutos = Math.floor((diferencaSegundos % 3600) / 60);
  const segundos = diferencaSegundos % 60;
  
  return `${horas.toString().padStart(2, '0')}:${minutos.toString().padStart(2, '0')}:${segundos.toString().padStart(2, '0')}`;
}
//--------------------------------------------------------------------------------------------
function calcularDiferencaDias(dataInicial, dataFinal) {
  // Converte as datas em milissegundos
  const msPorDia = 24 * 60 * 60 * 1000; // Quantidade de milissegundos em um dia
  const [diaIni, mesIni, anoIni] = dataInicial.split('/').map(Number);
  const [diaFim, mesFim, anoFim] = dataFinal.split('/').map(Number);
  // Cria objetos Date com as datas fornecidas
  const dataIni = new Date(anoIni, mesIni - 1, diaIni); // Subtrai 1 do mês porque o mês inicia do zero
  const dataFim = new Date(anoFim, mesFim - 1, diaFim);
  // Calcula a diferença em milissegundos entre as duas datas
  const diferencaMs = dataFim - dataIni;
  // Converte a diferença de milissegundos para dias e arredonda para baixo
  const diferencaDias = Math.floor(diferencaMs / msPorDia);
  return diferencaDias;
}
//--------------------------------------------------------------------------------------------
function converterDataFormatoISO8601(data) {
  const partes = data.split('/');
  const dia = partes[0].padStart(2, '0');
  const mes = partes[1].padStart(2, '0');
  const ano = partes[2];
  return `${ano}-${mes}-${dia}`;
}
//--------------------------------------------------------------------------------------------
function comparaTarefasDataHora(tarefa1, tarefa2) {
  const dataHoraTarefa1 = new Date(`${converterDataFormatoISO8601(tarefa1.data)}T${tarefa1.hora}`);
  const dataHoraTarefa2 = new Date(`${converterDataFormatoISO8601(tarefa2.data)}T${tarefa2.hora}`);
  if (dataHoraTarefa1.getTime() < dataHoraTarefa2.getTime()) {
    return tarefa1;
  } else {
    return tarefa2;
  }
}

