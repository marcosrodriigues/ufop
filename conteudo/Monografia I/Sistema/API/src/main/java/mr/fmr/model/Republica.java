package mr.fmr.model;

import javax.persistence.*;

@Entity
public class Republica extends User {

    public Republica() {

    }

    public Republica(User user) {
        super(user.getEmail(), user.getPassword(), user.getUsername(), user.isTermos(), user.getTipo(), user.getPerfil());
    }

    private String nome;


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
}
