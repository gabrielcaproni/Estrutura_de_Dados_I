/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pilhajava;

/**
 *
 * @author Gabriel Caproni Pegoraro
 */
public class Produto {
    private String descricao;
    private int quantidade;

    /**
     * @return the descricao
     */
    public String getDescricao() {
        return descricao;
    }

    /**
     * @param descricao the descricao to set
     */
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    /**
     * @return the quantidade
     */
    public int getQuantidade() {
        return quantidade;
    }

    /**
     * @param quantidade the quantidade to set
     */
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }
    
    // Faz sobrecarga do método padrão toString().
    
    @Override
    public String toString(){
        return this.getDescricao() + " : " + this.getQuantidade();
    }
    
} // Fim classe 
