package mr.fmr.model;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Estudante extends User {

    public Estudante(User user) {
        super(user.getEmail(), user.getPassword(), user.getUsername(), user.isTermos(), user.getTipo());
    }

    public Estudante() {

    }

    private String nome;

    private Date birthday;

    @ManyToOne
    private Universidade universidade;

    @ManyToOne
    private Republica republica;

    @OneToOne
    private Endereco endereco;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getBirthday() {
        return birthday;
    }

    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    public Universidade getUniversidade() {
        return universidade;
    }

    public void setUniversidade(Universidade universidade) {
        this.universidade = universidade;
    }

    public Republica getRepublica() {
        return republica;
    }

    public void setRepublica(Republica republica) {
        this.republica = republica;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }
}
