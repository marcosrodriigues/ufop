package mr.fmr.model;

import com.fasterxml.jackson.annotation.JsonIgnore;

import javax.persistence.*;
import java.util.Date;

@Entity
public class MoradorRepublica {

    @EmbeddedId
    private MoradorRepublicaId id;

    @OneToOne(fetch = FetchType.LAZY)
    @MapsId("estudante_id")
    private Estudante morador;

    @ManyToOne(fetch = FetchType.LAZY)
    @MapsId("republica_id")
    private Republica republica;

    private Date dataIngresso;

    private boolean aprovado;

    public MoradorRepublica() {

    }

    public MoradorRepublica(Estudante morador, Republica republica) {
        this.id = new MoradorRepublicaId(morador.getId(), republica.getId());
        this.morador = morador;
        this.republica = republica;
        this.dataIngresso = new Date();
        this.aprovado = false;
    }

    public MoradorRepublica(Estudante morador, Republica republica, Date dataIngresso, boolean aprovado) {
        this.id = new MoradorRepublicaId(morador.getId(), republica.getId());
        this.morador = morador;
        this.republica = republica;
        this.dataIngresso = dataIngresso;
        this.aprovado = aprovado;
    }

    public MoradorRepublicaId getId() {
        return id;
    }

    public void setId(MoradorRepublicaId id) {
        this.id = id;
    }

    @JsonIgnore
    public Estudante getMorador() {
        return morador;
    }

    public void setMorador(Estudante morador) {
        this.morador = morador;
    }

    public Republica getRepublica() {
        return republica;
    }

    public void setRepublica(Republica republica) {
        this.republica = republica;
    }

    public Date getDataIngresso() {
        return dataIngresso;
    }

    public void setDataIngresso(Date dataIngresso) {
        this.dataIngresso = dataIngresso;
    }

    public boolean isAprovado() {
        return aprovado;
    }

    public void setAprovado(boolean aprovado) {
        this.aprovado = aprovado;
    }
}
