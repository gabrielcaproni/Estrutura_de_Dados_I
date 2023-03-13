class Fila{
    constructor(maxSize){
        this.maximo = maxSize;
        this.itens = [];
    }

    enqueue(elemento){
        if(this.itens.length === this.maximo){
            return false;
        }
        this.itens.push(elemento); // Insere no final 
        return true;
    }

    dequeue(){
        let valor = this.itens.shift();
        return valor;
    }

}