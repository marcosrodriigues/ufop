package mr.fmr.model;

import com.fasterxml.jackson.annotation.JsonFormat;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Estudante extends User {

    public Estudante(User user) {
        super(user.getEmail(), user.getPassword(), user.getUsername(), user.isTermos(), user.getTipo(), user.getPerfil());
    }

    public Estudante() {

    }

    private String nome;

    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date birthday;

    @ManyToOne
    private Universidade universidade;

    @OneToOne(mappedBy = "morador", cascade = CascadeType.ALL)
    private MoradorRepublica moradorRepublica;

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

    public MoradorRepublica getMoradorRepublica() {
        return moradorRepublica;
    }

    public void setMoradorRepublica(MoradorRepublica moradorRepublica) {
        this.moradorRepublica = moradorRepublica;
    }
}
