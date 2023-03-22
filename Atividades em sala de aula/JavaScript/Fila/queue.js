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

    isEmpty(){
       /* if(this.itens.length == 0)
            return true;
        else 
            return false;*/
          return this.itens.length === 0;
    
    }

    toString(){
        return this.itens.toString();
    }

    first(){
        return this.itens[0];
    }
}// Fim classe