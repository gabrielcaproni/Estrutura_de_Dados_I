package javahash;

public class Pessoa {
    private String nome;
    private String cpf;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    
    @Override
    public boolean equals(Object outroObjeto){
        if(this == outroObjeto)
            return true;
        if(outroObjeto == null || this.getClass() != outroObjeto.getClass())
            return false;
        Pessoa outraPessoa = (Pessoa)outroObjeto;
        return this.cpf.equals(outraPessoa.cpf);
       
        /*if(this.cpf.equals(outraPessoa.cpf))
            return true;
        else 
            return false;*/
    }
    @Override
    public int hashCode(){
        if(this.cpf == null)
            return 0;
        else 
            return this.cpf.hashCode();
    }
    @Override 
    public String toString(){
        return getNome() + ": " + getCpf();
    }
    
    
    
    
}
