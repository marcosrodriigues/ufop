package mr.fmr.model;

import com.fasterxml.jackson.annotation.JsonIgnore;

import javax.persistence.*;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

@Entity
public class Republica extends User implements Serializable {

    public Republica() {

    }

    public Republica(User user) {
        super(user.getEmail(), user.getPassword(), user.getUsername(), user.isTermos(), user.getTipo(), user.getPerfil());
    }

    private String nome;

    @OneToMany(mappedBy = "republica", fetch = FetchType.LAZY)
    private List<MoradorRepublica> moradores = new ArrayList<>();

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    @JsonIgnore
    public List<MoradorRepublica> getMoradores() {
        return moradores;
    }

    public void setMoradores(List<MoradorRepublica> moradores) {
        this.moradores = moradores;
    }
}
