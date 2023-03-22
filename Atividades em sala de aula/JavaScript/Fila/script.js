// Criando instancia da fila a partir da classe 
let minhaFila = new Fila(5);

function addFila(){
    const novo = document.getElementById("novoElemento");
    if(minhaFila.enqueue(novo.value) == true){
        novo.valeu = "";
        novo.focus(); // volta o foco para o obj
        mostrarFila();
    }else{
        alert("Fila cheia!");
    }
}

    //_______________________________________________________

    function mostrarFila(){
        const filaElemento = document.getElementById("listFila");
        filaElemento.textContent = minhaFila.toString();
        minhaFila.toString();
    }

    //_______________________________________________________

    function removerFila(){
        if(minhaFila.isEmpty()){
            alert("Fila vazia!");

        }else{
            let retorno = minhaFila.dequeue();
            alert("Valor removido: " + retorno);
            mostrarFila(); 
        }

    }


